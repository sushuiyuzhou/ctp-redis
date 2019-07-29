//
// Created by colin on 7/28/2019.
//

#ifndef CTP_STORAGE_REDIS_REDIS_H_
#define CTP_STORAGE_REDIS_REDIS_H_

#include "../spdlog/spdlog.h"

#include <boost/current_function.hpp>

#include <hiredis/hiredis.h>

#include <map>
#include <memory>
#include <stdexcept>
#include <string>

namespace redis {

class Redis {
  // hiredis objects
  using ContextDeleter = void (*)(redisContext *);
  using ReplyDeleter = void (*)(void *);

  using RedisContext = std::unique_ptr<redisContext, ContextDeleter>;
  using RedisReply = std::unique_ptr<redisReply, ReplyDeleter>;

  RedisContext _cxt;

  std::string _host;
  int _port;
  timeval _timeout;

  std::shared_ptr<spdlog::logger> _logger;

 public:
  Redis(std::string host = "localhost",
        int port = 6379,
        timeval timeout = {1, 500000})
      : _logger(spdlog::stdout_color_mt("Redis")),
        _host(host),
        _port(port),
        _timeout(timeout),
        _cxt(nullptr, redisFree) {
    _logger->info("[Redis]: initialize redis client...");
    connect();
  }

  ~Redis() {
    _logger->info("[Redis]: disconnet client");
  }

  // force connect
  bool connect() {
    _cxt.reset(redisConnectWithTimeout(_host.c_str(), _port, _timeout));
    //_cxt.reset(redisConnect(_host.c_str(), _port));
    if (!_cxt || _cxt->err) {
      _logger->error("[Redis]: error connecting to redis server");
      throw std::runtime_error("[Redis]: error connecting to redis server.");
    }
    return true;
  }

  // return Reply handle from a redis request
  template<typename... Args>
  RedisReply getRedisReply(Args... args) {
    RedisReply reply(
        static_cast<redisReply *>(redisCommand(_cxt.get(), args...)), freeReplyObject);
    return reply;
  }

  // helper to check return status of the reply object
  void processReply(redisReply const *reply) {
    switch (reply->type) {
      case REDIS_REPLY_STATUS:_logger->info("[Redis]: redis returns the status {}", reply->str);
        break;
      case REDIS_REPLY_ERROR:_logger->info("[Redis]: redis returns error");
        break;
      case REDIS_REPLY_INTEGER:_logger->info("[Redis]: redis returns an integer {}", reply->integer);
        break;
      case REDIS_REPLY_NIL:_logger->info("[Redis]: redis returns nil");
        break;
      case REDIS_REPLY_STRING:_logger->info("[Redis]: redis returns string {}", reply->str);
        break;
      case REDIS_REPLY_ARRAY:_logger->info("[Redis]: redis returns array");
        for (auto j = 0; j < reply->elements; j++) {
          processReply(reply->element[j]);
        }
        break;
    }
  }

  // helper util to test the redis reply
  template<typename... Args>
  void testRedisReply(Args... args) {
    processReply(getRedisReply(args...).get());
  }

  bool checkStatusOK(redisReply const *reply) {
    if (reply->type == REDIS_REPLY_STATUS && std::string(reply->str) == "OK") {
      return true;
    } else {
      _logger->info("expect return status OK. Instead, got {}", reply->str);
      return false;
    }
  }

  bool matchReturnStatus(redisReply const *reply, int statusCode) {
    //#define REDIS_REPLY_STRING 1
    //#define REDIS_REPLY_ARRAY 2
    //#define REDIS_REPLY_INTEGER 3
    //#define REDIS_REPLY_NIL 4
    //#define REDIS_REPLY_STATUS 5
    //#define REDIS_REPLY_ERROR 6
    return reply->type == statusCode;
  }

  long long int getReturnInteger(redisReply const *reply) {
    return reply->integer;
  }

  // string interface
  bool SET(std::string const &key, std::string const &val) {
    auto query = "SET " + key + " " + val;
    auto reply = getRedisReply(query.c_str());
    return checkStatusOK(reply.get());
  }

  std::string GET(std::string const &key) {
    auto query = "GET " + key;
    auto reply = getRedisReply(query.c_str());

    if (matchReturnStatus(reply.get(), REDIS_REPLY_STRING)) {
      return reply->str;
    } else {
      _logger->info("incorrect return type {}, expect string", reply->type);
      return "";
    }
  }

  bool MSET(std::map<std::string, std::string> const &kvs) {
    auto query = std::string("MSET ");
    for (auto &e : kvs) {
      query += e.first + " " + e.second;
    }

    auto reply = getRedisReply(query.c_str());

    if (checkStatusOK(reply.get())) {
      return true;
    } else {
      _logger->error("[Redis]: error in MSET");
      processReply(reply.get());
      return false;
    }
  }

  std::map<std::string, std::string> MGET(std::vector<std::string> keys) {
    auto query = std::string("MGET ");
    for (auto & e : keys) {
      query += e;
    }

    auto reply = getRedisReply(query.c_str());

    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {

    }
    
  }

  // hash interface
  bool HMSET(std::string const &name, std::map<std::string, std::string> const &cnt) {
    std::string hash;
    for (auto &e : cnt) {
      if (!e.second.empty()) // avoid empty content
        hash += e.first + " " + e.second + " ";
    }

    auto query = "HMSET " + name + " " + hash;

    auto reply = getRedisReply(query.c_str());

    if (checkStatusOK(reply.get())) {
      return true;
    } else {
      processReply(reply.get());
      return false;
    }
  }

  std::map<std::string, std::string> HGETALL(std::string const &name) {
    auto query = "HGETALL " + name;

    auto reply = getRedisReply(query.c_str());

    std::map<std::string, std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i += 2) {
        res[reply->element[i]->str] = reply->element[i + 1]->str;
      }
    }

    return res;
  }

  bool ZADD(std::string const &set, long long int score, std::string const &str) {
    auto query = "ZADD " + set + " " + std::to_string(score) + " " + str;

    auto reply = getRedisReply(query.c_str());

    if (matchReturnStatus(reply.get(), REDIS_REPLY_INTEGER) && reply->integer >= 0) {
      return true;
    } else {
      _logger->info("failed to update {}", set);
      processReply(reply.get());
      return false;
    }
  }

  std::vector<std::string> ZRANGE(std::string const &set, long long int start, long long int end) {
    auto query = "ZRANGE " + set + " " + std::to_string(start) + " " + std::to_string(end);

    auto reply = getRedisReply(query.c_str());

    std::vector<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.emplace_back(reply->element[i]->str);
      }
    }

    if (matchReturnStatus(reply.get(), REDIS_REPLY_ERROR)) {
      _logger->info("redis returned error");
    }

    return res;
  }

  std::string ZFIRST(std::string const &set) {
    return ZRANGE(set, 0, 0).at(0);
  }

  std::string ZLAST(std::string const &set) {
    return ZRANGE(set, -1, -1).at(0);
  }

  std::vector<std::string> ZRANGEBYSCORE(std::string const &set, long long int start, long long int end) {
    auto query = "ZRANGEBYSCORE " + set + " " + std::to_string(start) + " " + std::to_string(end);

    auto reply = getRedisReply(query.c_str());

    std::vector<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.emplace_back(reply->element[i]->str);
      }
    }

    if (matchReturnStatus(reply.get(), REDIS_REPLY_ERROR)) {
      _logger->info("redis returned error");
    }

    return res;
  }

};

}

#endif //CTP_STORAGE_REDIS_REDIS_H_

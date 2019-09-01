//
// Created by colin on 7/28/2019.
//

#ifndef CTP_STORAGE_REDIS_REDIS_H_
#define CTP_STORAGE_REDIS_REDIS_H_

#include "../spdlog/spdlog.h"

#include <boost/current_function.hpp>

#include <hiredis/hiredis.h>

#include <functional>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <random>

#include <signal.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>

namespace redis {

static auto DIST = std::uniform_int_distribution<int>(100, 999);
static auto ENG = std::default_random_engine();

class Redis {
  // hiredis objects
  using ContextDeleter = void (*)(redisContext *);
  using ReplyDeleter = void (*)(void *);
  using AsyncContextDeleter = void (*)(redisAsyncContext *);

  using RedisContext = std::unique_ptr<redisContext, ContextDeleter>;
  using RedisReply = std::unique_ptr<redisReply, ReplyDeleter>;

  using RedisAsyncContect = std::unique_ptr<redisAsyncContext, AsyncContextDeleter>;
  using PubSubFunctor = std::function<void(redisAsyncContext *, void *, void *)>;

  std::string _id;
  RedisContext _cxt;
  RedisAsyncContect _async;

  std::string _host;
  int _port;
  timeval _timeout;

  std::shared_ptr<spdlog::logger> _logger;

 public:
  Redis(std::string host = "localhost",
        int port = 6379,
        timeval timeout = {1, 500000})
      : _id(std::to_string(DIST(ENG))),
        _logger(spdlog::stdout_color_mt("Redis Client " + _id)),
        _host(host),
        _port(port),
        _timeout(timeout),
        _cxt(nullptr, redisFree),
        _async(nullptr, redisAsyncDisconnect) {
    _logger->info("[Redis]: initialize redis client...");
    connect();
    initAsyncConnection();
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

  bool initAsyncConnection() {
    _logger->info("[Redis]: initialize async connection");
    _async.reset(redisAsyncConnect(_host.c_str(), _port));
    if (_async->err) {
      _logger->info("[Redis]: error establishing async context {}", _async->errstr);
    }
  }

  static void onSubMessage(redisAsyncContext *c, void *replyOrig, void *privdata) {
    auto reply = static_cast<redisReply *>(replyOrig);

    if (!reply) {
      return;
    }

    if (reply->type == REDIS_REPLY_ARRAY) {
      for (int j = 0; j < reply->elements; j++) {
        printf("%u) %s\n", j, reply->element[j]->str);
      }
    }
  }

  void subscribeToTopic(std::string const &topic, void(*func)(redisAsyncContext*, void*, void*)) {
    signal(SIGPIPE, SIG_IGN);

    using EventType = std::unique_ptr<event_base, void(*)(event_base*)>;
    EventType event(event_base_new(), event_base_free);

    redisLibeventAttach(_async.get(), event.get());
    redisAsyncCommand(_async.get(), func, NULL, (std::string("subscribe ")+topic).c_str());
    event_base_dispatch(event.get());
  }

  void publishToTopic(std::string const & topic, std::string const& content) {
    auto query = "publish " + topic + " " + content;
    auto reply = getRedisReply(query.c_str());
    if (reply->type == REDIS_REPLY_ERROR) {
      _logger->error("[Redis]: error publish to topic {}", topic);
    }
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

// TODO: expand to arbitrary arguments
  bool DEL(std::string const &key) {
    auto query = "DEL " + key;
    auto reply = getRedisReply(query.c_str());
    return reply->type == REDIS_REPLY_INTEGER && reply->integer == 1;
  }

  bool MSET(std::map<std::string, std::string> const &kvs) {
    auto query = std::string("MSET ");
    for (auto &e : kvs) {
      query += e.first + " " + e.second + " ";
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
    for (auto &e : keys) {
      query += e + " ";
    }

    auto reply = getRedisReply(query.c_str());

    std::map<std::string, std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res[keys[i]] = reply->element[i]->str;
      }
    } else {
      _logger->error("[Redis]: error in MGET");
    }

    return res;
  }

// set interface
// TODO: extend to arbitrary arguments
  bool SADD(std::string const &set, std::string const &value) {
    auto query = std::string("SADD ") + set + " " + value;
    auto reply = getRedisReply(query.c_str());
    return reply->type == REDIS_REPLY_INTEGER && reply->integer == 1;
  }

  std::set<std::string> SMEMBERS(std::string const &set) {
    auto query = std::string("SMEMBERS ") + set;
    auto reply = getRedisReply(query.c_str());

    std::set<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.insert(reply->element[i]->str);
      }
    } else {
      _logger->error("[Redis]: error in SADD");
    }

    return res;
  }

  bool SISMEMBER(std::string const &set, std::string const &mem) {
    auto query = std::string("SISMEMBER ") + set + " " + mem;
    auto reply = getRedisReply(query.c_str());
    return reply->type == REDIS_REPLY_INTEGER && reply->integer == 1;
  }

  std::set<std::string> SINTER(std::string const &l, std::string const &r) {
    auto query = std::string("SINTER ") + l + " " + r;
    auto reply = getRedisReply(query.c_str());

    std::set<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.insert(reply->element[i]->str);
      }
    } else {
      _logger->error("[Redis]: error in SINTER");
    }

    return res;
  }

  std::set<std::string> SUNION(std::string const &l, std::string const &r) {
    auto query = std::string("SUNION ") + l + " " + r;
    auto reply = getRedisReply(query.c_str());

    std::set<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.insert(reply->element[i]->str);
      }
    } else {
      _logger->error("[Redis]: error in SUNION");
    }

    return res;
  }

// hash interface
  bool HSET(std::string const &name, std::map<std::string, std::string> const &ctn) {
    std::string hash;
    for (auto &e : ctn) {
      if (!e.second.empty()) // avoid empty content
        hash += e.first + " " + e.second + " ";
    }

    auto query = "HSET " + name + " " + hash;
    auto reply = getRedisReply(query.c_str());

    return reply->type == REDIS_REPLY_INTEGER;
  }

  bool HEXISTS(std::string const &hash, std::string const &key) {
    auto query = std::string("HEXISTS ") + hash + " " + key;
    auto reply = getRedisReply(query.c_str());
    return reply->type == REDIS_REPLY_INTEGER && reply->integer == 1;
  }

  std::string HGET(std::string const &hash, std::string const &key) {
    auto query = std::string("HGET ") + hash + " " + key;
    auto reply = getRedisReply(query.c_str());

    if (reply->type == REDIS_REPLY_NIL) {
      _logger->warn("[Redis]: nil for hash {}, key {}", hash, key);
      return "";
    } else if (reply->type == REDIS_REPLY_STRING) {
      return reply->str;
    } else {
      _logger->error("[Redis]: error in HGET");
    }
  }

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

  std::vector<std::string> HMGET(std::string const &hash, std::vector<std::string> const &keys) {
    auto query = std::string("HMGET ") + hash + " ";
    for (auto &key : keys) {
      query += key + " ";
    }

    auto reply = getRedisReply(query.c_str());

    std::vector<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        if (reply->element[i]->type == REDIS_REPLY_NIL) {
          res.emplace_back("");
        } else {
          res.emplace_back(reply->element[i]->str);
        }
      }
    } else {
      _logger->error("[Redis]: error in HMGET");
    }
    return res;
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

// sorted sets interface
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
      _logger->error("[Redis]: error in ZRANGE");
    }

    return res;
  }

  std::vector<std::string> ZREVRANGE(std::string const &set, long long int start, long long int end) {
    auto query = "ZREVRANGE " + set + " " + std::to_string(start) + " " + std::to_string(end);

    auto reply = getRedisReply(query.c_str());

    std::vector<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.emplace_back(reply->element[i]->str);
      }
    } else {
      _logger->error("[Redis]: error in ZREVRANGE");
    }

    return res;
  }

  std::string ZFIRST(std::string const &set) {
    return ZREVRANGE(set, -1, -1).at(0);
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

  std::vector<std::string> ZRANGEBYLEX(std::string const &set, std::string const &start, std::string const &end) {
    auto query = "ZRANGEBYLEX " + set + " [" + start + " [" + end;
    auto reply = getRedisReply(query.c_str());

    std::vector<std::string> res;
    if (matchReturnStatus(reply.get(), REDIS_REPLY_ARRAY)) {
      for (auto i = 0; i < reply->elements; i++) {
        res.emplace_back(reply->element[i]->str);
      }
    } else {
      _logger->error("[Redis]: error in ZRANGEBYLEX");
    }

    return res;
  }

};

}

#endif //CTP_STORAGE_REDIS_REDIS_H_

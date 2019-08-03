//
// Created by colin on 7/28/2019.
//

#include <gtest/gtest.h>

#include "../redis/Redis.h"

#include <map>
#include <string>
#include <stdexcept>

namespace tests {

TEST(redis, init) {
  redis::Redis cli("localhost");
}

TEST(redis, init_fail) {
  EXPECT_ANY_THROW(redis::Redis("xxxx"));
}
class TestRedis : public ::testing::Test {
 protected:
  redis::Redis cli;

 public:
  TestRedis() : cli("localhost") {}
};

TEST_F(TestRedis, set) {
  cli.SET("hello", "world");
  EXPECT_EQ(cli.GET("hello"), "world");
  cli.DEL("hello");
}

TEST_F(TestRedis, mset) {
  std::map<std::string, std::string> in;
  in.insert({"a", "1"});
  in.insert({"b", "2"});
  cli.MSET(in);

  auto out = cli.MGET(std::vector<std::string>{"a", "b"});
  EXPECT_EQ(in, out);

  cli.DEL("a");
  cli.DEL("b");
}

TEST_F(TestRedis, sets) {
  cli.SADD("myset", "a");
  cli.SADD("myset", "b");
  cli.SADD("myset", "c");
  cli.SADD("myset2", "b");
  cli.SADD("myset2", "c");
  cli.SADD("myset2", "d");

  EXPECT_TRUE(cli.SISMEMBER("myset", "a"));

  std::set<std::string> myset{"a", "b", "c"};
  EXPECT_EQ(myset, cli.SMEMBERS("myset"));

  std::set<std::string> inter{"b", "c"};
  EXPECT_EQ(cli.SINTER("myset", "myset2"), inter);

  std::set<std::string> un{"a", "b", "c", "d"};
  EXPECT_EQ(cli.SUNION("myset", "myset2"), un);

  cli.DEL("myset");
  cli.DEL("myset2");
}

TEST_F(TestRedis, hset) {
  cli.DEL("myhash");

  std::map<std::string, std::string> ctn;
  ctn["key1"] = "value1";
  ctn["key2"] = "value2";
  cli.HSET("myhash", ctn);

  EXPECT_EQ(cli.HGET("myhash", "key2"), "value2");
  EXPECT_EQ(cli.HGET("myhash", "key3"), "");

  cli.DEL("myhash");
}

TEST_F(TestRedis, hmset) {
  cli.DEL("myhash2");

  std::map<std::string, std::string> ctn;
  ctn["key1"] = "value1";
  ctn["key2"] = "value2";
  cli.HMSET("myhash2", ctn);

  auto out = cli.HMGET("myhash2", std::vector<std::string>({"key1", "key2", "key3"}));
  EXPECT_EQ(out, std::vector<std::string>({"value1", "value2", ""}));
  EXPECT_EQ(ctn, cli.HGETALL("myhash2"));

  cli.DEL("myhash2");
}

TEST_F(TestRedis, zset) {
  cli.DEL("myset");
  cli.ZADD("myset", 0, "a");
  cli.ZADD("myset", 1, "b");
  cli.ZADD("myset", 2, "c");
  cli.ZADD("myset", 3, "d");

  EXPECT_EQ(cli.ZLAST("myset"), "d");
  EXPECT_EQ(cli.ZFIRST("myset"), "a");
  EXPECT_EQ(cli.ZRANGE("myset", 1, 2), std::vector<std::string>({"b", "c"}));
  EXPECT_EQ(cli.ZREVRANGE("myset", 1, 2), std::vector<std::string>({"c", "b"}));
  EXPECT_EQ(cli.ZRANGEBYLEX("myset", "a", "c"), std::vector<std::string>({"a", "b", "c"}));
  EXPECT_EQ(cli.ZRANGEBYSCORE("myset", 1, 2), std::vector<std::string>({"b", "c"}));

  cli.DEL("myset");
}

}


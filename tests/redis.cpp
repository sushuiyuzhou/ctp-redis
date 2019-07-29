//
// Created by colin on 7/28/2019.
//

#include <gtest/gtest.h>

#include "../redis/Redis.h"

#include <stdexcept>

namespace tests{

TEST(redis, init){
  redis::Redis cli("localhost");
}

TEST(redis, init_fail){
  EXPECT_ANY_THROW(redis::Redis("xxxx"));
}

}


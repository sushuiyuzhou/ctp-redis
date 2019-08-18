cmake_minimum_required(VERSION 3.10)
project(ctp-storage)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

# add system headers
include_directories(include)

set(SOURCE_FILES
        main.cpp
        redis/Redis.cpp
        redis/Redis.h
        tests/redis.cpp redis/utils.h tests/serdes.cpp redis/utils.cpp redis/score.h)

add_executable(ctp-storage ${SOURCE_FILES})

#Link with GoogleTest
#include_directories(include/gtest)
target_link_libraries(ctp-storage gtest gtest_main)

#Link with Boost
find_package(Boost COMPONENTS program_options filesystem date_time REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(ctp-storage ${Boost_LIBRARIES})

#Link with hiredis
#include_directories(include/hiredis)
target_link_libraries(ctp-storage hiredis)

#Link with CTP
include_directories(v1)
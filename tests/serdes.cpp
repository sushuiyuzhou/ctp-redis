//
// Created by colin on 8/4/2019.
//

#include <gtest/gtest.h>

#include "ctp/ThostFtdcUserApiDataType.h"
#include "ctp/ThostFtdcUserApiStruct.h"

#include "../redis/utils.h"

namespace tests {

//TEST(utils, type) {
//  if (storage::toString<int, storage::TypeID::T1>(3) != "3") {
//    FAIL();
//  }
//
//  if (storage::fromString<int, storage::TypeID::T1>("1") != 1) {
//    FAIL();
//  }
//
//  storage::toString<int, storage::TypeID::T2>(3);
//  storage::fromString<int, storage::TypeID::T2>("2");
//}

//template<class T, TypeID ID>
//inline std::string toString(T &&t) {
//  return "";
//}
//
//template<class T, TypeID ID>
//inline T fromString(std::string &&str) {
//  return T{};
//}
//
//template<>
//inline std::string toString<int, TypeID::T1>(int &&t) {
//  return std::to_string(std::forward<int>(t));
//}
//
//template<>
//inline int fromString<int, TypeID::T1>(std::string &&str) {
//  return std::stoi(std::forward<std::string>(str));
//}
//
//template<>
//inline std::string toString<int, TypeID::T2>(int &&t) {
//  return std::to_string(std::forward<int>(t));
//}
//
//template<>
//inline int fromString<int, TypeID::T2>(std::string &&str) {
//  return std::stoi(std::forward<std::string>(str));
//}

class TestSerDes : public ::testing::Test {
 protected:
  redis::Redis cli;

 public:
  TestSerDes() : cli("localhost") {}
};

TEST_F(TestSerDes, CThostFtdcDisseminationField) {
  cli.DEL("TestDataCThostFtdcDisseminationField");

  auto data = std::make_unique<CThostFtdcDisseminationField>();

  data->SequenceSeries = 123;
  data->SequenceNo = 1;

  storage::toRedis(cli, "TestDataCThostFtdcDisseminationField", *data);

  auto res = storage::fromRedis<CThostFtdcDisseminationField>()(cli, "TestDataCThostFtdcDisseminationField");

  EXPECT_EQ(res->SequenceSeries, data->SequenceSeries);
  EXPECT_EQ(res->SequenceNo, data->SequenceNo);

  cli.DEL("TestDataCThostFtdcDisseminationField");
}

TEST_F(TestSerDes, CThostFtdcReqUserLoginField) {
  cli.DEL("TestCThostFtdcReqUserLoginField");

  auto data = std::make_unique<CThostFtdcReqUserLoginField>();

  strcpy(data->TradingDay, "XXXXXXXX");
  strcpy(data->BrokerID, "BrokerID");
  strcpy(data->UserID, "UserID");
  strcpy(data->Password, "Password");
  strcpy(data->UserProductInfo, "UserProductInfo");
  strcpy(data->InterfaceProductInfo, "InterfaceProductInfo");
  strcpy(data->ProtocolInfo, "ProtocolInfo");
  strcpy(data->MacAddress, "MacAddress");
  strcpy(data->OneTimePassword, "OneTimePassword");
  strcpy(data->ClientIPAddress, "ClientIPAddress");

  storage::toRedis(cli, "TestCThostFtdcReqUserLoginField", *data);

  auto res = storage::fromRedis<CThostFtdcReqUserLoginField>()(cli, "TestCThostFtdcReqUserLoginField");

  EXPECT_EQ(std::string(res->TradingDay), std::string(data->TradingDay));
  EXPECT_EQ(std::string(res->BrokerID), std::string(data->BrokerID));

  cli.DEL("TestCThostFtdcReqUserLoginField");
}

};



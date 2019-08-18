//
// Created by colin on 8/4/2019.
//

#ifndef CTP_STORAGE_REDIS_UTILS_H_
#define CTP_STORAGE_REDIS_UTILS_H_

#include "ctp/ThostFtdcUserApiDataType.h"
#include "ctp/ThostFtdcUserApiStruct.h"

#include <boost/lexical_cast.hpp>

#include "score.h"
#include "Redis.h"

#include <memory>
#include <string>

namespace storage {

template<typename T>
class FromRedis {
 public:
  virtual std::unique_ptr<T> operator()(redis::Redis &cli, std::string const &path) = 0;
};

template<typename T>
class fromRedis : FromRedis<T> {
 public:
  std::unique_ptr<T> operator()(redis::Redis &cli, std::string const &path);
};

/*
 * Code below are automatically generated.
 * */

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDisseminationField const &data);

template<>
class fromRedis<CThostFtdcDisseminationField> {
 public:
  std::unique_ptr<CThostFtdcDisseminationField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcDisseminationField>();

    res->SequenceSeries = boost::lexical_cast<short>(map.at("SequenceSeries"));
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqUserLoginField const &data);

template<>
class fromRedis<CThostFtdcReqUserLoginField> {
 public:
  std::unique_ptr<CThostFtdcReqUserLoginField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqUserLoginField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->InterfaceProductInfo, map.at("InterfaceProductInfo").data());
    strcpy(res->ProtocolInfo, map.at("ProtocolInfo").data());
    strcpy(res->MacAddress, map.at("MacAddress").data());
    strcpy(res->OneTimePassword, map.at("OneTimePassword").data());
    strcpy(res->ClientIPAddress, map.at("ClientIPAddress").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspUserLoginField const &data);

template<>
class fromRedis<CThostFtdcRspUserLoginField> {
 public:
  std::unique_ptr<CThostFtdcRspUserLoginField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspUserLoginField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->LoginTime, map.at("LoginTime").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->SystemName, map.at("SystemName").data());
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->MaxOrderRef, map.at("MaxOrderRef").data());
    strcpy(res->SHFETime, map.at("SHFETime").data());
    strcpy(res->DCETime, map.at("DCETime").data());
    strcpy(res->CZCETime, map.at("CZCETime").data());
    strcpy(res->FFEXTime, map.at("FFEXTime").data());
    strcpy(res->INETime, map.at("INETime").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserLogoutField const &data);

template<>
class fromRedis<CThostFtdcUserLogoutField> {
 public:
  std::unique_ptr<CThostFtdcUserLogoutField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserLogoutField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForceUserLogoutField const &data);

template<>
class fromRedis<CThostFtdcForceUserLogoutField> {
 public:
  std::unique_ptr<CThostFtdcForceUserLogoutField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcForceUserLogoutField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqAuthenticateField const &data);

template<>
class fromRedis<CThostFtdcReqAuthenticateField> {
 public:
  std::unique_ptr<CThostFtdcReqAuthenticateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqAuthenticateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->AuthCode, map.at("AuthCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspAuthenticateField const &data);

template<>
class fromRedis<CThostFtdcRspAuthenticateField> {
 public:
  std::unique_ptr<CThostFtdcRspAuthenticateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspAuthenticateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcAuthenticationInfoField const &data);

template<>
class fromRedis<CThostFtdcAuthenticationInfoField> {
 public:
  std::unique_ptr<CThostFtdcAuthenticationInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcAuthenticationInfoField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->AuthInfo, map.at("AuthInfo").data());
    res->IsResult = boost::lexical_cast<int>(map.at("IsResult"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferHeaderField const &data);

template<>
class fromRedis<CThostFtdcTransferHeaderField> {
 public:
  std::unique_ptr<CThostFtdcTransferHeaderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferHeaderField>();

    strcpy(res->Version, map.at("Version").data());
    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->TradeSerial, map.at("TradeSerial").data());
    strcpy(res->FutureID, map.at("FutureID").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->RecordNum, map.at("RecordNum").data());
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankToFutureReqField const &data);

template<>
class fromRedis<CThostFtdcTransferBankToFutureReqField> {
 public:
  std::unique_ptr<CThostFtdcTransferBankToFutureReqField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferBankToFutureReqField>();

    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->FuturePwdFlag = boost::lexical_cast<char>(map.at("FuturePwdFlag"));
    strcpy(res->FutureAccPwd, map.at("FutureAccPwd").data());
    res->TradeAmt = boost::lexical_cast<double>(map.at("TradeAmt"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankToFutureRspField const &data);

template<>
class fromRedis<CThostFtdcTransferBankToFutureRspField> {
 public:
  std::unique_ptr<CThostFtdcTransferBankToFutureRspField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferBankToFutureRspField>();

    strcpy(res->RetCode, map.at("RetCode").data());
    strcpy(res->RetInfo, map.at("RetInfo").data());
    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->TradeAmt = boost::lexical_cast<double>(map.at("TradeAmt"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferFutureToBankReqField const &data);

template<>
class fromRedis<CThostFtdcTransferFutureToBankReqField> {
 public:
  std::unique_ptr<CThostFtdcTransferFutureToBankReqField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferFutureToBankReqField>();

    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->FuturePwdFlag = boost::lexical_cast<char>(map.at("FuturePwdFlag"));
    strcpy(res->FutureAccPwd, map.at("FutureAccPwd").data());
    res->TradeAmt = boost::lexical_cast<double>(map.at("TradeAmt"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferFutureToBankRspField const &data);

template<>
class fromRedis<CThostFtdcTransferFutureToBankRspField> {
 public:
  std::unique_ptr<CThostFtdcTransferFutureToBankRspField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferFutureToBankRspField>();

    strcpy(res->RetCode, map.at("RetCode").data());
    strcpy(res->RetInfo, map.at("RetInfo").data());
    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->TradeAmt = boost::lexical_cast<double>(map.at("TradeAmt"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryBankReqField const &data);

template<>
class fromRedis<CThostFtdcTransferQryBankReqField> {
 public:
  std::unique_ptr<CThostFtdcTransferQryBankReqField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferQryBankReqField>();

    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->FuturePwdFlag = boost::lexical_cast<char>(map.at("FuturePwdFlag"));
    strcpy(res->FutureAccPwd, map.at("FutureAccPwd").data());
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryBankRspField const &data);

template<>
class fromRedis<CThostFtdcTransferQryBankRspField> {
 public:
  std::unique_ptr<CThostFtdcTransferQryBankRspField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferQryBankRspField>();

    strcpy(res->RetCode, map.at("RetCode").data());
    strcpy(res->RetInfo, map.at("RetInfo").data());
    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->TradeAmt = boost::lexical_cast<double>(map.at("TradeAmt"));
    res->UseAmt = boost::lexical_cast<double>(map.at("UseAmt"));
    res->FetchAmt = boost::lexical_cast<double>(map.at("FetchAmt"));
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryDetailReqField const &data);

template<>
class fromRedis<CThostFtdcTransferQryDetailReqField> {
 public:
  std::unique_ptr<CThostFtdcTransferQryDetailReqField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferQryDetailReqField>();

    strcpy(res->FutureAccount, map.at("FutureAccount").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryDetailRspField const &data);

template<>
class fromRedis<CThostFtdcTransferQryDetailRspField> {
 public:
  std::unique_ptr<CThostFtdcTransferQryDetailRspField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferQryDetailRspField>();

    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->TradeCode, map.at("TradeCode").data());
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    strcpy(res->FutureID, map.at("FutureID").data());
    strcpy(res->FutureAccount, map.at("FutureAccount").data());
    res->BankSerial = boost::lexical_cast<int>(map.at("BankSerial"));
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->CertCode, map.at("CertCode").data());
    strcpy(res->CurrencyCode, map.at("CurrencyCode").data());
    res->TxAmount = boost::lexical_cast<double>(map.at("TxAmount"));
    res->Flag = boost::lexical_cast<char>(map.at("Flag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspInfoField const &data);

template<>
class fromRedis<CThostFtdcRspInfoField> {
 public:
  std::unique_ptr<CThostFtdcRspInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspInfoField>();

    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeField const &data);

template<>
class fromRedis<CThostFtdcExchangeField> {
 public:
  std::unique_ptr<CThostFtdcExchangeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeName, map.at("ExchangeName").data());
    res->ExchangeProperty = boost::lexical_cast<char>(map.at("ExchangeProperty"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcProductField const &data);

template<>
class fromRedis<CThostFtdcProductField> {
 public:
  std::unique_ptr<CThostFtdcProductField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcProductField>();

    strcpy(res->ProductID, map.at("ProductID").data());
    strcpy(res->ProductName, map.at("ProductName").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    res->ProductClass = boost::lexical_cast<char>(map.at("ProductClass"));
    res->VolumeMultiple = boost::lexical_cast<int>(map.at("VolumeMultiple"));
    res->PriceTick = boost::lexical_cast<double>(map.at("PriceTick"));
    res->MaxMarketOrderVolume = boost::lexical_cast<int>(map.at("MaxMarketOrderVolume"));
    res->MinMarketOrderVolume = boost::lexical_cast<int>(map.at("MinMarketOrderVolume"));
    res->MaxLimitOrderVolume = boost::lexical_cast<int>(map.at("MaxLimitOrderVolume"));
    res->MinLimitOrderVolume = boost::lexical_cast<int>(map.at("MinLimitOrderVolume"));
    res->PositionType = boost::lexical_cast<char>(map.at("PositionType"));
    res->PositionDateType = boost::lexical_cast<char>(map.at("PositionDateType"));
    res->CloseDealType = boost::lexical_cast<char>(map.at("CloseDealType"));
    strcpy(res->TradeCurrencyID, map.at("TradeCurrencyID").data());
    res->MortgageFundUseRange = boost::lexical_cast<char>(map.at("MortgageFundUseRange"));
    strcpy(res->ExchangeProductID, map.at("ExchangeProductID").data());
    res->UnderlyingMultiple = boost::lexical_cast<double>(map.at("UnderlyingMultiple"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentField const &data);

template<>
class fromRedis<CThostFtdcInstrumentField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InstrumentName, map.at("InstrumentName").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ProductID, map.at("ProductID").data());
    res->ProductClass = boost::lexical_cast<char>(map.at("ProductClass"));
    res->DeliveryYear = boost::lexical_cast<int>(map.at("DeliveryYear"));
    res->DeliveryMonth = boost::lexical_cast<int>(map.at("DeliveryMonth"));
    res->MaxMarketOrderVolume = boost::lexical_cast<int>(map.at("MaxMarketOrderVolume"));
    res->MinMarketOrderVolume = boost::lexical_cast<int>(map.at("MinMarketOrderVolume"));
    res->MaxLimitOrderVolume = boost::lexical_cast<int>(map.at("MaxLimitOrderVolume"));
    res->MinLimitOrderVolume = boost::lexical_cast<int>(map.at("MinLimitOrderVolume"));
    res->VolumeMultiple = boost::lexical_cast<int>(map.at("VolumeMultiple"));
    res->PriceTick = boost::lexical_cast<double>(map.at("PriceTick"));
    strcpy(res->CreateDate, map.at("CreateDate").data());
    strcpy(res->OpenDate, map.at("OpenDate").data());
    strcpy(res->ExpireDate, map.at("ExpireDate").data());
    strcpy(res->StartDelivDate, map.at("StartDelivDate").data());
    strcpy(res->EndDelivDate, map.at("EndDelivDate").data());
    res->InstLifePhase = boost::lexical_cast<char>(map.at("InstLifePhase"));
    res->IsTrading = boost::lexical_cast<int>(map.at("IsTrading"));
    res->PositionType = boost::lexical_cast<char>(map.at("PositionType"));
    res->PositionDateType = boost::lexical_cast<char>(map.at("PositionDateType"));
    res->LongMarginRatio = boost::lexical_cast<double>(map.at("LongMarginRatio"));
    res->ShortMarginRatio = boost::lexical_cast<double>(map.at("ShortMarginRatio"));
    res->MaxMarginSideAlgorithm = boost::lexical_cast<char>(map.at("MaxMarginSideAlgorithm"));
    strcpy(res->UnderlyingInstrID, map.at("UnderlyingInstrID").data());
    res->StrikePrice = boost::lexical_cast<double>(map.at("StrikePrice"));
    res->OptionsType = boost::lexical_cast<char>(map.at("OptionsType"));
    res->UnderlyingMultiple = boost::lexical_cast<double>(map.at("UnderlyingMultiple"));
    res->CombinationType = boost::lexical_cast<char>(map.at("CombinationType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerField const &data);

template<>
class fromRedis<CThostFtdcBrokerField> {
 public:
  std::unique_ptr<CThostFtdcBrokerField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerAbbr, map.at("BrokerAbbr").data());
    strcpy(res->BrokerName, map.at("BrokerName").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTraderField const &data);

template<>
class fromRedis<CThostFtdcTraderField> {
 public:
  std::unique_ptr<CThostFtdcTraderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTraderField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallCount = boost::lexical_cast<int>(map.at("InstallCount"));
    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorField const &data);

template<>
class fromRedis<CThostFtdcInvestorField> {
 public:
  std::unique_ptr<CThostFtdcInvestorField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorField>();

    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorGroupID, map.at("InvestorGroupID").data());
    strcpy(res->InvestorName, map.at("InvestorName").data());
    res->IdentifiedCardType = boost::lexical_cast<char>(map.at("IdentifiedCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->OpenDate, map.at("OpenDate").data());
    strcpy(res->Mobile, map.at("Mobile").data());
    strcpy(res->CommModelID, map.at("CommModelID").data());
    strcpy(res->MarginModelID, map.at("MarginModelID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingCodeField const &data);

template<>
class fromRedis<CThostFtdcTradingCodeField> {
 public:
  std::unique_ptr<CThostFtdcTradingCodeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingCodeField>();

    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));
    res->ClientIDType = boost::lexical_cast<char>(map.at("ClientIDType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcPartBrokerField const &data);

template<>
class fromRedis<CThostFtdcPartBrokerField> {
 public:
  std::unique_ptr<CThostFtdcPartBrokerField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcPartBrokerField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSuperUserField const &data);

template<>
class fromRedis<CThostFtdcSuperUserField> {
 public:
  std::unique_ptr<CThostFtdcSuperUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSuperUserField>();

    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->UserName, map.at("UserName").data());
    strcpy(res->Password, map.at("Password").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSuperUserFunctionField const &data);

template<>
class fromRedis<CThostFtdcSuperUserFunctionField> {
 public:
  std::unique_ptr<CThostFtdcSuperUserFunctionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSuperUserFunctionField>();

    strcpy(res->UserID, map.at("UserID").data());
    res->FunctionCode = boost::lexical_cast<char>(map.at("FunctionCode"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorGroupField const &data);

template<>
class fromRedis<CThostFtdcInvestorGroupField> {
 public:
  std::unique_ptr<CThostFtdcInvestorGroupField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorGroupField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorGroupID, map.at("InvestorGroupID").data());
    strcpy(res->InvestorGroupName, map.at("InvestorGroupName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountField const &data);

template<>
class fromRedis<CThostFtdcTradingAccountField> {
 public:
  std::unique_ptr<CThostFtdcTradingAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingAccountField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->PreMortgage = boost::lexical_cast<double>(map.at("PreMortgage"));
    res->PreCredit = boost::lexical_cast<double>(map.at("PreCredit"));
    res->PreDeposit = boost::lexical_cast<double>(map.at("PreDeposit"));
    res->PreBalance = boost::lexical_cast<double>(map.at("PreBalance"));
    res->PreMargin = boost::lexical_cast<double>(map.at("PreMargin"));
    res->InterestBase = boost::lexical_cast<double>(map.at("InterestBase"));
    res->Interest = boost::lexical_cast<double>(map.at("Interest"));
    res->Deposit = boost::lexical_cast<double>(map.at("Deposit"));
    res->Withdraw = boost::lexical_cast<double>(map.at("Withdraw"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));
    res->FrozenCash = boost::lexical_cast<double>(map.at("FrozenCash"));
    res->FrozenCommission = boost::lexical_cast<double>(map.at("FrozenCommission"));
    res->CurrMargin = boost::lexical_cast<double>(map.at("CurrMargin"));
    res->CashIn = boost::lexical_cast<double>(map.at("CashIn"));
    res->Commission = boost::lexical_cast<double>(map.at("Commission"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->PositionProfit = boost::lexical_cast<double>(map.at("PositionProfit"));
    res->Balance = boost::lexical_cast<double>(map.at("Balance"));
    res->Available = boost::lexical_cast<double>(map.at("Available"));
    res->WithdrawQuota = boost::lexical_cast<double>(map.at("WithdrawQuota"));
    res->Reserve = boost::lexical_cast<double>(map.at("Reserve"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->Credit = boost::lexical_cast<double>(map.at("Credit"));
    res->Mortgage = boost::lexical_cast<double>(map.at("Mortgage"));
    res->ExchangeMargin = boost::lexical_cast<double>(map.at("ExchangeMargin"));
    res->DeliveryMargin = boost::lexical_cast<double>(map.at("DeliveryMargin"));
    res->ExchangeDeliveryMargin = boost::lexical_cast<double>(map.at("ExchangeDeliveryMargin"));
    res->ReserveBalance = boost::lexical_cast<double>(map.at("ReserveBalance"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->PreFundMortgageIn = boost::lexical_cast<double>(map.at("PreFundMortgageIn"));
    res->PreFundMortgageOut = boost::lexical_cast<double>(map.at("PreFundMortgageOut"));
    res->FundMortgageIn = boost::lexical_cast<double>(map.at("FundMortgageIn"));
    res->FundMortgageOut = boost::lexical_cast<double>(map.at("FundMortgageOut"));
    res->FundMortgageAvailable = boost::lexical_cast<double>(map.at("FundMortgageAvailable"));
    res->MortgageableFund = boost::lexical_cast<double>(map.at("MortgageableFund"));
    res->SpecProductMargin = boost::lexical_cast<double>(map.at("SpecProductMargin"));
    res->SpecProductFrozenMargin = boost::lexical_cast<double>(map.at("SpecProductFrozenMargin"));
    res->SpecProductCommission = boost::lexical_cast<double>(map.at("SpecProductCommission"));
    res->SpecProductFrozenCommission = boost::lexical_cast<double>(map.at("SpecProductFrozenCommission"));
    res->SpecProductPositionProfit = boost::lexical_cast<double>(map.at("SpecProductPositionProfit"));
    res->SpecProductCloseProfit = boost::lexical_cast<double>(map.at("SpecProductCloseProfit"));
    res->SpecProductPositionProfitByAlg = boost::lexical_cast<double>(map.at("SpecProductPositionProfitByAlg"));
    res->SpecProductExchangeMargin = boost::lexical_cast<double>(map.at("SpecProductExchangeMargin"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionField const &data);

template<>
class fromRedis<CThostFtdcInvestorPositionField> {
 public:
  std::unique_ptr<CThostFtdcInvestorPositionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorPositionField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->PositionDate = boost::lexical_cast<char>(map.at("PositionDate"));
    res->YdPosition = boost::lexical_cast<int>(map.at("YdPosition"));
    res->Position = boost::lexical_cast<int>(map.at("Position"));
    res->LongFrozen = boost::lexical_cast<int>(map.at("LongFrozen"));
    res->ShortFrozen = boost::lexical_cast<int>(map.at("ShortFrozen"));
    res->LongFrozenAmount = boost::lexical_cast<double>(map.at("LongFrozenAmount"));
    res->ShortFrozenAmount = boost::lexical_cast<double>(map.at("ShortFrozenAmount"));
    res->OpenVolume = boost::lexical_cast<int>(map.at("OpenVolume"));
    res->CloseVolume = boost::lexical_cast<int>(map.at("CloseVolume"));
    res->OpenAmount = boost::lexical_cast<double>(map.at("OpenAmount"));
    res->CloseAmount = boost::lexical_cast<double>(map.at("CloseAmount"));
    res->PositionCost = boost::lexical_cast<double>(map.at("PositionCost"));
    res->PreMargin = boost::lexical_cast<double>(map.at("PreMargin"));
    res->UseMargin = boost::lexical_cast<double>(map.at("UseMargin"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));
    res->FrozenCash = boost::lexical_cast<double>(map.at("FrozenCash"));
    res->FrozenCommission = boost::lexical_cast<double>(map.at("FrozenCommission"));
    res->CashIn = boost::lexical_cast<double>(map.at("CashIn"));
    res->Commission = boost::lexical_cast<double>(map.at("Commission"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->PositionProfit = boost::lexical_cast<double>(map.at("PositionProfit"));
    res->PreSettlementPrice = boost::lexical_cast<double>(map.at("PreSettlementPrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->OpenCost = boost::lexical_cast<double>(map.at("OpenCost"));
    res->ExchangeMargin = boost::lexical_cast<double>(map.at("ExchangeMargin"));
    res->CombPosition = boost::lexical_cast<int>(map.at("CombPosition"));
    res->CombLongFrozen = boost::lexical_cast<int>(map.at("CombLongFrozen"));
    res->CombShortFrozen = boost::lexical_cast<int>(map.at("CombShortFrozen"));
    res->CloseProfitByDate = boost::lexical_cast<double>(map.at("CloseProfitByDate"));
    res->CloseProfitByTrade = boost::lexical_cast<double>(map.at("CloseProfitByTrade"));
    res->TodayPosition = boost::lexical_cast<int>(map.at("TodayPosition"));
    res->MarginRateByMoney = boost::lexical_cast<double>(map.at("MarginRateByMoney"));
    res->MarginRateByVolume = boost::lexical_cast<double>(map.at("MarginRateByVolume"));
    res->StrikeFrozen = boost::lexical_cast<int>(map.at("StrikeFrozen"));
    res->StrikeFrozenAmount = boost::lexical_cast<double>(map.at("StrikeFrozenAmount"));
    res->AbandonFrozen = boost::lexical_cast<int>(map.at("AbandonFrozen"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentMarginRateField const &data);

template<>
class fromRedis<CThostFtdcInstrumentMarginRateField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentMarginRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentMarginRateField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->LongMarginRatioByMoney = boost::lexical_cast<double>(map.at("LongMarginRatioByMoney"));
    res->LongMarginRatioByVolume = boost::lexical_cast<double>(map.at("LongMarginRatioByVolume"));
    res->ShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ShortMarginRatioByMoney"));
    res->ShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ShortMarginRatioByVolume"));
    res->IsRelative = boost::lexical_cast<int>(map.at("IsRelative"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentCommissionRateField const &data);

template<>
class fromRedis<CThostFtdcInstrumentCommissionRateField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentCommissionRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentCommissionRateField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OpenRatioByMoney = boost::lexical_cast<double>(map.at("OpenRatioByMoney"));
    res->OpenRatioByVolume = boost::lexical_cast<double>(map.at("OpenRatioByVolume"));
    res->CloseRatioByMoney = boost::lexical_cast<double>(map.at("CloseRatioByMoney"));
    res->CloseRatioByVolume = boost::lexical_cast<double>(map.at("CloseRatioByVolume"));
    res->CloseTodayRatioByMoney = boost::lexical_cast<double>(map.at("CloseTodayRatioByMoney"));
    res->CloseTodayRatioByVolume = boost::lexical_cast<double>(map.at("CloseTodayRatioByVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDepthMarketDataField const &data);

template<>
class fromRedis<CThostFtdcDepthMarketDataField> {
 public:
  std::unique_ptr<CThostFtdcDepthMarketDataField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcDepthMarketDataField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    res->LastPrice = boost::lexical_cast<double>(map.at("LastPrice"));
    res->PreSettlementPrice = boost::lexical_cast<double>(map.at("PreSettlementPrice"));
    res->PreClosePrice = boost::lexical_cast<double>(map.at("PreClosePrice"));
    res->PreOpenInterest = boost::lexical_cast<double>(map.at("PreOpenInterest"));
    res->OpenPrice = boost::lexical_cast<double>(map.at("OpenPrice"));
    res->HighestPrice = boost::lexical_cast<double>(map.at("HighestPrice"));
    res->LowestPrice = boost::lexical_cast<double>(map.at("LowestPrice"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->Turnover = boost::lexical_cast<double>(map.at("Turnover"));
    res->OpenInterest = boost::lexical_cast<double>(map.at("OpenInterest"));
    res->ClosePrice = boost::lexical_cast<double>(map.at("ClosePrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    res->UpperLimitPrice = boost::lexical_cast<double>(map.at("UpperLimitPrice"));
    res->LowerLimitPrice = boost::lexical_cast<double>(map.at("LowerLimitPrice"));
    res->PreDelta = boost::lexical_cast<double>(map.at("PreDelta"));
    res->CurrDelta = boost::lexical_cast<double>(map.at("CurrDelta"));
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    res->UpdateMillisec = boost::lexical_cast<int>(map.at("UpdateMillisec"));
    res->BidPrice1 = boost::lexical_cast<double>(map.at("BidPrice1"));
    res->BidVolume1 = boost::lexical_cast<int>(map.at("BidVolume1"));
    res->AskPrice1 = boost::lexical_cast<double>(map.at("AskPrice1"));
    res->AskVolume1 = boost::lexical_cast<int>(map.at("AskVolume1"));
    res->BidPrice2 = boost::lexical_cast<double>(map.at("BidPrice2"));
    res->BidVolume2 = boost::lexical_cast<int>(map.at("BidVolume2"));
    res->AskPrice2 = boost::lexical_cast<double>(map.at("AskPrice2"));
    res->AskVolume2 = boost::lexical_cast<int>(map.at("AskVolume2"));
    res->BidPrice3 = boost::lexical_cast<double>(map.at("BidPrice3"));
    res->BidVolume3 = boost::lexical_cast<int>(map.at("BidVolume3"));
    res->AskPrice3 = boost::lexical_cast<double>(map.at("AskPrice3"));
    res->AskVolume3 = boost::lexical_cast<int>(map.at("AskVolume3"));
    res->BidPrice4 = boost::lexical_cast<double>(map.at("BidPrice4"));
    res->BidVolume4 = boost::lexical_cast<int>(map.at("BidVolume4"));
    res->AskPrice4 = boost::lexical_cast<double>(map.at("AskPrice4"));
    res->AskVolume4 = boost::lexical_cast<int>(map.at("AskVolume4"));
    res->BidPrice5 = boost::lexical_cast<double>(map.at("BidPrice5"));
    res->BidVolume5 = boost::lexical_cast<int>(map.at("BidVolume5"));
    res->AskPrice5 = boost::lexical_cast<double>(map.at("AskPrice5"));
    res->AskVolume5 = boost::lexical_cast<int>(map.at("AskVolume5"));
    res->AveragePrice = boost::lexical_cast<double>(map.at("AveragePrice"));
    strcpy(res->ActionDay, map.at("ActionDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentTradingRightField const &data);

template<>
class fromRedis<CThostFtdcInstrumentTradingRightField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentTradingRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentTradingRightField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->TradingRight = boost::lexical_cast<char>(map.at("TradingRight"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->UserName, map.at("UserName").data());
    res->UserType = boost::lexical_cast<char>(map.at("UserType"));
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));
    res->IsUsingOTP = boost::lexical_cast<int>(map.at("IsUsingOTP"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserPasswordField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserPasswordField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserPasswordField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserPasswordField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Password, map.at("Password").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserFunctionField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserFunctionField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserFunctionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserFunctionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->BrokerFunctionCode = boost::lexical_cast<char>(map.at("BrokerFunctionCode"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTraderOfferField const &data);

template<>
class fromRedis<CThostFtdcTraderOfferField> {
 public:
  std::unique_ptr<CThostFtdcTraderOfferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTraderOfferField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    res->TraderConnectStatus = boost::lexical_cast<char>(map.at("TraderConnectStatus"));
    strcpy(res->ConnectRequestDate, map.at("ConnectRequestDate").data());
    strcpy(res->ConnectRequestTime, map.at("ConnectRequestTime").data());
    strcpy(res->LastReportDate, map.at("LastReportDate").data());
    strcpy(res->LastReportTime, map.at("LastReportTime").data());
    strcpy(res->ConnectDate, map.at("ConnectDate").data());
    strcpy(res->ConnectTime, map.at("ConnectTime").data());
    strcpy(res->StartDate, map.at("StartDate").data());
    strcpy(res->StartTime, map.at("StartTime").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->MaxTradeID, map.at("MaxTradeID").data());
    strcpy(res->MaxOrderMessageReference, map.at("MaxOrderMessageReference").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementInfoField const &data);

template<>
class fromRedis<CThostFtdcSettlementInfoField> {
 public:
  std::unique_ptr<CThostFtdcSettlementInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSettlementInfoField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    strcpy(res->Content, map.at("Content").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentMarginRateAdjustField const &data);

template<>
class fromRedis<CThostFtdcInstrumentMarginRateAdjustField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentMarginRateAdjustField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentMarginRateAdjustField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->LongMarginRatioByMoney = boost::lexical_cast<double>(map.at("LongMarginRatioByMoney"));
    res->LongMarginRatioByVolume = boost::lexical_cast<double>(map.at("LongMarginRatioByVolume"));
    res->ShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ShortMarginRatioByMoney"));
    res->ShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ShortMarginRatioByVolume"));
    res->IsRelative = boost::lexical_cast<int>(map.at("IsRelative"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeMarginRateField const &data);

template<>
class fromRedis<CThostFtdcExchangeMarginRateField> {
 public:
  std::unique_ptr<CThostFtdcExchangeMarginRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeMarginRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->LongMarginRatioByMoney = boost::lexical_cast<double>(map.at("LongMarginRatioByMoney"));
    res->LongMarginRatioByVolume = boost::lexical_cast<double>(map.at("LongMarginRatioByVolume"));
    res->ShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ShortMarginRatioByMoney"));
    res->ShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ShortMarginRatioByVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeMarginRateAdjustField const &data);

template<>
class fromRedis<CThostFtdcExchangeMarginRateAdjustField> {
 public:
  std::unique_ptr<CThostFtdcExchangeMarginRateAdjustField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeMarginRateAdjustField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->LongMarginRatioByMoney = boost::lexical_cast<double>(map.at("LongMarginRatioByMoney"));
    res->LongMarginRatioByVolume = boost::lexical_cast<double>(map.at("LongMarginRatioByVolume"));
    res->ShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ShortMarginRatioByMoney"));
    res->ShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ShortMarginRatioByVolume"));
    res->ExchLongMarginRatioByMoney = boost::lexical_cast<double>(map.at("ExchLongMarginRatioByMoney"));
    res->ExchLongMarginRatioByVolume = boost::lexical_cast<double>(map.at("ExchLongMarginRatioByVolume"));
    res->ExchShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ExchShortMarginRatioByMoney"));
    res->ExchShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ExchShortMarginRatioByVolume"));
    res->NoLongMarginRatioByMoney = boost::lexical_cast<double>(map.at("NoLongMarginRatioByMoney"));
    res->NoLongMarginRatioByVolume = boost::lexical_cast<double>(map.at("NoLongMarginRatioByVolume"));
    res->NoShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("NoShortMarginRatioByMoney"));
    res->NoShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("NoShortMarginRatioByVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeRateField const &data);

template<>
class fromRedis<CThostFtdcExchangeRateField> {
 public:
  std::unique_ptr<CThostFtdcExchangeRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->FromCurrencyID, map.at("FromCurrencyID").data());
    res->FromCurrencyUnit = boost::lexical_cast<double>(map.at("FromCurrencyUnit"));
    strcpy(res->ToCurrencyID, map.at("ToCurrencyID").data());
    res->ExchangeRate = boost::lexical_cast<double>(map.at("ExchangeRate"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementRefField const &data);

template<>
class fromRedis<CThostFtdcSettlementRefField> {
 public:
  std::unique_ptr<CThostFtdcSettlementRefField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSettlementRefField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCurrentTimeField const &data);

template<>
class fromRedis<CThostFtdcCurrentTimeField> {
 public:
  std::unique_ptr<CThostFtdcCurrentTimeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCurrentTimeField>();

    strcpy(res->CurrDate, map.at("CurrDate").data());
    strcpy(res->CurrTime, map.at("CurrTime").data());
    res->CurrMillisec = boost::lexical_cast<int>(map.at("CurrMillisec"));
    strcpy(res->ActionDay, map.at("ActionDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCommPhaseField const &data);

template<>
class fromRedis<CThostFtdcCommPhaseField> {
 public:
  std::unique_ptr<CThostFtdcCommPhaseField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCommPhaseField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->CommPhaseNo = boost::lexical_cast<short>(map.at("CommPhaseNo"));
    strcpy(res->SystemID, map.at("SystemID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoginInfoField const &data);

template<>
class fromRedis<CThostFtdcLoginInfoField> {
 public:
  std::unique_ptr<CThostFtdcLoginInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcLoginInfoField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->LoginDate, map.at("LoginDate").data());
    strcpy(res->LoginTime, map.at("LoginTime").data());
    strcpy(res->IPAddress, map.at("IPAddress").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->InterfaceProductInfo, map.at("InterfaceProductInfo").data());
    strcpy(res->ProtocolInfo, map.at("ProtocolInfo").data());
    strcpy(res->SystemName, map.at("SystemName").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->MaxOrderRef, map.at("MaxOrderRef").data());
    strcpy(res->SHFETime, map.at("SHFETime").data());
    strcpy(res->DCETime, map.at("DCETime").data());
    strcpy(res->CZCETime, map.at("CZCETime").data());
    strcpy(res->FFEXTime, map.at("FFEXTime").data());
    strcpy(res->MacAddress, map.at("MacAddress").data());
    strcpy(res->OneTimePassword, map.at("OneTimePassword").data());
    strcpy(res->INETime, map.at("INETime").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLogoutAllField const &data);

template<>
class fromRedis<CThostFtdcLogoutAllField> {
 public:
  std::unique_ptr<CThostFtdcLogoutAllField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcLogoutAllField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->SystemName, map.at("SystemName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFrontStatusField const &data);

template<>
class fromRedis<CThostFtdcFrontStatusField> {
 public:
  std::unique_ptr<CThostFtdcFrontStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcFrontStatusField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    strcpy(res->LastReportDate, map.at("LastReportDate").data());
    strcpy(res->LastReportTime, map.at("LastReportTime").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserPasswordUpdateField const &data);

template<>
class fromRedis<CThostFtdcUserPasswordUpdateField> {
 public:
  std::unique_ptr<CThostFtdcUserPasswordUpdateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserPasswordUpdateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->OldPassword, map.at("OldPassword").data());
    strcpy(res->NewPassword, map.at("NewPassword").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputOrderField const &data);

template<>
class fromRedis<CThostFtdcInputOrderField> {
 public:
  std::unique_ptr<CThostFtdcInputOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->UserForceClose = boost::lexical_cast<int>(map.at("UserForceClose"));
    res->IsSwapOrder = boost::lexical_cast<int>(map.at("IsSwapOrder"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOrderField const &data);

template<>
class fromRedis<CThostFtdcOrderField> {
 public:
  std::unique_ptr<CThostFtdcOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->OrderSource = boost::lexical_cast<char>(map.at("OrderSource"));
    res->OrderStatus = boost::lexical_cast<char>(map.at("OrderStatus"));
    res->OrderType = boost::lexical_cast<char>(map.at("OrderType"));
    res->VolumeTraded = boost::lexical_cast<int>(map.at("VolumeTraded"));
    res->VolumeTotal = boost::lexical_cast<int>(map.at("VolumeTotal"));
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->ActiveTime, map.at("ActiveTime").data());
    strcpy(res->SuspendTime, map.at("SuspendTime").data());
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    strcpy(res->ActiveTraderID, map.at("ActiveTraderID").data());
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    res->UserForceClose = boost::lexical_cast<int>(map.at("UserForceClose"));
    strcpy(res->ActiveUserID, map.at("ActiveUserID").data());
    res->BrokerOrderSeq = boost::lexical_cast<int>(map.at("BrokerOrderSeq"));
    strcpy(res->RelativeOrderSysID, map.at("RelativeOrderSysID").data());
    res->ZCETotalTradedVolume = boost::lexical_cast<int>(map.at("ZCETotalTradedVolume"));
    res->IsSwapOrder = boost::lexical_cast<int>(map.at("IsSwapOrder"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderField const &data);

template<>
class fromRedis<CThostFtdcExchangeOrderField> {
 public:
  std::unique_ptr<CThostFtdcExchangeOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeOrderField>();

    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->OrderSource = boost::lexical_cast<char>(map.at("OrderSource"));
    res->OrderStatus = boost::lexical_cast<char>(map.at("OrderStatus"));
    res->OrderType = boost::lexical_cast<char>(map.at("OrderType"));
    res->VolumeTraded = boost::lexical_cast<int>(map.at("VolumeTraded"));
    res->VolumeTotal = boost::lexical_cast<int>(map.at("VolumeTotal"));
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->ActiveTime, map.at("ActiveTime").data());
    strcpy(res->SuspendTime, map.at("SuspendTime").data());
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    strcpy(res->ActiveTraderID, map.at("ActiveTraderID").data());
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderInsertErrorField const &data);

template<>
class fromRedis<CThostFtdcExchangeOrderInsertErrorField> {
 public:
  std::unique_ptr<CThostFtdcExchangeOrderInsertErrorField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeOrderInsertErrorField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputOrderActionField const &data);

template<>
class fromRedis<CThostFtdcInputOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcInputOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OrderActionRef = boost::lexical_cast<int>(map.at("OrderActionRef"));
    strcpy(res->OrderRef, map.at("OrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeChange = boost::lexical_cast<int>(map.at("VolumeChange"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOrderActionField const &data);

template<>
class fromRedis<CThostFtdcOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OrderActionRef = boost::lexical_cast<int>(map.at("OrderActionRef"));
    strcpy(res->OrderRef, map.at("OrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeChange = boost::lexical_cast<int>(map.at("VolumeChange"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderActionField const &data);

template<>
class fromRedis<CThostFtdcExchangeOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcExchangeOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeOrderActionField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeChange = boost::lexical_cast<int>(map.at("VolumeChange"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderActionErrorField const &data);

template<>
class fromRedis<CThostFtdcExchangeOrderActionErrorField> {
 public:
  std::unique_ptr<CThostFtdcExchangeOrderActionErrorField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeOrderActionErrorField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeTradeField const &data);

template<>
class fromRedis<CThostFtdcExchangeTradeField> {
 public:
  std::unique_ptr<CThostFtdcExchangeTradeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeTradeField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TradeID, map.at("TradeID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    res->TradingRole = boost::lexical_cast<char>(map.at("TradingRole"));
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->Price = boost::lexical_cast<double>(map.at("Price"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    res->TradeType = boost::lexical_cast<char>(map.at("TradeType"));
    res->PriceSource = boost::lexical_cast<char>(map.at("PriceSource"));
    strcpy(res->TraderID, map.at("TraderID").data());
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->TradeSource = boost::lexical_cast<char>(map.at("TradeSource"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradeField const &data);

template<>
class fromRedis<CThostFtdcTradeField> {
 public:
  std::unique_ptr<CThostFtdcTradeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TradeID, map.at("TradeID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    res->TradingRole = boost::lexical_cast<char>(map.at("TradingRole"));
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->Price = boost::lexical_cast<double>(map.at("Price"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    res->TradeType = boost::lexical_cast<char>(map.at("TradeType"));
    res->PriceSource = boost::lexical_cast<char>(map.at("PriceSource"));
    strcpy(res->TraderID, map.at("TraderID").data());
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->BrokerOrderSeq = boost::lexical_cast<int>(map.at("BrokerOrderSeq"));
    res->TradeSource = boost::lexical_cast<char>(map.at("TradeSource"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserSessionField const &data);

template<>
class fromRedis<CThostFtdcUserSessionField> {
 public:
  std::unique_ptr<CThostFtdcUserSessionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserSessionField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->LoginDate, map.at("LoginDate").data());
    strcpy(res->LoginTime, map.at("LoginTime").data());
    strcpy(res->IPAddress, map.at("IPAddress").data());
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->InterfaceProductInfo, map.at("InterfaceProductInfo").data());
    strcpy(res->ProtocolInfo, map.at("ProtocolInfo").data());
    strcpy(res->MacAddress, map.at("MacAddress").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryMaxOrderVolumeField const &data);

template<>
class fromRedis<CThostFtdcQueryMaxOrderVolumeField> {
 public:
  std::unique_ptr<CThostFtdcQueryMaxOrderVolumeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQueryMaxOrderVolumeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->MaxVolume = boost::lexical_cast<int>(map.at("MaxVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementInfoConfirmField const &data);

template<>
class fromRedis<CThostFtdcSettlementInfoConfirmField> {
 public:
  std::unique_ptr<CThostFtdcSettlementInfoConfirmField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSettlementInfoConfirmField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ConfirmDate, map.at("ConfirmDate").data());
    strcpy(res->ConfirmTime, map.at("ConfirmTime").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncDepositField const &data);

template<>
class fromRedis<CThostFtdcSyncDepositField> {
 public:
  std::unique_ptr<CThostFtdcSyncDepositField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncDepositField>();

    strcpy(res->DepositSeqNo, map.at("DepositSeqNo").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Deposit = boost::lexical_cast<double>(map.at("Deposit"));
    res->IsForce = boost::lexical_cast<int>(map.at("IsForce"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncFundMortgageField const &data);

template<>
class fromRedis<CThostFtdcSyncFundMortgageField> {
 public:
  std::unique_ptr<CThostFtdcSyncFundMortgageField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncFundMortgageField>();

    strcpy(res->MortgageSeqNo, map.at("MortgageSeqNo").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->FromCurrencyID, map.at("FromCurrencyID").data());
    res->MortgageAmount = boost::lexical_cast<double>(map.at("MortgageAmount"));
    strcpy(res->ToCurrencyID, map.at("ToCurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerSyncField const &data);

template<>
class fromRedis<CThostFtdcBrokerSyncField> {
 public:
  std::unique_ptr<CThostFtdcBrokerSyncField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerSyncField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorField const &data);

template<>
class fromRedis<CThostFtdcSyncingInvestorField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInvestorField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInvestorField>();

    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorGroupID, map.at("InvestorGroupID").data());
    strcpy(res->InvestorName, map.at("InvestorName").data());
    res->IdentifiedCardType = boost::lexical_cast<char>(map.at("IdentifiedCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->OpenDate, map.at("OpenDate").data());
    strcpy(res->Mobile, map.at("Mobile").data());
    strcpy(res->CommModelID, map.at("CommModelID").data());
    strcpy(res->MarginModelID, map.at("MarginModelID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingTradingCodeField const &data);

template<>
class fromRedis<CThostFtdcSyncingTradingCodeField> {
 public:
  std::unique_ptr<CThostFtdcSyncingTradingCodeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingTradingCodeField>();

    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));
    res->ClientIDType = boost::lexical_cast<char>(map.at("ClientIDType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorGroupField const &data);

template<>
class fromRedis<CThostFtdcSyncingInvestorGroupField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInvestorGroupField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInvestorGroupField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorGroupID, map.at("InvestorGroupID").data());
    strcpy(res->InvestorGroupName, map.at("InvestorGroupName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingTradingAccountField const &data);

template<>
class fromRedis<CThostFtdcSyncingTradingAccountField> {
 public:
  std::unique_ptr<CThostFtdcSyncingTradingAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingTradingAccountField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->PreMortgage = boost::lexical_cast<double>(map.at("PreMortgage"));
    res->PreCredit = boost::lexical_cast<double>(map.at("PreCredit"));
    res->PreDeposit = boost::lexical_cast<double>(map.at("PreDeposit"));
    res->PreBalance = boost::lexical_cast<double>(map.at("PreBalance"));
    res->PreMargin = boost::lexical_cast<double>(map.at("PreMargin"));
    res->InterestBase = boost::lexical_cast<double>(map.at("InterestBase"));
    res->Interest = boost::lexical_cast<double>(map.at("Interest"));
    res->Deposit = boost::lexical_cast<double>(map.at("Deposit"));
    res->Withdraw = boost::lexical_cast<double>(map.at("Withdraw"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));
    res->FrozenCash = boost::lexical_cast<double>(map.at("FrozenCash"));
    res->FrozenCommission = boost::lexical_cast<double>(map.at("FrozenCommission"));
    res->CurrMargin = boost::lexical_cast<double>(map.at("CurrMargin"));
    res->CashIn = boost::lexical_cast<double>(map.at("CashIn"));
    res->Commission = boost::lexical_cast<double>(map.at("Commission"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->PositionProfit = boost::lexical_cast<double>(map.at("PositionProfit"));
    res->Balance = boost::lexical_cast<double>(map.at("Balance"));
    res->Available = boost::lexical_cast<double>(map.at("Available"));
    res->WithdrawQuota = boost::lexical_cast<double>(map.at("WithdrawQuota"));
    res->Reserve = boost::lexical_cast<double>(map.at("Reserve"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->Credit = boost::lexical_cast<double>(map.at("Credit"));
    res->Mortgage = boost::lexical_cast<double>(map.at("Mortgage"));
    res->ExchangeMargin = boost::lexical_cast<double>(map.at("ExchangeMargin"));
    res->DeliveryMargin = boost::lexical_cast<double>(map.at("DeliveryMargin"));
    res->ExchangeDeliveryMargin = boost::lexical_cast<double>(map.at("ExchangeDeliveryMargin"));
    res->ReserveBalance = boost::lexical_cast<double>(map.at("ReserveBalance"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->PreFundMortgageIn = boost::lexical_cast<double>(map.at("PreFundMortgageIn"));
    res->PreFundMortgageOut = boost::lexical_cast<double>(map.at("PreFundMortgageOut"));
    res->FundMortgageIn = boost::lexical_cast<double>(map.at("FundMortgageIn"));
    res->FundMortgageOut = boost::lexical_cast<double>(map.at("FundMortgageOut"));
    res->FundMortgageAvailable = boost::lexical_cast<double>(map.at("FundMortgageAvailable"));
    res->MortgageableFund = boost::lexical_cast<double>(map.at("MortgageableFund"));
    res->SpecProductMargin = boost::lexical_cast<double>(map.at("SpecProductMargin"));
    res->SpecProductFrozenMargin = boost::lexical_cast<double>(map.at("SpecProductFrozenMargin"));
    res->SpecProductCommission = boost::lexical_cast<double>(map.at("SpecProductCommission"));
    res->SpecProductFrozenCommission = boost::lexical_cast<double>(map.at("SpecProductFrozenCommission"));
    res->SpecProductPositionProfit = boost::lexical_cast<double>(map.at("SpecProductPositionProfit"));
    res->SpecProductCloseProfit = boost::lexical_cast<double>(map.at("SpecProductCloseProfit"));
    res->SpecProductPositionProfitByAlg = boost::lexical_cast<double>(map.at("SpecProductPositionProfitByAlg"));
    res->SpecProductExchangeMargin = boost::lexical_cast<double>(map.at("SpecProductExchangeMargin"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorPositionField const &data);

template<>
class fromRedis<CThostFtdcSyncingInvestorPositionField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInvestorPositionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInvestorPositionField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->PositionDate = boost::lexical_cast<char>(map.at("PositionDate"));
    res->YdPosition = boost::lexical_cast<int>(map.at("YdPosition"));
    res->Position = boost::lexical_cast<int>(map.at("Position"));
    res->LongFrozen = boost::lexical_cast<int>(map.at("LongFrozen"));
    res->ShortFrozen = boost::lexical_cast<int>(map.at("ShortFrozen"));
    res->LongFrozenAmount = boost::lexical_cast<double>(map.at("LongFrozenAmount"));
    res->ShortFrozenAmount = boost::lexical_cast<double>(map.at("ShortFrozenAmount"));
    res->OpenVolume = boost::lexical_cast<int>(map.at("OpenVolume"));
    res->CloseVolume = boost::lexical_cast<int>(map.at("CloseVolume"));
    res->OpenAmount = boost::lexical_cast<double>(map.at("OpenAmount"));
    res->CloseAmount = boost::lexical_cast<double>(map.at("CloseAmount"));
    res->PositionCost = boost::lexical_cast<double>(map.at("PositionCost"));
    res->PreMargin = boost::lexical_cast<double>(map.at("PreMargin"));
    res->UseMargin = boost::lexical_cast<double>(map.at("UseMargin"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));
    res->FrozenCash = boost::lexical_cast<double>(map.at("FrozenCash"));
    res->FrozenCommission = boost::lexical_cast<double>(map.at("FrozenCommission"));
    res->CashIn = boost::lexical_cast<double>(map.at("CashIn"));
    res->Commission = boost::lexical_cast<double>(map.at("Commission"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->PositionProfit = boost::lexical_cast<double>(map.at("PositionProfit"));
    res->PreSettlementPrice = boost::lexical_cast<double>(map.at("PreSettlementPrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->OpenCost = boost::lexical_cast<double>(map.at("OpenCost"));
    res->ExchangeMargin = boost::lexical_cast<double>(map.at("ExchangeMargin"));
    res->CombPosition = boost::lexical_cast<int>(map.at("CombPosition"));
    res->CombLongFrozen = boost::lexical_cast<int>(map.at("CombLongFrozen"));
    res->CombShortFrozen = boost::lexical_cast<int>(map.at("CombShortFrozen"));
    res->CloseProfitByDate = boost::lexical_cast<double>(map.at("CloseProfitByDate"));
    res->CloseProfitByTrade = boost::lexical_cast<double>(map.at("CloseProfitByTrade"));
    res->TodayPosition = boost::lexical_cast<int>(map.at("TodayPosition"));
    res->MarginRateByMoney = boost::lexical_cast<double>(map.at("MarginRateByMoney"));
    res->MarginRateByVolume = boost::lexical_cast<double>(map.at("MarginRateByVolume"));
    res->StrikeFrozen = boost::lexical_cast<int>(map.at("StrikeFrozen"));
    res->StrikeFrozenAmount = boost::lexical_cast<double>(map.at("StrikeFrozenAmount"));
    res->AbandonFrozen = boost::lexical_cast<int>(map.at("AbandonFrozen"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentMarginRateField const &data);

template<>
class fromRedis<CThostFtdcSyncingInstrumentMarginRateField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInstrumentMarginRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInstrumentMarginRateField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->LongMarginRatioByMoney = boost::lexical_cast<double>(map.at("LongMarginRatioByMoney"));
    res->LongMarginRatioByVolume = boost::lexical_cast<double>(map.at("LongMarginRatioByVolume"));
    res->ShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("ShortMarginRatioByMoney"));
    res->ShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("ShortMarginRatioByVolume"));
    res->IsRelative = boost::lexical_cast<int>(map.at("IsRelative"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentCommissionRateField const &data);

template<>
class fromRedis<CThostFtdcSyncingInstrumentCommissionRateField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInstrumentCommissionRateField> operator()(redis::Redis &cli,
                                                                             std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInstrumentCommissionRateField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OpenRatioByMoney = boost::lexical_cast<double>(map.at("OpenRatioByMoney"));
    res->OpenRatioByVolume = boost::lexical_cast<double>(map.at("OpenRatioByVolume"));
    res->CloseRatioByMoney = boost::lexical_cast<double>(map.at("CloseRatioByMoney"));
    res->CloseRatioByVolume = boost::lexical_cast<double>(map.at("CloseRatioByVolume"));
    res->CloseTodayRatioByMoney = boost::lexical_cast<double>(map.at("CloseTodayRatioByMoney"));
    res->CloseTodayRatioByVolume = boost::lexical_cast<double>(map.at("CloseTodayRatioByVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentTradingRightField const &data);

template<>
class fromRedis<CThostFtdcSyncingInstrumentTradingRightField> {
 public:
  std::unique_ptr<CThostFtdcSyncingInstrumentTradingRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncingInstrumentTradingRightField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->TradingRight = boost::lexical_cast<char>(map.at("TradingRight"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOrderField const &data);

template<>
class fromRedis<CThostFtdcQryOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    strcpy(res->InsertTimeStart, map.at("InsertTimeStart").data());
    strcpy(res->InsertTimeEnd, map.at("InsertTimeEnd").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradeField const &data);

template<>
class fromRedis<CThostFtdcQryTradeField> {
 public:
  std::unique_ptr<CThostFtdcQryTradeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTradeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TradeID, map.at("TradeID").data());
    strcpy(res->TradeTimeStart, map.at("TradeTimeStart").data());
    strcpy(res->TradeTimeEnd, map.at("TradeTimeEnd").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorPositionField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorPositionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorPositionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingAccountField const &data);

template<>
class fromRedis<CThostFtdcQryTradingAccountField> {
 public:
  std::unique_ptr<CThostFtdcQryTradingAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTradingAccountField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingCodeField const &data);

template<>
class fromRedis<CThostFtdcQryTradingCodeField> {
 public:
  std::unique_ptr<CThostFtdcQryTradingCodeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTradingCodeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    res->ClientIDType = boost::lexical_cast<char>(map.at("ClientIDType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorGroupField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorGroupField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorGroupField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorGroupField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentMarginRateField const &data);

template<>
class fromRedis<CThostFtdcQryInstrumentMarginRateField> {
 public:
  std::unique_ptr<CThostFtdcQryInstrumentMarginRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInstrumentMarginRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentCommissionRateField const &data);

template<>
class fromRedis<CThostFtdcQryInstrumentCommissionRateField> {
 public:
  std::unique_ptr<CThostFtdcQryInstrumentCommissionRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInstrumentCommissionRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentTradingRightField const &data);

template<>
class fromRedis<CThostFtdcQryInstrumentTradingRightField> {
 public:
  std::unique_ptr<CThostFtdcQryInstrumentTradingRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInstrumentTradingRightField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTraderField const &data);

template<>
class fromRedis<CThostFtdcQryTraderField> {
 public:
  std::unique_ptr<CThostFtdcQryTraderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTraderField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySuperUserFunctionField const &data);

template<>
class fromRedis<CThostFtdcQrySuperUserFunctionField> {
 public:
  std::unique_ptr<CThostFtdcQrySuperUserFunctionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySuperUserFunctionField>();

    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryUserSessionField const &data);

template<>
class fromRedis<CThostFtdcQryUserSessionField> {
 public:
  std::unique_ptr<CThostFtdcQryUserSessionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryUserSessionField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryPartBrokerField const &data);

template<>
class fromRedis<CThostFtdcQryPartBrokerField> {
 public:
  std::unique_ptr<CThostFtdcQryPartBrokerField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryPartBrokerField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryFrontStatusField const &data);

template<>
class fromRedis<CThostFtdcQryFrontStatusField> {
 public:
  std::unique_ptr<CThostFtdcQryFrontStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryFrontStatusField>();

    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeOrderField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeOrderField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeOrderActionField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySuperUserField const &data);

template<>
class fromRedis<CThostFtdcQrySuperUserField> {
 public:
  std::unique_ptr<CThostFtdcQrySuperUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySuperUserField>();

    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryProductField const &data);

template<>
class fromRedis<CThostFtdcQryProductField> {
 public:
  std::unique_ptr<CThostFtdcQryProductField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryProductField>();

    strcpy(res->ProductID, map.at("ProductID").data());
    res->ProductClass = boost::lexical_cast<char>(map.at("ProductClass"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentField const &data);

template<>
class fromRedis<CThostFtdcQryInstrumentField> {
 public:
  std::unique_ptr<CThostFtdcQryInstrumentField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInstrumentField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ProductID, map.at("ProductID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryDepthMarketDataField const &data);

template<>
class fromRedis<CThostFtdcQryDepthMarketDataField> {
 public:
  std::unique_ptr<CThostFtdcQryDepthMarketDataField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryDepthMarketDataField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerUserField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerUserField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserFunctionField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerUserFunctionField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerUserFunctionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerUserFunctionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTraderOfferField const &data);

template<>
class fromRedis<CThostFtdcQryTraderOfferField> {
 public:
  std::unique_ptr<CThostFtdcQryTraderOfferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTraderOfferField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncDepositField const &data);

template<>
class fromRedis<CThostFtdcQrySyncDepositField> {
 public:
  std::unique_ptr<CThostFtdcQrySyncDepositField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySyncDepositField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->DepositSeqNo, map.at("DepositSeqNo").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySettlementInfoField const &data);

template<>
class fromRedis<CThostFtdcQrySettlementInfoField> {
 public:
  std::unique_ptr<CThostFtdcQrySettlementInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySettlementInfoField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeMarginRateField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeMarginRateField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeMarginRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeMarginRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeMarginRateAdjustField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeMarginRateAdjustField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeMarginRateAdjustField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeMarginRateAdjustField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeRateField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeRateField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->FromCurrencyID, map.at("FromCurrencyID").data());
    strcpy(res->ToCurrencyID, map.at("ToCurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncFundMortgageField const &data);

template<>
class fromRedis<CThostFtdcQrySyncFundMortgageField> {
 public:
  std::unique_ptr<CThostFtdcQrySyncFundMortgageField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySyncFundMortgageField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->MortgageSeqNo, map.at("MortgageSeqNo").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryHisOrderField const &data);

template<>
class fromRedis<CThostFtdcQryHisOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryHisOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryHisOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    strcpy(res->InsertTimeStart, map.at("InsertTimeStart").data());
    strcpy(res->InsertTimeEnd, map.at("InsertTimeEnd").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrMiniMarginField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrMiniMarginField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrMiniMarginField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrMiniMarginField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->MinMargin = boost::lexical_cast<double>(map.at("MinMargin"));
    res->ValueMethod = boost::lexical_cast<char>(map.at("ValueMethod"));
    res->IsRelative = boost::lexical_cast<int>(map.at("IsRelative"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrMarginAdjustField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrMarginAdjustField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrMarginAdjustField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrMarginAdjustField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->SShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("SShortMarginRatioByMoney"));
    res->SShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("SShortMarginRatioByVolume"));
    res->HShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("HShortMarginRatioByMoney"));
    res->HShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("HShortMarginRatioByVolume"));
    res->AShortMarginRatioByMoney = boost::lexical_cast<double>(map.at("AShortMarginRatioByMoney"));
    res->AShortMarginRatioByVolume = boost::lexical_cast<double>(map.at("AShortMarginRatioByVolume"));
    res->IsRelative = boost::lexical_cast<int>(map.at("IsRelative"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrCommRateField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrCommRateField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrCommRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrCommRateField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OpenRatioByMoney = boost::lexical_cast<double>(map.at("OpenRatioByMoney"));
    res->OpenRatioByVolume = boost::lexical_cast<double>(map.at("OpenRatioByVolume"));
    res->CloseRatioByMoney = boost::lexical_cast<double>(map.at("CloseRatioByMoney"));
    res->CloseRatioByVolume = boost::lexical_cast<double>(map.at("CloseRatioByVolume"));
    res->CloseTodayRatioByMoney = boost::lexical_cast<double>(map.at("CloseTodayRatioByMoney"));
    res->CloseTodayRatioByVolume = boost::lexical_cast<double>(map.at("CloseTodayRatioByVolume"));
    res->StrikeRatioByMoney = boost::lexical_cast<double>(map.at("StrikeRatioByMoney"));
    res->StrikeRatioByVolume = boost::lexical_cast<double>(map.at("StrikeRatioByVolume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrTradeCostField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrTradeCostField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrTradeCostField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrTradeCostField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->FixedMargin = boost::lexical_cast<double>(map.at("FixedMargin"));
    res->MiniMargin = boost::lexical_cast<double>(map.at("MiniMargin"));
    res->Royalty = boost::lexical_cast<double>(map.at("Royalty"));
    res->ExchFixedMargin = boost::lexical_cast<double>(map.at("ExchFixedMargin"));
    res->ExchMiniMargin = boost::lexical_cast<double>(map.at("ExchMiniMargin"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrTradeCostField const &data);

template<>
class fromRedis<CThostFtdcQryOptionInstrTradeCostField> {
 public:
  std::unique_ptr<CThostFtdcQryOptionInstrTradeCostField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryOptionInstrTradeCostField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->InputPrice = boost::lexical_cast<double>(map.at("InputPrice"));
    res->UnderlyingPrice = boost::lexical_cast<double>(map.at("UnderlyingPrice"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrCommRateField const &data);

template<>
class fromRedis<CThostFtdcQryOptionInstrCommRateField> {
 public:
  std::unique_ptr<CThostFtdcQryOptionInstrCommRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryOptionInstrCommRateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcIndexPriceField const &data);

template<>
class fromRedis<CThostFtdcIndexPriceField> {
 public:
  std::unique_ptr<CThostFtdcIndexPriceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcIndexPriceField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->ClosePrice = boost::lexical_cast<double>(map.at("ClosePrice"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputExecOrderField const &data);

template<>
class fromRedis<CThostFtdcInputExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcInputExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputExecOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->ReservePositionFlag = boost::lexical_cast<char>(map.at("ReservePositionFlag"));
    res->CloseFlag = boost::lexical_cast<char>(map.at("CloseFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcInputExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcInputExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputExecOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->ExecOrderActionRef = boost::lexical_cast<int>(map.at("ExecOrderActionRef"));
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExecOrderField const &data);

template<>
class fromRedis<CThostFtdcExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExecOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->ReservePositionFlag = boost::lexical_cast<char>(map.at("ReservePositionFlag"));
    res->CloseFlag = boost::lexical_cast<char>(map.at("CloseFlag"));
    strcpy(res->ExecOrderLocalID, map.at("ExecOrderLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    res->ExecResult = boost::lexical_cast<char>(map.at("ExecResult"));
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->ActiveUserID, map.at("ActiveUserID").data());
    res->BrokerExecOrderSeq = boost::lexical_cast<int>(map.at("BrokerExecOrderSeq"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExecOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->ExecOrderActionRef = boost::lexical_cast<int>(map.at("ExecOrderActionRef"));
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->ExecOrderLocalID, map.at("ExecOrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExecOrderField const &data);

template<>
class fromRedis<CThostFtdcQryExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExecOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    strcpy(res->InsertTimeStart, map.at("InsertTimeStart").data());
    strcpy(res->InsertTimeEnd, map.at("InsertTimeEnd").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeExecOrderField const &data);

template<>
class fromRedis<CThostFtdcExchangeExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcExchangeExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeExecOrderField>();

    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->ReservePositionFlag = boost::lexical_cast<char>(map.at("ReservePositionFlag"));
    res->CloseFlag = boost::lexical_cast<char>(map.at("CloseFlag"));
    strcpy(res->ExecOrderLocalID, map.at("ExecOrderLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    res->ExecResult = boost::lexical_cast<char>(map.at("ExecResult"));
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeExecOrderField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeExecOrderField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExecOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcExchangeExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcExchangeExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeExecOrderActionField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->ExecOrderLocalID, map.at("ExecOrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeExecOrderActionField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrExecOrderField const &data);

template<>
class fromRedis<CThostFtdcErrExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcErrExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcErrExecOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->ActionType = boost::lexical_cast<char>(map.at("ActionType"));
    res->PosiDirection = boost::lexical_cast<char>(map.at("PosiDirection"));
    res->ReservePositionFlag = boost::lexical_cast<char>(map.at("ReservePositionFlag"));
    res->CloseFlag = boost::lexical_cast<char>(map.at("CloseFlag"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrExecOrderField const &data);

template<>
class fromRedis<CThostFtdcQryErrExecOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryErrExecOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryErrExecOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcErrExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcErrExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcErrExecOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->ExecOrderActionRef = boost::lexical_cast<int>(map.at("ExecOrderActionRef"));
    strcpy(res->ExecOrderRef, map.at("ExecOrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExecOrderSysID, map.at("ExecOrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrExecOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryErrExecOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryErrExecOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryErrExecOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrTradingRightField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrTradingRightField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrTradingRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrTradingRightField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->TradingRight = boost::lexical_cast<char>(map.at("TradingRight"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrTradingRightField const &data);

template<>
class fromRedis<CThostFtdcQryOptionInstrTradingRightField> {
 public:
  std::unique_ptr<CThostFtdcQryOptionInstrTradingRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryOptionInstrTradingRightField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputForQuoteField const &data);

template<>
class fromRedis<CThostFtdcInputForQuoteField> {
 public:
  std::unique_ptr<CThostFtdcInputForQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputForQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ForQuoteRef, map.at("ForQuoteRef").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForQuoteField const &data);

template<>
class fromRedis<CThostFtdcForQuoteField> {
 public:
  std::unique_ptr<CThostFtdcForQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcForQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ForQuoteRef, map.at("ForQuoteRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->ForQuoteLocalID, map.at("ForQuoteLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    res->ForQuoteStatus = boost::lexical_cast<char>(map.at("ForQuoteStatus"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->ActiveUserID, map.at("ActiveUserID").data());
    res->BrokerForQutoSeq = boost::lexical_cast<int>(map.at("BrokerForQutoSeq"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryForQuoteField const &data);

template<>
class fromRedis<CThostFtdcQryForQuoteField> {
 public:
  std::unique_ptr<CThostFtdcQryForQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryForQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InsertTimeStart, map.at("InsertTimeStart").data());
    strcpy(res->InsertTimeEnd, map.at("InsertTimeEnd").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeForQuoteField const &data);

template<>
class fromRedis<CThostFtdcExchangeForQuoteField> {
 public:
  std::unique_ptr<CThostFtdcExchangeForQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeForQuoteField>();

    strcpy(res->ForQuoteLocalID, map.at("ForQuoteLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    res->ForQuoteStatus = boost::lexical_cast<char>(map.at("ForQuoteStatus"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeForQuoteField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeForQuoteField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeForQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeForQuoteField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputQuoteField const &data);

template<>
class fromRedis<CThostFtdcInputQuoteField> {
 public:
  std::unique_ptr<CThostFtdcInputQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->QuoteRef, map.at("QuoteRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->AskPrice = boost::lexical_cast<double>(map.at("AskPrice"));
    res->BidPrice = boost::lexical_cast<double>(map.at("BidPrice"));
    res->AskVolume = boost::lexical_cast<int>(map.at("AskVolume"));
    res->BidVolume = boost::lexical_cast<int>(map.at("BidVolume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->AskOffsetFlag = boost::lexical_cast<char>(map.at("AskOffsetFlag"));
    res->BidOffsetFlag = boost::lexical_cast<char>(map.at("BidOffsetFlag"));
    res->AskHedgeFlag = boost::lexical_cast<char>(map.at("AskHedgeFlag"));
    res->BidHedgeFlag = boost::lexical_cast<char>(map.at("BidHedgeFlag"));
    strcpy(res->AskOrderRef, map.at("AskOrderRef").data());
    strcpy(res->BidOrderRef, map.at("BidOrderRef").data());
    strcpy(res->ForQuoteSysID, map.at("ForQuoteSysID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputQuoteActionField const &data);

template<>
class fromRedis<CThostFtdcInputQuoteActionField> {
 public:
  std::unique_ptr<CThostFtdcInputQuoteActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputQuoteActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->QuoteActionRef = boost::lexical_cast<int>(map.at("QuoteActionRef"));
    strcpy(res->QuoteRef, map.at("QuoteRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQuoteField const &data);

template<>
class fromRedis<CThostFtdcQuoteField> {
 public:
  std::unique_ptr<CThostFtdcQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->QuoteRef, map.at("QuoteRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->AskPrice = boost::lexical_cast<double>(map.at("AskPrice"));
    res->BidPrice = boost::lexical_cast<double>(map.at("BidPrice"));
    res->AskVolume = boost::lexical_cast<int>(map.at("AskVolume"));
    res->BidVolume = boost::lexical_cast<int>(map.at("BidVolume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->AskOffsetFlag = boost::lexical_cast<char>(map.at("AskOffsetFlag"));
    res->BidOffsetFlag = boost::lexical_cast<char>(map.at("BidOffsetFlag"));
    res->AskHedgeFlag = boost::lexical_cast<char>(map.at("AskHedgeFlag"));
    res->BidHedgeFlag = boost::lexical_cast<char>(map.at("BidHedgeFlag"));
    strcpy(res->QuoteLocalID, map.at("QuoteLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    res->QuoteStatus = boost::lexical_cast<char>(map.at("QuoteStatus"));
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    strcpy(res->AskOrderSysID, map.at("AskOrderSysID").data());
    strcpy(res->BidOrderSysID, map.at("BidOrderSysID").data());
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->ActiveUserID, map.at("ActiveUserID").data());
    res->BrokerQuoteSeq = boost::lexical_cast<int>(map.at("BrokerQuoteSeq"));
    strcpy(res->AskOrderRef, map.at("AskOrderRef").data());
    strcpy(res->BidOrderRef, map.at("BidOrderRef").data());
    strcpy(res->ForQuoteSysID, map.at("ForQuoteSysID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQuoteActionField const &data);

template<>
class fromRedis<CThostFtdcQuoteActionField> {
 public:
  std::unique_ptr<CThostFtdcQuoteActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQuoteActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->QuoteActionRef = boost::lexical_cast<int>(map.at("QuoteActionRef"));
    strcpy(res->QuoteRef, map.at("QuoteRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->QuoteLocalID, map.at("QuoteLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryQuoteField const &data);

template<>
class fromRedis<CThostFtdcQryQuoteField> {
 public:
  std::unique_ptr<CThostFtdcQryQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryQuoteField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    strcpy(res->InsertTimeStart, map.at("InsertTimeStart").data());
    strcpy(res->InsertTimeEnd, map.at("InsertTimeEnd").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeQuoteField const &data);

template<>
class fromRedis<CThostFtdcExchangeQuoteField> {
 public:
  std::unique_ptr<CThostFtdcExchangeQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeQuoteField>();

    res->AskPrice = boost::lexical_cast<double>(map.at("AskPrice"));
    res->BidPrice = boost::lexical_cast<double>(map.at("BidPrice"));
    res->AskVolume = boost::lexical_cast<int>(map.at("AskVolume"));
    res->BidVolume = boost::lexical_cast<int>(map.at("BidVolume"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->AskOffsetFlag = boost::lexical_cast<char>(map.at("AskOffsetFlag"));
    res->BidOffsetFlag = boost::lexical_cast<char>(map.at("BidOffsetFlag"));
    res->AskHedgeFlag = boost::lexical_cast<char>(map.at("AskHedgeFlag"));
    res->BidHedgeFlag = boost::lexical_cast<char>(map.at("BidHedgeFlag"));
    strcpy(res->QuoteLocalID, map.at("QuoteLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    res->QuoteStatus = boost::lexical_cast<char>(map.at("QuoteStatus"));
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    strcpy(res->AskOrderSysID, map.at("AskOrderSysID").data());
    strcpy(res->BidOrderSysID, map.at("BidOrderSysID").data());
    strcpy(res->ForQuoteSysID, map.at("ForQuoteSysID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeQuoteField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeQuoteField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeQuoteField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeQuoteField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryQuoteActionField const &data);

template<>
class fromRedis<CThostFtdcQryQuoteActionField> {
 public:
  std::unique_ptr<CThostFtdcQryQuoteActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryQuoteActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeQuoteActionField const &data);

template<>
class fromRedis<CThostFtdcExchangeQuoteActionField> {
 public:
  std::unique_ptr<CThostFtdcExchangeQuoteActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeQuoteActionField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->QuoteSysID, map.at("QuoteSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->QuoteLocalID, map.at("QuoteLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeQuoteActionField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeQuoteActionField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeQuoteActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeQuoteActionField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrDeltaField const &data);

template<>
class fromRedis<CThostFtdcOptionInstrDeltaField> {
 public:
  std::unique_ptr<CThostFtdcOptionInstrDeltaField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOptionInstrDeltaField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Delta = boost::lexical_cast<double>(map.at("Delta"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForQuoteRspField const &data);

template<>
class fromRedis<CThostFtdcForQuoteRspField> {
 public:
  std::unique_ptr<CThostFtdcForQuoteRspField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcForQuoteRspField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ForQuoteSysID, map.at("ForQuoteSysID").data());
    strcpy(res->ForQuoteTime, map.at("ForQuoteTime").data());
    strcpy(res->ActionDay, map.at("ActionDay").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcStrikeOffsetField const &data);

template<>
class fromRedis<CThostFtdcStrikeOffsetField> {
 public:
  std::unique_ptr<CThostFtdcStrikeOffsetField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcStrikeOffsetField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Offset = boost::lexical_cast<double>(map.at("Offset"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryStrikeOffsetField const &data);

template<>
class fromRedis<CThostFtdcQryStrikeOffsetField> {
 public:
  std::unique_ptr<CThostFtdcQryStrikeOffsetField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryStrikeOffsetField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombInstrumentGuardField const &data);

template<>
class fromRedis<CThostFtdcCombInstrumentGuardField> {
 public:
  std::unique_ptr<CThostFtdcCombInstrumentGuardField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCombInstrumentGuardField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->GuarantRatio = boost::lexical_cast<double>(map.at("GuarantRatio"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombInstrumentGuardField const &data);

template<>
class fromRedis<CThostFtdcQryCombInstrumentGuardField> {
 public:
  std::unique_ptr<CThostFtdcQryCombInstrumentGuardField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCombInstrumentGuardField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputCombActionField const &data);

template<>
class fromRedis<CThostFtdcInputCombActionField> {
 public:
  std::unique_ptr<CThostFtdcInputCombActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInputCombActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->CombActionRef, map.at("CombActionRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->CombDirection = boost::lexical_cast<char>(map.at("CombDirection"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombActionField const &data);

template<>
class fromRedis<CThostFtdcCombActionField> {
 public:
  std::unique_ptr<CThostFtdcCombActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCombActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->CombActionRef, map.at("CombActionRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->CombDirection = boost::lexical_cast<char>(map.at("CombDirection"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->ActionStatus = boost::lexical_cast<char>(map.at("ActionStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombActionField const &data);

template<>
class fromRedis<CThostFtdcQryCombActionField> {
 public:
  std::unique_ptr<CThostFtdcQryCombActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCombActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeCombActionField const &data);

template<>
class fromRedis<CThostFtdcExchangeCombActionField> {
 public:
  std::unique_ptr<CThostFtdcExchangeCombActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeCombActionField>();

    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->CombDirection = boost::lexical_cast<char>(map.at("CombDirection"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->ActionStatus = boost::lexical_cast<char>(map.at("ActionStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeCombActionField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeCombActionField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeCombActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeCombActionField>();

    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcProductExchRateField const &data);

template<>
class fromRedis<CThostFtdcProductExchRateField> {
 public:
  std::unique_ptr<CThostFtdcProductExchRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcProductExchRateField>();

    strcpy(res->ProductID, map.at("ProductID").data());
    strcpy(res->QuoteCurrencyID, map.at("QuoteCurrencyID").data());
    res->ExchangeRate = boost::lexical_cast<double>(map.at("ExchangeRate"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryProductExchRateField const &data);

template<>
class fromRedis<CThostFtdcQryProductExchRateField> {
 public:
  std::unique_ptr<CThostFtdcQryProductExchRateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryProductExchRateField>();

    strcpy(res->ProductID, map.at("ProductID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataField const &data);

template<>
class fromRedis<CThostFtdcMarketDataField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    res->LastPrice = boost::lexical_cast<double>(map.at("LastPrice"));
    res->PreSettlementPrice = boost::lexical_cast<double>(map.at("PreSettlementPrice"));
    res->PreClosePrice = boost::lexical_cast<double>(map.at("PreClosePrice"));
    res->PreOpenInterest = boost::lexical_cast<double>(map.at("PreOpenInterest"));
    res->OpenPrice = boost::lexical_cast<double>(map.at("OpenPrice"));
    res->HighestPrice = boost::lexical_cast<double>(map.at("HighestPrice"));
    res->LowestPrice = boost::lexical_cast<double>(map.at("LowestPrice"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->Turnover = boost::lexical_cast<double>(map.at("Turnover"));
    res->OpenInterest = boost::lexical_cast<double>(map.at("OpenInterest"));
    res->ClosePrice = boost::lexical_cast<double>(map.at("ClosePrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    res->UpperLimitPrice = boost::lexical_cast<double>(map.at("UpperLimitPrice"));
    res->LowerLimitPrice = boost::lexical_cast<double>(map.at("LowerLimitPrice"));
    res->PreDelta = boost::lexical_cast<double>(map.at("PreDelta"));
    res->CurrDelta = boost::lexical_cast<double>(map.at("CurrDelta"));
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    res->UpdateMillisec = boost::lexical_cast<int>(map.at("UpdateMillisec"));
    strcpy(res->ActionDay, map.at("ActionDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBaseField const &data);

template<>
class fromRedis<CThostFtdcMarketDataBaseField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataBaseField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataBaseField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PreSettlementPrice = boost::lexical_cast<double>(map.at("PreSettlementPrice"));
    res->PreClosePrice = boost::lexical_cast<double>(map.at("PreClosePrice"));
    res->PreOpenInterest = boost::lexical_cast<double>(map.at("PreOpenInterest"));
    res->PreDelta = boost::lexical_cast<double>(map.at("PreDelta"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataStaticField const &data);

template<>
class fromRedis<CThostFtdcMarketDataStaticField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataStaticField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataStaticField>();

    res->OpenPrice = boost::lexical_cast<double>(map.at("OpenPrice"));
    res->HighestPrice = boost::lexical_cast<double>(map.at("HighestPrice"));
    res->LowestPrice = boost::lexical_cast<double>(map.at("LowestPrice"));
    res->ClosePrice = boost::lexical_cast<double>(map.at("ClosePrice"));
    res->UpperLimitPrice = boost::lexical_cast<double>(map.at("UpperLimitPrice"));
    res->LowerLimitPrice = boost::lexical_cast<double>(map.at("LowerLimitPrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    res->CurrDelta = boost::lexical_cast<double>(map.at("CurrDelta"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataLastMatchField const &data);

template<>
class fromRedis<CThostFtdcMarketDataLastMatchField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataLastMatchField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataLastMatchField>();

    res->LastPrice = boost::lexical_cast<double>(map.at("LastPrice"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->Turnover = boost::lexical_cast<double>(map.at("Turnover"));
    res->OpenInterest = boost::lexical_cast<double>(map.at("OpenInterest"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBestPriceField const &data);

template<>
class fromRedis<CThostFtdcMarketDataBestPriceField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataBestPriceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataBestPriceField>();

    res->BidPrice1 = boost::lexical_cast<double>(map.at("BidPrice1"));
    res->BidVolume1 = boost::lexical_cast<int>(map.at("BidVolume1"));
    res->AskPrice1 = boost::lexical_cast<double>(map.at("AskPrice1"));
    res->AskVolume1 = boost::lexical_cast<int>(map.at("AskVolume1"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBid23Field const &data);

template<>
class fromRedis<CThostFtdcMarketDataBid23Field> {
 public:
  std::unique_ptr<CThostFtdcMarketDataBid23Field> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataBid23Field>();

    res->BidPrice2 = boost::lexical_cast<double>(map.at("BidPrice2"));
    res->BidVolume2 = boost::lexical_cast<int>(map.at("BidVolume2"));
    res->BidPrice3 = boost::lexical_cast<double>(map.at("BidPrice3"));
    res->BidVolume3 = boost::lexical_cast<int>(map.at("BidVolume3"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAsk23Field const &data);

template<>
class fromRedis<CThostFtdcMarketDataAsk23Field> {
 public:
  std::unique_ptr<CThostFtdcMarketDataAsk23Field> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataAsk23Field>();

    res->AskPrice2 = boost::lexical_cast<double>(map.at("AskPrice2"));
    res->AskVolume2 = boost::lexical_cast<int>(map.at("AskVolume2"));
    res->AskPrice3 = boost::lexical_cast<double>(map.at("AskPrice3"));
    res->AskVolume3 = boost::lexical_cast<int>(map.at("AskVolume3"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBid45Field const &data);

template<>
class fromRedis<CThostFtdcMarketDataBid45Field> {
 public:
  std::unique_ptr<CThostFtdcMarketDataBid45Field> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataBid45Field>();

    res->BidPrice4 = boost::lexical_cast<double>(map.at("BidPrice4"));
    res->BidVolume4 = boost::lexical_cast<int>(map.at("BidVolume4"));
    res->BidPrice5 = boost::lexical_cast<double>(map.at("BidPrice5"));
    res->BidVolume5 = boost::lexical_cast<int>(map.at("BidVolume5"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAsk45Field const &data);

template<>
class fromRedis<CThostFtdcMarketDataAsk45Field> {
 public:
  std::unique_ptr<CThostFtdcMarketDataAsk45Field> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataAsk45Field>();

    res->AskPrice4 = boost::lexical_cast<double>(map.at("AskPrice4"));
    res->AskVolume4 = boost::lexical_cast<int>(map.at("AskVolume4"));
    res->AskPrice5 = boost::lexical_cast<double>(map.at("AskPrice5"));
    res->AskVolume5 = boost::lexical_cast<int>(map.at("AskVolume5"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataUpdateTimeField const &data);

template<>
class fromRedis<CThostFtdcMarketDataUpdateTimeField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataUpdateTimeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataUpdateTimeField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    res->UpdateMillisec = boost::lexical_cast<int>(map.at("UpdateMillisec"));
    strcpy(res->ActionDay, map.at("ActionDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataExchangeField const &data);

template<>
class fromRedis<CThostFtdcMarketDataExchangeField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataExchangeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataExchangeField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSpecificInstrumentField const &data);

template<>
class fromRedis<CThostFtdcSpecificInstrumentField> {
 public:
  std::unique_ptr<CThostFtdcSpecificInstrumentField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSpecificInstrumentField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentStatusField const &data);

template<>
class fromRedis<CThostFtdcInstrumentStatusField> {
 public:
  std::unique_ptr<CThostFtdcInstrumentStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInstrumentStatusField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->SettlementGroupID, map.at("SettlementGroupID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->InstrumentStatus = boost::lexical_cast<char>(map.at("InstrumentStatus"));
    res->TradingSegmentSN = boost::lexical_cast<int>(map.at("TradingSegmentSN"));
    strcpy(res->EnterTime, map.at("EnterTime").data());
    res->EnterReason = boost::lexical_cast<char>(map.at("EnterReason"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentStatusField const &data);

template<>
class fromRedis<CThostFtdcQryInstrumentStatusField> {
 public:
  std::unique_ptr<CThostFtdcQryInstrumentStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInstrumentStatusField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorAccountField const &data);

template<>
class fromRedis<CThostFtdcInvestorAccountField> {
 public:
  std::unique_ptr<CThostFtdcInvestorAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorAccountField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcPositionProfitAlgorithmField const &data);

template<>
class fromRedis<CThostFtdcPositionProfitAlgorithmField> {
 public:
  std::unique_ptr<CThostFtdcPositionProfitAlgorithmField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcPositionProfitAlgorithmField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->Algorithm = boost::lexical_cast<char>(map.at("Algorithm"));
    strcpy(res->Memo, map.at("Memo").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDiscountField const &data);

template<>
class fromRedis<CThostFtdcDiscountField> {
 public:
  std::unique_ptr<CThostFtdcDiscountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcDiscountField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Discount = boost::lexical_cast<double>(map.at("Discount"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTransferBankField const &data);

template<>
class fromRedis<CThostFtdcQryTransferBankField> {
 public:
  std::unique_ptr<CThostFtdcQryTransferBankField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTransferBankField>();

    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankField const &data);

template<>
class fromRedis<CThostFtdcTransferBankField> {
 public:
  std::unique_ptr<CThostFtdcTransferBankField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferBankField>();

    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());
    strcpy(res->BankName, map.at("BankName").data());
    res->IsActive = boost::lexical_cast<int>(map.at("IsActive"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionDetailField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorPositionDetailField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorPositionDetailField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorPositionDetailField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionDetailField const &data);

template<>
class fromRedis<CThostFtdcInvestorPositionDetailField> {
 public:
  std::unique_ptr<CThostFtdcInvestorPositionDetailField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorPositionDetailField>();

    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->OpenDate, map.at("OpenDate").data());
    strcpy(res->TradeID, map.at("TradeID").data());
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));
    res->OpenPrice = boost::lexical_cast<double>(map.at("OpenPrice"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->TradeType = boost::lexical_cast<char>(map.at("TradeType"));
    strcpy(res->CombInstrumentID, map.at("CombInstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    res->CloseProfitByDate = boost::lexical_cast<double>(map.at("CloseProfitByDate"));
    res->CloseProfitByTrade = boost::lexical_cast<double>(map.at("CloseProfitByTrade"));
    res->PositionProfitByDate = boost::lexical_cast<double>(map.at("PositionProfitByDate"));
    res->PositionProfitByTrade = boost::lexical_cast<double>(map.at("PositionProfitByTrade"));
    res->Margin = boost::lexical_cast<double>(map.at("Margin"));
    res->ExchMargin = boost::lexical_cast<double>(map.at("ExchMargin"));
    res->MarginRateByMoney = boost::lexical_cast<double>(map.at("MarginRateByMoney"));
    res->MarginRateByVolume = boost::lexical_cast<double>(map.at("MarginRateByVolume"));
    res->LastSettlementPrice = boost::lexical_cast<double>(map.at("LastSettlementPrice"));
    res->SettlementPrice = boost::lexical_cast<double>(map.at("SettlementPrice"));
    res->CloseVolume = boost::lexical_cast<int>(map.at("CloseVolume"));
    res->CloseAmount = boost::lexical_cast<double>(map.at("CloseAmount"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordField const &data);

template<>
class fromRedis<CThostFtdcTradingAccountPasswordField> {
 public:
  std::unique_ptr<CThostFtdcTradingAccountPasswordField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingAccountPasswordField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMDTraderOfferField const &data);

template<>
class fromRedis<CThostFtdcMDTraderOfferField> {
 public:
  std::unique_ptr<CThostFtdcMDTraderOfferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMDTraderOfferField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    res->TraderConnectStatus = boost::lexical_cast<char>(map.at("TraderConnectStatus"));
    strcpy(res->ConnectRequestDate, map.at("ConnectRequestDate").data());
    strcpy(res->ConnectRequestTime, map.at("ConnectRequestTime").data());
    strcpy(res->LastReportDate, map.at("LastReportDate").data());
    strcpy(res->LastReportTime, map.at("LastReportTime").data());
    strcpy(res->ConnectDate, map.at("ConnectDate").data());
    strcpy(res->ConnectTime, map.at("ConnectTime").data());
    strcpy(res->StartDate, map.at("StartDate").data());
    strcpy(res->StartTime, map.at("StartTime").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->MaxTradeID, map.at("MaxTradeID").data());
    strcpy(res->MaxOrderMessageReference, map.at("MaxOrderMessageReference").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryMDTraderOfferField const &data);

template<>
class fromRedis<CThostFtdcQryMDTraderOfferField> {
 public:
  std::unique_ptr<CThostFtdcQryMDTraderOfferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryMDTraderOfferField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->TraderID, map.at("TraderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryNoticeField const &data);

template<>
class fromRedis<CThostFtdcQryNoticeField> {
 public:
  std::unique_ptr<CThostFtdcQryNoticeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryNoticeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNoticeField const &data);

template<>
class fromRedis<CThostFtdcNoticeField> {
 public:
  std::unique_ptr<CThostFtdcNoticeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcNoticeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->Content, map.at("Content").data());
    strcpy(res->SequenceLabel, map.at("SequenceLabel").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserRightField const &data);

template<>
class fromRedis<CThostFtdcUserRightField> {
 public:
  std::unique_ptr<CThostFtdcUserRightField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserRightField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->UserRightType = boost::lexical_cast<char>(map.at("UserRightType"));
    res->IsForbidden = boost::lexical_cast<int>(map.at("IsForbidden"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySettlementInfoConfirmField const &data);

template<>
class fromRedis<CThostFtdcQrySettlementInfoConfirmField> {
 public:
  std::unique_ptr<CThostFtdcQrySettlementInfoConfirmField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySettlementInfoConfirmField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoadSettlementInfoField const &data);

template<>
class fromRedis<CThostFtdcLoadSettlementInfoField> {
 public:
  std::unique_ptr<CThostFtdcLoadSettlementInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcLoadSettlementInfoField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerWithdrawAlgorithmField const &data);

template<>
class fromRedis<CThostFtdcBrokerWithdrawAlgorithmField> {
 public:
  std::unique_ptr<CThostFtdcBrokerWithdrawAlgorithmField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerWithdrawAlgorithmField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    res->WithdrawAlgorithm = boost::lexical_cast<char>(map.at("WithdrawAlgorithm"));
    res->UsingRatio = boost::lexical_cast<double>(map.at("UsingRatio"));
    res->IncludeCloseProfit = boost::lexical_cast<char>(map.at("IncludeCloseProfit"));
    res->AllWithoutTrade = boost::lexical_cast<char>(map.at("AllWithoutTrade"));
    res->AvailIncludeCloseProfit = boost::lexical_cast<char>(map.at("AvailIncludeCloseProfit"));
    res->IsBrokerUserEvent = boost::lexical_cast<int>(map.at("IsBrokerUserEvent"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->FundMortgageRatio = boost::lexical_cast<double>(map.at("FundMortgageRatio"));
    res->BalanceAlgorithm = boost::lexical_cast<char>(map.at("BalanceAlgorithm"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordUpdateV1Field const &data);

template<>
class fromRedis<CThostFtdcTradingAccountPasswordUpdateV1Field> {
 public:
  std::unique_ptr<CThostFtdcTradingAccountPasswordUpdateV1Field> operator()(redis::Redis &cli,
                                                                            std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingAccountPasswordUpdateV1Field>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->OldPassword, map.at("OldPassword").data());
    strcpy(res->NewPassword, map.at("NewPassword").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordUpdateField const &data);

template<>
class fromRedis<CThostFtdcTradingAccountPasswordUpdateField> {
 public:
  std::unique_ptr<CThostFtdcTradingAccountPasswordUpdateField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingAccountPasswordUpdateField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->OldPassword, map.at("OldPassword").data());
    strcpy(res->NewPassword, map.at("NewPassword").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombinationLegField const &data);

template<>
class fromRedis<CThostFtdcQryCombinationLegField> {
 public:
  std::unique_ptr<CThostFtdcQryCombinationLegField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCombinationLegField>();

    strcpy(res->CombInstrumentID, map.at("CombInstrumentID").data());
    res->LegID = boost::lexical_cast<int>(map.at("LegID"));
    strcpy(res->LegInstrumentID, map.at("LegInstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncStatusField const &data);

template<>
class fromRedis<CThostFtdcQrySyncStatusField> {
 public:
  std::unique_ptr<CThostFtdcQrySyncStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySyncStatusField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombinationLegField const &data);

template<>
class fromRedis<CThostFtdcCombinationLegField> {
 public:
  std::unique_ptr<CThostFtdcCombinationLegField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCombinationLegField>();

    strcpy(res->CombInstrumentID, map.at("CombInstrumentID").data());
    res->LegID = boost::lexical_cast<int>(map.at("LegID"));
    strcpy(res->LegInstrumentID, map.at("LegInstrumentID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->LegMultiple = boost::lexical_cast<int>(map.at("LegMultiple"));
    res->ImplyLevel = boost::lexical_cast<int>(map.at("ImplyLevel"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncStatusField const &data);

template<>
class fromRedis<CThostFtdcSyncStatusField> {
 public:
  std::unique_ptr<CThostFtdcSyncStatusField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSyncStatusField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->DataSyncStatus = boost::lexical_cast<char>(map.at("DataSyncStatus"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryLinkManField const &data);

template<>
class fromRedis<CThostFtdcQryLinkManField> {
 public:
  std::unique_ptr<CThostFtdcQryLinkManField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryLinkManField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLinkManField const &data);

template<>
class fromRedis<CThostFtdcLinkManField> {
 public:
  std::unique_ptr<CThostFtdcLinkManField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcLinkManField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->PersonType = boost::lexical_cast<char>(map.at("PersonType"));
    res->IdentifiedCardType = boost::lexical_cast<char>(map.at("IdentifiedCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    strcpy(res->PersonName, map.at("PersonName").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    res->Priority = boost::lexical_cast<int>(map.at("Priority"));
    strcpy(res->UOAZipCode, map.at("UOAZipCode").data());
    strcpy(res->PersonFullName, map.at("PersonFullName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserEventField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerUserEventField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerUserEventField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerUserEventField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->UserEventType = boost::lexical_cast<char>(map.at("UserEventType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserEventField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserEventField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserEventField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserEventField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->UserEventType = boost::lexical_cast<char>(map.at("UserEventType"));
    res->EventSequenceNo = boost::lexical_cast<int>(map.at("EventSequenceNo"));
    strcpy(res->EventDate, map.at("EventDate").data());
    strcpy(res->EventTime, map.at("EventTime").data());
    strcpy(res->UserEventInfo, map.at("UserEventInfo").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryContractBankField const &data);

template<>
class fromRedis<CThostFtdcQryContractBankField> {
 public:
  std::unique_ptr<CThostFtdcQryContractBankField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryContractBankField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcContractBankField const &data);

template<>
class fromRedis<CThostFtdcContractBankField> {
 public:
  std::unique_ptr<CThostFtdcContractBankField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcContractBankField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBrchID, map.at("BankBrchID").data());
    strcpy(res->BankName, map.at("BankName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionCombineDetailField const &data);

template<>
class fromRedis<CThostFtdcInvestorPositionCombineDetailField> {
 public:
  std::unique_ptr<CThostFtdcInvestorPositionCombineDetailField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorPositionCombineDetailField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->OpenDate, map.at("OpenDate").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ComTradeID, map.at("ComTradeID").data());
    strcpy(res->TradeID, map.at("TradeID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->TotalAmt = boost::lexical_cast<int>(map.at("TotalAmt"));
    res->Margin = boost::lexical_cast<double>(map.at("Margin"));
    res->ExchMargin = boost::lexical_cast<double>(map.at("ExchMargin"));
    res->MarginRateByMoney = boost::lexical_cast<double>(map.at("MarginRateByMoney"));
    res->MarginRateByVolume = boost::lexical_cast<double>(map.at("MarginRateByVolume"));
    res->LegID = boost::lexical_cast<int>(map.at("LegID"));
    res->LegMultiple = boost::lexical_cast<int>(map.at("LegMultiple"));
    strcpy(res->CombInstrumentID, map.at("CombInstrumentID").data());
    res->TradeGroupID = boost::lexical_cast<int>(map.at("TradeGroupID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcParkedOrderField const &data);

template<>
class fromRedis<CThostFtdcParkedOrderField> {
 public:
  std::unique_ptr<CThostFtdcParkedOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcParkedOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->UserForceClose = boost::lexical_cast<int>(map.at("UserForceClose"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParkedOrderID, map.at("ParkedOrderID").data());
    res->UserType = boost::lexical_cast<char>(map.at("UserType"));
    res->Status = boost::lexical_cast<char>(map.at("Status"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    res->IsSwapOrder = boost::lexical_cast<int>(map.at("IsSwapOrder"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcParkedOrderActionField const &data);

template<>
class fromRedis<CThostFtdcParkedOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcParkedOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcParkedOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OrderActionRef = boost::lexical_cast<int>(map.at("OrderActionRef"));
    strcpy(res->OrderRef, map.at("OrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeChange = boost::lexical_cast<int>(map.at("VolumeChange"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ParkedOrderActionID, map.at("ParkedOrderActionID").data());
    res->UserType = boost::lexical_cast<char>(map.at("UserType"));
    res->Status = boost::lexical_cast<char>(map.at("Status"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryParkedOrderField const &data);

template<>
class fromRedis<CThostFtdcQryParkedOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryParkedOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryParkedOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryParkedOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryParkedOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryParkedOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryParkedOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRemoveParkedOrderField const &data);

template<>
class fromRedis<CThostFtdcRemoveParkedOrderField> {
 public:
  std::unique_ptr<CThostFtdcRemoveParkedOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRemoveParkedOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ParkedOrderID, map.at("ParkedOrderID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRemoveParkedOrderActionField const &data);

template<>
class fromRedis<CThostFtdcRemoveParkedOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcRemoveParkedOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRemoveParkedOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ParkedOrderActionID, map.at("ParkedOrderActionID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorWithdrawAlgorithmField const &data);

template<>
class fromRedis<CThostFtdcInvestorWithdrawAlgorithmField> {
 public:
  std::unique_ptr<CThostFtdcInvestorWithdrawAlgorithmField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorWithdrawAlgorithmField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->UsingRatio = boost::lexical_cast<double>(map.at("UsingRatio"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->FundMortgageRatio = boost::lexical_cast<double>(map.at("FundMortgageRatio"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionCombineDetailField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorPositionCombineDetailField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorPositionCombineDetailField> operator()(redis::Redis &cli,
                                                                              std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorPositionCombineDetailField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->CombInstrumentID, map.at("CombInstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAveragePriceField const &data);

template<>
class fromRedis<CThostFtdcMarketDataAveragePriceField> {
 public:
  std::unique_ptr<CThostFtdcMarketDataAveragePriceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarketDataAveragePriceField>();

    res->AveragePrice = boost::lexical_cast<double>(map.at("AveragePrice"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyInvestorPasswordField const &data);

template<>
class fromRedis<CThostFtdcVerifyInvestorPasswordField> {
 public:
  std::unique_ptr<CThostFtdcVerifyInvestorPasswordField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcVerifyInvestorPasswordField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->Password, map.at("Password").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserIPField const &data);

template<>
class fromRedis<CThostFtdcUserIPField> {
 public:
  std::unique_ptr<CThostFtdcUserIPField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserIPField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->IPAddress, map.at("IPAddress").data());
    strcpy(res->IPMask, map.at("IPMask").data());
    strcpy(res->MacAddress, map.at("MacAddress").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingNoticeInfoField const &data);

template<>
class fromRedis<CThostFtdcTradingNoticeInfoField> {
 public:
  std::unique_ptr<CThostFtdcTradingNoticeInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingNoticeInfoField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->SendTime, map.at("SendTime").data());
    strcpy(res->FieldContent, map.at("FieldContent").data());
    res->SequenceSeries = boost::lexical_cast<short>(map.at("SequenceSeries"));
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingNoticeField const &data);

template<>
class fromRedis<CThostFtdcTradingNoticeField> {
 public:
  std::unique_ptr<CThostFtdcTradingNoticeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingNoticeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    res->InvestorRange = boost::lexical_cast<char>(map.at("InvestorRange"));
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->SequenceSeries = boost::lexical_cast<short>(map.at("SequenceSeries"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->SendTime, map.at("SendTime").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    strcpy(res->FieldContent, map.at("FieldContent").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingNoticeField const &data);

template<>
class fromRedis<CThostFtdcQryTradingNoticeField> {
 public:
  std::unique_ptr<CThostFtdcQryTradingNoticeField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTradingNoticeField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrOrderField const &data);

template<>
class fromRedis<CThostFtdcQryErrOrderField> {
 public:
  std::unique_ptr<CThostFtdcQryErrOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryErrOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrOrderField const &data);

template<>
class fromRedis<CThostFtdcErrOrderField> {
 public:
  std::unique_ptr<CThostFtdcErrOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcErrOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->UserForceClose = boost::lexical_cast<int>(map.at("UserForceClose"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    res->IsSwapOrder = boost::lexical_cast<int>(map.at("IsSwapOrder"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrorConditionalOrderField const &data);

template<>
class fromRedis<CThostFtdcErrorConditionalOrderField> {
 public:
  std::unique_ptr<CThostFtdcErrorConditionalOrderField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcErrorConditionalOrderField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    strcpy(res->OrderRef, map.at("OrderRef").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OrderPriceType = boost::lexical_cast<char>(map.at("OrderPriceType"));
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    strcpy(res->CombOffsetFlag, map.at("CombOffsetFlag").data());
    strcpy(res->CombHedgeFlag, map.at("CombHedgeFlag").data());
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeTotalOriginal = boost::lexical_cast<int>(map.at("VolumeTotalOriginal"));
    res->TimeCondition = boost::lexical_cast<char>(map.at("TimeCondition"));
    strcpy(res->GTDDate, map.at("GTDDate").data());
    res->VolumeCondition = boost::lexical_cast<char>(map.at("VolumeCondition"));
    res->MinVolume = boost::lexical_cast<int>(map.at("MinVolume"));
    res->ContingentCondition = boost::lexical_cast<char>(map.at("ContingentCondition"));
    res->StopPrice = boost::lexical_cast<double>(map.at("StopPrice"));
    res->ForceCloseReason = boost::lexical_cast<char>(map.at("ForceCloseReason"));
    res->IsAutoSuspend = boost::lexical_cast<int>(map.at("IsAutoSuspend"));
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->ExchangeInstID, map.at("ExchangeInstID").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->OrderSubmitStatus = boost::lexical_cast<char>(map.at("OrderSubmitStatus"));
    res->NotifySequence = boost::lexical_cast<int>(map.at("NotifySequence"));
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->OrderSource = boost::lexical_cast<char>(map.at("OrderSource"));
    res->OrderStatus = boost::lexical_cast<char>(map.at("OrderStatus"));
    res->OrderType = boost::lexical_cast<char>(map.at("OrderType"));
    res->VolumeTraded = boost::lexical_cast<int>(map.at("VolumeTraded"));
    res->VolumeTotal = boost::lexical_cast<int>(map.at("VolumeTotal"));
    strcpy(res->InsertDate, map.at("InsertDate").data());
    strcpy(res->InsertTime, map.at("InsertTime").data());
    strcpy(res->ActiveTime, map.at("ActiveTime").data());
    strcpy(res->SuspendTime, map.at("SuspendTime").data());
    strcpy(res->UpdateTime, map.at("UpdateTime").data());
    strcpy(res->CancelTime, map.at("CancelTime").data());
    strcpy(res->ActiveTraderID, map.at("ActiveTraderID").data());
    strcpy(res->ClearingPartID, map.at("ClearingPartID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->UserProductInfo, map.at("UserProductInfo").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    res->UserForceClose = boost::lexical_cast<int>(map.at("UserForceClose"));
    strcpy(res->ActiveUserID, map.at("ActiveUserID").data());
    res->BrokerOrderSeq = boost::lexical_cast<int>(map.at("BrokerOrderSeq"));
    strcpy(res->RelativeOrderSysID, map.at("RelativeOrderSysID").data());
    res->ZCETotalTradedVolume = boost::lexical_cast<int>(map.at("ZCETotalTradedVolume"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    res->IsSwapOrder = boost::lexical_cast<int>(map.at("IsSwapOrder"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrOrderActionField const &data);

template<>
class fromRedis<CThostFtdcQryErrOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcQryErrOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryErrOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrOrderActionField const &data);

template<>
class fromRedis<CThostFtdcErrOrderActionField> {
 public:
  std::unique_ptr<CThostFtdcErrOrderActionField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcErrOrderActionField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->OrderActionRef = boost::lexical_cast<int>(map.at("OrderActionRef"));
    strcpy(res->OrderRef, map.at("OrderRef").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->FrontID = boost::lexical_cast<int>(map.at("FrontID"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->OrderSysID, map.at("OrderSysID").data());
    res->ActionFlag = boost::lexical_cast<char>(map.at("ActionFlag"));
    res->LimitPrice = boost::lexical_cast<double>(map.at("LimitPrice"));
    res->VolumeChange = boost::lexical_cast<int>(map.at("VolumeChange"));
    strcpy(res->ActionDate, map.at("ActionDate").data());
    strcpy(res->ActionTime, map.at("ActionTime").data());
    strcpy(res->TraderID, map.at("TraderID").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->OrderLocalID, map.at("OrderLocalID").data());
    strcpy(res->ActionLocalID, map.at("ActionLocalID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ClientID, map.at("ClientID").data());
    strcpy(res->BusinessUnit, map.at("BusinessUnit").data());
    res->OrderActionStatus = boost::lexical_cast<char>(map.at("OrderActionStatus"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->StatusMsg, map.at("StatusMsg").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeSequenceField const &data);

template<>
class fromRedis<CThostFtdcQryExchangeSequenceField> {
 public:
  std::unique_ptr<CThostFtdcQryExchangeSequenceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryExchangeSequenceField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeSequenceField const &data);

template<>
class fromRedis<CThostFtdcExchangeSequenceField> {
 public:
  std::unique_ptr<CThostFtdcExchangeSequenceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcExchangeSequenceField>();

    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    res->SequenceNo = boost::lexical_cast<int>(map.at("SequenceNo"));
    res->MarketStatus = boost::lexical_cast<char>(map.at("MarketStatus"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryMaxOrderVolumeWithPriceField const &data);

template<>
class fromRedis<CThostFtdcQueryMaxOrderVolumeWithPriceField> {
 public:
  std::unique_ptr<CThostFtdcQueryMaxOrderVolumeWithPriceField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQueryMaxOrderVolumeWithPriceField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->OffsetFlag = boost::lexical_cast<char>(map.at("OffsetFlag"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->MaxVolume = boost::lexical_cast<int>(map.at("MaxVolume"));
    res->Price = boost::lexical_cast<double>(map.at("Price"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerTradingParamsField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerTradingParamsField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerTradingParamsField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerTradingParamsField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerTradingParamsField const &data);

template<>
class fromRedis<CThostFtdcBrokerTradingParamsField> {
 public:
  std::unique_ptr<CThostFtdcBrokerTradingParamsField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerTradingParamsField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->MarginPriceType = boost::lexical_cast<char>(map.at("MarginPriceType"));
    res->Algorithm = boost::lexical_cast<char>(map.at("Algorithm"));
    res->AvailIncludeCloseProfit = boost::lexical_cast<char>(map.at("AvailIncludeCloseProfit"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->OptionRoyaltyPriceType = boost::lexical_cast<char>(map.at("OptionRoyaltyPriceType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerTradingAlgosField const &data);

template<>
class fromRedis<CThostFtdcQryBrokerTradingAlgosField> {
 public:
  std::unique_ptr<CThostFtdcQryBrokerTradingAlgosField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryBrokerTradingAlgosField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerTradingAlgosField const &data);

template<>
class fromRedis<CThostFtdcBrokerTradingAlgosField> {
 public:
  std::unique_ptr<CThostFtdcBrokerTradingAlgosField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerTradingAlgosField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->HandlePositionAlgoID = boost::lexical_cast<char>(map.at("HandlePositionAlgoID"));
    res->FindMarginRateAlgoID = boost::lexical_cast<char>(map.at("FindMarginRateAlgoID"));
    res->HandleTradingAccountAlgoID = boost::lexical_cast<char>(map.at("HandleTradingAccountAlgoID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryBrokerDepositField const &data);

template<>
class fromRedis<CThostFtdcQueryBrokerDepositField> {
 public:
  std::unique_ptr<CThostFtdcQueryBrokerDepositField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQueryBrokerDepositField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerDepositField const &data);

template<>
class fromRedis<CThostFtdcBrokerDepositField> {
 public:
  std::unique_ptr<CThostFtdcBrokerDepositField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerDepositField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    res->PreBalance = boost::lexical_cast<double>(map.at("PreBalance"));
    res->CurrMargin = boost::lexical_cast<double>(map.at("CurrMargin"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->Balance = boost::lexical_cast<double>(map.at("Balance"));
    res->Deposit = boost::lexical_cast<double>(map.at("Deposit"));
    res->Withdraw = boost::lexical_cast<double>(map.at("Withdraw"));
    res->Available = boost::lexical_cast<double>(map.at("Available"));
    res->Reserve = boost::lexical_cast<double>(map.at("Reserve"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCFMMCBrokerKeyField const &data);

template<>
class fromRedis<CThostFtdcQryCFMMCBrokerKeyField> {
 public:
  std::unique_ptr<CThostFtdcQryCFMMCBrokerKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCFMMCBrokerKeyField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCBrokerKeyField const &data);

template<>
class fromRedis<CThostFtdcCFMMCBrokerKeyField> {
 public:
  std::unique_ptr<CThostFtdcCFMMCBrokerKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCFMMCBrokerKeyField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->CreateDate, map.at("CreateDate").data());
    strcpy(res->CreateTime, map.at("CreateTime").data());
    res->KeyID = boost::lexical_cast<int>(map.at("KeyID"));
    strcpy(res->CurrentKey, map.at("CurrentKey").data());
    res->KeyKind = boost::lexical_cast<char>(map.at("KeyKind"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCTradingAccountKeyField const &data);

template<>
class fromRedis<CThostFtdcCFMMCTradingAccountKeyField> {
 public:
  std::unique_ptr<CThostFtdcCFMMCTradingAccountKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCFMMCTradingAccountKeyField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->KeyID = boost::lexical_cast<int>(map.at("KeyID"));
    strcpy(res->CurrentKey, map.at("CurrentKey").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCFMMCTradingAccountKeyField const &data);

template<>
class fromRedis<CThostFtdcQryCFMMCTradingAccountKeyField> {
 public:
  std::unique_ptr<CThostFtdcQryCFMMCTradingAccountKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCFMMCTradingAccountKeyField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserOTPParamField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserOTPParamField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserOTPParamField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserOTPParamField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->OTPVendorsID, map.at("OTPVendorsID").data());
    strcpy(res->SerialNumber, map.at("SerialNumber").data());
    strcpy(res->AuthKey, map.at("AuthKey").data());
    res->LastDrift = boost::lexical_cast<int>(map.at("LastDrift"));
    res->LastSuccess = boost::lexical_cast<int>(map.at("LastSuccess"));
    res->OTPType = boost::lexical_cast<char>(map.at("OTPType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcManualSyncBrokerUserOTPField const &data);

template<>
class fromRedis<CThostFtdcManualSyncBrokerUserOTPField> {
 public:
  std::unique_ptr<CThostFtdcManualSyncBrokerUserOTPField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcManualSyncBrokerUserOTPField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->OTPType = boost::lexical_cast<char>(map.at("OTPType"));
    strcpy(res->FirstOTP, map.at("FirstOTP").data());
    strcpy(res->SecondOTP, map.at("SecondOTP").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCommRateModelField const &data);

template<>
class fromRedis<CThostFtdcCommRateModelField> {
 public:
  std::unique_ptr<CThostFtdcCommRateModelField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCommRateModelField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->CommModelID, map.at("CommModelID").data());
    strcpy(res->CommModelName, map.at("CommModelName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCommRateModelField const &data);

template<>
class fromRedis<CThostFtdcQryCommRateModelField> {
 public:
  std::unique_ptr<CThostFtdcQryCommRateModelField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryCommRateModelField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->CommModelID, map.at("CommModelID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarginModelField const &data);

template<>
class fromRedis<CThostFtdcMarginModelField> {
 public:
  std::unique_ptr<CThostFtdcMarginModelField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMarginModelField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->MarginModelID, map.at("MarginModelID").data());
    strcpy(res->MarginModelName, map.at("MarginModelName").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryMarginModelField const &data);

template<>
class fromRedis<CThostFtdcQryMarginModelField> {
 public:
  std::unique_ptr<CThostFtdcQryMarginModelField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryMarginModelField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->MarginModelID, map.at("MarginModelID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcEWarrantOffsetField const &data);

template<>
class fromRedis<CThostFtdcEWarrantOffsetField> {
 public:
  std::unique_ptr<CThostFtdcEWarrantOffsetField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcEWarrantOffsetField>();

    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());
    res->Direction = boost::lexical_cast<char>(map.at("Direction"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));
    res->Volume = boost::lexical_cast<int>(map.at("Volume"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryEWarrantOffsetField const &data);

template<>
class fromRedis<CThostFtdcQryEWarrantOffsetField> {
 public:
  std::unique_ptr<CThostFtdcQryEWarrantOffsetField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryEWarrantOffsetField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ExchangeID, map.at("ExchangeID").data());
    strcpy(res->InstrumentID, map.at("InstrumentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorProductGroupMarginField const &data);

template<>
class fromRedis<CThostFtdcQryInvestorProductGroupMarginField> {
 public:
  std::unique_ptr<CThostFtdcQryInvestorProductGroupMarginField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryInvestorProductGroupMarginField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->ProductGroupID, map.at("ProductGroupID").data());
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorProductGroupMarginField const &data);

template<>
class fromRedis<CThostFtdcInvestorProductGroupMarginField> {
 public:
  std::unique_ptr<CThostFtdcInvestorProductGroupMarginField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcInvestorProductGroupMarginField>();

    strcpy(res->ProductGroupID, map.at("ProductGroupID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->SettlementID = boost::lexical_cast<int>(map.at("SettlementID"));
    res->FrozenMargin = boost::lexical_cast<double>(map.at("FrozenMargin"));
    res->LongFrozenMargin = boost::lexical_cast<double>(map.at("LongFrozenMargin"));
    res->ShortFrozenMargin = boost::lexical_cast<double>(map.at("ShortFrozenMargin"));
    res->UseMargin = boost::lexical_cast<double>(map.at("UseMargin"));
    res->LongUseMargin = boost::lexical_cast<double>(map.at("LongUseMargin"));
    res->ShortUseMargin = boost::lexical_cast<double>(map.at("ShortUseMargin"));
    res->ExchMargin = boost::lexical_cast<double>(map.at("ExchMargin"));
    res->LongExchMargin = boost::lexical_cast<double>(map.at("LongExchMargin"));
    res->ShortExchMargin = boost::lexical_cast<double>(map.at("ShortExchMargin"));
    res->CloseProfit = boost::lexical_cast<double>(map.at("CloseProfit"));
    res->FrozenCommission = boost::lexical_cast<double>(map.at("FrozenCommission"));
    res->Commission = boost::lexical_cast<double>(map.at("Commission"));
    res->FrozenCash = boost::lexical_cast<double>(map.at("FrozenCash"));
    res->CashIn = boost::lexical_cast<double>(map.at("CashIn"));
    res->PositionProfit = boost::lexical_cast<double>(map.at("PositionProfit"));
    res->OffsetAmount = boost::lexical_cast<double>(map.at("OffsetAmount"));
    res->LongOffsetAmount = boost::lexical_cast<double>(map.at("LongOffsetAmount"));
    res->ShortOffsetAmount = boost::lexical_cast<double>(map.at("ShortOffsetAmount"));
    res->ExchOffsetAmount = boost::lexical_cast<double>(map.at("ExchOffsetAmount"));
    res->LongExchOffsetAmount = boost::lexical_cast<double>(map.at("LongExchOffsetAmount"));
    res->ShortExchOffsetAmount = boost::lexical_cast<double>(map.at("ShortExchOffsetAmount"));
    res->HedgeFlag = boost::lexical_cast<char>(map.at("HedgeFlag"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryCFMMCTradingAccountTokenField const &data);

template<>
class fromRedis<CThostFtdcQueryCFMMCTradingAccountTokenField> {
 public:
  std::unique_ptr<CThostFtdcQueryCFMMCTradingAccountTokenField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQueryCFMMCTradingAccountTokenField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCTradingAccountTokenField const &data);

template<>
class fromRedis<CThostFtdcCFMMCTradingAccountTokenField> {
 public:
  std::unique_ptr<CThostFtdcCFMMCTradingAccountTokenField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCFMMCTradingAccountTokenField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->ParticipantID, map.at("ParticipantID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->KeyID = boost::lexical_cast<int>(map.at("KeyID"));
    strcpy(res->Token, map.at("Token").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqOpenAccountField const &data);

template<>
class fromRedis<CThostFtdcReqOpenAccountField> {
 public:
  std::unique_ptr<CThostFtdcReqOpenAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqOpenAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->CashExchangeCode = boost::lexical_cast<char>(map.at("CashExchangeCode"));
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqCancelAccountField const &data);

template<>
class fromRedis<CThostFtdcReqCancelAccountField> {
 public:
  std::unique_ptr<CThostFtdcReqCancelAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqCancelAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->CashExchangeCode = boost::lexical_cast<char>(map.at("CashExchangeCode"));
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqChangeAccountField const &data);

template<>
class fromRedis<CThostFtdcReqChangeAccountField> {
 public:
  std::unique_ptr<CThostFtdcReqChangeAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqChangeAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->NewBankAccount, map.at("NewBankAccount").data());
    strcpy(res->NewBankPassWord, map.at("NewBankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->Digest, map.at("Digest").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqTransferField const &data);

template<>
class fromRedis<CThostFtdcReqTransferField> {
 public:
  std::unique_ptr<CThostFtdcReqTransferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqTransferField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    res->FutureFetchAmount = boost::lexical_cast<double>(map.at("FutureFetchAmount"));
    res->FeePayFlag = boost::lexical_cast<char>(map.at("FeePayFlag"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    res->BrokerFee = boost::lexical_cast<double>(map.at("BrokerFee"));
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->TransferStatus = boost::lexical_cast<char>(map.at("TransferStatus"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspTransferField const &data);

template<>
class fromRedis<CThostFtdcRspTransferField> {
 public:
  std::unique_ptr<CThostFtdcRspTransferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspTransferField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    res->FutureFetchAmount = boost::lexical_cast<double>(map.at("FutureFetchAmount"));
    res->FeePayFlag = boost::lexical_cast<char>(map.at("FeePayFlag"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    res->BrokerFee = boost::lexical_cast<double>(map.at("BrokerFee"));
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->TransferStatus = boost::lexical_cast<char>(map.at("TransferStatus"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqRepealField const &data);

template<>
class fromRedis<CThostFtdcReqRepealField> {
 public:
  std::unique_ptr<CThostFtdcReqRepealField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqRepealField>();

    res->RepealTimeInterval = boost::lexical_cast<int>(map.at("RepealTimeInterval"));
    res->RepealedTimes = boost::lexical_cast<int>(map.at("RepealedTimes"));
    res->BankRepealFlag = boost::lexical_cast<char>(map.at("BankRepealFlag"));
    res->BrokerRepealFlag = boost::lexical_cast<char>(map.at("BrokerRepealFlag"));
    res->PlateRepealSerial = boost::lexical_cast<int>(map.at("PlateRepealSerial"));
    strcpy(res->BankRepealSerial, map.at("BankRepealSerial").data());
    res->FutureRepealSerial = boost::lexical_cast<int>(map.at("FutureRepealSerial"));
    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    res->FutureFetchAmount = boost::lexical_cast<double>(map.at("FutureFetchAmount"));
    res->FeePayFlag = boost::lexical_cast<char>(map.at("FeePayFlag"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    res->BrokerFee = boost::lexical_cast<double>(map.at("BrokerFee"));
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->TransferStatus = boost::lexical_cast<char>(map.at("TransferStatus"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspRepealField const &data);

template<>
class fromRedis<CThostFtdcRspRepealField> {
 public:
  std::unique_ptr<CThostFtdcRspRepealField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspRepealField>();

    res->RepealTimeInterval = boost::lexical_cast<int>(map.at("RepealTimeInterval"));
    res->RepealedTimes = boost::lexical_cast<int>(map.at("RepealedTimes"));
    res->BankRepealFlag = boost::lexical_cast<char>(map.at("BankRepealFlag"));
    res->BrokerRepealFlag = boost::lexical_cast<char>(map.at("BrokerRepealFlag"));
    res->PlateRepealSerial = boost::lexical_cast<int>(map.at("PlateRepealSerial"));
    strcpy(res->BankRepealSerial, map.at("BankRepealSerial").data());
    res->FutureRepealSerial = boost::lexical_cast<int>(map.at("FutureRepealSerial"));
    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    res->FutureFetchAmount = boost::lexical_cast<double>(map.at("FutureFetchAmount"));
    res->FeePayFlag = boost::lexical_cast<char>(map.at("FeePayFlag"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    res->BrokerFee = boost::lexical_cast<double>(map.at("BrokerFee"));
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->TransferStatus = boost::lexical_cast<char>(map.at("TransferStatus"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqQueryAccountField const &data);

template<>
class fromRedis<CThostFtdcReqQueryAccountField> {
 public:
  std::unique_ptr<CThostFtdcReqQueryAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqQueryAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspQueryAccountField const &data);

template<>
class fromRedis<CThostFtdcRspQueryAccountField> {
 public:
  std::unique_ptr<CThostFtdcRspQueryAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspQueryAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->BankUseAmount = boost::lexical_cast<double>(map.at("BankUseAmount"));
    res->BankFetchAmount = boost::lexical_cast<double>(map.at("BankFetchAmount"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFutureSignIOField const &data);

template<>
class fromRedis<CThostFtdcFutureSignIOField> {
 public:
  std::unique_ptr<CThostFtdcFutureSignIOField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcFutureSignIOField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspFutureSignInField const &data);

template<>
class fromRedis<CThostFtdcRspFutureSignInField> {
 public:
  std::unique_ptr<CThostFtdcRspFutureSignInField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspFutureSignInField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    strcpy(res->PinKey, map.at("PinKey").data());
    strcpy(res->MacKey, map.at("MacKey").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqFutureSignOutField const &data);

template<>
class fromRedis<CThostFtdcReqFutureSignOutField> {
 public:
  std::unique_ptr<CThostFtdcReqFutureSignOutField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqFutureSignOutField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspFutureSignOutField const &data);

template<>
class fromRedis<CThostFtdcRspFutureSignOutField> {
 public:
  std::unique_ptr<CThostFtdcRspFutureSignOutField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspFutureSignOutField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqQueryTradeResultBySerialField const &data);

template<>
class fromRedis<CThostFtdcReqQueryTradeResultBySerialField> {
 public:
  std::unique_ptr<CThostFtdcReqQueryTradeResultBySerialField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqQueryTradeResultBySerialField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->Reference = boost::lexical_cast<int>(map.at("Reference"));
    res->RefrenceIssureType = boost::lexical_cast<char>(map.at("RefrenceIssureType"));
    strcpy(res->RefrenceIssure, map.at("RefrenceIssure").data());
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    strcpy(res->Digest, map.at("Digest").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspQueryTradeResultBySerialField const &data);

template<>
class fromRedis<CThostFtdcRspQueryTradeResultBySerialField> {
 public:
  std::unique_ptr<CThostFtdcRspQueryTradeResultBySerialField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspQueryTradeResultBySerialField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    res->Reference = boost::lexical_cast<int>(map.at("Reference"));
    res->RefrenceIssureType = boost::lexical_cast<char>(map.at("RefrenceIssureType"));
    strcpy(res->RefrenceIssure, map.at("RefrenceIssure").data());
    strcpy(res->OriginReturnCode, map.at("OriginReturnCode").data());
    strcpy(res->OriginDescrInfoForReturnCode, map.at("OriginDescrInfoForReturnCode").data());
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    strcpy(res->Digest, map.at("Digest").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqDayEndFileReadyField const &data);

template<>
class fromRedis<CThostFtdcReqDayEndFileReadyField> {
 public:
  std::unique_ptr<CThostFtdcReqDayEndFileReadyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqDayEndFileReadyField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->FileBusinessCode = boost::lexical_cast<char>(map.at("FileBusinessCode"));
    strcpy(res->Digest, map.at("Digest").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReturnResultField const &data);

template<>
class fromRedis<CThostFtdcReturnResultField> {
 public:
  std::unique_ptr<CThostFtdcReturnResultField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReturnResultField>();

    strcpy(res->ReturnCode, map.at("ReturnCode").data());
    strcpy(res->DescrInfoForReturnCode, map.at("DescrInfoForReturnCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyFuturePasswordField const &data);

template<>
class fromRedis<CThostFtdcVerifyFuturePasswordField> {
 public:
  std::unique_ptr<CThostFtdcVerifyFuturePasswordField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcVerifyFuturePasswordField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyCustInfoField const &data);

template<>
class fromRedis<CThostFtdcVerifyCustInfoField> {
 public:
  std::unique_ptr<CThostFtdcVerifyCustInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcVerifyCustInfoField>();

    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyFuturePasswordAndCustInfoField const &data);

template<>
class fromRedis<CThostFtdcVerifyFuturePasswordAndCustInfoField> {
 public:
  std::unique_ptr<CThostFtdcVerifyFuturePasswordAndCustInfoField> operator()(redis::Redis &cli,
                                                                             std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcVerifyFuturePasswordAndCustInfoField>();

    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDepositResultInformField const &data);

template<>
class fromRedis<CThostFtdcDepositResultInformField> {
 public:
  std::unique_ptr<CThostFtdcDepositResultInformField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcDepositResultInformField>();

    strcpy(res->DepositSeqNo, map.at("DepositSeqNo").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->Deposit = boost::lexical_cast<double>(map.at("Deposit"));
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    strcpy(res->ReturnCode, map.at("ReturnCode").data());
    strcpy(res->DescrInfoForReturnCode, map.at("DescrInfoForReturnCode").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqSyncKeyField const &data);

template<>
class fromRedis<CThostFtdcReqSyncKeyField> {
 public:
  std::unique_ptr<CThostFtdcReqSyncKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcReqSyncKeyField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspSyncKeyField const &data);

template<>
class fromRedis<CThostFtdcRspSyncKeyField> {
 public:
  std::unique_ptr<CThostFtdcRspSyncKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcRspSyncKeyField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyQueryAccountField const &data);

template<>
class fromRedis<CThostFtdcNotifyQueryAccountField> {
 public:
  std::unique_ptr<CThostFtdcNotifyQueryAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcNotifyQueryAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->BankUseAmount = boost::lexical_cast<double>(map.at("BankUseAmount"));
    res->BankFetchAmount = boost::lexical_cast<double>(map.at("BankFetchAmount"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferSerialField const &data);

template<>
class fromRedis<CThostFtdcTransferSerialField> {
 public:
  std::unique_ptr<CThostFtdcTransferSerialField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTransferSerialField>();

    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->TradeCode, map.at("TradeCode").data());
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    res->FutureAccType = boost::lexical_cast<char>(map.at("FutureAccType"));
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->InvestorID, map.at("InvestorID").data());
    res->FutureSerial = boost::lexical_cast<int>(map.at("FutureSerial"));
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->TradeAmount = boost::lexical_cast<double>(map.at("TradeAmount"));
    res->CustFee = boost::lexical_cast<double>(map.at("CustFee"));
    res->BrokerFee = boost::lexical_cast<double>(map.at("BrokerFee"));
    res->AvailabilityFlag = boost::lexical_cast<char>(map.at("AvailabilityFlag"));
    strcpy(res->OperatorCode, map.at("OperatorCode").data());
    strcpy(res->BankNewAccount, map.at("BankNewAccount").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTransferSerialField const &data);

template<>
class fromRedis<CThostFtdcQryTransferSerialField> {
 public:
  std::unique_ptr<CThostFtdcQryTransferSerialField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryTransferSerialField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyFutureSignInField const &data);

template<>
class fromRedis<CThostFtdcNotifyFutureSignInField> {
 public:
  std::unique_ptr<CThostFtdcNotifyFutureSignInField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcNotifyFutureSignInField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());
    strcpy(res->PinKey, map.at("PinKey").data());
    strcpy(res->MacKey, map.at("MacKey").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyFutureSignOutField const &data);

template<>
class fromRedis<CThostFtdcNotifyFutureSignOutField> {
 public:
  std::unique_ptr<CThostFtdcNotifyFutureSignOutField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcNotifyFutureSignOutField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Digest, map.at("Digest").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifySyncKeyField const &data);

template<>
class fromRedis<CThostFtdcNotifySyncKeyField> {
 public:
  std::unique_ptr<CThostFtdcNotifySyncKeyField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcNotifySyncKeyField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->Message, map.at("Message").data());
    strcpy(res->DeviceID, map.at("DeviceID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->OperNo, map.at("OperNo").data());
    res->RequestID = boost::lexical_cast<int>(map.at("RequestID"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryAccountregisterField const &data);

template<>
class fromRedis<CThostFtdcQryAccountregisterField> {
 public:
  std::unique_ptr<CThostFtdcQryAccountregisterField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryAccountregisterField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcAccountregisterField const &data);

template<>
class fromRedis<CThostFtdcAccountregisterField> {
 public:
  std::unique_ptr<CThostFtdcAccountregisterField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcAccountregisterField>();

    strcpy(res->TradeDay, map.at("TradeDay").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    strcpy(res->CustomerName, map.at("CustomerName").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->OpenOrDestroy = boost::lexical_cast<char>(map.at("OpenOrDestroy"));
    strcpy(res->RegDate, map.at("RegDate").data());
    strcpy(res->OutDate, map.at("OutDate").data());
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOpenAccountField const &data);

template<>
class fromRedis<CThostFtdcOpenAccountField> {
 public:
  std::unique_ptr<CThostFtdcOpenAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcOpenAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->CashExchangeCode = boost::lexical_cast<char>(map.at("CashExchangeCode"));
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->UserID, map.at("UserID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCancelAccountField const &data);

template<>
class fromRedis<CThostFtdcCancelAccountField> {
 public:
  std::unique_ptr<CThostFtdcCancelAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCancelAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    res->CashExchangeCode = boost::lexical_cast<char>(map.at("CashExchangeCode"));
    strcpy(res->Digest, map.at("Digest").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    strcpy(res->DeviceID, map.at("DeviceID").data());
    res->BankSecuAccType = boost::lexical_cast<char>(map.at("BankSecuAccType"));
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    strcpy(res->BankSecuAcc, map.at("BankSecuAcc").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    strcpy(res->OperNo, map.at("OperNo").data());
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->UserID, map.at("UserID").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcChangeAccountField const &data);

template<>
class fromRedis<CThostFtdcChangeAccountField> {
 public:
  std::unique_ptr<CThostFtdcChangeAccountField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcChangeAccountField>();

    strcpy(res->TradeCode, map.at("TradeCode").data());
    strcpy(res->BankID, map.at("BankID").data());
    strcpy(res->BankBranchID, map.at("BankBranchID").data());
    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->BrokerBranchID, map.at("BrokerBranchID").data());
    strcpy(res->TradeDate, map.at("TradeDate").data());
    strcpy(res->TradeTime, map.at("TradeTime").data());
    strcpy(res->BankSerial, map.at("BankSerial").data());
    strcpy(res->TradingDay, map.at("TradingDay").data());
    res->PlateSerial = boost::lexical_cast<int>(map.at("PlateSerial"));
    res->LastFragment = boost::lexical_cast<char>(map.at("LastFragment"));
    res->SessionID = boost::lexical_cast<int>(map.at("SessionID"));
    strcpy(res->CustomerName, map.at("CustomerName").data());
    res->IdCardType = boost::lexical_cast<char>(map.at("IdCardType"));
    strcpy(res->IdentifiedCardNo, map.at("IdentifiedCardNo").data());
    res->Gender = boost::lexical_cast<char>(map.at("Gender"));
    strcpy(res->CountryCode, map.at("CountryCode").data());
    res->CustType = boost::lexical_cast<char>(map.at("CustType"));
    strcpy(res->Address, map.at("Address").data());
    strcpy(res->ZipCode, map.at("ZipCode").data());
    strcpy(res->Telephone, map.at("Telephone").data());
    strcpy(res->MobilePhone, map.at("MobilePhone").data());
    strcpy(res->Fax, map.at("Fax").data());
    strcpy(res->EMail, map.at("EMail").data());
    res->MoneyAccountStatus = boost::lexical_cast<char>(map.at("MoneyAccountStatus"));
    strcpy(res->BankAccount, map.at("BankAccount").data());
    strcpy(res->BankPassWord, map.at("BankPassWord").data());
    strcpy(res->NewBankAccount, map.at("NewBankAccount").data());
    strcpy(res->NewBankPassWord, map.at("NewBankPassWord").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->Password, map.at("Password").data());
    res->BankAccType = boost::lexical_cast<char>(map.at("BankAccType"));
    res->InstallID = boost::lexical_cast<int>(map.at("InstallID"));
    res->VerifyCertNoFlag = boost::lexical_cast<char>(map.at("VerifyCertNoFlag"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->BrokerIDByBank, map.at("BrokerIDByBank").data());
    res->BankPwdFlag = boost::lexical_cast<char>(map.at("BankPwdFlag"));
    res->SecuPwdFlag = boost::lexical_cast<char>(map.at("SecuPwdFlag"));
    res->TID = boost::lexical_cast<int>(map.at("TID"));
    strcpy(res->Digest, map.at("Digest").data());
    res->ErrorID = boost::lexical_cast<int>(map.at("ErrorID"));
    strcpy(res->ErrorMsg, map.at("ErrorMsg").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSecAgentACIDMapField const &data);

template<>
class fromRedis<CThostFtdcSecAgentACIDMapField> {
 public:
  std::unique_ptr<CThostFtdcSecAgentACIDMapField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcSecAgentACIDMapField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());
    strcpy(res->BrokerSecAgentID, map.at("BrokerSecAgentID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySecAgentACIDMapField const &data);

template<>
class fromRedis<CThostFtdcQrySecAgentACIDMapField> {
 public:
  std::unique_ptr<CThostFtdcQrySecAgentACIDMapField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQrySecAgentACIDMapField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserRightsAssignField const &data);

template<>
class fromRedis<CThostFtdcUserRightsAssignField> {
 public:
  std::unique_ptr<CThostFtdcUserRightsAssignField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcUserRightsAssignField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->DRIdentityID = boost::lexical_cast<int>(map.at("DRIdentityID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserRightAssignField const &data);

template<>
class fromRedis<CThostFtdcBrokerUserRightAssignField> {
 public:
  std::unique_ptr<CThostFtdcBrokerUserRightAssignField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcBrokerUserRightAssignField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    res->DRIdentityID = boost::lexical_cast<int>(map.at("DRIdentityID"));
    res->Tradeable = boost::lexical_cast<int>(map.at("Tradeable"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDRTransferField const &data);

template<>
class fromRedis<CThostFtdcDRTransferField> {
 public:
  std::unique_ptr<CThostFtdcDRTransferField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcDRTransferField>();

    res->OrigDRIdentityID = boost::lexical_cast<int>(map.at("OrigDRIdentityID"));
    res->DestDRIdentityID = boost::lexical_cast<int>(map.at("DestDRIdentityID"));
    strcpy(res->OrigBrokerID, map.at("OrigBrokerID").data());
    strcpy(res->DestBrokerID, map.at("DestBrokerID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFensUserInfoField const &data);

template<>
class fromRedis<CThostFtdcFensUserInfoField> {
 public:
  std::unique_ptr<CThostFtdcFensUserInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcFensUserInfoField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());
    res->LoginMode = boost::lexical_cast<char>(map.at("LoginMode"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCurrTransferIdentityField const &data);

template<>
class fromRedis<CThostFtdcCurrTransferIdentityField> {
 public:
  std::unique_ptr<CThostFtdcCurrTransferIdentityField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcCurrTransferIdentityField>();

    res->IdentityID = boost::lexical_cast<int>(map.at("IdentityID"));

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoginForbiddenUserField const &data);

template<>
class fromRedis<CThostFtdcLoginForbiddenUserField> {
 public:
  std::unique_ptr<CThostFtdcLoginForbiddenUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcLoginForbiddenUserField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryLoginForbiddenUserField const &data);

template<>
class fromRedis<CThostFtdcQryLoginForbiddenUserField> {
 public:
  std::unique_ptr<CThostFtdcQryLoginForbiddenUserField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcQryLoginForbiddenUserField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->UserID, map.at("UserID").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMulticastGroupInfoField const &data);

template<>
class fromRedis<CThostFtdcMulticastGroupInfoField> {
 public:
  std::unique_ptr<CThostFtdcMulticastGroupInfoField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcMulticastGroupInfoField>();

    strcpy(res->GroupIP, map.at("GroupIP").data());
    res->GroupPort = boost::lexical_cast<int>(map.at("GroupPort"));
    strcpy(res->SourceIP, map.at("SourceIP").data());

    return res;
  }
};

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountReserveField const &data);

template<>
class fromRedis<CThostFtdcTradingAccountReserveField> {
 public:
  std::unique_ptr<CThostFtdcTradingAccountReserveField> operator()(redis::Redis &cli, std::string const &path) {
    auto map = cli.HGETALL(path);

    auto res = std::make_unique<CThostFtdcTradingAccountReserveField>();

    strcpy(res->BrokerID, map.at("BrokerID").data());
    strcpy(res->AccountID, map.at("AccountID").data());
    res->Reserve = boost::lexical_cast<double>(map.at("Reserve"));
    strcpy(res->CurrencyID, map.at("CurrencyID").data());

    return res;
  }
};

/*
 * Auto code end here
 * */

}

#endif //CTP_STORAGE_REDIS_UTILS_H_

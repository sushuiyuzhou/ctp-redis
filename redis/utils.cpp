//
// Created by colin on 8/9/2019.
//

#include "utils.h"

namespace storage {

namespace {

inline std::string toStr(const char *ptr) {
  return std::string(ptr);
}

inline std::string toStr(TThostFtdcPriceType price) {
  // ctp returns big value for non-price
  if (price && price > 0 && price < 1e10) {
    return std::to_string(price);
  }
  return std::to_string(0.0);
}

template<typename T>
inline std::string toStr(T t) {
  return std::to_string(t);
}

} // helper for toRedis methods

/*
 * Auto generated code start
 * */

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDisseminationField const &data) {
  std::map<std::string, std::string> map;

  map["SequenceSeries"] = toStr(data.SequenceSeries);
  map["SequenceNo"] = toStr(data.SequenceNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqUserLoginField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["Password"] = toStr(data.Password);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["InterfaceProductInfo"] = toStr(data.InterfaceProductInfo);
  map["ProtocolInfo"] = toStr(data.ProtocolInfo);
  map["MacAddress"] = toStr(data.MacAddress);
  map["OneTimePassword"] = toStr(data.OneTimePassword);
  map["ClientIPAddress"] = toStr(data.ClientIPAddress);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspUserLoginField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["LoginTime"] = toStr(data.LoginTime);
  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["SystemName"] = toStr(data.SystemName);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["MaxOrderRef"] = toStr(data.MaxOrderRef);
  map["SHFETime"] = toStr(data.SHFETime);
  map["DCETime"] = toStr(data.DCETime);
  map["CZCETime"] = toStr(data.CZCETime);
  map["FFEXTime"] = toStr(data.FFEXTime);
  map["INETime"] = toStr(data.INETime);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserLogoutField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForceUserLogoutField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqAuthenticateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["AuthCode"] = toStr(data.AuthCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspAuthenticateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcAuthenticationInfoField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["AuthInfo"] = toStr(data.AuthInfo);
  map["IsResult"] = toStr(data.IsResult);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferHeaderField const &data) {
  std::map<std::string, std::string> map;

  map["Version"] = toStr(data.Version);
  map["TradeCode"] = toStr(data.TradeCode);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["TradeSerial"] = toStr(data.TradeSerial);
  map["FutureID"] = toStr(data.FutureID);
  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);
  map["OperNo"] = toStr(data.OperNo);
  map["DeviceID"] = toStr(data.DeviceID);
  map["RecordNum"] = toStr(data.RecordNum);
  map["SessionID"] = toStr(data.SessionID);
  map["RequestID"] = toStr(data.RequestID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankToFutureReqField const &data) {
  std::map<std::string, std::string> map;

  map["FutureAccount"] = toStr(data.FutureAccount);
  map["FuturePwdFlag"] = toStr(data.FuturePwdFlag);
  map["FutureAccPwd"] = toStr(data.FutureAccPwd);
  map["TradeAmt"] = toStr(data.TradeAmt);
  map["CustFee"] = toStr(data.CustFee);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankToFutureRspField const &data) {
  std::map<std::string, std::string> map;

  map["RetCode"] = toStr(data.RetCode);
  map["RetInfo"] = toStr(data.RetInfo);
  map["FutureAccount"] = toStr(data.FutureAccount);
  map["TradeAmt"] = toStr(data.TradeAmt);
  map["CustFee"] = toStr(data.CustFee);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferFutureToBankReqField const &data) {
  std::map<std::string, std::string> map;

  map["FutureAccount"] = toStr(data.FutureAccount);
  map["FuturePwdFlag"] = toStr(data.FuturePwdFlag);
  map["FutureAccPwd"] = toStr(data.FutureAccPwd);
  map["TradeAmt"] = toStr(data.TradeAmt);
  map["CustFee"] = toStr(data.CustFee);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferFutureToBankRspField const &data) {
  std::map<std::string, std::string> map;

  map["RetCode"] = toStr(data.RetCode);
  map["RetInfo"] = toStr(data.RetInfo);
  map["FutureAccount"] = toStr(data.FutureAccount);
  map["TradeAmt"] = toStr(data.TradeAmt);
  map["CustFee"] = toStr(data.CustFee);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryBankReqField const &data) {
  std::map<std::string, std::string> map;

  map["FutureAccount"] = toStr(data.FutureAccount);
  map["FuturePwdFlag"] = toStr(data.FuturePwdFlag);
  map["FutureAccPwd"] = toStr(data.FutureAccPwd);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryBankRspField const &data) {
  std::map<std::string, std::string> map;

  map["RetCode"] = toStr(data.RetCode);
  map["RetInfo"] = toStr(data.RetInfo);
  map["FutureAccount"] = toStr(data.FutureAccount);
  map["TradeAmt"] = toStr(data.TradeAmt);
  map["UseAmt"] = toStr(data.UseAmt);
  map["FetchAmt"] = toStr(data.FetchAmt);
  map["CurrencyCode"] = toStr(data.CurrencyCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryDetailReqField const &data) {
  std::map<std::string, std::string> map;

  map["FutureAccount"] = toStr(data.FutureAccount);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferQryDetailRspField const &data) {
  std::map<std::string, std::string> map;

  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["TradeCode"] = toStr(data.TradeCode);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["FutureID"] = toStr(data.FutureID);
  map["FutureAccount"] = toStr(data.FutureAccount);
  map["BankSerial"] = toStr(data.BankSerial);
  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);
  map["BankAccount"] = toStr(data.BankAccount);
  map["CertCode"] = toStr(data.CertCode);
  map["CurrencyCode"] = toStr(data.CurrencyCode);
  map["TxAmount"] = toStr(data.TxAmount);
  map["Flag"] = toStr(data.Flag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspInfoField const &data) {
  std::map<std::string, std::string> map;

  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeName"] = toStr(data.ExchangeName);
  map["ExchangeProperty"] = toStr(data.ExchangeProperty);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcProductField const &data) {
  std::map<std::string, std::string> map;

  map["ProductID"] = toStr(data.ProductID);
  map["ProductName"] = toStr(data.ProductName);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ProductClass"] = toStr(data.ProductClass);
  map["VolumeMultiple"] = toStr(data.VolumeMultiple);
  map["PriceTick"] = toStr(data.PriceTick);
  map["MaxMarketOrderVolume"] = toStr(data.MaxMarketOrderVolume);
  map["MinMarketOrderVolume"] = toStr(data.MinMarketOrderVolume);
  map["MaxLimitOrderVolume"] = toStr(data.MaxLimitOrderVolume);
  map["MinLimitOrderVolume"] = toStr(data.MinLimitOrderVolume);
  map["PositionType"] = toStr(data.PositionType);
  map["PositionDateType"] = toStr(data.PositionDateType);
  map["CloseDealType"] = toStr(data.CloseDealType);
  map["TradeCurrencyID"] = toStr(data.TradeCurrencyID);
  map["MortgageFundUseRange"] = toStr(data.MortgageFundUseRange);
  map["ExchangeProductID"] = toStr(data.ExchangeProductID);
  map["UnderlyingMultiple"] = toStr(data.UnderlyingMultiple);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InstrumentName"] = toStr(data.InstrumentName);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ProductID"] = toStr(data.ProductID);
  map["ProductClass"] = toStr(data.ProductClass);
  map["DeliveryYear"] = toStr(data.DeliveryYear);
  map["DeliveryMonth"] = toStr(data.DeliveryMonth);
  map["MaxMarketOrderVolume"] = toStr(data.MaxMarketOrderVolume);
  map["MinMarketOrderVolume"] = toStr(data.MinMarketOrderVolume);
  map["MaxLimitOrderVolume"] = toStr(data.MaxLimitOrderVolume);
  map["MinLimitOrderVolume"] = toStr(data.MinLimitOrderVolume);
  map["VolumeMultiple"] = toStr(data.VolumeMultiple);
  map["PriceTick"] = toStr(data.PriceTick);
  map["CreateDate"] = toStr(data.CreateDate);
  map["OpenDate"] = toStr(data.OpenDate);
  map["ExpireDate"] = toStr(data.ExpireDate);
  map["StartDelivDate"] = toStr(data.StartDelivDate);
  map["EndDelivDate"] = toStr(data.EndDelivDate);
  map["InstLifePhase"] = toStr(data.InstLifePhase);
  map["IsTrading"] = toStr(data.IsTrading);
  map["PositionType"] = toStr(data.PositionType);
  map["PositionDateType"] = toStr(data.PositionDateType);
  map["LongMarginRatio"] = toStr(data.LongMarginRatio);
  map["ShortMarginRatio"] = toStr(data.ShortMarginRatio);
  map["MaxMarginSideAlgorithm"] = toStr(data.MaxMarginSideAlgorithm);
  map["UnderlyingInstrID"] = toStr(data.UnderlyingInstrID);
  map["StrikePrice"] = toStr(data.StrikePrice);
  map["OptionsType"] = toStr(data.OptionsType);
  map["UnderlyingMultiple"] = toStr(data.UnderlyingMultiple);
  map["CombinationType"] = toStr(data.CombinationType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerAbbr"] = toStr(data.BrokerAbbr);
  map["BrokerName"] = toStr(data.BrokerName);
  map["IsActive"] = toStr(data.IsActive);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTraderField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["Password"] = toStr(data.Password);
  map["InstallCount"] = toStr(data.InstallCount);
  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorField const &data) {
  std::map<std::string, std::string> map;

  map["InvestorID"] = toStr(data.InvestorID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorGroupID"] = toStr(data.InvestorGroupID);
  map["InvestorName"] = toStr(data.InvestorName);
  map["IdentifiedCardType"] = toStr(data.IdentifiedCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["IsActive"] = toStr(data.IsActive);
  map["Telephone"] = toStr(data.Telephone);
  map["Address"] = toStr(data.Address);
  map["OpenDate"] = toStr(data.OpenDate);
  map["Mobile"] = toStr(data.Mobile);
  map["CommModelID"] = toStr(data.CommModelID);
  map["MarginModelID"] = toStr(data.MarginModelID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingCodeField const &data) {
  std::map<std::string, std::string> map;

  map["InvestorID"] = toStr(data.InvestorID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ClientID"] = toStr(data.ClientID);
  map["IsActive"] = toStr(data.IsActive);
  map["ClientIDType"] = toStr(data.ClientIDType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcPartBrokerField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["IsActive"] = toStr(data.IsActive);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSuperUserField const &data) {
  std::map<std::string, std::string> map;

  map["UserID"] = toStr(data.UserID);
  map["UserName"] = toStr(data.UserName);
  map["Password"] = toStr(data.Password);
  map["IsActive"] = toStr(data.IsActive);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSuperUserFunctionField const &data) {
  std::map<std::string, std::string> map;

  map["UserID"] = toStr(data.UserID);
  map["FunctionCode"] = toStr(data.FunctionCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorGroupField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorGroupID"] = toStr(data.InvestorGroupID);
  map["InvestorGroupName"] = toStr(data.InvestorGroupName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["PreMortgage"] = toStr(data.PreMortgage);
  map["PreCredit"] = toStr(data.PreCredit);
  map["PreDeposit"] = toStr(data.PreDeposit);
  map["PreBalance"] = toStr(data.PreBalance);
  map["PreMargin"] = toStr(data.PreMargin);
  map["InterestBase"] = toStr(data.InterestBase);
  map["Interest"] = toStr(data.Interest);
  map["Deposit"] = toStr(data.Deposit);
  map["Withdraw"] = toStr(data.Withdraw);
  map["FrozenMargin"] = toStr(data.FrozenMargin);
  map["FrozenCash"] = toStr(data.FrozenCash);
  map["FrozenCommission"] = toStr(data.FrozenCommission);
  map["CurrMargin"] = toStr(data.CurrMargin);
  map["CashIn"] = toStr(data.CashIn);
  map["Commission"] = toStr(data.Commission);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["PositionProfit"] = toStr(data.PositionProfit);
  map["Balance"] = toStr(data.Balance);
  map["Available"] = toStr(data.Available);
  map["WithdrawQuota"] = toStr(data.WithdrawQuota);
  map["Reserve"] = toStr(data.Reserve);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["Credit"] = toStr(data.Credit);
  map["Mortgage"] = toStr(data.Mortgage);
  map["ExchangeMargin"] = toStr(data.ExchangeMargin);
  map["DeliveryMargin"] = toStr(data.DeliveryMargin);
  map["ExchangeDeliveryMargin"] = toStr(data.ExchangeDeliveryMargin);
  map["ReserveBalance"] = toStr(data.ReserveBalance);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["PreFundMortgageIn"] = toStr(data.PreFundMortgageIn);
  map["PreFundMortgageOut"] = toStr(data.PreFundMortgageOut);
  map["FundMortgageIn"] = toStr(data.FundMortgageIn);
  map["FundMortgageOut"] = toStr(data.FundMortgageOut);
  map["FundMortgageAvailable"] = toStr(data.FundMortgageAvailable);
  map["MortgageableFund"] = toStr(data.MortgageableFund);
  map["SpecProductMargin"] = toStr(data.SpecProductMargin);
  map["SpecProductFrozenMargin"] = toStr(data.SpecProductFrozenMargin);
  map["SpecProductCommission"] = toStr(data.SpecProductCommission);
  map["SpecProductFrozenCommission"] = toStr(data.SpecProductFrozenCommission);
  map["SpecProductPositionProfit"] = toStr(data.SpecProductPositionProfit);
  map["SpecProductCloseProfit"] = toStr(data.SpecProductCloseProfit);
  map["SpecProductPositionProfitByAlg"] = toStr(data.SpecProductPositionProfitByAlg);
  map["SpecProductExchangeMargin"] = toStr(data.SpecProductExchangeMargin);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["PositionDate"] = toStr(data.PositionDate);
  map["YdPosition"] = toStr(data.YdPosition);
  map["Position"] = toStr(data.Position);
  map["LongFrozen"] = toStr(data.LongFrozen);
  map["ShortFrozen"] = toStr(data.ShortFrozen);
  map["LongFrozenAmount"] = toStr(data.LongFrozenAmount);
  map["ShortFrozenAmount"] = toStr(data.ShortFrozenAmount);
  map["OpenVolume"] = toStr(data.OpenVolume);
  map["CloseVolume"] = toStr(data.CloseVolume);
  map["OpenAmount"] = toStr(data.OpenAmount);
  map["CloseAmount"] = toStr(data.CloseAmount);
  map["PositionCost"] = toStr(data.PositionCost);
  map["PreMargin"] = toStr(data.PreMargin);
  map["UseMargin"] = toStr(data.UseMargin);
  map["FrozenMargin"] = toStr(data.FrozenMargin);
  map["FrozenCash"] = toStr(data.FrozenCash);
  map["FrozenCommission"] = toStr(data.FrozenCommission);
  map["CashIn"] = toStr(data.CashIn);
  map["Commission"] = toStr(data.Commission);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["PositionProfit"] = toStr(data.PositionProfit);
  map["PreSettlementPrice"] = toStr(data.PreSettlementPrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["OpenCost"] = toStr(data.OpenCost);
  map["ExchangeMargin"] = toStr(data.ExchangeMargin);
  map["CombPosition"] = toStr(data.CombPosition);
  map["CombLongFrozen"] = toStr(data.CombLongFrozen);
  map["CombShortFrozen"] = toStr(data.CombShortFrozen);
  map["CloseProfitByDate"] = toStr(data.CloseProfitByDate);
  map["CloseProfitByTrade"] = toStr(data.CloseProfitByTrade);
  map["TodayPosition"] = toStr(data.TodayPosition);
  map["MarginRateByMoney"] = toStr(data.MarginRateByMoney);
  map["MarginRateByVolume"] = toStr(data.MarginRateByVolume);
  map["StrikeFrozen"] = toStr(data.StrikeFrozen);
  map["StrikeFrozenAmount"] = toStr(data.StrikeFrozenAmount);
  map["AbandonFrozen"] = toStr(data.AbandonFrozen);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentMarginRateField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["LongMarginRatioByMoney"] = toStr(data.LongMarginRatioByMoney);
  map["LongMarginRatioByVolume"] = toStr(data.LongMarginRatioByVolume);
  map["ShortMarginRatioByMoney"] = toStr(data.ShortMarginRatioByMoney);
  map["ShortMarginRatioByVolume"] = toStr(data.ShortMarginRatioByVolume);
  map["IsRelative"] = toStr(data.IsRelative);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentCommissionRateField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OpenRatioByMoney"] = toStr(data.OpenRatioByMoney);
  map["OpenRatioByVolume"] = toStr(data.OpenRatioByVolume);
  map["CloseRatioByMoney"] = toStr(data.CloseRatioByMoney);
  map["CloseRatioByVolume"] = toStr(data.CloseRatioByVolume);
  map["CloseTodayRatioByMoney"] = toStr(data.CloseTodayRatioByMoney);
  map["CloseTodayRatioByVolume"] = toStr(data.CloseTodayRatioByVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDepthMarketDataField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["LastPrice"] = toStr(data.LastPrice);
  map["PreSettlementPrice"] = toStr(data.PreSettlementPrice);
  map["PreClosePrice"] = toStr(data.PreClosePrice);
  map["PreOpenInterest"] = toStr(data.PreOpenInterest);
  map["OpenPrice"] = toStr(data.OpenPrice);
  map["HighestPrice"] = toStr(data.HighestPrice);
  map["LowestPrice"] = toStr(data.LowestPrice);
  map["Volume"] = toStr(data.Volume);
  map["Turnover"] = toStr(data.Turnover);
  map["OpenInterest"] = toStr(data.OpenInterest);
  map["ClosePrice"] = toStr(data.ClosePrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["UpperLimitPrice"] = toStr(data.UpperLimitPrice);
  map["LowerLimitPrice"] = toStr(data.LowerLimitPrice);
  map["PreDelta"] = toStr(data.PreDelta);
  map["CurrDelta"] = toStr(data.CurrDelta);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["UpdateMillisec"] = toStr(data.UpdateMillisec);
  map["BidPrice1"] = toStr(data.BidPrice1);
  map["BidVolume1"] = toStr(data.BidVolume1);
  map["AskPrice1"] = toStr(data.AskPrice1);
  map["AskVolume1"] = toStr(data.AskVolume1);
  map["BidPrice2"] = toStr(data.BidPrice2);
  map["BidVolume2"] = toStr(data.BidVolume2);
  map["AskPrice2"] = toStr(data.AskPrice2);
  map["AskVolume2"] = toStr(data.AskVolume2);
  map["BidPrice3"] = toStr(data.BidPrice3);
  map["BidVolume3"] = toStr(data.BidVolume3);
  map["AskPrice3"] = toStr(data.AskPrice3);
  map["AskVolume3"] = toStr(data.AskVolume3);
  map["BidPrice4"] = toStr(data.BidPrice4);
  map["BidVolume4"] = toStr(data.BidVolume4);
  map["AskPrice4"] = toStr(data.AskPrice4);
  map["AskVolume4"] = toStr(data.AskVolume4);
  map["BidPrice5"] = toStr(data.BidPrice5);
  map["BidVolume5"] = toStr(data.BidVolume5);
  map["AskPrice5"] = toStr(data.AskPrice5);
  map["AskVolume5"] = toStr(data.AskVolume5);
  map["AveragePrice"] = toStr(data.AveragePrice);
  map["ActionDay"] = toStr(data.ActionDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentTradingRightField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["TradingRight"] = toStr(data.TradingRight);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserName"] = toStr(data.UserName);
  map["UserType"] = toStr(data.UserType);
  map["IsActive"] = toStr(data.IsActive);
  map["IsUsingOTP"] = toStr(data.IsUsingOTP);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserPasswordField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["Password"] = toStr(data.Password);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserFunctionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["BrokerFunctionCode"] = toStr(data.BrokerFunctionCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTraderOfferField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["TraderConnectStatus"] = toStr(data.TraderConnectStatus);
  map["ConnectRequestDate"] = toStr(data.ConnectRequestDate);
  map["ConnectRequestTime"] = toStr(data.ConnectRequestTime);
  map["LastReportDate"] = toStr(data.LastReportDate);
  map["LastReportTime"] = toStr(data.LastReportTime);
  map["ConnectDate"] = toStr(data.ConnectDate);
  map["ConnectTime"] = toStr(data.ConnectTime);
  map["StartDate"] = toStr(data.StartDate);
  map["StartTime"] = toStr(data.StartTime);
  map["TradingDay"] = toStr(data.TradingDay);
  map["BrokerID"] = toStr(data.BrokerID);
  map["MaxTradeID"] = toStr(data.MaxTradeID);
  map["MaxOrderMessageReference"] = toStr(data.MaxOrderMessageReference);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementInfoField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["Content"] = toStr(data.Content);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentMarginRateAdjustField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["LongMarginRatioByMoney"] = toStr(data.LongMarginRatioByMoney);
  map["LongMarginRatioByVolume"] = toStr(data.LongMarginRatioByVolume);
  map["ShortMarginRatioByMoney"] = toStr(data.ShortMarginRatioByMoney);
  map["ShortMarginRatioByVolume"] = toStr(data.ShortMarginRatioByVolume);
  map["IsRelative"] = toStr(data.IsRelative);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeMarginRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["LongMarginRatioByMoney"] = toStr(data.LongMarginRatioByMoney);
  map["LongMarginRatioByVolume"] = toStr(data.LongMarginRatioByVolume);
  map["ShortMarginRatioByMoney"] = toStr(data.ShortMarginRatioByMoney);
  map["ShortMarginRatioByVolume"] = toStr(data.ShortMarginRatioByVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeMarginRateAdjustField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["LongMarginRatioByMoney"] = toStr(data.LongMarginRatioByMoney);
  map["LongMarginRatioByVolume"] = toStr(data.LongMarginRatioByVolume);
  map["ShortMarginRatioByMoney"] = toStr(data.ShortMarginRatioByMoney);
  map["ShortMarginRatioByVolume"] = toStr(data.ShortMarginRatioByVolume);
  map["ExchLongMarginRatioByMoney"] = toStr(data.ExchLongMarginRatioByMoney);
  map["ExchLongMarginRatioByVolume"] = toStr(data.ExchLongMarginRatioByVolume);
  map["ExchShortMarginRatioByMoney"] = toStr(data.ExchShortMarginRatioByMoney);
  map["ExchShortMarginRatioByVolume"] = toStr(data.ExchShortMarginRatioByVolume);
  map["NoLongMarginRatioByMoney"] = toStr(data.NoLongMarginRatioByMoney);
  map["NoLongMarginRatioByVolume"] = toStr(data.NoLongMarginRatioByVolume);
  map["NoShortMarginRatioByMoney"] = toStr(data.NoShortMarginRatioByMoney);
  map["NoShortMarginRatioByVolume"] = toStr(data.NoShortMarginRatioByVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["FromCurrencyID"] = toStr(data.FromCurrencyID);
  map["FromCurrencyUnit"] = toStr(data.FromCurrencyUnit);
  map["ToCurrencyID"] = toStr(data.ToCurrencyID);
  map["ExchangeRate"] = toStr(data.ExchangeRate);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementRefField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCurrentTimeField const &data) {
  std::map<std::string, std::string> map;

  map["CurrDate"] = toStr(data.CurrDate);
  map["CurrTime"] = toStr(data.CurrTime);
  map["CurrMillisec"] = toStr(data.CurrMillisec);
  map["ActionDay"] = toStr(data.ActionDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCommPhaseField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["CommPhaseNo"] = toStr(data.CommPhaseNo);
  map["SystemID"] = toStr(data.SystemID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoginInfoField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["LoginDate"] = toStr(data.LoginDate);
  map["LoginTime"] = toStr(data.LoginTime);
  map["IPAddress"] = toStr(data.IPAddress);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["InterfaceProductInfo"] = toStr(data.InterfaceProductInfo);
  map["ProtocolInfo"] = toStr(data.ProtocolInfo);
  map["SystemName"] = toStr(data.SystemName);
  map["Password"] = toStr(data.Password);
  map["MaxOrderRef"] = toStr(data.MaxOrderRef);
  map["SHFETime"] = toStr(data.SHFETime);
  map["DCETime"] = toStr(data.DCETime);
  map["CZCETime"] = toStr(data.CZCETime);
  map["FFEXTime"] = toStr(data.FFEXTime);
  map["MacAddress"] = toStr(data.MacAddress);
  map["OneTimePassword"] = toStr(data.OneTimePassword);
  map["INETime"] = toStr(data.INETime);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLogoutAllField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["SystemName"] = toStr(data.SystemName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFrontStatusField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);
  map["LastReportDate"] = toStr(data.LastReportDate);
  map["LastReportTime"] = toStr(data.LastReportTime);
  map["IsActive"] = toStr(data.IsActive);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserPasswordUpdateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["OldPassword"] = toStr(data.OldPassword);
  map["NewPassword"] = toStr(data.NewPassword);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["UserForceClose"] = toStr(data.UserForceClose);
  map["IsSwapOrder"] = toStr(data.IsSwapOrder);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["OrderSource"] = toStr(data.OrderSource);
  map["OrderStatus"] = toStr(data.OrderStatus);
  map["OrderType"] = toStr(data.OrderType);
  map["VolumeTraded"] = toStr(data.VolumeTraded);
  map["VolumeTotal"] = toStr(data.VolumeTotal);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["ActiveTime"] = toStr(data.ActiveTime);
  map["SuspendTime"] = toStr(data.SuspendTime);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["ActiveTraderID"] = toStr(data.ActiveTraderID);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["UserForceClose"] = toStr(data.UserForceClose);
  map["ActiveUserID"] = toStr(data.ActiveUserID);
  map["BrokerOrderSeq"] = toStr(data.BrokerOrderSeq);
  map["RelativeOrderSysID"] = toStr(data.RelativeOrderSysID);
  map["ZCETotalTradedVolume"] = toStr(data.ZCETotalTradedVolume);
  map["IsSwapOrder"] = toStr(data.IsSwapOrder);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderField const &data) {
  std::map<std::string, std::string> map;

  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["OrderSource"] = toStr(data.OrderSource);
  map["OrderStatus"] = toStr(data.OrderStatus);
  map["OrderType"] = toStr(data.OrderType);
  map["VolumeTraded"] = toStr(data.VolumeTraded);
  map["VolumeTotal"] = toStr(data.VolumeTotal);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["ActiveTime"] = toStr(data.ActiveTime);
  map["SuspendTime"] = toStr(data.SuspendTime);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["ActiveTraderID"] = toStr(data.ActiveTraderID);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderInsertErrorField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OrderActionRef"] = toStr(data.OrderActionRef);
  map["OrderRef"] = toStr(data.OrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeChange"] = toStr(data.VolumeChange);
  map["UserID"] = toStr(data.UserID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OrderActionRef"] = toStr(data.OrderActionRef);
  map["OrderRef"] = toStr(data.OrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeChange"] = toStr(data.VolumeChange);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeChange"] = toStr(data.VolumeChange);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeOrderActionErrorField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeTradeField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TradeID"] = toStr(data.TradeID);
  map["Direction"] = toStr(data.Direction);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["TradingRole"] = toStr(data.TradingRole);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["Price"] = toStr(data.Price);
  map["Volume"] = toStr(data.Volume);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["TradeType"] = toStr(data.TradeType);
  map["PriceSource"] = toStr(data.PriceSource);
  map["TraderID"] = toStr(data.TraderID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["TradeSource"] = toStr(data.TradeSource);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TradeID"] = toStr(data.TradeID);
  map["Direction"] = toStr(data.Direction);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["TradingRole"] = toStr(data.TradingRole);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["Price"] = toStr(data.Price);
  map["Volume"] = toStr(data.Volume);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["TradeType"] = toStr(data.TradeType);
  map["PriceSource"] = toStr(data.PriceSource);
  map["TraderID"] = toStr(data.TraderID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["BrokerOrderSeq"] = toStr(data.BrokerOrderSeq);
  map["TradeSource"] = toStr(data.TradeSource);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserSessionField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["LoginDate"] = toStr(data.LoginDate);
  map["LoginTime"] = toStr(data.LoginTime);
  map["IPAddress"] = toStr(data.IPAddress);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["InterfaceProductInfo"] = toStr(data.InterfaceProductInfo);
  map["ProtocolInfo"] = toStr(data.ProtocolInfo);
  map["MacAddress"] = toStr(data.MacAddress);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryMaxOrderVolumeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["Direction"] = toStr(data.Direction);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["MaxVolume"] = toStr(data.MaxVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSettlementInfoConfirmField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ConfirmDate"] = toStr(data.ConfirmDate);
  map["ConfirmTime"] = toStr(data.ConfirmTime);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncDepositField const &data) {
  std::map<std::string, std::string> map;

  map["DepositSeqNo"] = toStr(data.DepositSeqNo);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Deposit"] = toStr(data.Deposit);
  map["IsForce"] = toStr(data.IsForce);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncFundMortgageField const &data) {
  std::map<std::string, std::string> map;

  map["MortgageSeqNo"] = toStr(data.MortgageSeqNo);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["FromCurrencyID"] = toStr(data.FromCurrencyID);
  map["MortgageAmount"] = toStr(data.MortgageAmount);
  map["ToCurrencyID"] = toStr(data.ToCurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerSyncField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorField const &data) {
  std::map<std::string, std::string> map;

  map["InvestorID"] = toStr(data.InvestorID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorGroupID"] = toStr(data.InvestorGroupID);
  map["InvestorName"] = toStr(data.InvestorName);
  map["IdentifiedCardType"] = toStr(data.IdentifiedCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["IsActive"] = toStr(data.IsActive);
  map["Telephone"] = toStr(data.Telephone);
  map["Address"] = toStr(data.Address);
  map["OpenDate"] = toStr(data.OpenDate);
  map["Mobile"] = toStr(data.Mobile);
  map["CommModelID"] = toStr(data.CommModelID);
  map["MarginModelID"] = toStr(data.MarginModelID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingTradingCodeField const &data) {
  std::map<std::string, std::string> map;

  map["InvestorID"] = toStr(data.InvestorID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ClientID"] = toStr(data.ClientID);
  map["IsActive"] = toStr(data.IsActive);
  map["ClientIDType"] = toStr(data.ClientIDType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorGroupField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorGroupID"] = toStr(data.InvestorGroupID);
  map["InvestorGroupName"] = toStr(data.InvestorGroupName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingTradingAccountField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["PreMortgage"] = toStr(data.PreMortgage);
  map["PreCredit"] = toStr(data.PreCredit);
  map["PreDeposit"] = toStr(data.PreDeposit);
  map["PreBalance"] = toStr(data.PreBalance);
  map["PreMargin"] = toStr(data.PreMargin);
  map["InterestBase"] = toStr(data.InterestBase);
  map["Interest"] = toStr(data.Interest);
  map["Deposit"] = toStr(data.Deposit);
  map["Withdraw"] = toStr(data.Withdraw);
  map["FrozenMargin"] = toStr(data.FrozenMargin);
  map["FrozenCash"] = toStr(data.FrozenCash);
  map["FrozenCommission"] = toStr(data.FrozenCommission);
  map["CurrMargin"] = toStr(data.CurrMargin);
  map["CashIn"] = toStr(data.CashIn);
  map["Commission"] = toStr(data.Commission);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["PositionProfit"] = toStr(data.PositionProfit);
  map["Balance"] = toStr(data.Balance);
  map["Available"] = toStr(data.Available);
  map["WithdrawQuota"] = toStr(data.WithdrawQuota);
  map["Reserve"] = toStr(data.Reserve);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["Credit"] = toStr(data.Credit);
  map["Mortgage"] = toStr(data.Mortgage);
  map["ExchangeMargin"] = toStr(data.ExchangeMargin);
  map["DeliveryMargin"] = toStr(data.DeliveryMargin);
  map["ExchangeDeliveryMargin"] = toStr(data.ExchangeDeliveryMargin);
  map["ReserveBalance"] = toStr(data.ReserveBalance);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["PreFundMortgageIn"] = toStr(data.PreFundMortgageIn);
  map["PreFundMortgageOut"] = toStr(data.PreFundMortgageOut);
  map["FundMortgageIn"] = toStr(data.FundMortgageIn);
  map["FundMortgageOut"] = toStr(data.FundMortgageOut);
  map["FundMortgageAvailable"] = toStr(data.FundMortgageAvailable);
  map["MortgageableFund"] = toStr(data.MortgageableFund);
  map["SpecProductMargin"] = toStr(data.SpecProductMargin);
  map["SpecProductFrozenMargin"] = toStr(data.SpecProductFrozenMargin);
  map["SpecProductCommission"] = toStr(data.SpecProductCommission);
  map["SpecProductFrozenCommission"] = toStr(data.SpecProductFrozenCommission);
  map["SpecProductPositionProfit"] = toStr(data.SpecProductPositionProfit);
  map["SpecProductCloseProfit"] = toStr(data.SpecProductCloseProfit);
  map["SpecProductPositionProfitByAlg"] = toStr(data.SpecProductPositionProfitByAlg);
  map["SpecProductExchangeMargin"] = toStr(data.SpecProductExchangeMargin);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInvestorPositionField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["PositionDate"] = toStr(data.PositionDate);
  map["YdPosition"] = toStr(data.YdPosition);
  map["Position"] = toStr(data.Position);
  map["LongFrozen"] = toStr(data.LongFrozen);
  map["ShortFrozen"] = toStr(data.ShortFrozen);
  map["LongFrozenAmount"] = toStr(data.LongFrozenAmount);
  map["ShortFrozenAmount"] = toStr(data.ShortFrozenAmount);
  map["OpenVolume"] = toStr(data.OpenVolume);
  map["CloseVolume"] = toStr(data.CloseVolume);
  map["OpenAmount"] = toStr(data.OpenAmount);
  map["CloseAmount"] = toStr(data.CloseAmount);
  map["PositionCost"] = toStr(data.PositionCost);
  map["PreMargin"] = toStr(data.PreMargin);
  map["UseMargin"] = toStr(data.UseMargin);
  map["FrozenMargin"] = toStr(data.FrozenMargin);
  map["FrozenCash"] = toStr(data.FrozenCash);
  map["FrozenCommission"] = toStr(data.FrozenCommission);
  map["CashIn"] = toStr(data.CashIn);
  map["Commission"] = toStr(data.Commission);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["PositionProfit"] = toStr(data.PositionProfit);
  map["PreSettlementPrice"] = toStr(data.PreSettlementPrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["OpenCost"] = toStr(data.OpenCost);
  map["ExchangeMargin"] = toStr(data.ExchangeMargin);
  map["CombPosition"] = toStr(data.CombPosition);
  map["CombLongFrozen"] = toStr(data.CombLongFrozen);
  map["CombShortFrozen"] = toStr(data.CombShortFrozen);
  map["CloseProfitByDate"] = toStr(data.CloseProfitByDate);
  map["CloseProfitByTrade"] = toStr(data.CloseProfitByTrade);
  map["TodayPosition"] = toStr(data.TodayPosition);
  map["MarginRateByMoney"] = toStr(data.MarginRateByMoney);
  map["MarginRateByVolume"] = toStr(data.MarginRateByVolume);
  map["StrikeFrozen"] = toStr(data.StrikeFrozen);
  map["StrikeFrozenAmount"] = toStr(data.StrikeFrozenAmount);
  map["AbandonFrozen"] = toStr(data.AbandonFrozen);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentMarginRateField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["LongMarginRatioByMoney"] = toStr(data.LongMarginRatioByMoney);
  map["LongMarginRatioByVolume"] = toStr(data.LongMarginRatioByVolume);
  map["ShortMarginRatioByMoney"] = toStr(data.ShortMarginRatioByMoney);
  map["ShortMarginRatioByVolume"] = toStr(data.ShortMarginRatioByVolume);
  map["IsRelative"] = toStr(data.IsRelative);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentCommissionRateField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OpenRatioByMoney"] = toStr(data.OpenRatioByMoney);
  map["OpenRatioByVolume"] = toStr(data.OpenRatioByVolume);
  map["CloseRatioByMoney"] = toStr(data.CloseRatioByMoney);
  map["CloseRatioByVolume"] = toStr(data.CloseRatioByVolume);
  map["CloseTodayRatioByMoney"] = toStr(data.CloseTodayRatioByMoney);
  map["CloseTodayRatioByVolume"] = toStr(data.CloseTodayRatioByVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncingInstrumentTradingRightField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["TradingRight"] = toStr(data.TradingRight);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["InsertTimeStart"] = toStr(data.InsertTimeStart);
  map["InsertTimeEnd"] = toStr(data.InsertTimeEnd);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TradeID"] = toStr(data.TradeID);
  map["TradeTimeStart"] = toStr(data.TradeTimeStart);
  map["TradeTimeEnd"] = toStr(data.TradeTimeEnd);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingAccountField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingCodeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ClientID"] = toStr(data.ClientID);
  map["ClientIDType"] = toStr(data.ClientIDType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorGroupField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentMarginRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentCommissionRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentTradingRightField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTraderField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySuperUserFunctionField const &data) {
  std::map<std::string, std::string> map;

  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryUserSessionField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryPartBrokerField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["ParticipantID"] = toStr(data.ParticipantID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryFrontStatusField const &data) {
  std::map<std::string, std::string> map;

  map["FrontID"] = toStr(data.FrontID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeOrderField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySuperUserField const &data) {
  std::map<std::string, std::string> map;

  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryProductField const &data) {
  std::map<std::string, std::string> map;

  map["ProductID"] = toStr(data.ProductID);
  map["ProductClass"] = toStr(data.ProductClass);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ProductID"] = toStr(data.ProductID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryDepthMarketDataField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserFunctionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTraderOfferField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncDepositField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["DepositSeqNo"] = toStr(data.DepositSeqNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySettlementInfoField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["TradingDay"] = toStr(data.TradingDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeMarginRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeMarginRateAdjustField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["FromCurrencyID"] = toStr(data.FromCurrencyID);
  map["ToCurrencyID"] = toStr(data.ToCurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncFundMortgageField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["MortgageSeqNo"] = toStr(data.MortgageSeqNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryHisOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["InsertTimeStart"] = toStr(data.InsertTimeStart);
  map["InsertTimeEnd"] = toStr(data.InsertTimeEnd);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrMiniMarginField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["MinMargin"] = toStr(data.MinMargin);
  map["ValueMethod"] = toStr(data.ValueMethod);
  map["IsRelative"] = toStr(data.IsRelative);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrMarginAdjustField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["SShortMarginRatioByMoney"] = toStr(data.SShortMarginRatioByMoney);
  map["SShortMarginRatioByVolume"] = toStr(data.SShortMarginRatioByVolume);
  map["HShortMarginRatioByMoney"] = toStr(data.HShortMarginRatioByMoney);
  map["HShortMarginRatioByVolume"] = toStr(data.HShortMarginRatioByVolume);
  map["AShortMarginRatioByMoney"] = toStr(data.AShortMarginRatioByMoney);
  map["AShortMarginRatioByVolume"] = toStr(data.AShortMarginRatioByVolume);
  map["IsRelative"] = toStr(data.IsRelative);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrCommRateField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OpenRatioByMoney"] = toStr(data.OpenRatioByMoney);
  map["OpenRatioByVolume"] = toStr(data.OpenRatioByVolume);
  map["CloseRatioByMoney"] = toStr(data.CloseRatioByMoney);
  map["CloseRatioByVolume"] = toStr(data.CloseRatioByVolume);
  map["CloseTodayRatioByMoney"] = toStr(data.CloseTodayRatioByMoney);
  map["CloseTodayRatioByVolume"] = toStr(data.CloseTodayRatioByVolume);
  map["StrikeRatioByMoney"] = toStr(data.StrikeRatioByMoney);
  map["StrikeRatioByVolume"] = toStr(data.StrikeRatioByVolume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrTradeCostField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["FixedMargin"] = toStr(data.FixedMargin);
  map["MiniMargin"] = toStr(data.MiniMargin);
  map["Royalty"] = toStr(data.Royalty);
  map["ExchFixedMargin"] = toStr(data.ExchFixedMargin);
  map["ExchMiniMargin"] = toStr(data.ExchMiniMargin);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrTradeCostField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["InputPrice"] = toStr(data.InputPrice);
  map["UnderlyingPrice"] = toStr(data.UnderlyingPrice);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrCommRateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcIndexPriceField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ClosePrice"] = toStr(data.ClosePrice);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["UserID"] = toStr(data.UserID);
  map["Volume"] = toStr(data.Volume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionType"] = toStr(data.ActionType);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["ReservePositionFlag"] = toStr(data.ReservePositionFlag);
  map["CloseFlag"] = toStr(data.CloseFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExecOrderActionRef"] = toStr(data.ExecOrderActionRef);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["UserID"] = toStr(data.UserID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["UserID"] = toStr(data.UserID);
  map["Volume"] = toStr(data.Volume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionType"] = toStr(data.ActionType);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["ReservePositionFlag"] = toStr(data.ReservePositionFlag);
  map["CloseFlag"] = toStr(data.CloseFlag);
  map["ExecOrderLocalID"] = toStr(data.ExecOrderLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["ExecResult"] = toStr(data.ExecResult);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["ActiveUserID"] = toStr(data.ActiveUserID);
  map["BrokerExecOrderSeq"] = toStr(data.BrokerExecOrderSeq);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExecOrderActionRef"] = toStr(data.ExecOrderActionRef);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["ExecOrderLocalID"] = toStr(data.ExecOrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);
  map["ActionType"] = toStr(data.ActionType);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["InsertTimeStart"] = toStr(data.InsertTimeStart);
  map["InsertTimeEnd"] = toStr(data.InsertTimeEnd);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["Volume"] = toStr(data.Volume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionType"] = toStr(data.ActionType);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["ReservePositionFlag"] = toStr(data.ReservePositionFlag);
  map["CloseFlag"] = toStr(data.CloseFlag);
  map["ExecOrderLocalID"] = toStr(data.ExecOrderLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["ExecResult"] = toStr(data.ExecResult);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["ExecOrderLocalID"] = toStr(data.ExecOrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);
  map["ActionType"] = toStr(data.ActionType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["UserID"] = toStr(data.UserID);
  map["Volume"] = toStr(data.Volume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionType"] = toStr(data.ActionType);
  map["PosiDirection"] = toStr(data.PosiDirection);
  map["ReservePositionFlag"] = toStr(data.ReservePositionFlag);
  map["CloseFlag"] = toStr(data.CloseFlag);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrExecOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExecOrderActionRef"] = toStr(data.ExecOrderActionRef);
  map["ExecOrderRef"] = toStr(data.ExecOrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExecOrderSysID"] = toStr(data.ExecOrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["UserID"] = toStr(data.UserID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrExecOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrTradingRightField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Direction"] = toStr(data.Direction);
  map["TradingRight"] = toStr(data.TradingRight);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryOptionInstrTradingRightField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["Direction"] = toStr(data.Direction);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputForQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ForQuoteRef"] = toStr(data.ForQuoteRef);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ForQuoteRef"] = toStr(data.ForQuoteRef);
  map["UserID"] = toStr(data.UserID);
  map["ForQuoteLocalID"] = toStr(data.ForQuoteLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["ForQuoteStatus"] = toStr(data.ForQuoteStatus);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["ActiveUserID"] = toStr(data.ActiveUserID);
  map["BrokerForQutoSeq"] = toStr(data.BrokerForQutoSeq);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryForQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InsertTimeStart"] = toStr(data.InsertTimeStart);
  map["InsertTimeEnd"] = toStr(data.InsertTimeEnd);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeForQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["ForQuoteLocalID"] = toStr(data.ForQuoteLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["ForQuoteStatus"] = toStr(data.ForQuoteStatus);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeForQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["QuoteRef"] = toStr(data.QuoteRef);
  map["UserID"] = toStr(data.UserID);
  map["AskPrice"] = toStr(data.AskPrice);
  map["BidPrice"] = toStr(data.BidPrice);
  map["AskVolume"] = toStr(data.AskVolume);
  map["BidVolume"] = toStr(data.BidVolume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["AskOffsetFlag"] = toStr(data.AskOffsetFlag);
  map["BidOffsetFlag"] = toStr(data.BidOffsetFlag);
  map["AskHedgeFlag"] = toStr(data.AskHedgeFlag);
  map["BidHedgeFlag"] = toStr(data.BidHedgeFlag);
  map["AskOrderRef"] = toStr(data.AskOrderRef);
  map["BidOrderRef"] = toStr(data.BidOrderRef);
  map["ForQuoteSysID"] = toStr(data.ForQuoteSysID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputQuoteActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["QuoteActionRef"] = toStr(data.QuoteActionRef);
  map["QuoteRef"] = toStr(data.QuoteRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["UserID"] = toStr(data.UserID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["QuoteRef"] = toStr(data.QuoteRef);
  map["UserID"] = toStr(data.UserID);
  map["AskPrice"] = toStr(data.AskPrice);
  map["BidPrice"] = toStr(data.BidPrice);
  map["AskVolume"] = toStr(data.AskVolume);
  map["BidVolume"] = toStr(data.BidVolume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["AskOffsetFlag"] = toStr(data.AskOffsetFlag);
  map["BidOffsetFlag"] = toStr(data.BidOffsetFlag);
  map["AskHedgeFlag"] = toStr(data.AskHedgeFlag);
  map["BidHedgeFlag"] = toStr(data.BidHedgeFlag);
  map["QuoteLocalID"] = toStr(data.QuoteLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["QuoteStatus"] = toStr(data.QuoteStatus);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["AskOrderSysID"] = toStr(data.AskOrderSysID);
  map["BidOrderSysID"] = toStr(data.BidOrderSysID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["ActiveUserID"] = toStr(data.ActiveUserID);
  map["BrokerQuoteSeq"] = toStr(data.BrokerQuoteSeq);
  map["AskOrderRef"] = toStr(data.AskOrderRef);
  map["BidOrderRef"] = toStr(data.BidOrderRef);
  map["ForQuoteSysID"] = toStr(data.ForQuoteSysID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQuoteActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["QuoteActionRef"] = toStr(data.QuoteActionRef);
  map["QuoteRef"] = toStr(data.QuoteRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["QuoteLocalID"] = toStr(data.QuoteLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["InsertTimeStart"] = toStr(data.InsertTimeStart);
  map["InsertTimeEnd"] = toStr(data.InsertTimeEnd);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["AskPrice"] = toStr(data.AskPrice);
  map["BidPrice"] = toStr(data.BidPrice);
  map["AskVolume"] = toStr(data.AskVolume);
  map["BidVolume"] = toStr(data.BidVolume);
  map["RequestID"] = toStr(data.RequestID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["AskOffsetFlag"] = toStr(data.AskOffsetFlag);
  map["BidOffsetFlag"] = toStr(data.BidOffsetFlag);
  map["AskHedgeFlag"] = toStr(data.AskHedgeFlag);
  map["BidHedgeFlag"] = toStr(data.BidHedgeFlag);
  map["QuoteLocalID"] = toStr(data.QuoteLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["QuoteStatus"] = toStr(data.QuoteStatus);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["AskOrderSysID"] = toStr(data.AskOrderSysID);
  map["BidOrderSysID"] = toStr(data.BidOrderSysID);
  map["ForQuoteSysID"] = toStr(data.ForQuoteSysID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeQuoteField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryQuoteActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeQuoteActionField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["QuoteSysID"] = toStr(data.QuoteSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["QuoteLocalID"] = toStr(data.QuoteLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeQuoteActionField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOptionInstrDeltaField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Delta"] = toStr(data.Delta);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcForQuoteRspField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ForQuoteSysID"] = toStr(data.ForQuoteSysID);
  map["ForQuoteTime"] = toStr(data.ForQuoteTime);
  map["ActionDay"] = toStr(data.ActionDay);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcStrikeOffsetField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Offset"] = toStr(data.Offset);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryStrikeOffsetField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombInstrumentGuardField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["GuarantRatio"] = toStr(data.GuarantRatio);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombInstrumentGuardField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInputCombActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["CombActionRef"] = toStr(data.CombActionRef);
  map["UserID"] = toStr(data.UserID);
  map["Direction"] = toStr(data.Direction);
  map["Volume"] = toStr(data.Volume);
  map["CombDirection"] = toStr(data.CombDirection);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["CombActionRef"] = toStr(data.CombActionRef);
  map["UserID"] = toStr(data.UserID);
  map["Direction"] = toStr(data.Direction);
  map["Volume"] = toStr(data.Volume);
  map["CombDirection"] = toStr(data.CombDirection);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["ActionStatus"] = toStr(data.ActionStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["StatusMsg"] = toStr(data.StatusMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeCombActionField const &data) {
  std::map<std::string, std::string> map;

  map["Direction"] = toStr(data.Direction);
  map["Volume"] = toStr(data.Volume);
  map["CombDirection"] = toStr(data.CombDirection);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["ActionStatus"] = toStr(data.ActionStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["SequenceNo"] = toStr(data.SequenceNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeCombActionField const &data) {
  std::map<std::string, std::string> map;

  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcProductExchRateField const &data) {
  std::map<std::string, std::string> map;

  map["ProductID"] = toStr(data.ProductID);
  map["QuoteCurrencyID"] = toStr(data.QuoteCurrencyID);
  map["ExchangeRate"] = toStr(data.ExchangeRate);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryProductExchRateField const &data) {
  std::map<std::string, std::string> map;

  map["ProductID"] = toStr(data.ProductID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["LastPrice"] = toStr(data.LastPrice);
  map["PreSettlementPrice"] = toStr(data.PreSettlementPrice);
  map["PreClosePrice"] = toStr(data.PreClosePrice);
  map["PreOpenInterest"] = toStr(data.PreOpenInterest);
  map["OpenPrice"] = toStr(data.OpenPrice);
  map["HighestPrice"] = toStr(data.HighestPrice);
  map["LowestPrice"] = toStr(data.LowestPrice);
  map["Volume"] = toStr(data.Volume);
  map["Turnover"] = toStr(data.Turnover);
  map["OpenInterest"] = toStr(data.OpenInterest);
  map["ClosePrice"] = toStr(data.ClosePrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["UpperLimitPrice"] = toStr(data.UpperLimitPrice);
  map["LowerLimitPrice"] = toStr(data.LowerLimitPrice);
  map["PreDelta"] = toStr(data.PreDelta);
  map["CurrDelta"] = toStr(data.CurrDelta);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["UpdateMillisec"] = toStr(data.UpdateMillisec);
  map["ActionDay"] = toStr(data.ActionDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBaseField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["PreSettlementPrice"] = toStr(data.PreSettlementPrice);
  map["PreClosePrice"] = toStr(data.PreClosePrice);
  map["PreOpenInterest"] = toStr(data.PreOpenInterest);
  map["PreDelta"] = toStr(data.PreDelta);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataStaticField const &data) {
  std::map<std::string, std::string> map;

  map["OpenPrice"] = toStr(data.OpenPrice);
  map["HighestPrice"] = toStr(data.HighestPrice);
  map["LowestPrice"] = toStr(data.LowestPrice);
  map["ClosePrice"] = toStr(data.ClosePrice);
  map["UpperLimitPrice"] = toStr(data.UpperLimitPrice);
  map["LowerLimitPrice"] = toStr(data.LowerLimitPrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["CurrDelta"] = toStr(data.CurrDelta);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataLastMatchField const &data) {
  std::map<std::string, std::string> map;

  map["LastPrice"] = toStr(data.LastPrice);
  map["Volume"] = toStr(data.Volume);
  map["Turnover"] = toStr(data.Turnover);
  map["OpenInterest"] = toStr(data.OpenInterest);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBestPriceField const &data) {
  std::map<std::string, std::string> map;

  map["BidPrice1"] = toStr(data.BidPrice1);
  map["BidVolume1"] = toStr(data.BidVolume1);
  map["AskPrice1"] = toStr(data.AskPrice1);
  map["AskVolume1"] = toStr(data.AskVolume1);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBid23Field const &data) {
  std::map<std::string, std::string> map;

  map["BidPrice2"] = toStr(data.BidPrice2);
  map["BidVolume2"] = toStr(data.BidVolume2);
  map["BidPrice3"] = toStr(data.BidPrice3);
  map["BidVolume3"] = toStr(data.BidVolume3);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAsk23Field const &data) {
  std::map<std::string, std::string> map;

  map["AskPrice2"] = toStr(data.AskPrice2);
  map["AskVolume2"] = toStr(data.AskVolume2);
  map["AskPrice3"] = toStr(data.AskPrice3);
  map["AskVolume3"] = toStr(data.AskVolume3);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataBid45Field const &data) {
  std::map<std::string, std::string> map;

  map["BidPrice4"] = toStr(data.BidPrice4);
  map["BidVolume4"] = toStr(data.BidVolume4);
  map["BidPrice5"] = toStr(data.BidPrice5);
  map["BidVolume5"] = toStr(data.BidVolume5);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAsk45Field const &data) {
  std::map<std::string, std::string> map;

  map["AskPrice4"] = toStr(data.AskPrice4);
  map["AskVolume4"] = toStr(data.AskVolume4);
  map["AskPrice5"] = toStr(data.AskPrice5);
  map["AskVolume5"] = toStr(data.AskVolume5);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataUpdateTimeField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["UpdateMillisec"] = toStr(data.UpdateMillisec);
  map["ActionDay"] = toStr(data.ActionDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataExchangeField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSpecificInstrumentField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInstrumentStatusField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["SettlementGroupID"] = toStr(data.SettlementGroupID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["InstrumentStatus"] = toStr(data.InstrumentStatus);
  map["TradingSegmentSN"] = toStr(data.TradingSegmentSN);
  map["EnterTime"] = toStr(data.EnterTime);
  map["EnterReason"] = toStr(data.EnterReason);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInstrumentStatusField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorAccountField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["AccountID"] = toStr(data.AccountID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcPositionProfitAlgorithmField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["Algorithm"] = toStr(data.Algorithm);
  map["Memo"] = toStr(data.Memo);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDiscountField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Discount"] = toStr(data.Discount);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTransferBankField const &data) {
  std::map<std::string, std::string> map;

  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferBankField const &data) {
  std::map<std::string, std::string> map;

  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);
  map["BankName"] = toStr(data.BankName);
  map["IsActive"] = toStr(data.IsActive);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionDetailField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionDetailField const &data) {
  std::map<std::string, std::string> map;

  map["InstrumentID"] = toStr(data.InstrumentID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["Direction"] = toStr(data.Direction);
  map["OpenDate"] = toStr(data.OpenDate);
  map["TradeID"] = toStr(data.TradeID);
  map["Volume"] = toStr(data.Volume);
  map["OpenPrice"] = toStr(data.OpenPrice);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["TradeType"] = toStr(data.TradeType);
  map["CombInstrumentID"] = toStr(data.CombInstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["CloseProfitByDate"] = toStr(data.CloseProfitByDate);
  map["CloseProfitByTrade"] = toStr(data.CloseProfitByTrade);
  map["PositionProfitByDate"] = toStr(data.PositionProfitByDate);
  map["PositionProfitByTrade"] = toStr(data.PositionProfitByTrade);
  map["Margin"] = toStr(data.Margin);
  map["ExchMargin"] = toStr(data.ExchMargin);
  map["MarginRateByMoney"] = toStr(data.MarginRateByMoney);
  map["MarginRateByVolume"] = toStr(data.MarginRateByVolume);
  map["LastSettlementPrice"] = toStr(data.LastSettlementPrice);
  map["SettlementPrice"] = toStr(data.SettlementPrice);
  map["CloseVolume"] = toStr(data.CloseVolume);
  map["CloseAmount"] = toStr(data.CloseAmount);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMDTraderOfferField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["TraderID"] = toStr(data.TraderID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["TraderConnectStatus"] = toStr(data.TraderConnectStatus);
  map["ConnectRequestDate"] = toStr(data.ConnectRequestDate);
  map["ConnectRequestTime"] = toStr(data.ConnectRequestTime);
  map["LastReportDate"] = toStr(data.LastReportDate);
  map["LastReportTime"] = toStr(data.LastReportTime);
  map["ConnectDate"] = toStr(data.ConnectDate);
  map["ConnectTime"] = toStr(data.ConnectTime);
  map["StartDate"] = toStr(data.StartDate);
  map["StartTime"] = toStr(data.StartTime);
  map["TradingDay"] = toStr(data.TradingDay);
  map["BrokerID"] = toStr(data.BrokerID);
  map["MaxTradeID"] = toStr(data.MaxTradeID);
  map["MaxOrderMessageReference"] = toStr(data.MaxOrderMessageReference);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryMDTraderOfferField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["TraderID"] = toStr(data.TraderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryNoticeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNoticeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["Content"] = toStr(data.Content);
  map["SequenceLabel"] = toStr(data.SequenceLabel);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserRightField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserRightType"] = toStr(data.UserRightType);
  map["IsForbidden"] = toStr(data.IsForbidden);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySettlementInfoConfirmField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoadSettlementInfoField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerWithdrawAlgorithmField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["WithdrawAlgorithm"] = toStr(data.WithdrawAlgorithm);
  map["UsingRatio"] = toStr(data.UsingRatio);
  map["IncludeCloseProfit"] = toStr(data.IncludeCloseProfit);
  map["AllWithoutTrade"] = toStr(data.AllWithoutTrade);
  map["AvailIncludeCloseProfit"] = toStr(data.AvailIncludeCloseProfit);
  map["IsBrokerUserEvent"] = toStr(data.IsBrokerUserEvent);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["FundMortgageRatio"] = toStr(data.FundMortgageRatio);
  map["BalanceAlgorithm"] = toStr(data.BalanceAlgorithm);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordUpdateV1Field const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OldPassword"] = toStr(data.OldPassword);
  map["NewPassword"] = toStr(data.NewPassword);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountPasswordUpdateField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["OldPassword"] = toStr(data.OldPassword);
  map["NewPassword"] = toStr(data.NewPassword);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCombinationLegField const &data) {
  std::map<std::string, std::string> map;

  map["CombInstrumentID"] = toStr(data.CombInstrumentID);
  map["LegID"] = toStr(data.LegID);
  map["LegInstrumentID"] = toStr(data.LegInstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySyncStatusField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCombinationLegField const &data) {
  std::map<std::string, std::string> map;

  map["CombInstrumentID"] = toStr(data.CombInstrumentID);
  map["LegID"] = toStr(data.LegID);
  map["LegInstrumentID"] = toStr(data.LegInstrumentID);
  map["Direction"] = toStr(data.Direction);
  map["LegMultiple"] = toStr(data.LegMultiple);
  map["ImplyLevel"] = toStr(data.ImplyLevel);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSyncStatusField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["DataSyncStatus"] = toStr(data.DataSyncStatus);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryLinkManField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLinkManField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["PersonType"] = toStr(data.PersonType);
  map["IdentifiedCardType"] = toStr(data.IdentifiedCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["PersonName"] = toStr(data.PersonName);
  map["Telephone"] = toStr(data.Telephone);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Priority"] = toStr(data.Priority);
  map["UOAZipCode"] = toStr(data.UOAZipCode);
  map["PersonFullName"] = toStr(data.PersonFullName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerUserEventField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserEventType"] = toStr(data.UserEventType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserEventField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["UserEventType"] = toStr(data.UserEventType);
  map["EventSequenceNo"] = toStr(data.EventSequenceNo);
  map["EventDate"] = toStr(data.EventDate);
  map["EventTime"] = toStr(data.EventTime);
  map["UserEventInfo"] = toStr(data.UserEventInfo);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryContractBankField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcContractBankField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["BankID"] = toStr(data.BankID);
  map["BankBrchID"] = toStr(data.BankBrchID);
  map["BankName"] = toStr(data.BankName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorPositionCombineDetailField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["OpenDate"] = toStr(data.OpenDate);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["SettlementID"] = toStr(data.SettlementID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ComTradeID"] = toStr(data.ComTradeID);
  map["TradeID"] = toStr(data.TradeID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["Direction"] = toStr(data.Direction);
  map["TotalAmt"] = toStr(data.TotalAmt);
  map["Margin"] = toStr(data.Margin);
  map["ExchMargin"] = toStr(data.ExchMargin);
  map["MarginRateByMoney"] = toStr(data.MarginRateByMoney);
  map["MarginRateByVolume"] = toStr(data.MarginRateByVolume);
  map["LegID"] = toStr(data.LegID);
  map["LegMultiple"] = toStr(data.LegMultiple);
  map["CombInstrumentID"] = toStr(data.CombInstrumentID);
  map["TradeGroupID"] = toStr(data.TradeGroupID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcParkedOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["UserForceClose"] = toStr(data.UserForceClose);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParkedOrderID"] = toStr(data.ParkedOrderID);
  map["UserType"] = toStr(data.UserType);
  map["Status"] = toStr(data.Status);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["IsSwapOrder"] = toStr(data.IsSwapOrder);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcParkedOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OrderActionRef"] = toStr(data.OrderActionRef);
  map["OrderRef"] = toStr(data.OrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeChange"] = toStr(data.VolumeChange);
  map["UserID"] = toStr(data.UserID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ParkedOrderActionID"] = toStr(data.ParkedOrderActionID);
  map["UserType"] = toStr(data.UserType);
  map["Status"] = toStr(data.Status);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryParkedOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryParkedOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRemoveParkedOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ParkedOrderID"] = toStr(data.ParkedOrderID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRemoveParkedOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ParkedOrderActionID"] = toStr(data.ParkedOrderActionID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorWithdrawAlgorithmField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["InvestorID"] = toStr(data.InvestorID);
  map["UsingRatio"] = toStr(data.UsingRatio);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["FundMortgageRatio"] = toStr(data.FundMortgageRatio);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorPositionCombineDetailField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["CombInstrumentID"] = toStr(data.CombInstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarketDataAveragePriceField const &data) {
  std::map<std::string, std::string> map;

  map["AveragePrice"] = toStr(data.AveragePrice);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyInvestorPasswordField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Password"] = toStr(data.Password);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserIPField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["IPAddress"] = toStr(data.IPAddress);
  map["IPMask"] = toStr(data.IPMask);
  map["MacAddress"] = toStr(data.MacAddress);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingNoticeInfoField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["SendTime"] = toStr(data.SendTime);
  map["FieldContent"] = toStr(data.FieldContent);
  map["SequenceSeries"] = toStr(data.SequenceSeries);
  map["SequenceNo"] = toStr(data.SequenceNo);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingNoticeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorRange"] = toStr(data.InvestorRange);
  map["InvestorID"] = toStr(data.InvestorID);
  map["SequenceSeries"] = toStr(data.SequenceSeries);
  map["UserID"] = toStr(data.UserID);
  map["SendTime"] = toStr(data.SendTime);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["FieldContent"] = toStr(data.FieldContent);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTradingNoticeField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["UserForceClose"] = toStr(data.UserForceClose);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["IsSwapOrder"] = toStr(data.IsSwapOrder);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrorConditionalOrderField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["OrderRef"] = toStr(data.OrderRef);
  map["UserID"] = toStr(data.UserID);
  map["OrderPriceType"] = toStr(data.OrderPriceType);
  map["Direction"] = toStr(data.Direction);
  map["CombOffsetFlag"] = toStr(data.CombOffsetFlag);
  map["CombHedgeFlag"] = toStr(data.CombHedgeFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeTotalOriginal"] = toStr(data.VolumeTotalOriginal);
  map["TimeCondition"] = toStr(data.TimeCondition);
  map["GTDDate"] = toStr(data.GTDDate);
  map["VolumeCondition"] = toStr(data.VolumeCondition);
  map["MinVolume"] = toStr(data.MinVolume);
  map["ContingentCondition"] = toStr(data.ContingentCondition);
  map["StopPrice"] = toStr(data.StopPrice);
  map["ForceCloseReason"] = toStr(data.ForceCloseReason);
  map["IsAutoSuspend"] = toStr(data.IsAutoSuspend);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["RequestID"] = toStr(data.RequestID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["ExchangeInstID"] = toStr(data.ExchangeInstID);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderSubmitStatus"] = toStr(data.OrderSubmitStatus);
  map["NotifySequence"] = toStr(data.NotifySequence);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["OrderSource"] = toStr(data.OrderSource);
  map["OrderStatus"] = toStr(data.OrderStatus);
  map["OrderType"] = toStr(data.OrderType);
  map["VolumeTraded"] = toStr(data.VolumeTraded);
  map["VolumeTotal"] = toStr(data.VolumeTotal);
  map["InsertDate"] = toStr(data.InsertDate);
  map["InsertTime"] = toStr(data.InsertTime);
  map["ActiveTime"] = toStr(data.ActiveTime);
  map["SuspendTime"] = toStr(data.SuspendTime);
  map["UpdateTime"] = toStr(data.UpdateTime);
  map["CancelTime"] = toStr(data.CancelTime);
  map["ActiveTraderID"] = toStr(data.ActiveTraderID);
  map["ClearingPartID"] = toStr(data.ClearingPartID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["UserProductInfo"] = toStr(data.UserProductInfo);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["UserForceClose"] = toStr(data.UserForceClose);
  map["ActiveUserID"] = toStr(data.ActiveUserID);
  map["BrokerOrderSeq"] = toStr(data.BrokerOrderSeq);
  map["RelativeOrderSysID"] = toStr(data.RelativeOrderSysID);
  map["ZCETotalTradedVolume"] = toStr(data.ZCETotalTradedVolume);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["IsSwapOrder"] = toStr(data.IsSwapOrder);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryErrOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcErrOrderActionField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["OrderActionRef"] = toStr(data.OrderActionRef);
  map["OrderRef"] = toStr(data.OrderRef);
  map["RequestID"] = toStr(data.RequestID);
  map["FrontID"] = toStr(data.FrontID);
  map["SessionID"] = toStr(data.SessionID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["OrderSysID"] = toStr(data.OrderSysID);
  map["ActionFlag"] = toStr(data.ActionFlag);
  map["LimitPrice"] = toStr(data.LimitPrice);
  map["VolumeChange"] = toStr(data.VolumeChange);
  map["ActionDate"] = toStr(data.ActionDate);
  map["ActionTime"] = toStr(data.ActionTime);
  map["TraderID"] = toStr(data.TraderID);
  map["InstallID"] = toStr(data.InstallID);
  map["OrderLocalID"] = toStr(data.OrderLocalID);
  map["ActionLocalID"] = toStr(data.ActionLocalID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ClientID"] = toStr(data.ClientID);
  map["BusinessUnit"] = toStr(data.BusinessUnit);
  map["OrderActionStatus"] = toStr(data.OrderActionStatus);
  map["UserID"] = toStr(data.UserID);
  map["StatusMsg"] = toStr(data.StatusMsg);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryExchangeSequenceField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcExchangeSequenceField const &data) {
  std::map<std::string, std::string> map;

  map["ExchangeID"] = toStr(data.ExchangeID);
  map["SequenceNo"] = toStr(data.SequenceNo);
  map["MarketStatus"] = toStr(data.MarketStatus);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryMaxOrderVolumeWithPriceField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["Direction"] = toStr(data.Direction);
  map["OffsetFlag"] = toStr(data.OffsetFlag);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["MaxVolume"] = toStr(data.MaxVolume);
  map["Price"] = toStr(data.Price);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerTradingParamsField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerTradingParamsField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["MarginPriceType"] = toStr(data.MarginPriceType);
  map["Algorithm"] = toStr(data.Algorithm);
  map["AvailIncludeCloseProfit"] = toStr(data.AvailIncludeCloseProfit);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["OptionRoyaltyPriceType"] = toStr(data.OptionRoyaltyPriceType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryBrokerTradingAlgosField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerTradingAlgosField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["HandlePositionAlgoID"] = toStr(data.HandlePositionAlgoID);
  map["FindMarginRateAlgoID"] = toStr(data.FindMarginRateAlgoID);
  map["HandleTradingAccountAlgoID"] = toStr(data.HandleTradingAccountAlgoID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryBrokerDepositField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ExchangeID"] = toStr(data.ExchangeID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerDepositField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["BrokerID"] = toStr(data.BrokerID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["PreBalance"] = toStr(data.PreBalance);
  map["CurrMargin"] = toStr(data.CurrMargin);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["Balance"] = toStr(data.Balance);
  map["Deposit"] = toStr(data.Deposit);
  map["Withdraw"] = toStr(data.Withdraw);
  map["Available"] = toStr(data.Available);
  map["Reserve"] = toStr(data.Reserve);
  map["FrozenMargin"] = toStr(data.FrozenMargin);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCFMMCBrokerKeyField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCBrokerKeyField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["CreateDate"] = toStr(data.CreateDate);
  map["CreateTime"] = toStr(data.CreateTime);
  map["KeyID"] = toStr(data.KeyID);
  map["CurrentKey"] = toStr(data.CurrentKey);
  map["KeyKind"] = toStr(data.KeyKind);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCTradingAccountKeyField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["AccountID"] = toStr(data.AccountID);
  map["KeyID"] = toStr(data.KeyID);
  map["CurrentKey"] = toStr(data.CurrentKey);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCFMMCTradingAccountKeyField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserOTPParamField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["OTPVendorsID"] = toStr(data.OTPVendorsID);
  map["SerialNumber"] = toStr(data.SerialNumber);
  map["AuthKey"] = toStr(data.AuthKey);
  map["LastDrift"] = toStr(data.LastDrift);
  map["LastSuccess"] = toStr(data.LastSuccess);
  map["OTPType"] = toStr(data.OTPType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcManualSyncBrokerUserOTPField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["OTPType"] = toStr(data.OTPType);
  map["FirstOTP"] = toStr(data.FirstOTP);
  map["SecondOTP"] = toStr(data.SecondOTP);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCommRateModelField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["CommModelID"] = toStr(data.CommModelID);
  map["CommModelName"] = toStr(data.CommModelName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryCommRateModelField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["CommModelID"] = toStr(data.CommModelID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMarginModelField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["MarginModelID"] = toStr(data.MarginModelID);
  map["MarginModelName"] = toStr(data.MarginModelName);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryMarginModelField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["MarginModelID"] = toStr(data.MarginModelID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcEWarrantOffsetField const &data) {
  std::map<std::string, std::string> map;

  map["TradingDay"] = toStr(data.TradingDay);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InstrumentID"] = toStr(data.InstrumentID);
  map["Direction"] = toStr(data.Direction);
  map["HedgeFlag"] = toStr(data.HedgeFlag);
  map["Volume"] = toStr(data.Volume);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryEWarrantOffsetField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ExchangeID"] = toStr(data.ExchangeID);
  map["InstrumentID"] = toStr(data.InstrumentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryInvestorProductGroupMarginField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["ProductGroupID"] = toStr(data.ProductGroupID);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcInvestorProductGroupMarginField const &data) {
  std::map<std::string, std::string> map;

  map["ProductGroupID"] = toStr(data.ProductGroupID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["TradingDay"] = toStr(data.TradingDay);
  map["SettlementID"] = toStr(data.SettlementID);
  map["FrozenMargin"] = toStr(data.FrozenMargin);
  map["LongFrozenMargin"] = toStr(data.LongFrozenMargin);
  map["ShortFrozenMargin"] = toStr(data.ShortFrozenMargin);
  map["UseMargin"] = toStr(data.UseMargin);
  map["LongUseMargin"] = toStr(data.LongUseMargin);
  map["ShortUseMargin"] = toStr(data.ShortUseMargin);
  map["ExchMargin"] = toStr(data.ExchMargin);
  map["LongExchMargin"] = toStr(data.LongExchMargin);
  map["ShortExchMargin"] = toStr(data.ShortExchMargin);
  map["CloseProfit"] = toStr(data.CloseProfit);
  map["FrozenCommission"] = toStr(data.FrozenCommission);
  map["Commission"] = toStr(data.Commission);
  map["FrozenCash"] = toStr(data.FrozenCash);
  map["CashIn"] = toStr(data.CashIn);
  map["PositionProfit"] = toStr(data.PositionProfit);
  map["OffsetAmount"] = toStr(data.OffsetAmount);
  map["LongOffsetAmount"] = toStr(data.LongOffsetAmount);
  map["ShortOffsetAmount"] = toStr(data.ShortOffsetAmount);
  map["ExchOffsetAmount"] = toStr(data.ExchOffsetAmount);
  map["LongExchOffsetAmount"] = toStr(data.LongExchOffsetAmount);
  map["ShortExchOffsetAmount"] = toStr(data.ShortExchOffsetAmount);
  map["HedgeFlag"] = toStr(data.HedgeFlag);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQueryCFMMCTradingAccountTokenField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCFMMCTradingAccountTokenField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["ParticipantID"] = toStr(data.ParticipantID);
  map["AccountID"] = toStr(data.AccountID);
  map["KeyID"] = toStr(data.KeyID);
  map["Token"] = toStr(data.Token);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqOpenAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["CashExchangeCode"] = toStr(data.CashExchangeCode);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["TID"] = toStr(data.TID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqCancelAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["CashExchangeCode"] = toStr(data.CashExchangeCode);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["TID"] = toStr(data.TID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqChangeAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["NewBankAccount"] = toStr(data.NewBankAccount);
  map["NewBankPassWord"] = toStr(data.NewBankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["BankAccType"] = toStr(data.BankAccType);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["TID"] = toStr(data.TID);
  map["Digest"] = toStr(data.Digest);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqTransferField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["FutureFetchAmount"] = toStr(data.FutureFetchAmount);
  map["FeePayFlag"] = toStr(data.FeePayFlag);
  map["CustFee"] = toStr(data.CustFee);
  map["BrokerFee"] = toStr(data.BrokerFee);
  map["Message"] = toStr(data.Message);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["TransferStatus"] = toStr(data.TransferStatus);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspTransferField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["FutureFetchAmount"] = toStr(data.FutureFetchAmount);
  map["FeePayFlag"] = toStr(data.FeePayFlag);
  map["CustFee"] = toStr(data.CustFee);
  map["BrokerFee"] = toStr(data.BrokerFee);
  map["Message"] = toStr(data.Message);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["TransferStatus"] = toStr(data.TransferStatus);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqRepealField const &data) {
  std::map<std::string, std::string> map;

  map["RepealTimeInterval"] = toStr(data.RepealTimeInterval);
  map["RepealedTimes"] = toStr(data.RepealedTimes);
  map["BankRepealFlag"] = toStr(data.BankRepealFlag);
  map["BrokerRepealFlag"] = toStr(data.BrokerRepealFlag);
  map["PlateRepealSerial"] = toStr(data.PlateRepealSerial);
  map["BankRepealSerial"] = toStr(data.BankRepealSerial);
  map["FutureRepealSerial"] = toStr(data.FutureRepealSerial);
  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["FutureFetchAmount"] = toStr(data.FutureFetchAmount);
  map["FeePayFlag"] = toStr(data.FeePayFlag);
  map["CustFee"] = toStr(data.CustFee);
  map["BrokerFee"] = toStr(data.BrokerFee);
  map["Message"] = toStr(data.Message);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["TransferStatus"] = toStr(data.TransferStatus);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspRepealField const &data) {
  std::map<std::string, std::string> map;

  map["RepealTimeInterval"] = toStr(data.RepealTimeInterval);
  map["RepealedTimes"] = toStr(data.RepealedTimes);
  map["BankRepealFlag"] = toStr(data.BankRepealFlag);
  map["BrokerRepealFlag"] = toStr(data.BrokerRepealFlag);
  map["PlateRepealSerial"] = toStr(data.PlateRepealSerial);
  map["BankRepealSerial"] = toStr(data.BankRepealSerial);
  map["FutureRepealSerial"] = toStr(data.FutureRepealSerial);
  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["FutureFetchAmount"] = toStr(data.FutureFetchAmount);
  map["FeePayFlag"] = toStr(data.FeePayFlag);
  map["CustFee"] = toStr(data.CustFee);
  map["BrokerFee"] = toStr(data.BrokerFee);
  map["Message"] = toStr(data.Message);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["TransferStatus"] = toStr(data.TransferStatus);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqQueryAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspQueryAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["BankUseAmount"] = toStr(data.BankUseAmount);
  map["BankFetchAmount"] = toStr(data.BankFetchAmount);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFutureSignIOField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspFutureSignInField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["PinKey"] = toStr(data.PinKey);
  map["MacKey"] = toStr(data.MacKey);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqFutureSignOutField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspFutureSignOutField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqQueryTradeResultBySerialField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["Reference"] = toStr(data.Reference);
  map["RefrenceIssureType"] = toStr(data.RefrenceIssureType);
  map["RefrenceIssure"] = toStr(data.RefrenceIssure);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["Digest"] = toStr(data.Digest);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspQueryTradeResultBySerialField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["Reference"] = toStr(data.Reference);
  map["RefrenceIssureType"] = toStr(data.RefrenceIssureType);
  map["RefrenceIssure"] = toStr(data.RefrenceIssure);
  map["OriginReturnCode"] = toStr(data.OriginReturnCode);
  map["OriginDescrInfoForReturnCode"] = toStr(data.OriginDescrInfoForReturnCode);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["Digest"] = toStr(data.Digest);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqDayEndFileReadyField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["FileBusinessCode"] = toStr(data.FileBusinessCode);
  map["Digest"] = toStr(data.Digest);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReturnResultField const &data) {
  std::map<std::string, std::string> map;

  map["ReturnCode"] = toStr(data.ReturnCode);
  map["DescrInfoForReturnCode"] = toStr(data.DescrInfoForReturnCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyFuturePasswordField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["InstallID"] = toStr(data.InstallID);
  map["TID"] = toStr(data.TID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyCustInfoField const &data) {
  std::map<std::string, std::string> map;

  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcVerifyFuturePasswordAndCustInfoField const &data) {
  std::map<std::string, std::string> map;

  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDepositResultInformField const &data) {
  std::map<std::string, std::string> map;

  map["DepositSeqNo"] = toStr(data.DepositSeqNo);
  map["BrokerID"] = toStr(data.BrokerID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["Deposit"] = toStr(data.Deposit);
  map["RequestID"] = toStr(data.RequestID);
  map["ReturnCode"] = toStr(data.ReturnCode);
  map["DescrInfoForReturnCode"] = toStr(data.DescrInfoForReturnCode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcReqSyncKeyField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Message"] = toStr(data.Message);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcRspSyncKeyField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Message"] = toStr(data.Message);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyQueryAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustType"] = toStr(data.CustType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["BankUseAmount"] = toStr(data.BankUseAmount);
  map["BankFetchAmount"] = toStr(data.BankFetchAmount);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTransferSerialField const &data) {
  std::map<std::string, std::string> map;

  map["PlateSerial"] = toStr(data.PlateSerial);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradingDay"] = toStr(data.TradingDay);
  map["TradeTime"] = toStr(data.TradeTime);
  map["TradeCode"] = toStr(data.TradeCode);
  map["SessionID"] = toStr(data.SessionID);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BankAccType"] = toStr(data.BankAccType);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankSerial"] = toStr(data.BankSerial);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["FutureAccType"] = toStr(data.FutureAccType);
  map["AccountID"] = toStr(data.AccountID);
  map["InvestorID"] = toStr(data.InvestorID);
  map["FutureSerial"] = toStr(data.FutureSerial);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["TradeAmount"] = toStr(data.TradeAmount);
  map["CustFee"] = toStr(data.CustFee);
  map["BrokerFee"] = toStr(data.BrokerFee);
  map["AvailabilityFlag"] = toStr(data.AvailabilityFlag);
  map["OperatorCode"] = toStr(data.OperatorCode);
  map["BankNewAccount"] = toStr(data.BankNewAccount);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryTransferSerialField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["BankID"] = toStr(data.BankID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyFutureSignInField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);
  map["PinKey"] = toStr(data.PinKey);
  map["MacKey"] = toStr(data.MacKey);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifyFutureSignOutField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Digest"] = toStr(data.Digest);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcNotifySyncKeyField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["InstallID"] = toStr(data.InstallID);
  map["UserID"] = toStr(data.UserID);
  map["Message"] = toStr(data.Message);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["OperNo"] = toStr(data.OperNo);
  map["RequestID"] = toStr(data.RequestID);
  map["TID"] = toStr(data.TID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryAccountregisterField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcAccountregisterField const &data) {
  std::map<std::string, std::string> map;

  map["TradeDay"] = toStr(data.TradeDay);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["AccountID"] = toStr(data.AccountID);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["CustomerName"] = toStr(data.CustomerName);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["OpenOrDestroy"] = toStr(data.OpenOrDestroy);
  map["RegDate"] = toStr(data.RegDate);
  map["OutDate"] = toStr(data.OutDate);
  map["TID"] = toStr(data.TID);
  map["CustType"] = toStr(data.CustType);
  map["BankAccType"] = toStr(data.BankAccType);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcOpenAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["CashExchangeCode"] = toStr(data.CashExchangeCode);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["TID"] = toStr(data.TID);
  map["UserID"] = toStr(data.UserID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCancelAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["CashExchangeCode"] = toStr(data.CashExchangeCode);
  map["Digest"] = toStr(data.Digest);
  map["BankAccType"] = toStr(data.BankAccType);
  map["DeviceID"] = toStr(data.DeviceID);
  map["BankSecuAccType"] = toStr(data.BankSecuAccType);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankSecuAcc"] = toStr(data.BankSecuAcc);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["OperNo"] = toStr(data.OperNo);
  map["TID"] = toStr(data.TID);
  map["UserID"] = toStr(data.UserID);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcChangeAccountField const &data) {
  std::map<std::string, std::string> map;

  map["TradeCode"] = toStr(data.TradeCode);
  map["BankID"] = toStr(data.BankID);
  map["BankBranchID"] = toStr(data.BankBranchID);
  map["BrokerID"] = toStr(data.BrokerID);
  map["BrokerBranchID"] = toStr(data.BrokerBranchID);
  map["TradeDate"] = toStr(data.TradeDate);
  map["TradeTime"] = toStr(data.TradeTime);
  map["BankSerial"] = toStr(data.BankSerial);
  map["TradingDay"] = toStr(data.TradingDay);
  map["PlateSerial"] = toStr(data.PlateSerial);
  map["LastFragment"] = toStr(data.LastFragment);
  map["SessionID"] = toStr(data.SessionID);
  map["CustomerName"] = toStr(data.CustomerName);
  map["IdCardType"] = toStr(data.IdCardType);
  map["IdentifiedCardNo"] = toStr(data.IdentifiedCardNo);
  map["Gender"] = toStr(data.Gender);
  map["CountryCode"] = toStr(data.CountryCode);
  map["CustType"] = toStr(data.CustType);
  map["Address"] = toStr(data.Address);
  map["ZipCode"] = toStr(data.ZipCode);
  map["Telephone"] = toStr(data.Telephone);
  map["MobilePhone"] = toStr(data.MobilePhone);
  map["Fax"] = toStr(data.Fax);
  map["EMail"] = toStr(data.EMail);
  map["MoneyAccountStatus"] = toStr(data.MoneyAccountStatus);
  map["BankAccount"] = toStr(data.BankAccount);
  map["BankPassWord"] = toStr(data.BankPassWord);
  map["NewBankAccount"] = toStr(data.NewBankAccount);
  map["NewBankPassWord"] = toStr(data.NewBankPassWord);
  map["AccountID"] = toStr(data.AccountID);
  map["Password"] = toStr(data.Password);
  map["BankAccType"] = toStr(data.BankAccType);
  map["InstallID"] = toStr(data.InstallID);
  map["VerifyCertNoFlag"] = toStr(data.VerifyCertNoFlag);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["BrokerIDByBank"] = toStr(data.BrokerIDByBank);
  map["BankPwdFlag"] = toStr(data.BankPwdFlag);
  map["SecuPwdFlag"] = toStr(data.SecuPwdFlag);
  map["TID"] = toStr(data.TID);
  map["Digest"] = toStr(data.Digest);
  map["ErrorID"] = toStr(data.ErrorID);
  map["ErrorMsg"] = toStr(data.ErrorMsg);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcSecAgentACIDMapField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["AccountID"] = toStr(data.AccountID);
  map["CurrencyID"] = toStr(data.CurrencyID);
  map["BrokerSecAgentID"] = toStr(data.BrokerSecAgentID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQrySecAgentACIDMapField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["AccountID"] = toStr(data.AccountID);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcUserRightsAssignField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["DRIdentityID"] = toStr(data.DRIdentityID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcBrokerUserRightAssignField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["DRIdentityID"] = toStr(data.DRIdentityID);
  map["Tradeable"] = toStr(data.Tradeable);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcDRTransferField const &data) {
  std::map<std::string, std::string> map;

  map["OrigDRIdentityID"] = toStr(data.OrigDRIdentityID);
  map["DestDRIdentityID"] = toStr(data.DestDRIdentityID);
  map["OrigBrokerID"] = toStr(data.OrigBrokerID);
  map["DestBrokerID"] = toStr(data.DestBrokerID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcFensUserInfoField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);
  map["LoginMode"] = toStr(data.LoginMode);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcCurrTransferIdentityField const &data) {
  std::map<std::string, std::string> map;

  map["IdentityID"] = toStr(data.IdentityID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcLoginForbiddenUserField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcQryLoginForbiddenUserField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["UserID"] = toStr(data.UserID);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcMulticastGroupInfoField const &data) {
  std::map<std::string, std::string> map;

  map["GroupIP"] = toStr(data.GroupIP);
  map["GroupPort"] = toStr(data.GroupPort);
  map["SourceIP"] = toStr(data.SourceIP);

  return cli.HMSET(path, map);
}

bool toRedis(redis::Redis &cli, std::string const &path, CThostFtdcTradingAccountReserveField const &data) {
  std::map<std::string, std::string> map;

  map["BrokerID"] = toStr(data.BrokerID);
  map["AccountID"] = toStr(data.AccountID);
  map["Reserve"] = toStr(data.Reserve);
  map["CurrencyID"] = toStr(data.CurrencyID);

  return cli.HMSET(path, map);
}

/*
 * Auto generated code end
 * */

}

//
// Created by colin on 8/4/2019.
//

#ifndef CTP_STORAGE_REDIS_UTILS_H_
#define CTP_STORAGE_REDIS_UTILS_H_

#include "ctp/ThostFtdcUserApiDataType.h"
#include "ctp/ThostFtdcUserApiStruct.h"

#include <memory>
#include <string>

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

}

template<typename T>
class FromRedis {
 public:
  virtual std::unique_ptr<T> operator()(std::string const& prefix) = 0;
};

template<typename T>
class fromRedis : FromRedis<T> {
 public:
  std::unique_ptr<T> operator()(std::string const& prefix);
};

bool toRedis(std::string const &prefix, long long int score, CThostFtdcDisseminationField const &data) {
  return true;
}

template<>
class fromRedis<CThostFtdcDisseminationField> : FromRedis<CThostFtdcDisseminationField> {
  std::unique_ptr<CThostFtdcDisseminationField> operator()(std::string const& prefix) {
    auto res = std::unique_ptr<CThostFtdcDisseminationField>();
    return res;
  }
};

}

#endif //CTP_STORAGE_REDIS_UTILS_H_

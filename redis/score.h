//
// Created by colin on 8/10/2019.
//

#ifndef CTP_STORAGE_REDIS_SCORE_H_
#define CTP_STORAGE_REDIS_SCORE_H_

#include <boost/date_time/posix_time/posix_time.hpp>

namespace storage{

namespace pt = boost::posix_time;

// hard-coded start time for system
static auto startTime = pt::ptime(pt::time_from_string("2019-03-12 23:59:59.500"));
//static auto minDuration = pt::time_duration(pt::milliseconds(1));
static auto minDuration = pt::time_duration(0,0,0,10); // 10 nanoseconds as minimal

static auto genScore = []() {
  return (pt::microsec_clock::universal_time() - startTime).total_nanoseconds() / minDuration.total_nanoseconds();
};

static auto decodeScore = [](auto frameID) {
  // this is only approximation to second
  return pt::to_simple_string((startTime + pt::milliseconds(frameID / 100)));
};

}

#endif //CTP_STORAGE_REDIS_SCORE_H_

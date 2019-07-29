#include "spdlog/spdlog.h"

#include <gtest/gtest.h>

#include <boost/program_options.hpp>

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  namespace po = boost::program_options;

  po::options_description desc("Allowed options", 200);
  desc.add_options()
      ("test, t", "run tests");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("test")) {
    ::testing::InitGoogleTest(&argc, argv);
    spdlog::stdout_color_mt("Test Mode")->info("which test to perform?");
    std::string filter;
    std::getline(std::cin, filter);
    ::testing::FLAGS_gtest_filter = filter.c_str();
    return RUN_ALL_TESTS();
  }
}


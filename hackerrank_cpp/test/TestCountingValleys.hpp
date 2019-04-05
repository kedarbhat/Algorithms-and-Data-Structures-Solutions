#pragma once

#include <gtest/gtest.h>

#include "CountingValleys.hpp"

namespace {
TEST(TestCountingValleys, NoValleys) {
  EXPECT_EQ(0, CountingValleys::countingValleys(0, "UUUUU"));
}

TEST(TestCountingValleys, HackerRankExample) {
  EXPECT_EQ(1, CountingValleys::countingValleys(8, "UDDDUDUU"));
}
} // namespace
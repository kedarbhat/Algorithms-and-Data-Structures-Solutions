#include "CountingValleys.hpp"
#include "gtest/gtest.h"

namespace {
TEST(TestCountingValleys, NoValleys) {
  EXPECT_EQ(0, CountingValleys::countingValleys(0, "UUUUU"));
}

TEST(TestCountingValleys, HackerRankExample) {
  EXPECT_EQ(1, CountingValleys::countingValleys(8, "UDDDUDUU"));
}
} // namespace
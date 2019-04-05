#include <gtest/gtest.h>

#include "TestAbstractClasses.hpp"
#include "TestCountingValleys.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

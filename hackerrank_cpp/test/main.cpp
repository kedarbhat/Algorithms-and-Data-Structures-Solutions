#include <gtest/gtest.h>

#include "TestInheritedCode.hpp"
#include "TestCountingValleys.hpp"
#include "TestTemplateSpecialization.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

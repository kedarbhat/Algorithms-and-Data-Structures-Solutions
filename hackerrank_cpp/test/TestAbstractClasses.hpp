#pragma once

#include <gtest/gtest.h>

#include "AbstractClasses.hpp"

namespace {
TEST(TestAbstractClasses, NeverPass) {
  AbstractClasses::StringLengthChecker checker{std::string::npos};
  EXPECT_THROW(checker.isValid("Should Be Valid"),
               AbstractClasses::BadLengthException);
}

TEST(TestAbstractClasses, AlwaysPass) {
  AbstractClasses::StringLengthChecker checker{0};
  EXPECT_EQ("Valid", checker.isValid(""));
}

TEST(TestAbstractClasses, HackerRankExample) {
  AbstractClasses::StringLengthChecker checker{3};
  EXPECT_EQ("Valid", checker.isValid("Peter"));
  EXPECT_THROW(checker.isValid("Me"), AbstractClasses::BadLengthException);
  EXPECT_EQ("Invalid", checker.isValid("Arxwwz"));
}
} // namespace
/*
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <gtest/gtest.h>

#include "InheritedCode.hpp"

#include <string>

namespace {
TEST(TestAbstractClasses, NeverPass) {
  abstract_classes::StringLengthChecker checker{std::string::npos};
  ASSERT_THROW(checker.IsValid("Should Be Valid"),
               abstract_classes::BadLengthException);
}

TEST(TestAbstractClasses, AlwaysPass) {
  abstract_classes::StringLengthChecker checker{0};
  ASSERT_EQ("Valid", checker.IsValid(""));
}

TEST(TestAbstractClasses, HackerRankExample) {
  abstract_classes::StringLengthChecker checker{3};
  ASSERT_EQ("Valid", checker.IsValid("Peter"));
  ASSERT_THROW(checker.IsValid("Me"), abstract_classes::BadLengthException);
  ASSERT_EQ("Invalid", checker.IsValid("Arxwwz"));
  try {
    checker.IsValid("Me");
  } catch (const abstract_classes::BadLengthException& e) {
    ASSERT_STREQ(e.what(), "2");
  }
}
}  // namespace
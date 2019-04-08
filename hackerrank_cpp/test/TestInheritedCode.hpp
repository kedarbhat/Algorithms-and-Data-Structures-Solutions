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

#include "InheritedCode.hpp"

#include <string>

namespace {
TEST(TestAbstractClasses, NeverPass) {
  abstract_classes::StringLengthChecker checker{std::string::npos};
  EXPECT_THROW(checker.IsValid("Should Be Valid"),
               abstract_classes::BadLengthException);
}

TEST(TestAbstractClasses, AlwaysPass) {
  abstract_classes::StringLengthChecker checker{0};
  EXPECT_EQ("Valid", checker.IsValid(""));
}

TEST(TestAbstractClasses, HackerRankExample) {
  abstract_classes::StringLengthChecker checker{3};
  EXPECT_EQ("Valid", checker.IsValid("Peter"));
  EXPECT_THROW(checker.IsValid("Me"), abstract_classes::BadLengthException);
  EXPECT_EQ("Invalid", checker.IsValid("Arxwwz"));
}
}  // namespace
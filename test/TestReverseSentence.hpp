// Copyright (C) 2019 Kedar R. Bhat

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#pragma once
#include <gtest/gtest.h>

#include "ReverseSentence.hpp"

namespace {
TEST(TestReverseSentence, EmptyString) {
  std::string str;
  EXPECT_TRUE(str.empty());
  ReverseString(str);
  EXPECT_EQ(str, std::string{});
}

TEST(TestReverseSentence, SingleSpace) {
  std::string str = " ";
  ReverseString(str);
  EXPECT_EQ(str, " ");
}

TEST(TestReverseSentence, SingleLetter) {
  std::string str = "a";
  ReverseString(str);
  EXPECT_EQ(str, "a");
}

TEST(TestReverseSentence, BeginsWithASpace) {
  std::string str = " a";
  ReverseString(str);
  EXPECT_EQ(str, "a ");
}

TEST(TestReverseSentence, EndsWithASpace) {
  std::string str = "a ";
  ReverseString(str);
  EXPECT_EQ(str, " a");
}

TEST(TestReverseSentence, NormalSentence) {
  std::string str = "i live in a house";
  auto expected = "house a in live i";
  ReverseString(str);
  EXPECT_EQ(str, expected);
}

}  // namespace

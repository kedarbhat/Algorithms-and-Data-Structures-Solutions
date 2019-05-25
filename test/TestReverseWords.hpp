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
#include "ReverseWords.hpp"

namespace {
TEST(TestReverseWords, one_word) {
  const std::string expected = "vault";
  std::string actual = "vault";
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseWords, two_words) {
  const std::string expected = "cake thief";
  std::string actual = "thief cake";
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseWords, three_words) {
  const std::string expected = "get another one";
  std::string actual = "one another get";
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseWords, multiple_words_same_length) {
  const std::string expected = "the cat ate the rat";
  std::string actual = "rat the ate cat the";
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseWords, multiple_words_different_lengths) {
  const std::string expected = "chocolate bundt cake is yummy";
  std::string actual = "yummy is cake bundt chocolate";
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseWords, empty_string) {
  const std::string expected;
  std::string actual;
  ReverseWords(actual);
  ASSERT_EQ(actual, expected);
}
}  // namespace
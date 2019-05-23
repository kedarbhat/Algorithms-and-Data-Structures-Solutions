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
#include "LongestCommonSubsequence.hpp"
namespace {
TEST(TestLongestCommonSubsequence, EmptySequences) {
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{}, std::vector<int>{}),
            std::vector<int>{});
  ASSERT_EQ(
      longestCommonSubsequence(std::vector<int>{}, std::vector<int>{1, 2, 3}),
      std::vector<int>{});
  ASSERT_EQ(
      longestCommonSubsequence(std::vector<int>{1, 2, 3}, std::vector<int>{}),
      std::vector<int>{});
}

TEST(TestLongestCommonSubsequence, OneElementSequences) {
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{1}, std::vector<int>{2}),
            std::vector<int>{});
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{2}, std::vector<int>{2}),
            std::vector<int>{2});
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{2}, std::vector<int>{1}),
            std::vector<int>{});
}

TEST(TestLongestCommonSubsequence, IdenticalSequences) {
  ASSERT_EQ(
      longestCommonSubsequence(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                               std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
      ((std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})));
}

TEST(TestLongestCommonSubsequence, ShorterFirstSequence) {
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{1, 2, 3, 4, 1},
                                     std::vector<int>{3, 4, 1, 2, 1, 3}),
            ((std::vector<int>{1, 2, 3})));
}

TEST(TestLongestCommonSubsequence, LongerFirstSequence) {
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{3, 4, 1, 2, 1, 3},
                                     std::vector<int>{1, 2, 3, 4, 1}),
            ((std::vector<int>{1, 2, 3})));
}

TEST(TestLongestCommonSubsequence, EqualLengthSequences) {
  ASSERT_EQ(longestCommonSubsequence(std::vector<int>{3, 4, 1, 2, 3},
                                     std::vector<int>{1, 2, 3, 4, 1}),
            ((std::vector<int>{3, 4, 1})));
}
}  // namespace
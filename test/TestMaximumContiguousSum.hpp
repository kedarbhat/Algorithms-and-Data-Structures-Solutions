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

#include "MaximumContiguousSum.hpp"

namespace {
using maximum_contiguous_sum::GetMaximumContiguousSum;
using maximum_contiguous_sum::GetMaximumContiguousSumTargetZero;

TEST(TestMaximumContiguousSum, EmptyArray) {
  std::vector<int> vec;
  EXPECT_EQ(GetMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, SingleElementNegative) {
  std::vector<int> vec{-10};
  EXPECT_EQ(GetMaximumContiguousSum(vec), -10);
}

TEST(TestMaximumContiguousSum, SingleElementZero) {
  std::vector<int> vec{0};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, SingleElementPositive) {
  std::vector<int> vec{10};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 10);
}

TEST(TestMaximumContiguousSum, AllNegativeElements) {
  std::vector<int> vec{-10, -9, -8, -1};
  EXPECT_EQ(GetMaximumContiguousSum(vec), -1);
}

TEST(TestMaximumContiguousSum, AllZeroElements) {
  std::vector<int> vec{0, 0, 0, 0};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, AllPositiveElements) {
  std::vector<int> vec{10, 9, 8, 1};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 28);
}

TEST(TestMaximumContiguousSum, NormalArray1) {
  std::vector<int> vec{1, 2, -1, 2, -3, 2, -5};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 4);
}

TEST(TestMaximumContiguousSum, NormalArray2) {
  std::vector<int> vec{-2, -3, 4, -1, -2, 1, 5, -1};
  EXPECT_EQ(GetMaximumContiguousSum(vec), 7);
}

TEST(TestMaximumContiguousSumWithTarget, EmptyArray) {
  std::vector<int> vec;
  EXPECT_EQ(GetMaximumContiguousSum(vec, 10),
            std::make_pair(std::size_t{0}, std::size_t{0}));
}

TEST(TestMaximumContiguousSumWithTarget, SingleElementPositiveExistingSum) {
  std::vector<int> vec{10};
  EXPECT_EQ(GetMaximumContiguousSum(vec, 10),
            std::make_pair(std::size_t{0}, std::size_t{1}));
}

TEST(TestMaximumContiguousSumWithTarget, SingleElementPositiveNonexistingSum) {
  std::vector<int> vec{10};
  EXPECT_EQ(GetMaximumContiguousSum(vec, 11),
            std::make_pair(std::size_t{1}, std::size_t{2}));
}

TEST(TestMaximumContiguousSumWithTarget, MultipleElementPositiveExistingSum) {
  std::vector<int> vec{2, 1, 4, 5, 3, 5, 1, 2, 4};
  EXPECT_EQ(GetMaximumContiguousSum(vec, 13),
            std::make_pair(std::size_t{1}, std::size_t{5}));
}

TEST(TestMaximumContiguousSumWithTarget,
     MultipleElementPositiveNonexistingSum) {
  std::vector<int> vec{2, 1, 4, 5, 3, 5, 1, 2, 4};
  EXPECT_EQ(GetMaximumContiguousSum(vec, 90),
            std::make_pair(vec.size(), vec.size() + 1));
}

TEST(TestMaximumContiguousSumWithTargetZero, EmptyArray) {
  std::vector<int> vec;
  EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
            std::make_pair(std::size_t{0}, std::size_t{0}));
}

TEST(TestMaximumContiguousSumWithTargetZero, SingleElementPositiveExistingSum) {
  std::vector<int> vec{0};
  EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
            std::make_pair(std::size_t{0}, std::size_t{1}));
}

TEST(TestMaximumContiguousSumWithTargetZero,
     SingleElementPositiveNonexistingSum) {
  std::vector<int> vec{1};
  EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
            std::make_pair(std::size_t{1}, std::size_t{2}));
}

TEST(TestMaximumContiguousSumWithTargetZero,
     MultipleElementPositiveExistingSum) {
  std::vector<int> vec{-1, -1, 2, 1, -4, 2, 3, -1, 2};
  EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
            std::make_pair(std::size_t{0}, std::size_t{3}));
}

TEST(TestMaximumContiguousSumWithTargetZero,
     MultipleElementPositiveNonexistingSum) {
  std::vector<int> vec{-1, -1, -1, -1, -1, -1, -1, -1};
  EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
            std::make_pair(vec.size(), vec.size() + 1));
}

TEST(TestMaximumContiguousSumWithTargetZero, MultipleElementCommonDiff) {
  {
    std::vector<int> vec{-1, -1, -4, 1, 2, -2, 3, -1, 2};
    EXPECT_EQ(GetMaximumContiguousSumTargetZero(vec),
              std::make_pair(std::size_t{4}, std::size_t{6}));
  }
  {
    std::vector<int> vec{-1, -1, -4, 1, 2, -2, 3, -1, 2};
    EXPECT_EQ(std::accumulate(std::cbegin(vec) + 4, std::cbegin(vec) + 6, 0),
              0);
  }
}

}  // namespace
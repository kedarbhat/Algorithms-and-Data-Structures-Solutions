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

#include "MaximumContiguousSum.hpp"

namespace {
TEST(TestMaximumContiguousSum, EmptyArray) {
  std::vector<int> vec;
  EXPECT_EQ(getMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, SingleElementNegative) {
  std::vector<int> vec{-10};
  EXPECT_EQ(getMaximumContiguousSum(vec), -10);
}

TEST(TestMaximumContiguousSum, SingleElementZero) {
  std::vector<int> vec{0};
  EXPECT_EQ(getMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, SingleElementPositive) {
  std::vector<int> vec{10};
  EXPECT_EQ(getMaximumContiguousSum(vec), 10);
}

TEST(TestMaximumContiguousSum, AllNegativeElements) {
  std::vector<int> vec{-10, -9, -8, -1};
  EXPECT_EQ(getMaximumContiguousSum(vec), -1);
}

TEST(TestMaximumContiguousSum, AllZeroElements) {
  std::vector<int> vec{0, 0, 0, 0};
  EXPECT_EQ(getMaximumContiguousSum(vec), 0);
}

TEST(TestMaximumContiguousSum, AllPositiveElements) {
  std::vector<int> vec{10, 9, 8, 1};
  EXPECT_EQ(getMaximumContiguousSum(vec), 28);
}

TEST(TestMaximumContiguousSum, NormalArray1) {
  std::vector<int> vec{1, 2, -1, 2, -3, 2, -5};
  EXPECT_EQ(getMaximumContiguousSum(vec), 4);
}

TEST(TestMaximumContiguousSum, NormalArray2) {
  std::vector<int> vec{-2, -3, 4, -1, -2, 1, 5, -1};
  EXPECT_EQ(getMaximumContiguousSum(vec), 7);
}
}  // namespace
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

#include "DutchNationalFlagPartition.hpp"
namespace {
using djikstra_partition::DnfPartition;

TEST(TestDutchNationalFlag, EmptyArray) {
  std::vector<int> vec;
  std::vector<int> expected;
  DnfPartition(vec, 3);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, PivotOutOfBounds) {
  std::vector<int> vec{0, 10};
  std::vector<int> expected{0, 10};
  DnfPartition(vec, 3);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, SingleElementArray) {
  std::vector<int> vec{10};
  std::vector<int> expected{10};
  DnfPartition(vec, 0);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, TwoElementsLargerPivot) {
  std::vector<int> vec{10, 0};
  std::vector<int> expected{0, 10};
  DnfPartition(vec, 0);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, TwoElementsSmallerPivot) {
  std::vector<int> vec{10, 0};
  std::vector<int> expected{0, 10};
  DnfPartition(vec, 1);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, TwoElementsEqualToPivot) {
  std::vector<int> vec{10, 10};
  std::vector<int> expected{10, 10};
  DnfPartition(vec, 1);
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, NormalArrayPivot6) {
  std::vector<int> vec{3, 5, 2, 6, 8, 4, 4, 6, 4, 4, 3};
  EXPECT_EQ(vec[vec.size() / 3], 6);
  DnfPartition(vec, vec.size() / 3);
  std::vector<int> expected{3, 5, 2, 3, 4, 4, 4, 4, 6, 6, 8};
  EXPECT_EQ(vec, expected);
}

TEST(TestDutchNationalFlag, NormalArrayPivot4) {
  std::vector<int> vec{3, 5, 2, 6, 8, 4, 4, 6, 4, 4, 3};
  std::vector<int> expected{3, 3, 2, 4, 4, 4, 4, 6, 8, 6, 5};
  EXPECT_EQ(vec[5], 4);
  DnfPartition(vec, 5);
  EXPECT_EQ(vec, expected);
}
}  // namespace
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
#include "DutchNationalFlagPartition.hpp"

TEST(EmptyArray, TestDutchNationalFlag) {
  std::vector<int> vec;
  std::vector<int> expected;
  dnfPartition(vec, 3);
  EXPECT_EQ(vec, expected);
}

TEST(PivotOutOfBounds, TestDutchNationalFlag) {
  std::vector<int> vec{0, 10};
  std::vector<int> expected{0, 10};
  dnfPartition(vec, 3);
  EXPECT_EQ(vec, expected);
}

TEST(SingleElementArray, TestDutchNationalFlag) {
  std::vector<int> vec{10};
  std::vector<int> expected{10};
  dnfPartition(vec, 0);
  EXPECT_EQ(vec, expected);
}

TEST(TwoElementsLargerPivot, TestDutchNationalFlag) {
  std::vector<int> vec{10, 0};
  std::vector<int> expected{0, 10};
  dnfPartition(vec, 0);
  EXPECT_EQ(vec, expected);
}

TEST(TwoElementsSmallerPivot, TestDutchNationalFlag) {
  std::vector<int> vec{10, 0};
  std::vector<int> expected{0, 10};
  dnfPartition(vec, 1);
  EXPECT_EQ(vec, expected);
}

TEST(TwoElementsEqualToPivot, TestDutchNationalFlag) {
  std::vector<int> vec{10, 10};
  std::vector<int> expected{10, 10};
  dnfPartition(vec, 1);
  EXPECT_EQ(vec, expected);
}

TEST(NormalArrayPivot6, TestDutchNationalFlag) {
  std::vector<int> vec{3, 5, 2, 6, 8, 4, 4, 6, 4, 4, 3};
  EXPECT_EQ(vec[vec.size() / 3], 6);
  dnfPartition(vec, vec.size() / 3);
  std::vector<int> expected{3, 5, 2, 3, 4, 4, 4, 4, 6, 6, 8};
  EXPECT_EQ(vec, expected);
}

TEST(NormalArrayPivot4, TestDutchNationalFlag) {
  std::vector<int> vec{3, 5, 2, 6, 8, 4, 4, 6, 4, 4, 3};
  std::vector<int> expected{3, 3, 2, 4, 4, 4, 4, 6, 8, 6, 5};
  EXPECT_EQ(vec[5], 4);
  dnfPartition(vec, 5);
  EXPECT_EQ(vec, expected);
}
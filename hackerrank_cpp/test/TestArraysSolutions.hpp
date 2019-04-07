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

#include "ArraysSolutions/DynamicArray.hpp"
#include "ArraysSolutions/HourGlassSum.hpp"
#include "ArraysSolutions/ReverseArray.hpp"
#include "ArraysSolutions/RotateLeft.hpp"

namespace { // NOLINT
TEST(TestArraySolutions, RotateLeft) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  int64_t numRotations = 4;
  auto rotatedVec = arrays::rotateLeft(vec, numRotations);
  std::rotate(std::begin(vec), std::begin(vec) + numRotations, std::end(vec));
  ASSERT_EQ(rotatedVec, vec);
}

TEST(TestArraySolutions, ReverseArray) {
  std::vector<int> vec{1, 4, 3, 2};
  auto reversedVec = arrays::reverseArray(vec);
  std::reverse(std::begin(vec), std::end(vec));
  ASSERT_EQ(reversedVec, vec);
}

TEST(TestArraySolutions, HouseGlassSum) {
  std::vector<std::vector<int>> data{{1, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0},
                                     {1, 1, 1, 0, 0, 0}, {0, 0, 2, 4, 4, 0},
                                     {0, 0, 0, 2, 0, 0}, {0, 0, 1, 2, 4, 0}};
  ASSERT_EQ(arrays::hourglassSum(data), 19);
}

TEST(TestArraySolutions, DynamicArray) {
  std::vector<std::vector<int>> data{
      {1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
  ASSERT_EQ(arrays::dynamicArray(2, data), ((std::vector<int>{7, 3})));
}
}  // namespace
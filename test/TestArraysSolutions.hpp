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

#include <string>

#include "ArrayManipulation.hpp"
#include "BalancedSums.hpp"
#include "DynamicArray.hpp"
#include "HourGlassSum.hpp"
#include "ReverseArray.hpp"
#include "RotateLeft.hpp"

namespace {
TEST(TestArraySolutions, RotateLeft) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  int64_t num_rotations = 4;
  auto rotated_vec = arrays::RotateLeft(vec, num_rotations);
  std::rotate(std::begin(vec), std::begin(vec) + num_rotations, std::end(vec));
  ASSERT_EQ(rotated_vec, vec);
}

TEST(TestArraySolutions, ReverseArray) {
  std::vector<int> vec{1, 4, 3, 2};
  auto reversed_vec = arrays::ReverseArray(vec);
  std::reverse(std::begin(vec), std::end(vec));
  ASSERT_EQ(reversed_vec, vec);
}

TEST(TestArraySolutions, HouseGlassSum) {
  std::vector<std::vector<int>> data{{1, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0},
                                     {1, 1, 1, 0, 0, 0}, {0, 0, 2, 4, 4, 0},
                                     {0, 0, 0, 2, 0, 0}, {0, 0, 1, 2, 4, 0}};
  ASSERT_EQ(arrays::HourglassSum(data), 19);
}

TEST(TestArraySolutions, DynamicArray) {
  std::vector<std::vector<int>> data{
      {1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
  ASSERT_EQ(arrays::DynamicArray(2, data), ((std::vector<int>{7, 3})));
}

TEST(TestArraySolutions, ArrayManipulation) {
  std::vector<std::vector<int>> data{{1, 2, 100}, {2, 5, 100}, {3, 4, 100}};
  auto expected = int64_t(200);
  auto result = arrays::ArrayManipulation(5, data);
  ASSERT_EQ(result, expected);
}

TEST(TestArraySolutions, BalancedSums) {
  using namespace std::literals::string_literals;
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{1, 2, 3, 3}), "YES"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{0, 0, 2, 0}), "YES"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{}), "NO"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{1}), "YES"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{2, 0, 0, 0}), "YES"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{1, 1, 4, 1, 1}), "YES"s);
  ASSERT_EQ(arrays::BalancedSums(std::vector<int>{1, 2, 3}), "NO"s);
}
}  // namespace
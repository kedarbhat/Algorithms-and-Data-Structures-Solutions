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

#include "FindUnsortedSubarray.hpp"

namespace {
using PairT = std::pair<arrays::SizeType<std::vector<int>>,
                        arrays::SizeType<std::vector<int>>>;
using arrays::FindUnsortedSubarray;
TEST(TestFindUnsortedSubarray, EmptyArray) {
  std::vector<int> vec;
  PairT expected = {std::numeric_limits<arrays::SizeType<int>>::max(),
                    std::numeric_limits<arrays::SizeType<int>>::max()};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}

TEST(TestFindUnsortedSubarray, NormalArray) {
  std::vector<int> vec{0, 2, 5, 3, 1, 8, 6, 9};
  PairT expected = {1, 6};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}

TEST(TestFindUnsortedSubarray, NormalArray2) {
  std::vector<int> vec{1, 3, 5, 2, 6, 4, 7, 8, 9};
  PairT expected = {1, 5};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}

TEST(TestFindUnsortedSubarray, SortedBeginningArray) {
  std::vector<int> vec{1, 2, 3, 4, 10, 9, 8, 7, 6, 5};
  PairT expected = {4, 9};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}

TEST(TestFindUnsortedSubarray, SortedEndArray) {
  std::vector<int> vec{1, 2, 4, 5, 3, 5, 6, 7, 9};
  PairT expected = {2, 4};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}

TEST(TestFindUnsortedSubarray, SortedArray) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  PairT expected = {vec.size() - 1, 0};
  EXPECT_EQ(FindUnsortedSubarray(vec), expected);
}
}  // namespace

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

#include "FindUnsortedSubarray.hpp"

namespace {
using pair_t = std::pair<size_type<std::vector<int>>, size_type<std::vector<int>>>;
TEST(NormalArray, TestFindUnsortedSubarray) {
  std::vector<int> vec{0, 2, 5, 3, 1, 8, 6, 9};
  pair_t expected = {1,6};
  EXPECT_EQ(findUnsortedSubarray(vec), expected);
}

TEST(SortedArray, TestFindUnsortedSubarray) {
  std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
  pair_t expected = {0,9};
  EXPECT_EQ(findUnsortedSubarray(vec), expected);
}
} // namespace


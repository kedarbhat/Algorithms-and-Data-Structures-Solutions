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

#include "SortThreeEnumArrays.hpp"

namespace {
TEST(TestSortThreeEnumArrays, EmptyArray) {
  std::vector<arrays::Colors> vec;
  std::vector<arrays::Colors> expected;
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestSortThreeEnumArrays, NormalArray) {
  std::vector<arrays::Colors> vec{arrays::Colors::WHITE, arrays::Colors::RED,
                                  arrays::Colors::WHITE, arrays::Colors::BLUE,
                                  arrays::Colors::WHITE, arrays::Colors::RED,
                                  arrays::Colors::WHITE, arrays::Colors::BLUE};
  std::vector<arrays::Colors> expected{
      arrays::Colors::RED,   arrays::Colors::RED,   arrays::Colors::WHITE,
      arrays::Colors::WHITE, arrays::Colors::WHITE, arrays::Colors::WHITE,
      arrays::Colors::BLUE,  arrays::Colors::BLUE};
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestSortThreeEnumArrays, SortedArray) {
  std::vector<arrays::Colors> vec{arrays::Colors::RED,   arrays::Colors::RED,
                                  arrays::Colors::WHITE, arrays::Colors::WHITE,
                                  arrays::Colors::WHITE, arrays::Colors::WHITE,
                                  arrays::Colors::BLUE,  arrays::Colors::BLUE};
  std::vector<arrays::Colors> expected{
      arrays::Colors::RED,   arrays::Colors::RED,   arrays::Colors::WHITE,
      arrays::Colors::WHITE, arrays::Colors::WHITE, arrays::Colors::WHITE,
      arrays::Colors::BLUE,  arrays::Colors::BLUE};
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}
}  // namespace
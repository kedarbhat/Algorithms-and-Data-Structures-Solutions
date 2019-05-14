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
  std::vector<Colors> vec;
  std::vector<Colors> expected;
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestSortThreeEnumArrays, NormalArray) {
  std::vector<Colors> vec{Colors::WHITE, Colors::RED,   Colors::WHITE,
                          Colors::BLUE,  Colors::WHITE, Colors::RED,
                          Colors::WHITE, Colors::BLUE};
  std::vector<Colors> expected{Colors::RED,   Colors::RED,   Colors::WHITE,
                               Colors::WHITE, Colors::WHITE, Colors::WHITE,
                               Colors::BLUE,  Colors::BLUE};
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestSortThreeEnumArrays, SortedArray) {
  std::vector<Colors> vec{Colors::RED,   Colors::RED,   Colors::WHITE,
                          Colors::WHITE, Colors::WHITE, Colors::WHITE,
                          Colors::BLUE,  Colors::BLUE};
  std::vector<Colors> expected{Colors::RED,   Colors::RED,   Colors::WHITE,
                               Colors::WHITE, Colors::WHITE, Colors::WHITE,
                               Colors::BLUE,  Colors::BLUE};
  SortThreeEnumArrays(vec);
  EXPECT_EQ(vec, expected);
}
}  // namespace
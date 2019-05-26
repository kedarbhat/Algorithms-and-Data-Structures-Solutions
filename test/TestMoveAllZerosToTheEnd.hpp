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

#include "MoveAllZerosToTheEnd.hpp"
namespace {
TEST(TestMoveAllZerosToTheEnd, EmptyArray) {
  std::vector<int> vec;
  std::vector<int> expected;
  djikstra_partition::MoveAllZerosToTheEnd(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestMoveAllZerosToTheEnd, AllZerosArray) {
  std::vector<int> vec{0, 0, 0, 0, 0};
  std::vector<int> expected{0, 0, 0, 0, 0};
  djikstra_partition::MoveAllZerosToTheEnd(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestMoveAllZerosToTheEnd, NoZerosArray) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
  const auto expected = vec;
  djikstra_partition::MoveAllZerosToTheEnd(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestMoveAllZerosToTheEnd, NormalArray) {
  std::vector<int> vec{2, 3, 0, 3, 0, 1, 0};
  std::vector<int> expected{2, 3, 1, 3, 0, 0, 0};
  djikstra_partition::MoveAllZerosToTheEnd(vec);
  EXPECT_EQ(vec, expected);
}
}  // namespace
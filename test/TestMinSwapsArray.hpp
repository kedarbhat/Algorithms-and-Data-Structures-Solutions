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
#include "MinSwapsArray.hpp"
namespace {
TEST(TestMinSwapsArray, HackerRankTestCases) {
  ASSERT_EQ(minimumSwaps(std::vector<int>{}), 0);
  ASSERT_EQ(minimumSwaps(std::vector<int>{4, 3, 1, 2}), 3);
  ASSERT_EQ(minimumSwaps(std::vector<int>{2, 3, 4, 1, 5}), 3);
  ASSERT_EQ(minimumSwaps(std::vector<int>{1, 2, 3, 4, 5, 6}), 0);
  ASSERT_EQ(minimumSwaps(std::vector<int>{6, 5, 4, 3, 2, 1}), 3);
}
}  // namespace
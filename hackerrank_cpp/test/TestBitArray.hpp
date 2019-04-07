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

#include "BitArray.hpp"

namespace {  // NOLINT
TEST(TestBitArray, HackerRankTestCases) {
  EXPECT_EQ(
      bit_array::GenerateSequence(100000000, 178349423, 584642695, 2037647927),
      100000000);
  EXPECT_EQ(bit_array::GenerateSequence(3, 1, 1, 1), 3);
}
}  // namespace

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

#include "MakeChange.hpp"
namespace {
TEST(TestMakeChange, ZeroCoins) {
  ASSERT_EQ(makeChangeRecursive(0), 0);
  ASSERT_EQ(makeChangeDynamic(0), 0);
}

TEST(TestMakeChange, SingleCoins) {
  for (auto denomination : sDenominations) {
    ASSERT_EQ(makeChangeRecursive(denomination), 1);
    ASSERT_EQ(makeChangeDynamic(denomination), 1);
  }
}

TEST(TestMakeChange, NormalAmounts) {
  constexpr std::array<int, 51> numCoins{{0, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3,
                                          4, 5, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 1,
                                          2, 3, 4, 5, 2, 3, 4, 5, 6, 2, 3, 4, 5,
                                          6, 3, 4, 5, 6, 7, 3, 4, 5, 6, 7, 2}};
  for (auto value : boost::irange(51)) {
    ASSERT_EQ(makeChangeRecursive(value), numCoins[value]);
    ASSERT_EQ(makeChangeDynamic(value), numCoins[value]);
  }
}

}  // namespace
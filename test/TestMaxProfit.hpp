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
#include "MaxProfit.hpp"

namespace {
TEST(TestMaxProfit, price_goes_up_then_down) {
  const int actual = GetMaxProfit({1, 5, 3, 2});
  const int expected = 4;
  ASSERT_EQ(actual, expected);
}

TEST(TestMaxProfit, price_goes_down_then_up) {
  const int actual = GetMaxProfit({7, 2, 8, 9});
  const int expected = 7;
  ASSERT_EQ(actual, expected);
}

TEST(TestMaxProfit, price_goes_up_all_day) {
  const int actual = GetMaxProfit({1, 6, 7, 9});
  const int expected = 8;
  ASSERT_EQ(actual, expected);
}

TEST(TestMaxProfit, price_goes_down_all_day) {
  const int actual = GetMaxProfit({9, 7, 4, 1});
  const int expected = -2;
  ASSERT_EQ(actual, expected);
}

TEST(TestMaxProfit, price_stays_the_same_all_day) {
  const int actual = GetMaxProfit({1, 1, 1, 1});
  const int expected = 0;
  ASSERT_EQ(actual, expected);
}

TEST(TestMaxProfit, no_prices) {
  ASSERT_THROW(GetMaxProfit({}), std::invalid_argument);
}

TEST(TestMaxProfit, one_price) {
  ASSERT_THROW(GetMaxProfit({1}), std::invalid_argument);
}
}  // namespace
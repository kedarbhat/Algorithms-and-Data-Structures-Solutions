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

// https://www.interviewcake.com/question/cpp/stock-price?course=fc1&section=greedy

#pragma once

#include <exception>
#include <vector>

namespace {
int GetMaxProfit(const std::vector<int>& stock_prices) {
  if (stock_prices.size() < 2u) {
    throw std::invalid_argument(
        "Stock Price vector must have at least 2 prices.");
  }

  auto max_profit_so_far = stock_prices[1u] - stock_prices[0u];
  auto min_price_so_far = stock_prices[0u];
  for (auto idx = 1u; idx < stock_prices.size(); ++idx) {
    max_profit_so_far =
        std::max(max_profit_so_far, stock_prices[idx] - min_price_so_far);
    min_price_so_far = std::min(min_price_so_far, stock_prices[idx]);
  }

  return max_profit_so_far;
}
}  // namespace
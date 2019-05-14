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

#include <algorithm>
#include <array>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/irange.hpp>
#include <vector>

namespace {

// Problem: Return the minimum number of coins which sum to a given value

constexpr std::array<int, 4> s_denominations{1, 5, 10, 25};

// Brute Force recursive algorithm
int MakeChangeRecursive(const int total_value) noexcept {
  if (total_value == 0) {
    return 0;
  }

  // all pennies for initialization
  auto min_coins = total_value;
  for (auto denomination : s_denominations) {
    if (total_value >= denomination) {
      auto denomination_min_coins =
          MakeChangeRecursive(total_value - denomination);
      min_coins = std::min(min_coins, denomination_min_coins);
    }
  }
  assert(min_coins < std::numeric_limits<int>::max());
  return min_coins + 1;
}

/**
 * @brief Function object used in makeChangeDynamic to filter denominations that
 * aren't possible to be used
 */
struct LessThanValueT {
  constexpr bool operator()(int i) const noexcept { return i <= value_; }
  const int value_;
};

int MakeChangeDynamic(const int total_value) noexcept {
  using boost::adaptors::filtered;
  std::vector<int> min_coins_by_value(static_cast<std::size_t>(total_value) +
                                      1u);

  const auto& total_value_possible_denominations =
      s_denominations | filtered(LessThanValueT{total_value});

  for (auto value : boost::irange(1, total_value + 1)) {
    // use only pennies for initial minimum coin calculation per value
    min_coins_by_value[value] = value;
    const auto& current_value_possible_denominations =
        total_value_possible_denominations | filtered(LessThanValueT{value});
    for (auto denomination : current_value_possible_denominations) {
      auto min_coins = 1 + min_coins_by_value[value - denomination];
      min_coins_by_value[value] =
          std::min(min_coins_by_value[value], min_coins);
    }
  }
  return min_coins_by_value[total_value];
}

}  // namespace
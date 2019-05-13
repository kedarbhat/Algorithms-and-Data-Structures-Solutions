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

constexpr std::array<int, 4> sDenominations{1, 5, 10, 25};

// Brute Force recursive algorithm
int makeChangeRecursive(const int totalValue) noexcept {
  if (totalValue == 0) {
    return 0;
  }

  // all pennies for initialization
  auto minCoins = totalValue;
  for (auto denomination : sDenominations) {
    if (totalValue >= denomination) {
      auto denominationMinCoins =
          makeChangeRecursive(totalValue - denomination);
      minCoins = std::min(minCoins, denominationMinCoins);
    }
  }
  assert(minCoins < std::numeric_limits<int>::max());
  return minCoins + 1;
}

/**
 * @brief Function object used in makeChangeDynamic to filter denominations that
 * aren't possible to be used
 */
struct LessThanValue_t {
  constexpr bool operator()(int i) const noexcept { return i <= value; }
  const int value;
};

int makeChangeDynamic(const int totalValue) noexcept {
  using boost::adaptors::filtered;
  std::vector<int> minCoinsByValue(static_cast<std::size_t>(totalValue) + 1u);

  const auto& totalValuePossibleDenominations =
      sDenominations | filtered(LessThanValue_t{totalValue});

  for (auto value : boost::irange(1, totalValue + 1)) {
    // use only pennies for initial minimum coin calculation per value
    minCoinsByValue[value] = value;
    const auto& currentValuePossibleDenominations =
        totalValuePossibleDenominations | filtered(LessThanValue_t{value});
    for (auto denomination : currentValuePossibleDenominations) {
      auto minCoins = 1 + minCoinsByValue[value - denomination];
      minCoinsByValue[value] = std::min(minCoinsByValue[value], minCoins);
    }
  }
  return minCoinsByValue[totalValue];
}

}  // namespace
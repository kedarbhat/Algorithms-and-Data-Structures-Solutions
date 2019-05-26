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

#include <iterator>

namespace arrays {
// 2 Sum Problem: Given a sorted array of integers, find two numbers in the
// array that sum to an integer X.For example, given a=[1,2,3,5,6,7] and X=11,
// the answer would be 5 and 6, which sum to 11.
std::pair<std::size_t, std::size_t> TwoSumInwardIteration(
    const std::vector<int>& vec, const int target) noexcept {
  assert(std::is_sorted(std::cbegin(vec), std::cend(vec)));
  if (vec.size() < 2) {
    return std::make_pair(vec.size(), vec.size());
  }

  auto start_iter = std::cbegin(vec);
  auto finish_iter = std::prev(std::cend(vec));
  while (start_iter != finish_iter) {
    auto sum = *start_iter + *finish_iter;
    if (sum < target) {
      std::advance(start_iter, 1);
    } else if (sum > target) {
      std::advance(finish_iter, -1);
    } else {
      break;
    }
  }
  return std::make_pair(
      static_cast<std::size_t>(std::distance(std::cbegin(vec), start_iter)),
      static_cast<std::size_t>(std::distance(std::cbegin(vec), finish_iter)));
}
}  // namespace arrays
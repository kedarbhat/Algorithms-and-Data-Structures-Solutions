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

// https://www.hackerrank.com/challenges/minimum-swaps-2

#pragma once

#include <boost/range/irange.hpp>
#include <vector>

namespace {
std::size_t MinimumSwaps(const std::vector<std::size_t>& arr) {
  std::vector<bool> seen(arr.size());
  std::vector<std::size_t> elements(arr.size());
  for (auto idx : boost::irange<std::size_t>(0u, arr.size())) {
    elements[arr[idx] - 1] = idx;
  }

  std::size_t num_swaps = 0;
  for (auto current_element : boost::irange<std::size_t>(0u, elements.size())) {
    const auto actual_idx = elements[current_element];
    if (!(seen[current_element] || current_element == actual_idx)) {
      auto cycle_count = 0u;
      while (!seen[current_element]) {
        seen[current_element] = true;
        current_element = elements[current_element];
        ++cycle_count;
      }
      num_swaps += cycle_count - 1;
    }
  }
  return num_swaps;
}
}  // namespace
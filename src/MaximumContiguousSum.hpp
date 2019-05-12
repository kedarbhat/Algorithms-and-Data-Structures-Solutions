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
#include <vector>

namespace {

// Given an array of integers that can be both +ve and -ve, find the contiguous
// subarraywith the largest sum.e.g, [1,2,-1,2,-3,2,-5]  -> the first 4 elements
// have the largest sum.

template <typename T>
T getMaximumContiguousSum(std::vector<T>& vec) {
  if (vec.empty()) {
    return 0;
  }

  auto numNegativeElements = std::count_if(std::begin(vec), std::end(vec),
                                           [](auto&& i) { return i < 0; });
  if (numNegativeElements == vec.size()) {
    return *std::max_element(std::begin(vec), std::end(vec));
  }

  auto currentMaximum = std::max(0, vec[0]);
  for (auto idx = 1; idx < vec.size(); ++idx) {
    vec[idx] = std::max(vec[idx - 1] + vec[idx], 0);
    currentMaximum = std::max(currentMaximum, vec[idx]);
  }

  return currentMaximum;
}
}  // namespace
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

namespace {
template <typename T>
using diff_t = typename std::vector<T>::difference_type;

template <typename T>
using size_type = typename std::vector<T>::size_type;

void dnfPartition(std::vector<int>& vec, size_type<int> pivotIdx) {
  if (vec.empty() || pivotIdx >= vec.size()) {
    return;
  }

  auto pivot = vec[pivotIdx];
  auto lowIdx = size_type<int>(0);
  auto midIdx = size_type<int>(0);
  auto highIdx = vec.size();
  while (midIdx < highIdx) {
    auto currentElement = vec[midIdx];
    if (currentElement > pivot) {
      std::swap(vec[highIdx - 1], vec[midIdx]);
      --highIdx;
    } else if (currentElement < pivot) {
      if (lowIdx < midIdx) {
        std::swap(vec[lowIdx], vec[midIdx]);
      }
      ++lowIdx;
      ++midIdx;
    } else {
      assert(vec[midIdx] == pivot);
      ++midIdx;
    }
    assert(std::all_of(std::begin(vec), std::begin(vec) + diff_t<int>(lowIdx),
                       [pivot](auto&& i) { return i < pivot; }));
    assert(std::all_of(std::begin(vec) + diff_t<int>(lowIdx),
                       std::begin(vec) + diff_t<int>(midIdx),
                       [pivot](auto&& i) { return i == pivot; }));
    assert(std::all_of(std::begin(vec) + diff_t<int>(highIdx), std::end(vec),
                       [pivot](auto&& i) { return i > pivot; }));
  }
}
}  // namespace
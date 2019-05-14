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

void DnfPartition(std::vector<int>& vec, size_type<int> pivot_idx) {
  if (vec.empty() || pivot_idx >= vec.size()) {
    return;
  }

  auto pivot = vec[pivot_idx];
  auto low_idx = size_type<int>(0);
  auto mid_idx = size_type<int>(0);
  auto high_idx = vec.size();
  while (mid_idx < high_idx) {
    auto current_element = vec[mid_idx];
    if (current_element > pivot) {
      std::swap(vec[high_idx - 1], vec[mid_idx]);
      --high_idx;
    } else if (current_element < pivot) {
      if (low_idx < mid_idx) {
        std::swap(vec[low_idx], vec[mid_idx]);
      }
      ++low_idx;
      ++mid_idx;
    } else {
      assert(vec[mid_idx] == pivot);
      ++mid_idx;
    }
    assert(std::all_of(std::begin(vec), std::begin(vec) + diff_t<int>(low_idx),
                       [pivot](auto&& i) { return i < pivot; }));
    assert(std::all_of(std::begin(vec) + diff_t<int>(low_idx),
                       std::begin(vec) + diff_t<int>(mid_idx),
                       [pivot](auto&& i) { return i == pivot; }));
    assert(std::all_of(std::begin(vec) + diff_t<int>(high_idx), std::end(vec),
                       [pivot](auto&& i) { return i > pivot; }));
  }
}
}  // namespace
/*
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

namespace {
// Given an array of integers, find the continuous subarray, which when sorted,
// results in the entire array being sorted. For example: A = [0,2,5,3,1,8,6,9],
// result is the subarray [2,5,3,1,8,6]

template <typename T>
using diff_t = typename std::vector<T>::difference_type;

template <typename T>
using size_type = typename std::vector<T>::size_type;

template <typename T>
std::pair<size_type<T>, size_type<T>> FindUnsortedSubarray(
    const std::vector<T> &vec) noexcept {
  if (vec.empty()) {
    return std::make_pair(std::numeric_limits<size_type<T>>::max(),
                          std::numeric_limits<size_type<T>>::max());
  }

  auto i = size_type<T>(0);
  auto j = vec.size() - 1;
  assert(i <= j);

  // check for "unsortedness" (assuming non-decreasing order is correct)
  while (i + 1 < vec.size() && vec[i] <= vec[i + 1]) {
    ++i;
  }

  // check for "unsortedness" (assuming non-decreasing order is correct)
  while (j >= 1 && vec[j] >= vec[j - 1]) {
    --j;
  }

  if (i == vec.size() - 1) {
    assert(j == 0);
    return std::make_pair(i, j);
  }

  assert(i <= j);
  auto subrange_min_max_iters = std::minmax_element(
      std::begin(vec) + diff_t<T>(i), std::begin(vec) + diff_t<T>(j) + 1);
  auto subrange_min_element = *subrange_min_max_iters.first;
  auto subrange_max_element = *subrange_min_max_iters.second;
  while (i > 0 && vec[i - 1] > subrange_min_element) {
    --i;
  }

  while (j + 1 < vec.size() && vec[j + 1] < subrange_max_element) {
    ++j;
  }

  return std::make_pair(i, j);
}

}  // namespace

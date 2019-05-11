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

template<typename T>
using diff_t = typename std::vector<T>::difference_type;

template<typename T>
using size_type = typename std::vector<T>::size_type;

template <typename T>
std::pair<size_type<T>, size_type<T>> findUnsortedSubarray(const std::vector<T> &vec) noexcept {
  auto i = size_type<T>{0};
  auto j = vec.size() - 1;
  for (auto idx = 0; idx + 1 < vec.size(); ++idx) {
    if (vec[idx] > vec[idx + 1]) {
      i = idx;
      break;
    }
  }

  for (auto idx = vec.size() - 1u; idx > 0u; --idx) {
    if (vec[idx] < vec[idx - 1]) {
      j = idx;
      break;
    }
  }

  auto minmaxPair =
      std::minmax_element(std::begin(vec) + i, std::begin(vec) + j + 1);
  while (i > 0 && vec[i - 1] > *(minmaxPair.first)) {
    --i;
  }

  while (j < (vec.size() - 1) && vec[j + 1] < *(minmaxPair.second)) {
    --j;
  }

  return std::make_pair(i, j);
}

} // namespace

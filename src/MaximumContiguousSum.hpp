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
#include <numeric>
#include <unordered_map>
#include <vector>

namespace {

// Given an array of integers that can be both +ve and -ve, find the contiguous
// subarray with the largest sum.e.g, [1,2,-1,2,-3,2,-5]  -> the first 4
// elements have the largest sum.

template <typename T>
T getMaximumContiguousSum(std::vector<T> &vec) noexcept {
  if (vec.empty()) {
    return 0;
  }

  auto numNegativeElements = std::count_if(std::begin(vec), std::end(vec),
                                           [](auto &&i) { return i < 0; });
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

// Given an array of positive integers, find a subarray that sums to a given
// number X.
template <typename T>
std::pair<std::size_t, std::size_t> getMaximumContiguousSum(
    const std::vector<T> &vec, const T &target) noexcept {
  if (vec.empty()) {
    return std::make_pair(std::size_t{0}, std::size_t{0});
  }

  assert(std::all_of(std::cbegin(vec), std::cend(vec),
                     [](auto &&i) { return i >= 0; }));
  auto start = std::cbegin(vec);
  auto finish = std::cbegin(vec);
  auto sum = *start;
  while (start != std::cend(vec) && finish != std::cend(vec)) {
    if (std::distance(start, finish) < 0) {
      finish = start;
      sum = *start;
    } else if (sum < target) {
      std::advance(finish, 1);
      if (finish != std::cend(vec)) {
        sum += *finish;
      }
    } else if (sum > target) {
      sum -= *start;
      std::advance(start, 1);
    } else {
      return std::make_pair(
          static_cast<std::size_t>(std::distance(std::cbegin(vec), start)),
          static_cast<std::size_t>(std::distance(std::cbegin(vec), finish) +
                                   1));
    }
  }
  return std::make_pair(vec.size(), vec.size() + 1u);
}

template <typename T>
std::pair<std::size_t, std::size_t> getMaximumContiguousSumTargetZero(
    std::vector<T> &vec) noexcept {
  if (vec.empty()) {
    return std::make_pair(std::size_t{0}, std::size_t{0});
  }

  auto maxSum = vec[0];
  for (auto i : boost::irange<std::size_t>(1u, vec.size())) {
    vec[i] += vec[i - 1];
  }
  auto zeroElementIter = std::find(std::cbegin(vec), std::cend(vec), T{0});
  if (zeroElementIter != std::cend(vec)) {
    return std::make_pair(
        std::size_t{0},
        static_cast<std::size_t>(
            std::distance(std::cbegin(vec), zeroElementIter) + 1));
  }

  std::unordered_map<int, std::size_t> commonDiffMap;
  for (auto i : boost::irange<std::size_t>(vec.size())) {
    auto iter = commonDiffMap.find(vec[i]);
    if (iter == std::cend(commonDiffMap)) {
      commonDiffMap[vec[i]] = i;
    } else {
      return std::make_pair(iter->second + 1, i + 1);
    }
  }
  return std::make_pair(vec.size(), vec.size() + 1u);
}
}  // namespace
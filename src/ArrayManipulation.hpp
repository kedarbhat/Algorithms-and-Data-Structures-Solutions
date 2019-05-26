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

// https://www.hackerrank.com/challenges/crush/problem

#pragma once

#include <algorithm>
#include <boost/range/irange.hpp>
#include <vector>

namespace arrays {
int64_t ArrayManipulation(int n, std::vector<std::vector<int>> queries) {
  std::vector<int64_t> vec(n + 1, 0);
  for (auto &&query : queries) {
    auto start_idx = query[0] - 1;
    auto finish_idx = query[1];
    vec[start_idx] += query[2];
    vec[finish_idx] -= query[2];
  }
  auto max_sum = vec[0];

  for (auto idx : boost::irange<std::size_t>(1u, vec.size())) {
    vec[idx] += vec[idx - 1u];
    max_sum = std::max(max_sum, vec[idx]);
  }
  return max_sum;
}
}  // namespace arrays

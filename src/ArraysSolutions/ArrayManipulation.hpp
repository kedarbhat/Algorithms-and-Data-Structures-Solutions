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
#include <vector>

namespace arrays {
int64_t ArrayManipulation(int n, std::vector<std::vector<int>> queries) {
  std::vector<int64_t> vec(n, 0);
  for (auto &&query : queries) {
    auto startIdx = query[0] - 1;
    auto finishIdx = query[1];
    vec[startIdx] += query[2];
    vec[finishIdx] -= query[2];
  }
  auto maxSum = vec[0];
  for (auto idx = 1u; idx < vec.size(); ++idx) {
    vec[idx] += vec[idx - 1u];
    maxSum = std::max(maxSum, vec[idx]);
  }
  return maxSum;
}
}  // namespace arrays

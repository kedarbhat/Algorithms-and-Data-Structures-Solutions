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

// https://www.hackerrank.com/challenges/2d-array/problem

#pragma once

namespace hourGlassSum {
int hourglassSum(const std::vector<std::vector<int>>& arr,
                 const std::pair<std::size_t, std::size_t>& center) {
  auto x = center.first;
  auto y = center.second;
  return arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y] +
         arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1];
}

int hourglassSum(const std::vector<std::vector<int>>& arr) {
  auto max_sum = std::numeric_limits<int>::lowest();
  for (std::size_t x = 1; x + 1 < arr.size(); ++x) {
    for (std::size_t y = 1; y + 1 < arr[x].size(); ++y) {
      max_sum = std::max<int>(max_sum, hourglassSum(arr, std::make_pair(x, y)));
    }
  }
  return max_sum;
}
}  // namespace hourGlassSum
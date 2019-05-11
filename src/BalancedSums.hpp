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

// https://www.hackerrank.com/challenges/sherlock-and-array/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#pragma once
#include <string>
#include <vector>

namespace arrays {
std::string BalancedSums(std::vector<int> arr) {
  // Note: this is not an ideal solution; memory is wasted on the second array,
  // and we do 3 passes instead of 1. A 1 pass solution involves some indexing
  // arithmetic (using both a right-to-left and a left-to-right index that can
  // quickly become messy, so I opted for this in the interests of time.
  std::vector<int> rightToLeft_arr(begin(arr), end(arr));
  for (auto idx = 1u; idx < arr.size(); ++idx) {
    arr[idx] += arr[idx - 1];
    rightToLeft_arr[arr.size() - 1u - idx] += rightToLeft_arr[arr.size() - idx];
  }
  for (auto idx = 0u; idx < arr.size(); ++idx) {
    arr[idx] -= rightToLeft_arr[idx];
  }

  return std::find(begin(arr), end(arr), 0) == end(arr) ? "NO" : "YES";
}
}  // namespace arrays
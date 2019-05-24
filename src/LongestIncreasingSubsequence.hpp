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

#include <vector>

namespace {
// index magic to achieve better performance than the canonical O(n**2) solution
// (O(n*log(n)))
int LongestIncreasingSubsequence(const std::vector<int>& arr) {
  std::vector<int> tails(arr.size());
  auto longest_subsequence_length = 0;
  for (auto n : arr) {
    auto i = 0, j = longest_subsequence_length;
    while (i < j) {
      auto mid_idx = i + (j - i) / 2;
      if (tails[mid_idx] < n) {
        i = mid_idx + 1;
      } else {
        j = mid_idx;
      }
    }
    tails[i] = n;
    longest_subsequence_length = std::max(longest_subsequence_length, i + 1);
  }
  return longest_subsequence_length;
}
}  // namespace
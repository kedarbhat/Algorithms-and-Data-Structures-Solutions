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

namespace arrays {
enum Colors { RED = 0, WHITE = 1, BLUE = 2 };

void SortThreeEnumArrays(std::vector<Colors>& vec) {
  using SizeType = typename std::vector<Colors>::size_type;
  auto pivot = Colors::WHITE;

  auto low_idx = SizeType(0);
  auto mid_idx = SizeType(0);
  auto high_idx = vec.size();
  while (mid_idx < high_idx) {
    auto current = vec[mid_idx];
    if (pivot < current) {
      std::swap(vec[mid_idx], vec[high_idx - 1]);
      --high_idx;
    } else if (pivot > current) {
      if (mid_idx > low_idx) {
        std::swap(vec[low_idx], vec[mid_idx]);
      }
      ++low_idx;
      ++mid_idx;
    } else {
      ++mid_idx;
    }
  }
}
}  // namespace arrays
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
enum Colors { Red = 0, White = 1, Blue = 2 };

void sortThreeEnumArrays(std::vector<Colors>& vec) {
  using size_type = typename std::vector<Colors>::size_type;
  auto pivot = Colors::White;

  auto lowIdx = size_type(0);
  auto midIdx = size_type(0);
  auto highIdx = vec.size();
  while (midIdx < highIdx) {
    auto current = vec[midIdx];
    if (pivot < current) {
      std::swap(vec[midIdx], vec[highIdx - 1]);
      --highIdx;
    } else if (pivot > current) {
      if (midIdx > lowIdx) {
        std::swap(vec[lowIdx], vec[midIdx]);
      }
      ++lowIdx;
      ++midIdx;
    } else {
      ++midIdx;
    }
  }
}
}  // namespace
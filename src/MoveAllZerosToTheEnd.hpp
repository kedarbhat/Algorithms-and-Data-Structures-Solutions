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
void MoveAllZerosToTheEnd(std::vector<int>& vec) {
  using size_type = typename std::vector<int>::size_type;
  auto low_idx = size_type(0);
  auto high_idx = vec.size();
  while (low_idx < high_idx) {
    auto current = vec[low_idx];
    if (current == 0) {
      if (vec[high_idx - 1] != 0) {
        std::swap(vec[low_idx], vec[high_idx - 1]);
      }
      --high_idx;
    } else {
      ++low_idx;
    }
  }
}
}  // namespace
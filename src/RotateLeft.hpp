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

// https://www.hackerrank.com/challenges/array-left-rotation/problem

#pragma once

#include <algorithm>
#include <vector>

namespace arrays {
std::vector<int> RotateLeft(std::vector<int> arr, int64_t rotations) {
  std::reverse(std::begin(arr), std::begin(arr) + rotations);
  std::reverse(std::begin(arr) + rotations, std::end(arr));
  std::reverse(std::begin(arr), std::end(arr));
  return arr;
}
}  // namespace arrays
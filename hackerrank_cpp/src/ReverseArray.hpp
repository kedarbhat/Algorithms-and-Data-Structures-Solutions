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

// https://www.hackerrank.com/challenges/arrays-ds/problem

#pragma once

namespace reverseArray {
std::vector<int> reverseArray(std::vector<int> a) {
  for (std::size_t idx = 0; 2 * idx < a.size(); ++idx) {
    std::swap(a[idx], a[a.size() - 1 - idx]);
  }
  return a;
}
}  // namespace reverseArray
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

// https://www.hackerrank.com/challenges/dynamic-array/problem

#pragma once

namespace arrays {
std::vector<int> dynamicArray(int n,
                              const std::vector<std::vector<int>> &queries) {
  std::vector<int> result;
  std::vector<std::vector<int>> seqList(n);
  int lastAnswer = 0;
  for (const auto &query : queries) {
    // casting to unsigned due to bitwise operation
    auto &seq = seqList[(static_cast<unsigned>(query[1]) ^
                         static_cast<unsigned>(lastAnswer)) %
                        n];
    if (query[0] == 1) {
      seq.emplace_back(query[2]);
    } else {
      lastAnswer = seq[query[2] % seq.size()];
      result.emplace_back(lastAnswer);
    }
  }
  return result;
}
}  // namespace arrays
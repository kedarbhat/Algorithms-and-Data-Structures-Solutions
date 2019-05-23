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
#include <boost/range/irange.hpp>
#include <cmath>
#include <vector>
std::vector<int> longestCommonSubsequence(const std::vector<int>& a,
                                          const std::vector<int>& b) {
  // minimize number of rows
  const std::vector<int>& lhs = a.size() > b.size() ? b : a;
  const std::vector<int>& rhs = a.size() > b.size() ? a : b;

  // row/column == 0 -> all zeros
  std::vector<std::vector<int>> matrix(lhs.size() + 1,
                                       std::vector<int>(rhs.size() + 1, 0));
  for (auto row : boost::irange<std::size_t>(1u, lhs.size() + 1)) {
    for (auto col : boost::irange<std::size_t>(1u, rhs.size() + 1)) {
      if (lhs[row - 1] == rhs[col - 1]) {
        // add from a diagonal cell (up/left)
        matrix[row][col] = matrix[row - 1][col - 1] + 1;
      } else {
        matrix[row][col] = std::max(matrix[row][col - 1], matrix[row - 1][col]);
      }
    }
  }

  // when doing the backtrack to get the final result, move as far left and up
  // as possible before grabbing an element
  std::vector<int> result;
  for (auto row = lhs.size(), col = rhs.size(); row > 0u && col > 0u;) {
    if (matrix[row - 1][col] == matrix[row][col]) {
      --row;
    } else if (matrix[row][col - 1] == matrix[row][col]) {
      --col;
    } else {
      assert(matrix[row - 1][col - 1] + 1 == matrix[row][col]);
      result.emplace_back(lhs[row - 1]);
      --row;
      --col;
    }
  }

  return {std::rbegin(result), std::rend(result)};
}
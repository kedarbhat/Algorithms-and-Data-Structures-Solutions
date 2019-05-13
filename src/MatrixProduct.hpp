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

#include <algorithm>
#include <boost/range/irange.hpp>
#include <exception>

namespace {
// Compute maximum product of matrix elements by moving only "down" and "to the
// right".
// TODO(kbhat): Replace two dimensional container for a single type (wrapping a
// std::array), using striding to emulate 2-dimensions

using row_type = std::vector<int>;
using matrix_type = std::vector<row_type>;

int matrixProduct(const matrix_type& matrix) {
  if (matrix.empty() || matrix.front().empty()) {
    throw std::invalid_argument("Matrix must have valid dimensions!");
  }

  const auto numRows = matrix.size();
  const auto numColumns = matrix.front().size();

  matrix_type maxProductMatrix(numRows, row_type(numColumns));
  matrix_type minProductMatrix(numRows, row_type(numColumns));

  for (auto i : boost::irange<std::size_t>(numRows)) {
    for (auto j : boost::irange<std::size_t>(numColumns)) {
      auto maxValue_ij =
          i == 0 && j == 0 ? matrix[i][j] : std::numeric_limits<int>::lowest();
      auto minValue_ij =
          i == 0 && j == 0 ? matrix[i][j] : std::numeric_limits<int>::max();

      if (i > 0) {
        const auto& original_ij = matrix[i][j];
        maxValue_ij = std::max(
            maxValue_ij, std::max(original_ij * maxProductMatrix[i - 1][j],
                                  original_ij * minProductMatrix[i - 1][j]));
        minValue_ij = std::min(
            minValue_ij, std::min(original_ij * maxProductMatrix[i - 1][j],
                                  original_ij * minProductMatrix[i - 1][j]));
      }

      if (j > 0) {
        maxValue_ij = std::max(
            maxValue_ij, std::max(matrix[i][j] * maxProductMatrix[i][j - 1],
                                  matrix[i][j] * minProductMatrix[i][j - 1]));
        minValue_ij = std::min(
            minValue_ij, std::min(matrix[i][j] * maxProductMatrix[i][j - 1],
                                  matrix[i][j] * minProductMatrix[i][j - 1]));
      }

      maxProductMatrix[i][j] = maxValue_ij;
      minProductMatrix[i][j] = minValue_ij;
    }
  }

  return maxProductMatrix.back().back();
}
}  // namespace
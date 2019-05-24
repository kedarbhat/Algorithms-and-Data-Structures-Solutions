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

using RowType = std::vector<int>;
using MatrixType = std::vector<RowType>;

int MatrixProduct(const MatrixType& matrix) {
  if (matrix.empty() || matrix.front().empty()) {
    throw std::invalid_argument("Matrix must have valid dimensions!");
  }

  const auto num_rows = matrix.size();
  const auto num_columns = matrix.front().size();

  MatrixType max_product_matrix(num_rows, RowType(num_columns));
  MatrixType min_product_matrix(num_rows, RowType(num_columns));

  for (auto i : boost::irange<std::size_t>(0u, num_rows)) {
    for (auto j : boost::irange<std::size_t>(0u, num_columns)) {
      auto max_value_ij =
          i == 0 && j == 0 ? matrix[i][j] : std::numeric_limits<int>::lowest();
      auto min_value_ij =
          i == 0 && j == 0 ? matrix[i][j] : std::numeric_limits<int>::max();

      if (i > 0) {
        const auto& original_ij = matrix[i][j];
        max_value_ij = std::max(
            max_value_ij, std::max(original_ij * max_product_matrix[i - 1][j],
                                   original_ij * min_product_matrix[i - 1][j]));
        min_value_ij = std::min(
            min_value_ij, std::min(original_ij * max_product_matrix[i - 1][j],
                                   original_ij * min_product_matrix[i - 1][j]));
      }

      if (j > 0) {
        max_value_ij =
            std::max(max_value_ij,
                     std::max(matrix[i][j] * max_product_matrix[i][j - 1],
                              matrix[i][j] * min_product_matrix[i][j - 1]));
        min_value_ij =
            std::min(min_value_ij,
                     std::min(matrix[i][j] * max_product_matrix[i][j - 1],
                              matrix[i][j] * min_product_matrix[i][j - 1]));
      }

      max_product_matrix[i][j] = max_value_ij;
      min_product_matrix[i][j] = min_value_ij;
    }
  }

  return max_product_matrix.back().back();
}
}  // namespace
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
#include <gtest/gtest.h>

#include "MatrixProduct.hpp"

namespace {
TEST(TestMatrixProduct, EmptyMatrix) {
  matrix_type matrix;
  ASSERT_THROW(MatrixProduct(matrix), std::invalid_argument);
}

TEST(TestMatrixProduct, AllPositiveCells) {
  matrix_type matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ASSERT_EQ(MatrixProduct(matrix), 2016);
}

TEST(TestMatrixProduct, OneNegativeCell) {
  matrix_type matrix{{-1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ASSERT_EQ(MatrixProduct(matrix), -324);
}

TEST(TestMatrixProduct, TwoNegativeCells) {
  matrix_type matrix{{-1, 2, 3}, {4, 5, -6}, {7, 8, 9}};
  ASSERT_EQ(MatrixProduct(matrix), 1080);
}

TEST(TestMatrixProduct, AllNegativeCells) {
  matrix_type matrix{{-1, -2, -3, -4}, {-5, -6, -7, -8}, {-9, -10, -11, -12}};
  ASSERT_EQ(MatrixProduct(matrix), 59400);
}

}  // namespace
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
#include "ProductsOfAllIntsExceptAtIndex.hpp"

namespace {
TEST(TestGetProductsOfAllIntsExceptAtIndex, small_vector) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({2, 4, 10});
  const auto expected = std::vector<int>{40, 20, 8};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, small_vector2) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({1, 2, 3});
  const auto expected = std::vector<int>{6, 3, 2};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, longer_vector) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
  const auto expected = std::vector<int>{120, 480, 240, 320, 960, 192};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, vector_has_one_zero) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
  const auto expected = std::vector<int>{0, 0, 36, 0};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, vector_has_two_zeros) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
  const auto expected = std::vector<int>{0, 0, 0, 0, 0};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, one_negative_number) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({-3, 8, 4});
  const auto expected = std::vector<int>{32, -12, -24};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, all_negative_numbers) {
  const auto actual = ProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
  const auto expected = std::vector<int>{-8, -56, -14, -28};
  ASSERT_EQ(actual, expected);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, error_with_empty_vector) {
  ASSERT_THROW(ProductsOfAllIntsExceptAtIndex({}), std::invalid_argument);
}

TEST(TestGetProductsOfAllIntsExceptAtIndex, error_with_one_number) {
  ASSERT_THROW(ProductsOfAllIntsExceptAtIndex({1}), std::invalid_argument);
}
}  // namespace
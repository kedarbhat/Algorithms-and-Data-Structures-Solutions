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
#include "MergeVectors.hpp"

namespace {
TEST(TestMergeVectors, both_vectors_are_empty) {
  const std::vector<int> my_vector;
  const std::vector<int> alices_vector;
  const std::vector<int> expected;
  const auto actual = merge_vectors::MergeVectors(my_vector, alices_vector);
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeVectors, first_vector_is_empty) {
  const std::vector<int> my_vector;
  const std::vector<int> alices_vector{1, 2, 3};
  const std::vector<int> expected{1, 2, 3};
  const auto actual = merge_vectors::MergeVectors(my_vector, alices_vector);
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeVectors, second_vector_is_empty) {
  const std::vector<int> my_vector{5, 6, 7};
  const std::vector<int> alices_vector;
  const std::vector<int> expected{5, 6, 7};
  const auto actual = merge_vectors::MergeVectors(my_vector, alices_vector);
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeVectors, both_vectors_have_some_numbers) {
  const std::vector<int> my_vector{2, 4, 6};
  const std::vector<int> alices_vector{1, 3, 7};
  const std::vector<int> expected{1, 2, 3, 4, 6, 7};
  const auto actual = merge_vectors::MergeVectors(my_vector, alices_vector);
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeVectors, vectors_are_different_lengths) {
  const std::vector<int> my_vector{2, 4, 6, 8};
  const std::vector<int> alices_vector{1, 7};
  const std::vector<int> expected{1, 2, 4, 6, 7, 8};
  const auto actual = merge_vectors::MergeVectors(my_vector, alices_vector);
  ASSERT_EQ(actual, expected);
}
}  // namespace
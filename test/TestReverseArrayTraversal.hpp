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

#pragma once
#include <gtest/gtest.h>
#include "ReverseArrayTraversal.hpp"
namespace {
TEST(TestReverseArrayTraversal, EmptyVector) {
  std::vector<int64_t> vec(0);
  const auto expected = vec;
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, AllOdd) {
  std::vector<int64_t> vec{1, 3, 5};
  const auto expected = vec;
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, AllEven) {
  std::vector<int64_t> vec{2, 4, 6};
  const auto expected = std::vector<int64_t>{2, 2, 4, 4, 6, 6};
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, OneOdd) {
  std::vector<int64_t> vec{1};
  const auto expected = vec;
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, OneEven) {
  std::vector<int64_t> vec{2};
  const auto expected = std::vector<int64_t>{2, 2};
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, Mixed) {
  std::vector<int64_t> vec{1, 2, 5, 6, 8};
  const auto expected = std::vector<int64_t>{1, 2, 2, 5, 6, 6, 8, 8};
  ReverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

}  // namespace
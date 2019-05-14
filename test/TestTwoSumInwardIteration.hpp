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

#include "TwoSumInwardIteration.hpp"

namespace {

TEST(TestTwoSumInwardIteration, EmptyArray) {
  std::vector<int> vec;
  const auto& expected = std::make_pair(vec.size(), vec.size());
  ASSERT_EQ(TwoSumInwardIteration(vec, 0), expected);
}

TEST(TestTwoSumInwardIteration, OneElementArray) {
  std::vector<int> vec{1};
  const auto& expected = std::make_pair(vec.size(), vec.size());
  ASSERT_EQ(TwoSumInwardIteration(vec, vec[0]), expected);
}

TEST(TestTwoSumInwardIteration, TwoElementsWithSum) {
  std::vector<int> vec{1, 2};
  const auto& expected = std::make_pair(std::size_t{0}, std::size_t{1});
  ASSERT_EQ(TwoSumInwardIteration(vec, 3), expected);
}

TEST(TestTwoSumInwardIteration, TwoElementsWithoutSum) {
  std::vector<int> vec{1, 2};
  const auto& expected = std::make_pair(std::size_t{1}, std::size_t{1});
  ASSERT_EQ(TwoSumInwardIteration(vec, 4), expected);
}

TEST(TestTwoSumInwardIteration, NormalArray) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
  const auto& expected = std::make_pair(std::size_t{3}, std::size_t{6});
  ASSERT_EQ(TwoSumInwardIteration(vec, 11), expected);
}

}  // namespace
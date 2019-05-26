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
#include "SortScores.hpp"

namespace {

TEST(TestSortScores, no_scores) {
  const std::vector<int> scores;
  const std::vector<int> expected;
  const auto actual = SortScores(scores, 100);
  ASSERT_EQ(actual, expected);
}

TEST(TestSortScores, one_score) {
  const std::vector<int> scores{55};
  const std::vector<int> expected{55};
  const auto actual = SortScores(scores, 100);
  ASSERT_EQ(actual, expected);
}

TEST(TestSortScores, two_scores) {
  const std::vector<int> scores{30, 60};
  const std::vector<int> expected{60, 30};
  const auto actual = SortScores(scores, 100);
  ASSERT_EQ(actual, expected);
}

TEST(TestSortScores, many_scores) {
  const std::vector<int> scores{37, 89, 41, 65, 91, 53};
  const std::vector<int> expected{91, 89, 65, 53, 41, 37};
  const auto actual = SortScores(scores, 100);
  ASSERT_EQ(actual, expected);
}

TEST(TestSortScores, repeated_scores) {
  const std::vector<int> scores{20, 10, 30, 30, 10, 20};
  const std::vector<int> expected{30, 30, 20, 20, 10, 10};
  const auto actual = SortScores(scores, 100);
  ASSERT_EQ(actual, expected);
}

}  // namespace
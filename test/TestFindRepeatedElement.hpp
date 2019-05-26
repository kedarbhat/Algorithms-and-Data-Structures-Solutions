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

#include "FindRepeatedElement.hpp"

namespace {
TEST(TestFindRepeatedElement, just_the_repeated_number) {
  const std::vector<unsigned int> numbers{1, 1};
  const auto expected = 1;
  const auto actual = interview_cake::FindRepeat(numbers);
  ASSERT_EQ(actual, expected);
}

TEST(TestFindRepeatedElement, short_vector) {
  const std::vector<unsigned int> numbers{1, 2, 3, 2};
  const auto expected = 2;
  const auto actual = interview_cake::FindRepeat(numbers);
  ASSERT_EQ(actual, expected);
}

TEST(TestFindRepeatedElement, medium_vector) {
  const std::vector<unsigned int> numbers{1, 2, 5, 5, 5, 5};
  const auto expected = 5;
  const auto actual = interview_cake::FindRepeat(numbers);
  ASSERT_EQ(actual, expected);
}

TEST(TestFindRepeatedElement, long_vector) {
  const std::vector<unsigned int> numbers{4, 1, 4, 8, 3, 2, 7, 6, 5};
  const auto expected = 4;
  const auto actual = interview_cake::FindRepeat(numbers);
  ASSERT_EQ(actual, expected);
}
}  // namespace
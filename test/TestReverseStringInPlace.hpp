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
#include "ReverseStringInPlace.hpp"

namespace {
TEST(TestReverseStringInPlace, empty_string) {
  const std::string expected;
  std::string actual;
  reverse_string_inplace::reverse(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseStringInPlace, single_character_string) {
  const std::string expected("A");
  std::string actual("A");
  reverse_string_inplace::reverse(actual);
  ASSERT_EQ(actual, expected);
}

TEST(TestReverseStringInPlace, longer_string) {
  const std::string expected("EDCBA");
  std::string actual("ABCDE");
  reverse_string_inplace::reverse(actual);
  ASSERT_EQ(actual, expected);
}
}  // namespace
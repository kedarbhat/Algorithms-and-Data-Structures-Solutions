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

#include "CountingValleys.hpp"

namespace {
TEST(TestCountingValleys, NoValleys) {
  ASSERT_EQ(0, counting_valleys::CountingValleys("UUUUU"));
}

TEST(TestCountingValleys, HackerRankExample) {
  ASSERT_EQ(1, counting_valleys::CountingValleys("UDDDUDUU"));
}

TEST(TestCountingValleys, InvalidInput) {
  ASSERT_THROW(counting_valleys::CountingValleys("UXDDDUE"),
               std::invalid_argument);
}
}  // namespace
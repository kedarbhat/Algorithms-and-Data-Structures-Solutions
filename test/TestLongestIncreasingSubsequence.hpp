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

#include <gtest/gtest.h>

#include "LongestIncreasingSubsequence.hpp"

namespace {
TEST(TestLongestIncreasingSubsequence, EmptySequence) {
  ASSERT_EQ(LongestIncreasingSubsequence(std::vector<int>{}), 0);
}

TEST(TestLongestIncreasingSubsequence, SingleElementSequence) {
  ASSERT_EQ(LongestIncreasingSubsequence(std::vector<int>{15}), 1);
}

TEST(TestLongestIncreasingSubsequence, RegularSequence) {
  ASSERT_EQ(LongestIncreasingSubsequence(
                std::vector<int>{15, 27, 14, 38, 26, 55, 46, 65, 85}),
            6);
}
}  // namespace
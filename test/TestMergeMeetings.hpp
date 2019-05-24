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

#include "MergeMeetings.hpp"

namespace {
using Meeting = merge_meetings::Meeting;
TEST(TestMergeMeetings, meetings_overlap) {
  const auto meetings = std::vector<Meeting>{Meeting{1, 3}, Meeting{2, 4}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 4}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, meetings_touch) {
  const auto meetings = std::vector<Meeting>{Meeting{5, 6}, Meeting{6, 8}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{5, 8}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, meeting_contains_other_meeting) {
  const auto meetings = std::vector<Meeting>{Meeting{1, 8}, Meeting{2, 5}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 8}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, meeting_stay_separate) {
  const auto meetings = std::vector<Meeting>{Meeting{1, 3}, Meeting{4, 8}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 3}, Meeting{4, 8}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, multiple_merged_meetings) {
  const auto meetings =
      std::vector<Meeting>{Meeting{1, 4}, Meeting{2, 5}, Meeting{5, 8}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 8}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, meetings_not_sorted) {
  const auto meetings =
      std::vector<Meeting>{Meeting{5, 8}, Meeting{1, 4}, Meeting{6, 8}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 4}, Meeting{5, 8}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, one_long_meeting_contains_smaller_meetings) {
  const auto meetings =
      std::vector<Meeting>{Meeting{1, 10}, Meeting{2, 5}, Meeting{6, 8},
                           Meeting{9, 10}, Meeting{10, 12}};
  const auto actual = mergeRanges(meetings);
  const auto expected = std::vector<Meeting>{Meeting{1, 12}};
  ASSERT_EQ(actual, expected);
}

TEST(TestMergeMeetings, sample_input) {
  const auto meetings =
      std::vector<Meeting>{Meeting{0, 1}, Meeting{3, 5}, Meeting{4, 8},
                           Meeting{10, 12}, Meeting{9, 10}};
  const auto actual = mergeRanges(meetings);
  const auto expected =
      std::vector<Meeting>{Meeting{0, 1}, Meeting{3, 8}, Meeting{9, 12}};
  ASSERT_EQ(actual, expected);
}
}  // namespace
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

// https://www.interviewcake.com/question/cpp/merging-ranges?course=fc1&section=array-and-string-manipulation
#pragma once

#include <cmath>
#include <vector>

namespace merge_meetings {
struct Meeting {
  unsigned start_time_;
  unsigned end_time_;
};

constexpr bool operator==(const Meeting& lhs, const Meeting& rhs) noexcept {
  return lhs.start_time_ == rhs.start_time_ && lhs.end_time_ == rhs.end_time_;
}
constexpr bool MeetingContainsNextMeeting(const Meeting& lhs,
                                          const Meeting& rhs) noexcept {
  return lhs.start_time_ <= rhs.start_time_ && lhs.end_time_ >= rhs.end_time_;
}

constexpr bool MeetingsOverlap(const Meeting& lhs,
                               const Meeting& rhs) noexcept {
  return lhs.start_time_ <= rhs.end_time_ && lhs.end_time_ >= rhs.start_time_;
}

std::vector<Meeting> MergeRanges(const std::vector<Meeting>& meetings) {
  std::vector<Meeting> result{std::cbegin(meetings), std::cend(meetings)};
  std::sort(std::begin(result), std::end(result), [](auto&& lhs, auto&& rhs) {
    return lhs.start_time_ <= rhs.start_time_;
  });
  for (auto iter = std::begin(result);
       std::distance(iter, std::end(result)) > 1;) {
    const auto& curr_meeting = *iter;
    const auto& next_meeting = *std::next(iter);
    if (MeetingContainsNextMeeting(curr_meeting, next_meeting)) {
      // erase next meeting, don't advance the iterator
      result.erase(std::next(iter));
    } else if (MeetingsOverlap(curr_meeting, next_meeting)) {
      // overwrite current iterator, erase next element
      *iter =
          Meeting{std::min(curr_meeting.start_time_, next_meeting.start_time_),
                  std::max(curr_meeting.end_time_, next_meeting.end_time_)};
      result.erase(std::next(iter));
    } else {
      // meetings are separate, advance the iterator
      std::advance(iter, 1);
    }
  }
  result.shrink_to_fit();
  return result;
}

}  // namespace merge_meetings
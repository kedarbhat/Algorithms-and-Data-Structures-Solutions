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

#include <vector>
#include <cmath>

namespace merge_meetings {
struct Meeting {
  unsigned startTime_;
  unsigned endTime_;
};
 
constexpr bool operator==(const Meeting& lhs, const Meeting& rhs) noexcept {   
  return lhs.startTime_ == rhs.startTime_  && lhs.endTime_ == rhs.endTime_;
}
constexpr bool meetingContainsNextMeeting(const Meeting& lhs,
                                          const Meeting& rhs) noexcept {
  return lhs.startTime_ <= rhs.startTime_ &&
         lhs.endTime_ >= rhs.endTime_;
}

constexpr bool meetingsOverlap(const Meeting& lhs,
                               const Meeting& rhs) noexcept {
  return lhs.startTime_ <= rhs.endTime_ &&
         lhs.endTime_ >= rhs.startTime_;
}

std::vector<Meeting> mergeRanges(const std::vector<Meeting>& meetings) {
  std::vector<Meeting> result{std::cbegin(meetings), std::cend(meetings)};
  std::sort(std::begin(result), std::end(result), [](auto&& lhs, auto&& rhs) {
    return lhs.startTime_ <= rhs.startTime_;
  });
  for (auto iter = std::begin(result);
       std::distance(iter, std::end(result)) > 1;) {
    const auto& curr_meeting = *iter;
    const auto& next_meeting = *std::next(iter);
    if (meetingContainsNextMeeting(curr_meeting, next_meeting)) {
      // erase next meeting, don't advance the iterator
      result.erase(std::next(iter));
    } else if (meetingsOverlap(curr_meeting, next_meeting)) {
      // overwrite current iterator, erase next element
      *iter = Meeting{
          std::min(curr_meeting.startTime_, next_meeting.startTime_),
          std::max(curr_meeting.endTime_, next_meeting.endTime_)};
      result.erase(std::next(iter));
    } else {
      // meetings are separate, advance the iterator
      std::advance(iter, 1);
    }
  }
  result.shrink_to_fit();
  return result;
}

}
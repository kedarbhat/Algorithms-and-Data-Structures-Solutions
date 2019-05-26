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

// https://www.interviewcake.com/question/cpp/find-duplicate-optimize-for-space?course=fc1&section=sorting-searching-logarithms

#pragma once

#include <vector>

namespace interview_cake {

struct RangeType {
  std::size_t start_;
  std::size_t finish_;
};

unsigned int FindRepeat(const std::vector<unsigned int>& the_vector) {
  auto low_idx = std::size_t{1};
  auto high_idx = the_vector.size() - 1;
  while (low_idx < high_idx) {
    auto mid_idx = low_idx + (high_idx - low_idx) / 2;

    auto low_range = RangeType{low_idx, mid_idx};
    auto high_range = RangeType{mid_idx + 1, high_idx};

    auto low_range_count = static_cast<unsigned>(std::count_if(
        std::begin(the_vector), std::end(the_vector), [low_range](auto&& x) {
          return x >= low_range.start_ && x <= low_range.finish_;
        }));

    auto maximum_unique_low_range_ints =
        low_range.finish_ - low_range.start_ + 1;
    if (low_range_count > maximum_unique_low_range_ints) {
      low_idx = low_range.start_;
      high_idx = low_range.finish_;
    } else {
      low_idx = high_range.start_;
      high_idx = high_range.finish_;
    }
  }
  return low_idx;
}
}  // namespace interview_cake
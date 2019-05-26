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

// https://www.interviewcake.com/question/cpp/top-scores?course=fc1&section=hashing-and-hash-tables

#pragma once
#include <vector>

namespace interview_cake {
std::vector<int> SortScores(const std::vector<int>& unordered_scores,
                            int highest_possible_score) {
  if (std::is_sorted(std::cbegin(unordered_scores), std::cend(unordered_scores),
                     std::greater<>{})) {
    return {std::cbegin(unordered_scores), std::cend(unordered_scores)};
  }

  std::vector<int> counts(static_cast<std::size_t>(highest_possible_score + 1),
                          0);
  for (auto i : unordered_scores) {
    ++counts[i];
  }

  for (auto idx = 1u; idx < counts.size(); ++idx) {
    counts[idx] += counts[idx - 1];
  }

  std::vector<int> result(unordered_scores.size());
  for (auto iter = std::prev(std::cend(unordered_scores));
       std::distance(std::cbegin(unordered_scores), iter) >= 0;
       std::advance(iter, -1)) {
    auto element = *iter;
    result[counts[element] - 1] = element;
    --counts[element];
    assert(counts[element] >= 0);
  }

  return {std::crbegin(result), std::crend(result)};
}
}  // namespace interview_cake
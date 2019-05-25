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

// https://www.interviewcake.com/question/cpp/reverse-words?course=fc1&section=array-and-string-manipulation

#pragma once
#include <algorithm>
#include <cassert>
#include <string>

namespace {
void ReverseWords(std::string& message) {
  using DiffType = typename std::string::difference_type;
  using SizeType = typename std::string::size_type;
  // reverse the entire string
  std::reverse(std::begin(message), std::end(message));

  for (auto lhs_iter = std::begin(message);
       std::distance(lhs_iter, std::end(message)) > 0;) {
    auto space_idx = message.find_first_of(
        ' ',
        static_cast<SizeType>(std::distance(std::begin(message), lhs_iter)));
    auto rhs_iter =
        space_idx == std::string::npos
            ? std::end(message)
            : std::begin(message) + static_cast<DiffType>(space_idx);
    assert(rhs_iter == std::end(message) || std::isspace(*rhs_iter));

    // reverse [start of word, space)
    std::reverse(lhs_iter, rhs_iter);

    auto non_space_idx = message.find_first_not_of(
        ' ',
        static_cast<SizeType>(std::distance(std::begin(message), rhs_iter)));
    lhs_iter = non_space_idx == std::string::npos
                   ? std::end(message)
                   : std::begin(message) + static_cast<DiffType>(non_space_idx);
  }
}

}  // namespace
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

// https://www.interviewcake.com/question/cpp/merge-sorted-arrays?course=fc1&section=array-and-string-manipulation

#pragma once

#include <algorithm>
#include <vector>

namespace merge_vectors {
inline std::vector<int> MergeVectors(const std::vector<int>& my_vector,
                                     const std::vector<int>& alices_vector) {
  std::vector<int> result;
  result.reserve(my_vector.size() + alices_vector.size());
  auto my_iter = std::cbegin(my_vector);
  auto alices_iter = std::cbegin(alices_vector);

  while (std::distance(my_iter, std::cend(my_vector)) > 0 &&
         std::distance(alices_iter, std::cend(alices_vector)) > 0) {
    const auto my_value = *my_iter;
    const auto alices_value = *alices_iter;
    if (my_value < alices_value) {
      result.emplace_back(my_value);
      std::advance(my_iter, 1);
    } else {
      result.emplace_back(alices_value);
      std::advance(alices_iter, 1);
    }
  }

  // copy remaining characters
  std::copy(my_iter, std::cend(my_vector), std::back_inserter(result));
  std::copy(alices_iter, std::cend(alices_vector), std::back_inserter(result));

  return result;
}
}  // namespace merge_vectors
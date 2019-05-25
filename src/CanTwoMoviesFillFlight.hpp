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

// https://www.interviewcake.com/question/cpp/inflight-entertainment?course=fc1&section=hashing-and-hash-tables

#pragma once
#include <unordered_set>
#include <vector>

namespace {
bool CanTwoMoviesFillFlight(const std::vector<int>& movie_lengths,
                            int flight_length) {
  std::unordered_set<int> movie_lengths_set{};
  for (auto movie_length : movie_lengths) {
    if (movie_length >= flight_length) {
      continue;
    }
    auto target_movie_length = flight_length - movie_length;
    auto target_movie_length_iter = movie_lengths_set.find(target_movie_length);
    if (target_movie_length_iter == std::cend(movie_lengths_set)) {
      movie_lengths_set.emplace(movie_length);
    } else {
      return true;
    }
  }

  return false;
}
}  // namespace
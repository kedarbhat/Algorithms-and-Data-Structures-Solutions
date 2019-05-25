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
#include "CanTwoMoviesFillFlight.hpp"

namespace {
TEST(TestCanTwoMoviesFillFlight, short_flight) {
  const std::vector<int> movieLengths{2, 4};
  ASSERT_FALSE(CanTwoMoviesFillFlight(movieLengths, 1));
}

TEST(TestCanTwoMoviesFillFlight, long_flight) {
  const std::vector<int> movieLengths{2, 4};
  ASSERT_TRUE(CanTwoMoviesFillFlight(movieLengths, 6));
}

TEST(TestCanTwoMoviesFillFlight, only_one_movie_half_flight_length) {
  const std::vector<int> movieLengths{3, 8};
  ASSERT_FALSE(CanTwoMoviesFillFlight(movieLengths, 6));
}

TEST(TestCanTwoMoviesFillFlight, two_movies_half_flight_length) {
  const std::vector<int> movieLengths{3, 8, 3};
  ASSERT_TRUE(CanTwoMoviesFillFlight(movieLengths, 6));
}

TEST(TestCanTwoMoviesFillFlight, lots_of_possible_pairs) {
  const std::vector<int> movieLengths{1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(CanTwoMoviesFillFlight(movieLengths, 7));
}

TEST(TestCanTwoMoviesFillFlight, not_using_first_movie) {
  const std::vector<int> movieLengths{4, 3, 2};
  ASSERT_TRUE(CanTwoMoviesFillFlight(movieLengths, 5));
}

TEST(TestCanTwoMoviesFillFlight, only_one_movie) {
  const std::vector<int> movieLengths{6};
  ASSERT_FALSE(CanTwoMoviesFillFlight(movieLengths, 6));
}

TEST(TestCanTwoMoviesFillFlight, no_movies) {
  const std::vector<int> movieLengths;
  ASSERT_FALSE(CanTwoMoviesFillFlight(movieLengths, 6));
}

}  // namespace
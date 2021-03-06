/*
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

#pragma once

#include <string>

namespace counting_valleys {
unsigned CountingValleys(const std::string &s) {
  int current_depth = 0;
  unsigned num_valleys = 0;
  for (auto step : s) {
    switch (step) {
      case 'D': {
        if (current_depth == 0) {
          ++num_valleys;
        }
        --current_depth;
        break;
      }
      case 'U': {
        ++current_depth;
        break;
      }
      default:
        throw std::invalid_argument(std::addressof(step));
    }
  }
  return num_valleys;
}
}  // namespace counting_valleys
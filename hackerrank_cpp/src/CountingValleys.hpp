// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

#pragma once

#include <string>

namespace CountingValleys {
int countingValleys(int /*n*/, const std::string &s) noexcept {
  int currentDepth = 0;
  int numValleys = 0;
  for (auto step : s) {
    if (step == 'D') {
      if (currentDepth == 0) {
        ++numValleys;
      }
      --currentDepth;
    } else if (step == 'U') {
      ++currentDepth;
    }
  }
  return numValleys;
}
} // namespace CountingValleys
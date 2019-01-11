//
// Created by Kedar Bhat on 11/4/18.
//


#include <iostream>

template<uint64_t denom>
static constexpr uint64_t divSum(uint64_t maxNum) {
    return ((maxNum - 1) / denom) * ((maxNum-1) / denom + 1) / 2 * denom;
}

int main() {
  int numTestCases = 0;
  std::cin >> numTestCases;
  for(auto testCase = 0u; testCase < numTestCases; ++testCase) {
    uint64_t maxNum;
    std::cin >> maxNum;
    uint64_t total = divSum<5>(maxNum) + divSum<3>(maxNum) - divSum<15>(maxNum);
    std::cout << total << std::endl;
  }
  return 0;
}
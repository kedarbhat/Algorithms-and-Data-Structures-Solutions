//
// Created by Kedar Bhat on 11/4/18.
//

#include <iostream>

std::size_t getMaxPrime(std::size_t n) {
    while (n % 2 == 0) {
        n /= 2;
        if (n == 1) {
            return 2;
        }
    }
    for (std::size_t i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            std::size_t rhs = n / i;
            if (i >= rhs) {
                return rhs;
            }
            n /= i;
        }
    }
    return n;
}

int main() {
    int numTestCases;
    std::cin >> numTestCases;
    for (auto i = 0; i < numTestCases; ++i) {
        std::size_t n;
        std::cin >> n;
        std::cout << getMaxPrime(n) << std::endl;
    }
    return 0;
}
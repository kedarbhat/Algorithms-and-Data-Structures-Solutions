//
// Created by Kedar Bhat on 11/24/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

static std::vector<uint64_t> getPrimeProducts() {
    constexpr uint64_t maxBound { 1000000000000000000ULL };
    std::vector<uint64_t> primes{2u};
    std::vector<uint64_t> primeProducts{2u};
    for (uint64_t i = 3u; i < maxBound; ++i) {
        if (std::none_of(std::cbegin(primes), std::cend(primes),
                [i](auto&& primeElement) { return i % primeElement == 0; }))
        {
            if (primeProducts.back() * i < maxBound) {
                primeProducts.emplace_back(primeProducts.back() * i);
                primes.emplace_back(i);
            } else {
                break;
            }
        }
    }
    return primeProducts;
}

int primeCount(uint64_t n) {
    static std::vector<uint64_t> primeProducts = getPrimeProducts();
    auto iter = std::find_if(std::rbegin(primeProducts), std::rend(primeProducts), [n](auto&& primeProduct) {
       return primeProduct <= n;
    });
    return static_cast<int>(std::distance(iter, std::rend(primeProducts)));
}

int main() {
    std::cout << primeCount(uint64_t(10000000000ULL)) << std::endl;
    return 0;
}
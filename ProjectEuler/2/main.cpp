#include <limits>
#include <cstdint>
#include <iostream>
#include <utility>

template<uint64_t n>
constexpr uint64_t fib() {
    return fib<n-1>() + fib<n-2>();
}

template<>
constexpr uint64_t fib<1>() {
    return 2;
}

template<>
constexpr uint64_t fib<0>() {
    return 1;
}

template<uint64_t n>
constexpr uint64_t even_fib(uint64_t i) {
    return (fib<n>() & 1) == 0 && fib<n>() < i ? fib<n>() : 0;
}

template<uint64_t... Ns>
uint64_t sum_fibs(std::integer_sequence<uint64_t, Ns...>, uint64_t i) {
    uint64_t total = 0u;
    std::initializer_list<bool>{(total += even_fib<Ns>(i), void(), false)...};
    return total;
}

int main() {
    int numTestCases;
    std::cin >> numTestCases;
    for (auto testCaseIdx = 0; testCaseIdx < numTestCases; ++testCaseIdx) {
        uint64_t upper_limit;
        std::cin >> upper_limit;
        std::cout << sum_fibs(std::make_integer_sequence<uint64_t, 81u>{}, upper_limit) << std::endl;
    }
    return 0;
}
// https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem

#pragma once

#include <string>
#include <type_traits>

namespace TemplateSpecialization {
enum class Fruit { apple, orange, pear, max };
enum class Color { red, green, orange, max };

template<typename T>
using array_t = std::array<const char *, static_cast<std::size_t>(T::max) + 1>;

template<typename T>
struct Name;

template<>
struct Name<Fruit> {
  static constexpr array_t<Fruit> s_names{{"apple", "orange", "pear", "unknown"}};
};
constexpr array_t<Fruit> Name<Fruit>::s_names; // ODR rule deprecated in C++17

template<>
struct Name<Color> {
  static constexpr array_t<Color> s_names{{"red", "green", "orange", "unknown"}};
};
constexpr array_t<Color> Name<Color>::s_names; // ODR rule deprecated in C++17

template<typename T>
struct Traits {
  static constexpr const char *name(std::size_t idx) noexcept {
    return Name<T>::s_names[idx];
  }
};
}

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

// https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem

#pragma once

#include <string>
#include <type_traits>

namespace template_specialization {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
enum class Fruit { APPLE, ORANGE, PEAR, MAX };
enum class Color { RED, GREEN, ORANGE, MAX };
#pragma clang diagnostic pop


template <typename T>
using array_t = std::array<const char *, static_cast<std::size_t>(T::MAX) + 1u>;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
template <typename T>
struct Name;
#pragma clang diagnostic pop

template <>
struct Name<Fruit> {
  static constexpr array_t<Fruit> s_names_{
      {"apple", "orange", "pear", "unknown"}};
};
constexpr array_t<Fruit> Name<Fruit>::s_names_;  // ODR rule deprecated in C++17

template <>
struct Name<Color> {
  static constexpr array_t<Color> s_names_{
      {"red", "green", "orange", "unknown"}};
};
constexpr array_t<Color> Name<Color>::s_names_;  // ODR rule deprecated in C++17

template <typename T>
struct Traits {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
  static constexpr const char *name(std::size_t idx) noexcept {  // NOLINT
    return Name<T>::s_names_[idx];
  }
  static constexpr const char *name(T enumVal) noexcept {  // NOLINT
    using underlying_t = typename std::underlying_type<T>::type;
    return Name<T>::s_names_[static_cast<underlying_t>(enumVal)];
  }
#pragma clang diagnostic pop
};
}  // namespace template_specialization

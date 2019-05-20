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
enum class Fruit { APPLE, ORANGE, PEAR, MAX };
enum class Color { RED, GREEN, ORANGE, MAX };

template <typename T>
using array_t = std::array<const char *, static_cast<std::size_t>(T::MAX) + 1u>;

template <typename>
struct NameType;

template <>
struct NameType<Fruit> {
  static constexpr array_t<Fruit> s_names{
      {"apple", "orange", "pear", "unknown"}};
};
constexpr array_t<Fruit>
    NameType<Fruit>::s_names;  // ODR rule deprecated in C++17

template <>
struct NameType<Color> {
  static constexpr array_t<Color> s_names{
      {"red", "green", "orange", "unknown"}};
};
constexpr array_t<Color>
    NameType<Color>::s_names;  // ODR rule deprecated in C++17

template <typename T>
struct Traits {
  static constexpr const char *Name(std::size_t idx) noexcept {
    return NameType<T>::s_names[idx];
  }

  static constexpr const char *Name(T enum_val) noexcept {
    using underlying_t = typename std::underlying_type<T>::type;
    return NameType<T>::s_names[static_cast<underlying_t>(enum_val)];
  }
};
}  // namespace template_specialization

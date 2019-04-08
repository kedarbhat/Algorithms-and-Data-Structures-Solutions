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

// https://www.hackerrank.com/challenges/bitset-1/problem

#pragma once

namespace bit_array {
std::size_t GenerateSequence(unsigned n, unsigned s, unsigned p, unsigned q) {
  static constexpr auto modulo_m_1{(1u << 31u) - 1u};
  auto prev = s;
  std::size_t counter{1u};
  for (std::size_t i = 1u; i < n; ++i) {
    auto current = (prev * p + q) & modulo_m_1;
    if (current == prev) {
      return counter;
    }
    prev = current;
    ++counter;
  }

  return counter;
}

}  // namespace bit_array
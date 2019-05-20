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

#pragma once

namespace {
// Given an array of numbers, replace each even number with two of the same
// number. e.g, [1,2,5,6,8, , , ,] -> [1,2,2,5,6,6,8,8]

/**
 * Function object used to determine if a given integral value is even or not
 */
struct IsEvenT {
  template <typename T, typename = std::enable_if_t<
                            std::is_integral<std::decay_t<T>>::value>>
  constexpr bool operator()(T &&i) noexcept {
    return std::forward<T>(i) % 2 == 0;
  }
};

/**
 *
 * \tparam T
 * \param vec vector of integral types
 * \return the number of \param vec elements that are even
 */
template <typename T,
          typename = std::enable_if_t<std::is_integral<std::decay_t<T>>::value>>
static int64_t NumberOfEvenNumbers(const std::vector<T> &vec) noexcept {
  IsEvenT is_even;
  return std::count_if(std::begin(vec), std::end(vec), is_even);
}

/**
 *
 * \tparam T integral type
 * \param vec Vector of integral values
 * \return void
 */
template <typename T,
          typename = std::enable_if_t<std::is_integral<std::decay_t<T>>::value>>
void ReverseArrayTraversal(std::vector<T> &vec) noexcept {
  using diff_t = typename std::vector<T>::difference_type;
  using size_type = typename std::vector<T>::size_type;

  auto original_size = static_cast<diff_t>(vec.size());
  auto num_even_numbers = NumberOfEvenNumbers(vec);
  auto needed_capacity = num_even_numbers + static_cast<diff_t>(vec.size()) -
                         static_cast<diff_t>(vec.capacity());
  if (needed_capacity == 0) {
    IsEvenT is_even_t;
    assert(std::none_of(std::begin(vec), std::end(vec), is_even_t));
    return;
  }

  if (needed_capacity > 0) {
    vec.resize(vec.capacity() + static_cast<size_type>(needed_capacity));
  }

  auto write_iter = std::rbegin(vec);
  auto read_iter =
      std::make_reverse_iterator(std::next(std::begin(vec), original_size));
  while (read_iter != std::rend(vec) && write_iter != std::rend(vec)) {
    assert(std::distance(write_iter, read_iter) >= 0);
    *write_iter = *read_iter;
    std::advance(write_iter, 1);
    IsEvenT is_even_t;
    if (write_iter != std::rend(vec) && is_even_t(*read_iter)) {
      *write_iter = *read_iter;
      std::advance(write_iter, 1);
    }
    std::advance(read_iter, 1);
  }
}

}  // namespace

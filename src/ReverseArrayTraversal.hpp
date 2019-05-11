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
struct IsEven_t {
  template <typename T>
  constexpr typename std::enable_if<std::is_integral<std::decay_t<T>>::value,
                                    bool>::type
  operator()(T &&i) noexcept {
    return std::forward<T>(i) % 2 == 0;
  }
};

/**
 *
 * \tparam T
 * \param vec vector of integral types
 * \return the number of \param vec elements that are even
 */
template <typename T>
static typename std::enable_if<std::is_integral<std::decay_t<T>>::value,
                               int64_t>::type
numberOfEvenNumbers(const std::vector<T> &vec) noexcept {
  IsEven_t isEven;
  return std::count_if(std::begin(vec), std::end(vec), isEven);
}

/**
 *
 * \tparam T integral type
 * \param vec Vector of integral values
 * \return void
 */
template <typename T>
typename std::enable_if<std::is_integral<std::decay_t<T>>::value>::type
reverseArrayTraversal(std::vector<T> &vec) noexcept {
  using diff_t = typename std::vector<T>::difference_type;
  using size_type = typename std::vector<T>::size_type;
  IsEven_t isEven;

  auto originalSize = static_cast<diff_t>(vec.size());
  auto numEvenNumbers = numberOfEvenNumbers(vec);
  auto neededCapacity = numEvenNumbers + static_cast<diff_t>(vec.size()) -
                        static_cast<diff_t>(vec.capacity());
  if (neededCapacity == 0) {
    assert(std::none_of(std::begin(vec), std::end(vec), isEven));
    return;
  }

  if (neededCapacity > 0) {
    vec.resize(vec.capacity() + static_cast<size_type>(neededCapacity));
  }

  auto writeIter = std::rbegin(vec);
  auto readIter =
      std::make_reverse_iterator(std::next(std::begin(vec), originalSize));
  while (readIter != std::rend(vec) && writeIter != std::rend(vec)) {
    assert(std::distance(writeIter, readIter) >= 0);
    *writeIter = *readIter;
    std::advance(writeIter, 1);
    if (writeIter != std::rend(vec) && isEven(*readIter)) {
      *writeIter = *readIter;
      std::advance(writeIter, 1);
    }
    std::advance(readIter, 1);
  }
}

} // namespace

//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_SRC_REVERSEARRAYTRAVERSAL_HPP_
#define INTERVIEWCAMP_SRC_REVERSEARRAYTRAVERSAL_HPP_

#include <algorithm>
#include <cmath>
#include <iterator>
#include <type_traits>
#include <vector>

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
#endif // INTERVIEWCAMP_SRC_REVERSEARRAYTRAVERSAL_HPP_

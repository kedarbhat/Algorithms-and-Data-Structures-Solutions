//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_SRC_REVERSECONTAINER_HPP_
#define INTERVIEWCAMP_SRC_REVERSECONTAINER_HPP_
#include <algorithm>
#include <iterator>
#include <vector>

namespace {
template <typename T> void reverseContainer(std::vector<T> &vec) noexcept {
  auto fwdIter = std::begin(vec);
  auto revIter = std::prev(std::end(vec), 1);
  while (std::distance(fwdIter, revIter) > 0) {
    std::iter_swap(fwdIter, revIter);
    std::advance(fwdIter, 1);
    std::advance(revIter, -1);
  }
}
} // namespace
#endif // INTERVIEWCAMP_SRC_REVERSECONTAINER_HPP_

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
#include <boost/type_traits/is_nothrow_swappable.hpp>
#include <type_traits>
namespace {
/**
 * Given an array, reverse the order of its elements. For
 * example,[3,5,2,5,2,3,9] --> [9,3,2,5,2,5,3]["hello", "world"] --> ["world",
 * "hello"] \tparam T a swappable type \param vec Vector holding the elements to
 * be reversed
 */
template <typename T, typename = std::enable_if_t<
                          boost::is_nothrow_swappable<std::decay_t<T>>::value>>
void ReverseContainer(std::vector<T> &vec) noexcept {
  auto fwd_iter = std::begin(vec);
  auto rev_iter = std::prev(std::end(vec), 1);
  while (std::distance(fwd_iter, rev_iter) > 0) {
    std::iter_swap(fwd_iter, rev_iter);
    std::advance(fwd_iter, 1);
    std::advance(rev_iter, -1);
  }
}
}  // namespace

// Copyright (C) 2019 Kedar R. Bhat

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// https://www.interviewcake.com/question/cpp/product-of-other-numbers?course=fc1&section=greedy

#pragma once

#include <boost/range/irange.hpp>

#include <exception>
#include <numeric>
#include <vector>

namespace interview_cake {
std::vector<int> ProductsOfAllIntsExceptAtIndex(const std::vector<int>& input) {
  if (input.size() < 2u) {
    throw std::invalid_argument("Vector must have at least 2 elements");
  }

  /**
   * for each element in the input vector:
   * 1. set the corresponding element in the product vector to the product of
   * all prior elements
   * 2. update cumulative product */
  std::vector<int> cumulative_product_ex_idx(input.size());
  auto cumulative_product = 1;
  for (auto idx : boost::irange<std::size_t>(0u, input.size())) {
    cumulative_product_ex_idx[idx] = cumulative_product;
    cumulative_product *= input[idx];
  }

  /**
   * for each element of the input vector:
   * 1. multiply the corresponding element in the product vector to the product
   * of all subsequent elements
   * 2. update the cumulative product */
  cumulative_product = 1;
  using DiffType = typename std::vector<int>::difference_type;
  using SizeType = std::make_unsigned_t<DiffType>;
  for (auto s_idx : boost::irange<DiffType>(input.size() - 1, -1, -1)) {
    auto idx = static_cast<SizeType>(s_idx);
    cumulative_product_ex_idx[idx] *= cumulative_product;
    cumulative_product *= input[idx];
  }

  return cumulative_product_ex_idx;
}
}  // namespace interview_cake
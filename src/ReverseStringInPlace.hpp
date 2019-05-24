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

// https://www.interviewcake.com/question/cpp/reverse-string-in-place?course=fc1&section=array-and-string-manipulation

#pragma once

#include <string>
namespace reverse_string_inplace {
void reverse(std::string& str) {
  auto fwd_iter = std::begin(str);
  auto bwd_iter = std::prev(std::end(str));

  while (std::distance(fwd_iter, bwd_iter) > 0) {
    std::iter_swap(fwd_iter, bwd_iter);
    std::advance(fwd_iter, 1);
    std::advance(bwd_iter, -1);
  }
}
}  // namespace reverse_string_inplace
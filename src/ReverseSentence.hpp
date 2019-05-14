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

#include <algorithm>
#include <string>
namespace {

/**
 * Given a sentence, reverse the words of the sentence. For example, "i live in
 * a house" becomes "house a in live i". There are cleaner ways to do this, but
 * this is to practice reverse iteration. \param str string to be reversed
 */

void ReverseString(std::string &str) noexcept {
  if (str.empty()) {
    return;
  }

  auto word_end_idx = str.size();
  for (auto space_idx = str.rfind(' ');
       space_idx != 0 && space_idx != std::string::npos;
       space_idx = str.rfind(' ', word_end_idx - 1)) {
    std::reverse(std::begin(str) + space_idx + 1,
                 std::begin(str) + word_end_idx);
    word_end_idx = space_idx;
  }
  std::reverse(std::begin(str), std::end(str));
}
}  // namespace

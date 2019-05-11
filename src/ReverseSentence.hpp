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

void reverseString(std::string &str) noexcept {
  if (str.empty()) {
    return;
  }

  auto endOfWordIdx = str.find_last_not_of(' ');
  if (endOfWordIdx == std::string::npos) {
    return;
  } else {
    ++endOfWordIdx;
  }

  auto spaceIdx = str.rfind(' ');
  while (spaceIdx != std::string::npos) {
    assert(spaceIdx <= endOfWordIdx);
    std::reverse(std::begin(str) + spaceIdx + 1,
                 std::begin(str) + std::min(str.size(), endOfWordIdx + 1));
    endOfWordIdx = str.find_last_not_of(' ', spaceIdx);
    spaceIdx = str.rfind(' ', endOfWordIdx);
  }
  std::reverse(std::begin(str), std::end(str));
}
} // namespace

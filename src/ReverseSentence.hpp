//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_SRC_REVERSESENTENCE_HPP_
#define INTERVIEWCAMP_SRC_REVERSESENTENCE_HPP_

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
#endif // INTERVIEWCAMP_SRC_REVERSESENTENCE_HPP_

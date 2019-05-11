//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_TEST_TESTREVERSESENTENCE_HPP_
#define INTERVIEWCAMP_TEST_TESTREVERSESENTENCE_HPP_

#include "../src/ReverseSentence.hpp"

namespace {
TEST(EmptyString, TestReverseSentence) {
  std::string str;
  const auto expected = str;

  EXPECT_EQ(str, expected);
}
TEST(NormalSentence, TestReverseSentence) {
  std::string str = "i live in a house";
  auto expected = "house a in live i";
  reverseString(str);
  EXPECT_EQ(str, expected);
}

}
#endif //INTERVIEWCAMP_TEST_TESTREVERSESENTENCE_HPP_

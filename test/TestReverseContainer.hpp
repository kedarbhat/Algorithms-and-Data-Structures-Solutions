//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_TEST_REVERSECONTAINER_HPP_
#define INTERVIEWCAMP_TEST_REVERSECONTAINER_HPP_

#include "../src/ReverseContainer.hpp"

TEST(EmptyContainer, TestReverseContainer) {
  std::vector<int> vec;
  const auto expected = vec;
  reverseContainer(vec);
  EXPECT_EQ(vec, expected);
}

TEST(NormalContainer, TestReverseContainer) {
  std::vector<std::string> vec {"Hello", "my", "name", "is", "sew"};
  auto expected = vec;
  std::reverse(std::begin(expected), std::end(expected));
  reverseContainer(vec);
  EXPECT_EQ(vec, expected);
}

#endif //INTERVIEWCAMP_TEST_REVERSECONTAINER_HPP_

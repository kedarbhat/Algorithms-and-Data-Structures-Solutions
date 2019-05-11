//
// Created by parallels on 5/10/19.
//

#ifndef INTERVIEWCAMP_TEST_TESTFINDUNSORTEDSUBARRAY_HPP_
#define INTERVIEWCAMP_TEST_TESTFINDUNSORTEDSUBARRAY_HPP_

#include "FindUnsortedSubarray.hpp"

namespace {
using pair_t = std::pair<size_type<std::vector<int>>, size_type<std::vector<int>>>;
TEST(NormalArray, TestFindUnsortedSubarray) {
  std::vector<int> vec{0, 2, 5, 3, 1, 8, 6, 9};
  pair_t expected = {1,6};
  EXPECT_EQ(findUnsortedSubarray(vec), expected);
}

TEST(SortedArray, TestFindUnsortedSubarray) {
  std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
  pair_t expected = {0,9};
  EXPECT_EQ(findUnsortedSubarray(vec), expected);
}
} // namespace

#endif // INTERVIEWCAMP_TEST_TESTFINDUNSORTEDSUBARRAY_HPP_

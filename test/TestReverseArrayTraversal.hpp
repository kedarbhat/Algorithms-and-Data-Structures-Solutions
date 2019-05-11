#include "../src/ReverseArrayTraversal.hpp"
namespace {
TEST(EmptyVector, TestReverseArrayTraversal) {
  std::vector<int64_t> vec(0);
  const auto expected = vec;
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

TEST(AllOdd, TestReverseArrayTraversal) {
  std::vector<int64_t> vec{1,3,5};
  const auto expected = vec;
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

TEST(AllEven, TestReverseArrayTraversal) {
  std::vector<int64_t> vec{2,4,6};
  const auto expected = std::vector<int64_t>{2,2,4,4,6,6};
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

TEST(OneOdd, TestReverseArrayTraversal) {
  std::vector<int64_t> vec{1};
  const auto expected = vec;
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

TEST(OneEven, TestReverseArrayTraversal) {
  std::vector<int64_t> vec{2};
  const auto expected = std::vector<int64_t>{2,2};
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

TEST(Mixed, TestReverseArrayTraversal) {
  std::vector<int64_t> vec{1,2,3,4,5};
  const auto expected = std::vector<int64_t>{1,2,2,3,4,4,5};
  reverseArrayTraversal(vec);
  GTEST_ASSERT_EQ(vec, expected);
}

}
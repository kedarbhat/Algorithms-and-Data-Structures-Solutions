#include "ReverseArrayTraversal.hpp"
namespace {
TEST(TestReverseArrayTraversal, EmptyVector) {
  std::vector<int64_t> vec(0);
  const auto expected = vec;
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, AllOdd) {
  std::vector<int64_t> vec{1, 3, 5};
  const auto expected = vec;
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, AllEven) {
  std::vector<int64_t> vec{2, 4, 6};
  const auto expected = std::vector<int64_t>{2, 2, 4, 4, 6, 6};
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, OneOdd) {
  std::vector<int64_t> vec{1};
  const auto expected = vec;
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, OneEven) {
  std::vector<int64_t> vec{2};
  const auto expected = std::vector<int64_t>{2, 2};
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

TEST(TestReverseArrayTraversal, Mixed) {
  std::vector<int64_t> vec{1, 2, 5, 6, 8};
  const auto expected = std::vector<int64_t>{1, 2, 2, 5, 6, 6, 8, 8};
  reverseArrayTraversal(vec);
  ASSERT_EQ(vec, expected);
}

}  // namespace
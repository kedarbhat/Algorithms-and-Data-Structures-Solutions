// Implementation provided by HackerRank
#pragma once

namespace linked_lists {
namespace detail {
struct SinglyLinkedListNode {
  explicit SinglyLinkedListNode(int data)
      : SinglyLinkedListNode(data, nullptr) {}
  explicit SinglyLinkedListNode(int data,
                                SinglyLinkedListNode *next)
      : data_(data), next_(next) {}

  int data_;
  SinglyLinkedListNode *next_;
};
}  // namespace detail
}  // namespace linked_lists
// Implementation provided by HackerRank
#pragma once

namespace detail {
struct SinglyLinkedListNode {
  explicit SinglyLinkedListNode(int data)
      : SinglyLinkedListNode(data, std::unique_ptr<SinglyLinkedListNode>{}) {}
  explicit SinglyLinkedListNode(int data,
                                std::unique_ptr<SinglyLinkedListNode>&& next)
      : data_(data), next_(std::move(next)) {}

  int data_;
  std::unique_ptr<SinglyLinkedListNode> next_;
};
}  // namespace detail
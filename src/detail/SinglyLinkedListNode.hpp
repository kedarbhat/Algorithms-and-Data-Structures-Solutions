// Implementation provided by HackerRank
#pragma once

namespace linked_lists {
namespace detail {
template <typename T>
struct SinglyLinkedListNode_t {
  template <typename U>
  explicit SinglyLinkedListNode_t(const U& data)
      : SinglyLinkedListNode_t(data, nullptr) {}
  template <typename U>
  explicit SinglyLinkedListNode_t(const U& data, SinglyLinkedListNode_t* next)
      : data_(static_cast<T>(data)), next_(next) {}
  const T data_;
  SinglyLinkedListNode_t* next_;
};

}  // namespace detail

template <typename T>
using SinglyLinkedListNode = detail::SinglyLinkedListNode_t<T>;
}  // namespace linked_lists
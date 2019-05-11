// Implementation provided by HackerRank
#pragma once

namespace linked_lists {
namespace detail {
template<typename T>
struct SinglyLinkedListNode_t {
  template<typename U>
  explicit SinglyLinkedListNode_t(U&& data)
      : SinglyLinkedListNode_t(std::forward<U>(data), nullptr) {}
  template<typename U>
  explicit SinglyLinkedListNode_t(U&& data, SinglyLinkedListNode_t *next)
      : data_(std::forward<T>(static_cast<T>(data))), next_(next) {}
  T data_;
  SinglyLinkedListNode_t *next_;
};

}  // namespace detail

template<typename T>
using SinglyLinkedListNode = detail::SinglyLinkedListNode_t<T>;
}  // namespace linked_lists
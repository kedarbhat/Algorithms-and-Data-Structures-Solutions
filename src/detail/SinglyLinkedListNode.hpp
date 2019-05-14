// Implementation provided by HackerRank
#pragma once

namespace linked_lists {
namespace detail {
template <typename T>
struct SinglyLinkedListNodeT {
  template <typename U>
  explicit SinglyLinkedListNodeT(const U& data,
                                 SinglyLinkedListNodeT* next = nullptr)
      : data_(static_cast<T>(data)), next_(next) {}
  const T data_;
  SinglyLinkedListNodeT* next_;
};

}  // namespace detail

template <typename T>
using SinglyLinkedListNode = detail::SinglyLinkedListNodeT<T>;
}  // namespace linked_lists
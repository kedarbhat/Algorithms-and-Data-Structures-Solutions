// Implementation provided by HackerRank
#pragma once

#include <memory>
#include <utility>

namespace linked_lists {
namespace detail {
template <typename T>
struct SinglyLinkedListNodeT {
  template <typename U>
  explicit SinglyLinkedListNodeT(U&& data, SinglyLinkedListNodeT* next)
      : data_(static_cast<T>(std::forward<U>(data))), next_(next) {}

  template <typename U>
  explicit SinglyLinkedListNodeT(U&& data)
      : SinglyLinkedListNodeT(std::forward<U>(data), nullptr) {}

  const T data_;
  SinglyLinkedListNodeT* next_;
};

}  // namespace detail

template <typename T>
using SinglyLinkedListNode = detail::SinglyLinkedListNodeT<T>;
}  // namespace linked_lists
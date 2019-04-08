/*
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

#pragma once

#include "detail/SinglyLinkedListNode.hpp"

namespace linked_lists {
detail::SinglyLinkedListNode* insertNodeAtPosition(
    detail::SinglyLinkedListNode* head, int data, int position) {
  int counter = 0;
  auto* node = head;
  while (node != nullptr) {
    if (position == counter + 1) {
      auto* tmp = node->next_;
      node->next_ = new detail::SinglyLinkedListNode(data);
      node->next_->next_ = tmp;
      break;
    } else {
      node = node->next_;
      ++counter;
    }
  }
  return head;
}
}  // namespace linked_lists
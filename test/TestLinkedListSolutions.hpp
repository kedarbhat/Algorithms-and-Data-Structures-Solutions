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

#pragma once
#include <gtest/gtest.h>

#include "DeleteNodeAtPosition.hpp"
#include "InsertNodeAtHead.hpp"
#include "InsertNodeAtPosition.hpp"
#include "InsertNodeAtTail.hpp"
#include "PrintLinkedListElements.hpp"
#include "PrintLinkedListElementsReverse.hpp"

namespace {
void DeleteLinkedList(linked_lists::SinglyLinkedListNode<int> *head) {
  while (head != nullptr) {
    auto *tmp = head->next_;
    delete head;
    head = tmp;
  }
}
}  // namespace

namespace {
TEST(TestLinkedListSolutions, PrintListedListElements) {
  auto *head = new linked_lists::SinglyLinkedListNode<int>(16);
  head->next_ = new linked_lists::SinglyLinkedListNode<int>(13);
  ASSERT_EQ(linked_lists::PrintLinkedList(head), std::string("16 13"));
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtTail) {
  linked_lists::SinglyLinkedListNode<int> *head = nullptr;
  for (auto i : {141, 302, 164, 530, 474}) {
    head = linked_lists::InsertNodeAtTail(head, i);
  }

  for (auto i : {141, 302, 164, 530, 474}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_, i);
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtHead) {
  linked_lists::SinglyLinkedListNode<int> *head = nullptr;
  for (auto i : {383, 484, 392, 975, 321}) {
    head = linked_lists::InsertNodeAtHead(head, i);
  }

  for (auto i : {321, 975, 392, 484, 383}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_, i);
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtPosition) {
  linked_lists::SinglyLinkedListNode<int> *head = nullptr;
  for (auto i : {16, 13, 7}) {
    head = linked_lists::InsertNodeAtTail(head, i);
  }

  head = linked_lists::InsertNodeAtPosition(head, 1, 2);

  for (auto i : {16, 13, 1, 7}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_,
              i);  // NOLINT(clang-analyzer-core.NonNullParamChecker)
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, DeleteNodeAtPosition) {
  {
    linked_lists::SinglyLinkedListNode<int> *head = nullptr;
    for (auto i : {20, 6, 2, 19, 7, 4, 15, 9}) {
      head = linked_lists::InsertNodeAtTail(head, i);
    }

    head = linked_lists::DeleteNode(head, 3);

    for (auto i : {20, 6, 2, 7, 4, 15, 9}) {
      ASSERT_FALSE(head == nullptr);
      ASSERT_EQ(head->data_, i);
      head = head->next_;
    }
    DeleteLinkedList(head);
  }
  {
    linked_lists::SinglyLinkedListNode<int> *head = nullptr;
    for (auto i : {20, 6, 2, 19, 7, 4, 15, 9}) {
      head = linked_lists::InsertNodeAtTail(head, i);
    }
    head = linked_lists::DeleteNode(head, 0);
    for (auto i : {6, 2, 19, 7, 4, 15, 9}) {
      ASSERT_FALSE(head == nullptr);
      ASSERT_EQ(head->data_, i);
      head = head->next_;
    }
    DeleteLinkedList(head);
  }
}

TEST(TestLinkedListSolutions, PrintListedListElementsReverse) {
  {
    linked_lists::SinglyLinkedListNode<int> *head = nullptr;
    for (auto i : {16, 12, 4, 2, 5}) {
      head = linked_lists::InsertNodeAtTail(head, i);
    }
    ASSERT_EQ(linked_lists::PrintLinkedListReverse(head), "5 2 4 12 16");
  }
  {
    linked_lists::SinglyLinkedListNode<int> *head = nullptr;
    for (auto i : {7, 3, 9}) {
      head = linked_lists::InsertNodeAtTail(head, i);
    }
    ASSERT_EQ(linked_lists::PrintLinkedListReverse(head), "9 3 7");
  }
  {
    linked_lists::SinglyLinkedListNode<int> *head = nullptr;
    for (auto i : {5, 1, 18, 3, 13}) {
      head = linked_lists::InsertNodeAtTail(head, i);
    }
    ASSERT_EQ(linked_lists::PrintLinkedListReverse(head), "13 3 18 1 5");
  }
}

}  // namespace
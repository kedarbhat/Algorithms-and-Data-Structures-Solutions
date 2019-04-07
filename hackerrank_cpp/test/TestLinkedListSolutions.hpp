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

#include "LinkedListSolutions/PrintLinkedListElements.hpp"

namespace {  // NOLINT
TEST(TestLinkedListSolutions, PrintListedListElements) {
  std::unique_ptr<detail::SinglyLinkedListNode> head =
      std::make_unique<detail::SinglyLinkedListNode>(16);
  head->next_ = std::make_unique<detail::SinglyLinkedListNode>(13);
  ASSERT_EQ(linked_lists::PrintLinkedList(head), std::string("16 13"));
}
}  // namespace
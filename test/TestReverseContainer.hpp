// Copyright (C) 2019 Kedar R. Bhat

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#pragma once
#include <gtest/gtest.h>

#include "ReverseContainer.hpp"
namespace {
TEST(TestReverseContainer, EmptyContainer) {
  std::vector<int> vec;
  const auto expected = vec;
  arrays::ReverseContainer(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestReverseContainer, ContainerOfStrings) {
  std::vector<std::string> vec{"Hello", "world"};
  auto expected = vec;
  std::reverse(std::begin(expected), std::end(expected));
  arrays::ReverseContainer(vec);
  EXPECT_EQ(vec, expected);
}

TEST(TestReverseContainer, ContainerOfInts) {
  std::vector<int> vec{3, 5, 2, 5, 2, 3, 9};
  auto expected = vec;
  std::reverse(std::begin(expected), std::end(expected));
  arrays::ReverseContainer(vec);
  EXPECT_EQ(vec, expected);
}

}  // namespace
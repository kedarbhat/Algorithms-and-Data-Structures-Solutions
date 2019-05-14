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

#include "TemplateSpecialization.hpp"

namespace {
TEST(TestTemplateSpecialization, TestBothEnums) {
  using FruitType = template_specialization::Fruit;
  using ColorType = template_specialization::Color;
  using FruitTraits = template_specialization::Traits<FruitType>;
  using ColorTraits = template_specialization::Traits<ColorType>;

  ASSERT_STREQ(FruitTraits::Name(0), "apple");
  ASSERT_STREQ(FruitTraits::Name(1), "orange");
  ASSERT_STREQ(FruitTraits::Name(2), "pear");
  ASSERT_STREQ(FruitTraits::Name(3), "unknown");
  ASSERT_STREQ(FruitTraits::Name(FruitType::APPLE), "apple");
  ASSERT_STREQ(FruitTraits::Name(FruitType::ORANGE), "orange");
  ASSERT_STREQ(FruitTraits::Name(FruitType::PEAR), "pear");
  ASSERT_STREQ(FruitTraits::Name(FruitType::MAX), "unknown");

  ASSERT_STREQ(ColorTraits::Name(0), "red");
  ASSERT_STREQ(ColorTraits::Name(1), "green");
  ASSERT_STREQ(ColorTraits::Name(2), "orange");
  ASSERT_STREQ(ColorTraits::Name(3), "unknown");
  ASSERT_STREQ(ColorTraits::Name(ColorType::RED), "red");
  ASSERT_STREQ(ColorTraits::Name(ColorType::GREEN), "green");
  ASSERT_STREQ(ColorTraits::Name(ColorType::ORANGE), "orange");
  ASSERT_STREQ(ColorTraits::Name(ColorType::MAX), "unknown");
}
}  // namespace
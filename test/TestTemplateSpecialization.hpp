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

#include "TemplateSpecialization.hpp"

namespace {
TEST(TestTemplateSpecialization, TestBothEnums) {
  using FruitType = template_specialization::Fruit;
  using ColorType = template_specialization::Color;
  using FruitTraits =
      template_specialization::Traits<FruitType>;
  using ColorTraits =
      template_specialization::Traits<ColorType>;

  ASSERT_STREQ(FruitTraits::name(0), "apple");
  ASSERT_STREQ(FruitTraits::name(1), "orange");
  ASSERT_STREQ(FruitTraits::name(2), "pear");
  ASSERT_STREQ(FruitTraits::name(3), "unknown");
  ASSERT_STREQ(FruitTraits::name(FruitType::APPLE), "apple");
  ASSERT_STREQ(FruitTraits::name(FruitType::ORANGE), "orange");
  ASSERT_STREQ(FruitTraits::name(FruitType::PEAR), "pear");
  ASSERT_STREQ(FruitTraits::name(FruitType::MAX), "unknown");

  ASSERT_STREQ(ColorTraits::name(0), "red");
  ASSERT_STREQ(ColorTraits::name(1), "green");
  ASSERT_STREQ(ColorTraits::name(2), "orange");
  ASSERT_STREQ(ColorTraits::name(3), "unknown");
  ASSERT_STREQ(ColorTraits::name(ColorType::RED), "red");
  ASSERT_STREQ(ColorTraits::name(ColorType::GREEN), "green");
  ASSERT_STREQ(ColorTraits::name(ColorType::ORANGE), "orange");
  ASSERT_STREQ(ColorTraits::name(ColorType::MAX), "unknown");
}
}  // namespace
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

namespace { // NOLINT
TEST(TestTemplateSpecialization, TestBothEnums) {
  using FruitTraits =
      template_specialization::Traits<template_specialization::Fruit>;
  using ColorTraits =
      template_specialization::Traits<template_specialization::Color>;

  EXPECT_STREQ(FruitTraits::name(0), "apple");
  EXPECT_STREQ(FruitTraits::name(1), "orange");
  EXPECT_STREQ(FruitTraits::name(2), "pear");
  EXPECT_STREQ(FruitTraits::name(3), "unknown");

  EXPECT_STREQ(ColorTraits::name(0), "red");
  EXPECT_STREQ(ColorTraits::name(1), "green");
  EXPECT_STREQ(ColorTraits::name(2), "orange");
  EXPECT_STREQ(ColorTraits::name(3), "unknown");
}
}  // namespace
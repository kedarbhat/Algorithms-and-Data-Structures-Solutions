#pragma once

#include <gtest/gtest.h>

#include "TemplateSpecialization.hpp"

namespace {
TEST(TestTemplateSpecialization, TestBothEnums) {
  using FruitTraits = TemplateSpecialization::Traits<TemplateSpecialization::Fruit>;
  using ColorTraits = TemplateSpecialization::Traits<TemplateSpecialization::Color>;

  EXPECT_STREQ(FruitTraits::name(0), "apple");
  EXPECT_STREQ(FruitTraits::name(1), "orange");
  EXPECT_STREQ(FruitTraits::name(2), "pear");
  EXPECT_STREQ(FruitTraits::name(3), "unknown");

  EXPECT_STREQ(ColorTraits::name(0), "red");
  EXPECT_STREQ(ColorTraits::name(1), "green");
  EXPECT_STREQ(ColorTraits::name(2), "orange");
  EXPECT_STREQ(ColorTraits::name(3), "unknown");
}
}
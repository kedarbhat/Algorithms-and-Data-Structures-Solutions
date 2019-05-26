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
#include "WordCloud.hpp"

namespace {
TEST(TestWordCloud, simple_sentence) {
  const std::string text = "I like cake";
  const std::unordered_map<std::string, size_t> expected{
      {"I", 1}, {"like", 1}, {"cake", 1}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}

TEST(TestWordCloud, longer_sentence) {
  const std::string text =
      "Chocolate cake for dinner and pound cake for dessert";
  const std::unordered_map<std::string, size_t> expected{
      {"and", 1},       {"pound", 1},  {"for", 2}, {"dessert", 1},
      {"Chocolate", 1}, {"dinner", 1}, {"cake", 2}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}

TEST(TestWordCloud, punctuation) {
  const std::string text = "Strawberry short cake? Yum!";
  const std::unordered_map<std::string, size_t> expected{
      {"cake", 1}, {"Strawberry", 1}, {"short", 1}, {"Yum", 1}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}

TEST(TestWordCloud, hyphenated_words) {
  const std::string text = "Dessert - mille-feuille cake";
  const std::unordered_map<std::string, size_t> expected{
      {"cake", 1}, {"Dessert", 1}, {"mille-feuille", 1}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}

TEST(TestWordCloud, ellipses_between_words) {
  const std::string text = "Mmm...mmm...decisions...decisions";
  const std::unordered_map<std::string, size_t> expected{{"mmm", 2},
                                                         {"decisions", 2}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}

TEST(TestWordCloud, apostrophes) {
  const std::string text = "Allie's Bakery: Sasha's Cakes";
  const std::unordered_map<std::string, size_t> expected{
      {"Bakery", 1}, {"Cakes", 1}, {"Allie's", 1}, {"Sasha's", 1}};
  const WordCloudData actual(text);
  ASSERT_EQ(actual.GetWordsToCounts(), expected);
}
}  // namespace
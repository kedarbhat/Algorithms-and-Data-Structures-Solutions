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

// https://www.interviewcake.com/question/cpp/word-cloud?course=fc1&section=hashing-and-hash-tables

// This is not an optimal solution

#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace {
class WordCloudData {
 private:
  std::unordered_map<std::string, std::size_t> words_to_counts_;

  static std::vector<std::string> GetTokens(const std::string& input_string) {
    std::vector<std::string> tokens;
    std::size_t word_starting_idx = 0u;
    std::size_t word_length = 0u;
    for (auto idx = 0u; idx < input_string.size(); ++idx) {
      auto c = input_string[idx];
      if (std::isalpha(c) || c == '\'' ||
          (c == '-' && idx > 0 && std::isalpha(input_string[idx - 1]))) {
        if (word_length == 0u) {
          // no letters yet
          word_starting_idx = idx;
        }
        ++word_length;
      } else {
        if (word_length > 0) {
          tokens.emplace_back(
              input_string.substr(word_starting_idx, word_length));
          word_length = 0;
        }
      }
    }
    if (word_length > 0) {
      tokens.emplace_back(input_string.substr(word_starting_idx, word_length));
    }
    return tokens;
  }

  void PopulateWordsToCounts(const std::string& input_string) {
    auto tokens = GetTokens(input_string);
    std::sort(std::rbegin(tokens), std::rend(tokens));
    for (const auto& token : tokens) {
      auto key = token;
      for (auto& c : key) {
        if (std::isalpha(c)) {
          c = static_cast<char>(std::tolower(c));
        }
      }
      if (words_to_counts_.find(key) != std::cend(words_to_counts_)) {
        ++words_to_counts_[key];
      } else {
        ++words_to_counts_[token];
      }
    }
  }

 public:
  explicit WordCloudData(const std::string& input_string) {
    PopulateWordsToCounts(input_string);
  }

  const std::unordered_map<std::string, std::size_t> GetWordsToCounts() const {
    return words_to_counts_;
  }
};

}  // namespace
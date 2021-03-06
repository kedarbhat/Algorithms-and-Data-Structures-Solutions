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

// https://www.hackerrank.com/challenges/inherited-code/problem

#pragma once

#include <exception>
#include <string>

namespace abstract_classes {
struct BadLengthException : std::exception {
  explicit BadLengthException(std::size_t n) : n_(std::to_string(n)) {}
  const char *what() const noexcept override { return n_.c_str(); }
  std::string n_;
};

class StringLengthChecker final {
 public:
  explicit StringLengthChecker(std::size_t min_length)
      : min_length_(min_length) {}
  std::string IsValid(const std::string &s) {
    return CheckStringLength(s) ? "Valid" : "Invalid";
  }

 private:
  bool CheckStringLength(const std::string &s) {
    auto n = s.length();
    if (n < min_length_) {
      throw BadLengthException(n);
    }
    for (auto iter = std::cbegin(s);
         std::distance(std::next(iter), std::cend(s)) > 0;
         std::advance(iter, 1)) {
      if (*iter == 'w' && *std::next(iter) == 'w') {
        return false;
      }
    }
    return true;
  }

  std::size_t min_length_;
};
}  // namespace abstract_classes

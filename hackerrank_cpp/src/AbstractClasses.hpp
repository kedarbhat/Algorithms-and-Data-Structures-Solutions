#pragma once

#include <exception>
#include <string>

namespace AbstractClasses {

struct BadLengthException : std::exception {
  explicit BadLengthException(int n) : n_(std::to_string(n)) {}
  const char *what() const noexcept override { return n_.c_str(); }
  std::string n_;
};

class StringLengthChecker {
  bool checkStringLength(const std::string &s) {
    bool isValid = true;
    auto n = s.length();
    if (n < minLength_) {
      throw BadLengthException(n);
    }
    for (std::size_t i = 0; i + 1 < n; ++i) {
      if (s[i] == 'w' && s[i + 1] == 'w') {
        isValid = false;
      }
    }
    return isValid;
  }

public:
  explicit StringLengthChecker(std::size_t minLength) : minLength_(minLength) {}
  std::string isValid(const std::string &s) {
    return checkStringLength(s) ? "Valid" : "Invalid";
  }

private:
  std::size_t minLength_;
};
} // namespace AbstractClasses
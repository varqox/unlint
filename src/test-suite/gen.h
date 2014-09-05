#include <string>
#include <cstdlib>

#pragma once

namespace generator {

inline char genFirstDigit() { return '1' + rand() % 9; }
inline char genDigit() { return '0' + rand() % 10; }
std::string genNum(size_t max_length);

} // namespace generator

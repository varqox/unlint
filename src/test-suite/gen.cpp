#include "gen.h"

namespace generator {

std::string genNum(size_t max_length) {
	size_t length = rand() % max_length + 1;
	std::string result(length, genFirstDigit());
	for (size_t i = 1; i < length; ++i)
		result[i] = genDigit();
	return result;
}

} // namespace generator

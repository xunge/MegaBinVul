#include <stddef.h>

template<char start, char stop>
const char* skip_over_scopes(const char* src, const char* end);

const char start = '{';
const char stop = '}';
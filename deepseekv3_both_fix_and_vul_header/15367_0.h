#include <cassert>
#include <cwchar>
#include <string>
#include <cstring>

#define ENCODE_DIRECT_BASE 0xF000
#define INTERNAL_SEPARATOR 0xF100

using wcstring = std::wstring;

size_t count_ascii_prefix(const char *str, size_t len);
bool fish_reserved_codepoint(wchar_t wc);
#include <wchar.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef wchar_t wchar;

#define MappedStringMark 0xE000
#define MapAreaStart 0xE000
#define MB_CUR_MAX 4

static inline uint32_t Min(uint32_t a, uint32_t b) { return a < b ? a : b; }
static inline uint32_t Max(uint32_t a, uint32_t b) { return a > b ? a : b; }
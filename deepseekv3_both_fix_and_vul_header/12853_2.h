#include <wchar.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef wchar_t wchar;
typedef uint32_t uint;
typedef uint8_t byte;

#define MappedStringMark 0xE000
#define MapAreaStart 0xE000

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
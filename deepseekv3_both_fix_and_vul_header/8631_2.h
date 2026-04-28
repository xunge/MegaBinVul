#include <stdint.h>

#define CODE_MASK 0xFFFF
#define REPEAT(n, op) { int _i = (n); while (_i-- > 0) { op; } }
typedef uint16_t uint16;
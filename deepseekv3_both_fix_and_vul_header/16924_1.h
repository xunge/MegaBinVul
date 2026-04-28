#include <stdint.h>
#include <stdbool.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define READ32(ptr) (*(ptr) | ((*(ptr + 1)) << 8) | ((*(ptr + 2)) << 16) | ((*(ptr + 3)) << 24))
#define READ64(ptr) (READ32(ptr) | ((uint64_t)READ32((ptr) + 4) << 32))
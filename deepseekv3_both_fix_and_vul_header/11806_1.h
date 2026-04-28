#include <stdint.h>

typedef uint8_t *octet_iterator;
typedef uint32_t *u32bit_iterator;

namespace utf8 {
    uint32_t next(octet_iterator &start, octet_iterator end);
}
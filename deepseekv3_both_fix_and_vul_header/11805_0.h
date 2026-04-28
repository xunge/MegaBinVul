#include <stdint.h>

namespace internal {
    const uint16_t LEAD_OFFSET = 0xD800 - (0x10000 >> 10);
    const uint16_t TRAIL_SURROGATE_MIN = 0xDC00;
}

namespace utf8 {
    uint32_t next(uint8_t*& start, uint8_t* end);
}

typedef uint8_t* octet_iterator;
typedef uint16_t* u16bit_iterator;
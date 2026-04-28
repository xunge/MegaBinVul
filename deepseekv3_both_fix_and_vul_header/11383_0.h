#include <stdint.h>

struct branch {
    uint8_t opcode;
    int32_t delta;
};

typedef uint16_t u16;
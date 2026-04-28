#include <stdint.h>
#include <string.h>

typedef struct RE {
    uint8_t* code;
    int flags;
} RE;

int yr_re_exec(uint8_t* code, uint8_t* target, size_t length, int flags, ...);

#define RE_FLAGS_SCAN 1
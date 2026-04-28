#include <stdint.h>

#define CODE_MASK 0xffff
#define REPEAT(n, op) \
    { \
        int _n = (n); \
        while (_n > 0) { \
            op; \
            _n--; \
        } \
    }

typedef uint16_t uint16;
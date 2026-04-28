#include <stdio.h>
#include <string.h>

typedef int spx_int32_t;
typedef short spx_int16_t;

static inline spx_int32_t le_int(spx_int32_t i) {
    return i;
}

static inline spx_int16_t le_short(spx_int16_t s) {
    return s;
}
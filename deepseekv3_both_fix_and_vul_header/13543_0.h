#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NNI_GET16(p, v) \
    do { \
        const uint8_t *q = (p); \
        (v) = ((uint32_t)q[0] << 8) | ((uint32_t)q[1]); \
    } while (0)

void *nng_alloc(size_t size);
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NNI_GET16(p, v) \
    do { \
        const uint8_t *ptr = (const uint8_t *)(p); \
        (v) = ((uint32_t)ptr[0] << 8) | (uint32_t)ptr[1]; \
    } while (0)

#define ERR_SUCCESS 0

void *nng_alloc(size_t size) { return malloc(size); }

int utf8_check(const char *str, int len);
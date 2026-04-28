#include <stdint.h>

typedef uint64_t guint64;
typedef uint8_t guint8;

static inline uint32_t pletoh32(const uint8_t *p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | 
           ((uint32_t)p[2] << 8) | (uint32_t)p[3];
}
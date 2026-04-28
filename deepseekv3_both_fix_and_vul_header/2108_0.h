#include <stdint.h>
#include <string.h>

#define QUEUE_SIZE 4096
#define QUEUE_MASK (QUEUE_SIZE - 1)

static inline uint32_t AV_RL32(const uint8_t *p) {
    return ((uint32_t)p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}
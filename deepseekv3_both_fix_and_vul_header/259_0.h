#include <stddef.h>
#include <stdint.h>

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

static inline uint8_t from_hex(uint8_t c) {
    return (c >= '0' && c <= '9') ? c - '0' :
           (c >= 'A' && c <= 'F') ? c - 'A' + 10 :
           (c >= 'a' && c <= 'f') ? c - 'a' + 10 : 0;
}
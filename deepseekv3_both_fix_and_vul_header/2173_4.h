#include <stdint.h>

#define TICK_NSEC ((uint64_t)(1000000000UL / 100))
#define NSEC_PER_SEC 1000000000UL
#define NSEC_PER_USEC 1000UL

struct compat_timeval {
    uint32_t tv_sec;
    uint32_t tv_usec;
};

static inline uint64_t div_u64_rem(uint64_t dividend, uint32_t divisor, uint32_t *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}

typedef uint64_t u64;
typedef uint32_t u32;
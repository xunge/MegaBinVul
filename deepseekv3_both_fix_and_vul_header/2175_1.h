#include <stdint.h>

#define TICK_NSEC ((NSEC_PER_SEC) / HZ)
#define NSEC_PER_SEC 1000000000L
#define HZ 100

typedef uint32_t u32;
typedef uint64_t u64;

struct timespec {
    long tv_sec;
    long tv_nsec;
};

static inline u64 div_u64_rem(u64 dividend, u32 divisor, u32 *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}
#include <stdint.h>

#define TICK_NSEC ((NSEC_PER_SEC + HZ / 2) / HZ)
#define NSEC_PER_SEC 1000000000L
#define NSEC_PER_USEC 1000L
#define HZ 100

typedef uint64_t u64;
typedef uint32_t u32;

struct compat_timeval {
    int tv_sec;
    int tv_usec;
};

static inline u64 div_u64_rem(u64 dividend, u32 divisor, u32 *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}

static inline long div_long_long_rem(long long dividend, long divisor, long *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}
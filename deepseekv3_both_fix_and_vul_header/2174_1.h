#include <stdint.h>

#define NSEC_PER_SEC 1000000000L
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef int64_t s64;
typedef int32_t s32;

struct timespec {
    int64_t tv_sec;
    long tv_nsec;
};

static inline s64 div_s64_rem(s64 dividend, s32 divisor, s32 *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}
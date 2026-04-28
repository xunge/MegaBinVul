#include <time.h>
#include <stdint.h>

typedef uint64_t u64;
#define NSEC_PER_SEC 1000000000L

struct timespec sgi_clock_offset;
unsigned long sgi_clock_period;

static inline struct timespec ns_to_timespec(u64 nsec) {
    struct timespec ts;
    ts.tv_sec = nsec / NSEC_PER_SEC;
    ts.tv_nsec = nsec % NSEC_PER_SEC;
    return ts;
}

static inline long div_long_long_rem(long long dividend, long long divisor, long long *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}
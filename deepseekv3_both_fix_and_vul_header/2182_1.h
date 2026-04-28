#include <time.h>
#include <stdint.h>

#define CPUCLOCK_WHICH(clock) ((clock) & (clockid_t)3)
#define CPUCLOCK_SCHED 2
#define NSEC_PER_SEC 1000000000L

typedef int64_t cputime_t;

union cpu_time_count {
    int64_t sched;
    cputime_t cpu;
};

static inline struct timespec ns_to_timespec(int64_t nsec);
static void cputime_to_timespec(cputime_t cpu, struct timespec *tp);
static long div_long_long_rem(int64_t dividend, long divisor, long *remainder);
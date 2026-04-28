#include <stdint.h>

typedef uint64_t u64;

struct cfs_bandwidth {
    u64 quota;
    u64 runtime;
    u64 runtime_expires;
    u64 period;
    int expires_seq;
};

#define RUNTIME_INF (~0ULL)

u64 sched_clock_cpu(int cpu);
int smp_processor_id(void);
u64 ktime_to_ns(u64 ktime);
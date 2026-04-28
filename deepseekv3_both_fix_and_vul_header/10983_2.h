#include <stdint.h>

typedef uint64_t u64;

struct spinlock {
    int dummy;
};

struct hrtimer {
    int dummy; 
};

struct cfs_bandwidth {
    struct spinlock lock;
    int period_active;
    u64 period;
    struct hrtimer period_timer;
    u64 runtime_expires;
    u64 expires_seq;
};

#define HRTIMER_MODE_ABS_PINNED 0

void lockdep_assert_held(struct spinlock *lock);
u64 hrtimer_forward_now(struct hrtimer *timer, u64 interval);
u64 ktime_to_ns(u64 time);
void hrtimer_start_expires(struct hrtimer *timer, int mode);
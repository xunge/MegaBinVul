#include <stdbool.h>
#include <stddef.h>

enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};

#define HRTIMER_STATE_INACTIVE 0
#define HRTIMER_STATE_ENQUEUED (1 << 0)

struct hrtimer;
struct hrtimer_clock_base;

typedef long long ktime_t;

struct hrtimer_cpu_base {
    int lock;
    struct hrtimer *running;
    int seq;
};

struct hrtimer {
    enum hrtimer_restart (*function)(struct hrtimer *);
    unsigned long state;
    bool is_rel;
};

#define lockdep_assert_held(lock) ((void)0)
#define raw_write_seqcount_barrier(seq) ((void)0)
#define IS_ENABLED(x) 0
#define WARN_ON_ONCE(cond) ((void)0)

static inline void debug_deactivate(struct hrtimer *timer) {}
static inline void __remove_hrtimer(struct hrtimer *timer, struct hrtimer_clock_base *base, int state, int flags) {}
static inline void timer_stats_account_hrtimer(struct hrtimer *timer) {}
static inline void raw_spin_unlock(int *lock) {}
static inline void trace_hrtimer_expire_entry(struct hrtimer *timer, ktime_t *now) {}
static inline void trace_hrtimer_expire_exit(struct hrtimer *timer) {}
static inline void raw_spin_lock(int *lock) {}
static inline void enqueue_hrtimer(struct hrtimer *timer, struct hrtimer_clock_base *base) {}
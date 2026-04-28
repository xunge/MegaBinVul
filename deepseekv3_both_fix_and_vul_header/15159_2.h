#include <time.h>

#define __init
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define CLOCK_MONOTONIC_RAW 4
#define SLAB_PANIC 0x00040000UL

struct k_clock {
    int (*clock_getres)(const clockid_t, struct timespec*);
    int (*clock_get)(struct timespec*);
    int (*clock_set)(const struct timespec*);
    int (*timer_create)(void*);
    int (*nsleep)(const clockid_t, int, struct timespec*, struct timespec*);
};

struct k_itimer {
    // Minimal definition since actual contents aren't used in this snippet
    int dummy;
};

extern int hrtimer_get_res(const clockid_t which_clock, struct timespec *tp);
extern int posix_ktime_get_ts(struct timespec *tp);
extern int posix_get_monotonic_raw(struct timespec *tp);
extern int do_posix_clock_nosettime(const struct timespec *tp);
extern int no_timer_create(struct k_itimer *timer);
extern int no_nsleep(const clockid_t which_clock, int flags,
                    struct timespec *tsave, struct timespec *rmtp);
extern void register_posix_clock(int clock_id, struct k_clock *new_clock);
extern void *kmem_cache_create(const char *name, size_t size, unsigned long flags, 
                             unsigned long slab_flags, void (*ctor)(void *));
extern void idr_init(void *idr);

static void *posix_timers_cache;
static void *posix_timers_id;
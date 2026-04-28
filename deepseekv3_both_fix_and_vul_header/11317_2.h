#include <stdbool.h>
#include <time.h>

typedef long long ktime_t;

struct timespec64 {
    long long tv_sec;
    long long tv_nsec;
};

struct itimerspec64 {
    struct timespec64 it_interval;
    struct timespec64 it_value;
};

struct k_clock {
    int (*clock_get)(int clockid, struct timespec64 *tp);
    ktime_t (*timer_forward)(struct k_itimer *timr, ktime_t now);
    ktime_t (*timer_remaining)(struct k_itimer *timr, ktime_t now);
};

struct k_itimer {
    struct k_clock *kclock;
    int it_sigev_notify;
    ktime_t it_interval;
    int it_active;
    int it_clock;
    int it_requeue_pending;
    int it_overrun;
};

static inline struct timespec64 ktime_to_timespec64(ktime_t kt) {
    struct timespec64 ts;
    ts.tv_sec = kt / 1000000000;
    ts.tv_nsec = kt % 1000000000;
    return ts;
}

static inline ktime_t timespec64_to_ktime(struct timespec64 ts) {
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

#define SIGEV_THREAD_ID 0
#define SIGEV_NONE 1
#define REQUEUE_PENDING 1
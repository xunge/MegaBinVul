#include <stdbool.h>
#include <time.h>

struct timespec64 {
    long tv_sec;
    long tv_nsec;
};

struct itimerspec64 {
    struct timespec64 it_interval;
    struct timespec64 it_value;
};

struct k_clock {
    int (*timer_try_to_cancel)(struct k_itimer *);
    void (*timer_arm)(struct k_itimer *, long long, int, bool);
};

struct k_itimer {
    struct k_clock *kclock;
    long long it_interval;
    int it_active;
    int it_requeue_pending;
    int it_overrun_last;
    int it_sigev_notify;
};

#define TIMER_RETRY 1
#define SIGEV_NONE 0
#define SIGEV_THREAD_ID 1
#define REQUEUE_PENDING 1

typedef long long ktime_t;

extern int common_timer_get(struct k_itimer *timr, struct itimerspec64 *cur_setting);
extern ktime_t timespec64_to_ktime(struct timespec64 ts);
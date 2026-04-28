#include <stddef.h>

typedef long long ktime_t;

enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};

struct hrtimer {
    // minimal definition
};

struct k_itimer {
    struct {
        struct {
            struct hrtimer timer;
        } real;
    } it;
    int it_lock;
    int it_active;
    ktime_t it_interval;
    int it_requeue_pending;
    unsigned int it_overrun;
};

#define NSEC_PER_SEC 1000000000L
#define HZ 100

static inline ktime_t hrtimer_cb_get_time(struct hrtimer *timer) {
    return (ktime_t){0};
}

static inline unsigned int hrtimer_forward(struct hrtimer *timer, ktime_t now, ktime_t interval) {
    return 0;
}

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {
}

static inline void unlock_timer(struct k_itimer *timr, unsigned long flags) {
}

static inline int posix_timer_event(struct k_itimer *timr, int si_private) {
    return 0;
}

static inline ktime_t ktime_add(ktime_t a, ktime_t b) {
    return (ktime_t){0};
}

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
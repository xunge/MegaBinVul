#include <stdint.h>

typedef int64_t ktime_t;

struct hrtimer_base {
    ktime_t (*get_time)(void);
};

struct hrtimer {
    struct hrtimer_base *base;
};

struct k_itimer {
    struct {
        struct {
            struct hrtimer timer;
        } real;
    } it;
    unsigned long it_interval;
    unsigned int it_overrun;
};

unsigned int hrtimer_forward(struct hrtimer *timer, ktime_t now, ktime_t interval);
void hrtimer_restart(struct hrtimer *timer);
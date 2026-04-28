#include <stdbool.h>
#include <stdint.h>

typedef unsigned long ktime_t;
typedef uint64_t u64;

enum hrtimer_mode {
    HRTIMER_MODE_ABS,
    HRTIMER_MODE_REL,
    HRTIMER_MODE_PINNED
};

struct hrtimer;
struct hrtimer_clock_base {
    ktime_t (*get_time)(void);
    struct hrtimer_cpu_base *cpu_base;
};

struct hrtimer_cpu_base {
    bool nohz_active;
    int cpu;
};

extern struct hrtimer_clock_base *lock_hrtimer_base(struct hrtimer *timer, unsigned long *flags);
extern void remove_hrtimer(struct hrtimer *timer, struct hrtimer_clock_base *base, bool restart);
extern ktime_t ktime_add_safe(ktime_t a, ktime_t b);
extern ktime_t hrtimer_update_lowres(struct hrtimer *timer, ktime_t tim, enum hrtimer_mode mode);
extern void hrtimer_set_expires_range_ns(struct hrtimer *timer, ktime_t tim, u64 delta_ns);
extern struct hrtimer_clock_base *switch_hrtimer_base(struct hrtimer *timer, struct hrtimer_clock_base *base, bool pinned);
extern void timer_stats_hrtimer_set_start_info(struct hrtimer *timer);
extern int enqueue_hrtimer(struct hrtimer *timer, struct hrtimer_clock_base *base);
extern bool hrtimer_is_hres_active(struct hrtimer *timer);
extern void wake_up_nohz_cpu(int cpu);
extern void hrtimer_reprogram(struct hrtimer *timer, struct hrtimer_clock_base *base);
extern void unlock_hrtimer_base(struct hrtimer *timer, unsigned long *flags);
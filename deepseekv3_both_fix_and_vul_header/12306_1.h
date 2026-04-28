#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;

struct hrtimer {
    u8 state;
};

struct hrtimer_clock_base {
    struct hrtimer_cpu_base *cpu_base;
};

struct hrtimer_cpu_base {
    // dummy definition
};

extern struct hrtimer_cpu_base hrtimer_bases;

static inline bool hrtimer_is_queued(struct hrtimer *timer) { return false; }
static inline void debug_deactivate(struct hrtimer *timer) {}
static inline void timer_stats_hrtimer_clear_start_info(struct hrtimer *timer) {}
static inline void __remove_hrtimer(struct hrtimer *timer, struct hrtimer_clock_base *base, u8 state, int reprogram) {}

#define this_cpu_ptr(ptr) (ptr)
#define HRTIMER_STATE_INACTIVE 0
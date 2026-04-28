#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int dummy;
} spinlock_t;

struct timer_list {
    unsigned long expires;
    unsigned int flags;
    void (*function)(unsigned long);
    unsigned long data;
};

struct timer_base {
    unsigned long clk;
    spinlock_t lock;
    struct timer_list *running_timer;
    int cpu;
};

#define TIMER_BASEMASK 0xFF
#define TIMER_MIGRATING 0x100

#define BUG_ON(condition) do { if (condition) abort(); } while(0)
#define likely(x) __builtin_expect(!!(x), 1)
#define WRITE_ONCE(var, val) (*(volatile typeof(val) *)&(var) = (val))

static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) {}

static inline unsigned int calc_wheel_index(unsigned long expires, unsigned long clk) { return 0; }
static inline unsigned int timer_get_idx(struct timer_list *timer) { return 0; }
static inline bool timer_pending(struct timer_list *timer) { return false; }
static inline struct timer_base *lock_timer_base(struct timer_list *timer, unsigned long *flags) { return NULL; }
static inline void timer_stats_timer_set_start_info(struct timer_list *timer) {}
static inline int detach_if_pending(struct timer_list *timer, struct timer_base *base, bool detach) { return 0; }
static inline void debug_activate(struct timer_list *timer, unsigned long expires) {}
static inline struct timer_base *get_target_base(struct timer_base *base, unsigned int flags) { return NULL; }
static inline void forward_timer_base(struct timer_base *base) {}
static inline void enqueue_timer(struct timer_base *base, struct timer_list *timer, unsigned int idx) {}
static inline void trigger_dyntick_cpu(struct timer_base *base, struct timer_list *timer) {}
static inline void internal_add_timer(struct timer_base *base, struct timer_list *timer) {}
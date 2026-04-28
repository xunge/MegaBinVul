#include <stdbool.h>

struct timer_list;
struct timer_base {
    struct timer_list *running_timer;
    unsigned long lock;
};

extern void debug_assert_init(struct timer_list *timer);
extern struct timer_base *lock_timer_base(struct timer_list *timer, unsigned long *flags);
extern void timer_stats_timer_clear_start_info(struct timer_list *timer);
extern int detach_if_pending(struct timer_list *timer, struct timer_base *base, bool pending);
extern void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
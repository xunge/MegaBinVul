#include <stdbool.h>

struct timer_list;
struct timer_base {
    int lock;  // Simplified spinlock representation
};

extern void debug_assert_init(struct timer_list *timer);
extern void timer_stats_timer_clear_start_info(struct timer_list *timer);
extern bool timer_pending(struct timer_list *timer);
extern struct timer_base *lock_timer_base(struct timer_list *timer, unsigned long *flags);
extern int detach_if_pending(struct timer_list *timer, struct timer_base *base, bool clear_pending);
extern void spin_unlock_irqrestore(int *lock, unsigned long flags);
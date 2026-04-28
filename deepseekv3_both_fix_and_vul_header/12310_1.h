#include <stdbool.h>

struct timer_list {
    unsigned long flags;
    void (*function)(struct timer_list *);
    unsigned long expires;
};

struct timer_base {
    int lock;
};

#define TIMER_MIGRATING 0x01
#define TIMER_BASEMASK 0x02
#define BUG_ON(cond) ((void)0)
#define WRITE_ONCE(x, val) (x = val)

void timer_stats_timer_set_start_info(struct timer_list *timer);
bool timer_pending(struct timer_list *timer);
struct timer_base *get_timer_cpu_base(unsigned long flags, int cpu);
struct timer_base *lock_timer_base(struct timer_list *timer, unsigned long *flags);
void debug_activate(struct timer_list *timer, unsigned long expires);
void internal_add_timer(struct timer_base *base, struct timer_list *timer);
void spin_unlock(int *lock);
void spin_lock(int *lock);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
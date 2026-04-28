#include <stddef.h>
#include <stdbool.h>

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct timer_list {
    struct hlist_node entry;
    void (*function)(unsigned long);
    unsigned long data;
    unsigned int flags;
};

struct timer_base {
    struct timer_list *running_timer;
    void *lock;
};

#define hlist_empty(ptr) ((ptr)->first == NULL)
#define hlist_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define TIMER_IRQSAFE (1 << 0)

void timer_stats_account_timer(struct timer_list *timer);
void detach_timer(struct timer_list *timer, bool clear_pending);
void call_timer_fn(struct timer_list *timer, void (*fn)(unsigned long), unsigned long data);
void spin_lock(void *lock);
void spin_unlock(void *lock);
void spin_lock_irq(void *lock);
void spin_unlock_irq(void *lock);
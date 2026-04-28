#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct timer_list {
    void (*function)(unsigned long);
    unsigned long data;
    unsigned long expires;
};

struct kthread_work {
    struct list_head node;
    struct kthread_worker *worker;
};

struct kthread_delayed_work {
    struct kthread_work work;
    struct timer_list timer;
};

struct kthread_worker {
    struct list_head work_list;
    struct list_head delayed_work_list;
};

#define WARN_ON_ONCE(cond) ((void)0)

extern unsigned long jiffies;

void kthread_insert_work(struct kthread_worker *worker,
                        struct kthread_work *work,
                        struct list_head *work_list);
void kthread_insert_work_sanity_check(struct kthread_worker *worker,
                                    struct kthread_work *work);
void timer_stats_timer_set_start_info(struct timer_list *timer);
void add_timer(struct timer_list *timer);
void kthread_delayed_work_timer_fn(unsigned long data);
void list_add(struct list_head *new, struct list_head *head);
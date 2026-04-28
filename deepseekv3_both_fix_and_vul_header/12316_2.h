#include <stddef.h>

#define WORK_CPU_UNBOUND (-1)
#define WARN_ON_ONCE(condition) do { } while (0)
#define unlikely(x) (x)

struct list_head {
    struct list_head *next, *prev;
};

struct workqueue_struct;

struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct work_struct {
    struct list_head entry;
};

struct delayed_work {
    struct timer_list timer;
    struct work_struct work;
    struct workqueue_struct *wq;
    int cpu;
};

extern unsigned long jiffies;
void __queue_work(int cpu, struct workqueue_struct *wq, struct work_struct *work);
void add_timer(struct timer_list *timer);
void add_timer_on(struct timer_list *timer, int cpu);
int timer_pending(const struct timer_list *timer);
void timer_stats_timer_set_start_info(struct timer_list *timer);
void delayed_work_timer_fn(unsigned long data);
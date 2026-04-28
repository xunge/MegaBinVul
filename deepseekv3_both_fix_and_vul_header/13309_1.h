#include <stddef.h>
#include <stdlib.h>

#define NOTIFY_DONE 0
#define NOTIFY_BAD 1
#define FIB_EVENT_ENTRY_DEL 0
#define AF_INET 2
#define AF_INET6 10
#define GFP_ATOMIC 0

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    int dummy;
};

struct nsim_fib_event {
    struct nsim_fib_data *data;
    unsigned long event;
    int family;
    struct list_head list;
};

struct nsim_fib_data {
    struct list_head fib_event_queue;
    struct work_struct fib_event_work;
    struct work_struct fib_flush_work;
    int fib_event_queue_lock;
};

struct fib_notifier_info {
    int family;
};

void spin_lock_bh(int *lock);
void spin_unlock_bh(int *lock);
void schedule_work(struct work_struct *work);
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);

int nsim_fib4_prepare_event(struct fib_notifier_info *info, struct nsim_fib_event *fib_event, unsigned long event);
int nsim_fib6_prepare_event(struct fib_notifier_info *info, struct nsim_fib_event *fib_event, unsigned long event);
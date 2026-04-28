#include <stdbool.h>

#define CLOCK_REALTIME 0
#define CLOCK_REALTIME_ALARM 8
#define TFD_TIMER_ABSTIME (1 << 0)
#define TFD_TIMER_CANCEL_ON_SET (1 << 1)

struct list_head {
    struct list_head *next, *prev;
};

struct timerfd_ctx {
    int clockid;
    bool might_cancel;
    int cancel_lock;
    struct list_head clist;
};

static int cancel_lock;
static struct list_head cancel_list;

void spin_lock(int *lock);
void spin_unlock(int *lock);
void list_add_rcu(struct list_head *new, struct list_head *head);
void __timerfd_remove_cancel(struct timerfd_ctx *ctx);
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct timerfd_ctx {
    bool might_cancel;
    struct list_head clist;
};

static int cancel_lock;

#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define list_del_rcu(list) (void)0
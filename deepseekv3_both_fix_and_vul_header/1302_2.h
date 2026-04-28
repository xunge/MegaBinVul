#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint64_t u64;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define ULLONG_MAX UINT64_MAX
#define UPDATES_PER_WINDOW 10

struct kref {
    int count;
};

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int lock;
};

struct task_struct {
    int dummy;
};

struct timer_list {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

#define static_branch_likely(x) (1)
#define wake_up_interruptible(x) do {} while (0)
#define mutex_lock(x) do {} while (0)
#define mutex_unlock(x) do {} while (0)
#define list_empty(x) (1)
#define list_del(x) do {} while (0)
#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)
#define div_u64(a, b) ((a)/(b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rcu_dereference_protected(p, c) (p)
#define rcu_assign_pointer(p, v) do { (p) = (v); } while (0)
#define del_timer(x) do {} while (0)
#define synchronize_rcu() do {} while (0)
#define kthread_stop(x) do {} while (0)
#define lockdep_is_held(x) (1)

struct psi_trigger {
    struct kref refcount;
    struct psi_group *group;
    int state;
    struct list_head node;
    struct wait_queue_head event_wait;
    struct {
        u64 size;
    } win;
};

struct psi_group {
    struct mutex trigger_lock;
    unsigned long poll_states;
    u64 poll_min_period;
    unsigned long polling_until;
    struct task_struct *poll_task;
    struct timer_list poll_timer;
    struct list_head triggers;
    int nr_triggers[1];
};

static inline void kfree(void *ptr) {
    free(ptr);
}
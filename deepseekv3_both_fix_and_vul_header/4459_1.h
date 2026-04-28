#include <stdint.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct wait_queue_head {
    uintptr_t lock;
};

struct fs_pin {
    struct hlist_node m_list;
    struct hlist_node s_list;
    struct wait_queue_head wait;
    int done;
};

static uintptr_t pin_lock;

void spin_lock(uintptr_t *lock);
void spin_unlock(uintptr_t *lock);
void spin_lock_irq(uintptr_t *lock);
void spin_unlock_irq(uintptr_t *lock);
void hlist_del(struct hlist_node *n);
void wake_up_locked(struct wait_queue_head *wq_head);
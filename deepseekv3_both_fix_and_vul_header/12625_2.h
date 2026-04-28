#include <stdatomic.h>
#include <stddef.h>

typedef struct {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct cipso_v4_doi {
    struct list_head list;
    _Atomic int refcount;
    struct rcu_head rcu;
};

extern spinlock_t cipso_v4_doi_list_lock;
extern void cipso_v4_cache_invalidate(void);
extern void cipso_v4_doi_free_rcu(struct rcu_head *head);

static inline int refcount_dec_and_test(_Atomic int *r) {
    return atomic_fetch_sub(r, 1) == 1;
}

static inline void spin_lock(spinlock_t *lock) {
    while (atomic_flag_test_and_set(&lock->lock));
}

static inline void spin_unlock(spinlock_t *lock) {
    atomic_flag_clear(&lock->lock);
}

static inline void list_del_rcu(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *)) {
    head->func = func;
    func(head);
}
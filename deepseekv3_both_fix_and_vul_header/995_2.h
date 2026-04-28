#include <stdatomic.h>
#include <stdbool.h>
#include <stdlib.h>

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct user_namespace;
typedef int kuid_t;

typedef struct {
    int lock;
} spinlock_t;

#define GFP_KERNEL 0

struct ucounts {
    struct user_namespace *ns;
    kuid_t uid;
    atomic_int count;
    struct hlist_node node;
};

spinlock_t ucounts_lock;

static inline void atomic_set(atomic_int *v, int i) {
    atomic_store(v, i);
}

static inline void spin_lock_irq(spinlock_t *lock) {
    (void)lock;
}

static inline void spin_unlock_irq(spinlock_t *lock) {
    (void)lock;
}

struct hlist_head *ucounts_hashentry(struct user_namespace *ns, kuid_t uid);
struct ucounts *find_ucounts(struct user_namespace *ns, kuid_t uid, struct hlist_head *hashent);
bool get_ucounts_or_wrap(struct ucounts *ucounts);
void put_ucounts(struct ucounts *ucounts);
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void hlist_add_head(struct hlist_node *n, struct hlist_head *h);
#include <stdatomic.h>
#include <stdlib.h>
#include <limits.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct user_namespace;
typedef int kuid_t;

struct ucounts {
    struct user_namespace *ns;
    kuid_t uid;
    atomic_int count;
    struct hlist_node node;
};

typedef struct {
    int lock;
} spinlock_t;
extern spinlock_t ucounts_lock;

#define spin_lock_irq(lock) ((void)(lock))
#define spin_unlock_irq(lock) ((void)(lock))

#define GFP_KERNEL 0
#define kzalloc(size, flags) calloc(1, (size))
#define kfree(ptr) free((ptr))

static inline void atomic_set(atomic_int *v, int i) {
    atomic_store(v, i);
}

static inline int atomic_add_unless(atomic_int *v, int a, int u) {
    int old = atomic_load(v);
    while (old != u) {
        if (atomic_compare_exchange_weak(v, &old, old + a))
            return 1;
    }
    return 0;
}

extern struct hlist_head *ucounts_hashentry(struct user_namespace *ns, kuid_t uid);
extern struct ucounts *find_ucounts(struct user_namespace *ns, kuid_t uid, struct hlist_head *hashent);
extern void hlist_add_head(struct hlist_node *node, struct hlist_head *head);
#include <stdatomic.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};
struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct calipso_doi {
    struct list_head list;
    _Atomic int refcount;
    struct rcu_head rcu;
};

int calipso_doi_list_lock;
void calipso_doi_free_rcu(struct rcu_head *head);

static inline int refcount_dec_and_test(_Atomic int *r) {
    return --(*r) == 0;
}

#define spin_lock(lock) ((void)(lock))
#define spin_unlock(lock) ((void)(lock)) 
#define list_del_rcu(list) ((void)(list))
#define call_rcu(head, func) ((func)(head))
#include <stdbool.h>
#include <stdlib.h>

struct swevent_hlist {
    // 空结构体定义
};

struct swevent_htable {
    int hlist_mutex;
    bool online;
    int hlist_refcount;
    struct swevent_hlist *swevent_hlist;
};

static struct swevent_htable swevent_htable;
#define per_cpu(var, cpu) (swevent_htable)

static inline void *kzalloc_node(size_t size, int flags, int node) {
    return calloc(1, size);
}

#define GFP_KERNEL 0
#define cpu_to_node(cpu) (0)
#define WARN_ON(cond) ((void)0)
#define mutex_lock(lock) ((void)0)
#define mutex_unlock(lock) ((void)0)
#define rcu_assign_pointer(p, v) ((p) = (v))
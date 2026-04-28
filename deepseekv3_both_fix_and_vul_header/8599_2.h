#include <stdlib.h>
#include <pthread.h>

struct perf_event;

struct swevent_htable {
    pthread_mutex_t hlist_mutex;
    struct swevent_hlist *swevent_hlist;
    int hlist_refcount;
};

struct swevent_hlist {
    // Add necessary fields here
};

#define per_cpu(var, cpu) (var)
#define GFP_KERNEL 0
#define ENOMEM 12
#define cpu_online(cpu) 1

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline struct swevent_hlist *swevent_hlist_deref(struct swevent_htable *swhash) {
    return swhash->swevent_hlist;
}

static inline void rcu_assign_pointer(struct swevent_hlist **p, struct swevent_hlist *v) {
    *p = v;
}

static struct swevent_htable swevent_htable;
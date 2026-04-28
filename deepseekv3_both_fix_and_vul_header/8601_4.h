#include <stdbool.h>

#define NR_CPUS 8

struct mutex {
    int dummy;
};

struct swevent_htable {
    bool online;
    struct mutex hlist_mutex;
};

struct swevent_htable swevent_htable[NR_CPUS];

#define per_cpu(var, cpu) (var[cpu])

void perf_event_exit_cpu_context(int cpu);
void swevent_hlist_release(struct swevent_htable *swhash);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
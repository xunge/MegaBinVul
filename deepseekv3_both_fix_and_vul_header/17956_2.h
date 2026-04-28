#include <stdint.h>
#include <stdlib.h>

typedef uint64_t u64;

struct eventfd_ctx {
    int dummy;
};

struct cgroup {
    int dummy;
};

struct cftype {
    unsigned long private;
};

struct mem_cgroup_threshold {
    struct eventfd_ctx *eventfd;
    u64 threshold;
};

struct mem_cgroup_threshold_ary {
    int size;
    int current_threshold;
    struct mem_cgroup_threshold *entries;
};

struct mem_cgroup_thresholds {
    struct mem_cgroup_threshold_ary *primary;
    struct mem_cgroup_threshold_ary *spare;
};

struct mem_cgroup {
    struct mem_cgroup_thresholds thresholds;
    struct mem_cgroup_thresholds memsw_thresholds;
    int thresholds_lock;
};

enum {
    _MEM,
    _MEMSWAP
};

#define MEMFILE_TYPE(_priv) ((_priv) & 0xFFFF)

#define BUG() abort()
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define mutex_lock(lock) (void)0
#define mutex_unlock(lock) (void)0
#define kfree(ptr) free(ptr)
#define rcu_assign_pointer(p, v) ((p) = (v))
#define synchronize_rcu() (void)0

static struct mem_cgroup *mem_cgroup_from_cont(struct cgroup *cgrp) { return NULL; }
static u64 mem_cgroup_usage(struct mem_cgroup *memcg, int swap) { return 0; }
static void __mem_cgroup_threshold(struct mem_cgroup *memcg, int swap) {}
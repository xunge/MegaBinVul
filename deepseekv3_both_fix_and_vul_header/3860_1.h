#include <stdbool.h>
#include <stddef.h>

extern bool cgroup_sk_alloc_disabled;
extern int in_interrupt(void);
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void cpu_relax(void);
#define likely(x) __builtin_expect(!!(x), 1)

struct task_struct;
struct css_set {
    struct cgroup *dfl_cgrp;
};
struct cgroup;

struct sock_cgroup_data {
    union {
        unsigned long val;
        struct cgroup *cgrp;
        struct {
            unsigned short priority;
            unsigned short classid;
        };
    };
    unsigned char no_refcnt;
};

extern struct task_struct *current;
extern struct css_set *task_css_set(struct task_struct *task);
extern bool cgroup_tryget(struct cgroup *cgrp);
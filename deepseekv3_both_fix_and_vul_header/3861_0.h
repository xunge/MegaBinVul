#include <stddef.h>

struct sock_cgroup_data {
    int no_refcnt;
};

struct cgroup;

static inline struct cgroup *sock_cgroup_ptr(struct sock_cgroup_data *skcd) {
    return NULL;
}

void cgroup_put(struct cgroup *cg);
#include <stddef.h>

struct cgroup {
    // minimal definition to make it complete
    int dummy;
};

struct sock_cgroup_data {
    unsigned long val;
};

struct cgrp_dfl_root {
    struct cgroup cgrp;
};

extern struct cgrp_dfl_root cgrp_dfl_root;

#define READ_ONCE(x) (x)
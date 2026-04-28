#include <stddef.h>

struct kernfs_open_file {
    void *priv;
};

struct psi_trigger;

struct cgroup_file_ctx {
    struct {
        struct psi_trigger *trigger;
    } psi;
};

void psi_trigger_replace(struct psi_trigger **old, struct psi_trigger *new);
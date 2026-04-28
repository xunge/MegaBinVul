#include <sys/types.h>
#include <stddef.h>
#include <errno.h>
#include <stdbool.h>

enum psi_res {
    PSI_IO,
    PSI_MEM,
    PSI_CPU,
    PSI_NONE
};

struct kernfs_open_file {
    void *kn;
    void *priv;
};

struct cgroup_file_ctx {
    struct {
        void *trigger;
    } psi;
};

struct psi_group {
    int dummy;
};

struct cgroup {
    unsigned long ino;
    struct psi_group psi;
};

struct psi_trigger {
    int dummy;
};

extern struct psi_group psi_system;
extern struct cgroup *cgroup_kn_lock_live(void *kn, bool b);
extern void cgroup_kn_unlock(void *kn);
extern void cgroup_get(struct cgroup *cgrp);
extern void cgroup_put(struct cgroup *cgrp);
extern unsigned long cgroup_ino(struct cgroup *cgrp);
extern struct psi_trigger *psi_trigger_create(struct psi_group *psi, char *buf, size_t nbytes, enum psi_res res);
extern int IS_ERR(const void *ptr);
extern long PTR_ERR(const void *ptr);
extern void smp_store_release(void **ptr, void *new);
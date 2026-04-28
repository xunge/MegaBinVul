#include <sys/mount.h>

struct pid_namespace {
    void *proc_mnt;
};

struct vfsmount;
void mntput(struct vfsmount *mnt);
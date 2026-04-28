#include <sys/types.h>
#include <signal.h>
#include <stddef.h>

#define __exit

struct pid {
    int wait_pidfd;
};

struct umd_info {
    struct pid *tgid;
};

struct umd_ops {
    struct umd_info info;
};

extern struct umd_ops umd_ops;
extern void *bpf_preload_ops;
extern void umd_cleanup_helper(struct umd_info *info);
extern void umd_unload_blob(struct umd_info *info);
extern int kill_pid(struct pid *pid, int sig, int priv);
extern int thread_group_exited(struct pid *pid);
extern void wait_event(int wait_pidfd, int condition);
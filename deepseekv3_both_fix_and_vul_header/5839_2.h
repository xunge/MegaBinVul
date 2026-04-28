#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/personality.h>
#include <grp.h>
#include <sched.h>
#include <sys/mount.h>

#define CLONE_NEWNS 0x00020000
#define CLONE_NEWUSER 0x10000000
#define LXC_ATTACH_REMOUNT_PROC_SYS (1 << 0)
#define LXC_ATTACH_DROP_CAPABILITIES (1 << 1)
#define LXC_ATTACH_SET_PERSONALITY (1 << 2)
#define LXC_ATTACH_LSM (1 << 3)
#define LXC_ATTACH_LSM_EXEC (1 << 4)

typedef struct lxc_attach_options lxc_attach_options_t;

struct attach_clone_payload {
    int ipc_socket;
    int procfd;
    lxc_attach_options_t *options;
    struct lxc_proc_context_info *init_ctx;
    int (*exec_function)(void *);
    void *exec_payload;
};

struct lxc_attach_options {
    int namespaces;
    int attach_flags;
    int stdin_fd;
    int stdout_fd;
    int stderr_fd;
    uid_t uid;
    gid_t gid;
    long personality;
    char **extra_env_vars;
    char **extra_keep_env;
    int env_policy;
};

struct lxc_proc_context_info {
    long personality;
    char *lsm_label;
    struct lxc_container *container;
};

struct lxc_container {
    struct lxc_conf *lxc_conf;
};

struct lxc_conf;

static inline int lxc_read_nointr_expect(int fd, void *buf, size_t count, int *expected) {
    return read(fd, buf, count);
}

static inline int lxc_attach_remount_sys_proc(void) {
    return 0;
}

static inline int lxc_attach_drop_privs(struct lxc_proc_context_info *ctx) {
    return 0;
}

static inline int lxc_attach_set_environment(int policy, char **extra_env, char **extra_keep) {
    return 0;
}

static inline void lxc_attach_get_init_uidgid(uid_t *uid, gid_t *gid) {
    *uid = 0;
    *gid = 0;
}

static inline int lxc_write_nointr(int fd, const void *buf, size_t count) {
    return write(fd, buf, count);
}

static inline int lsm_set_label_at(int fd, int on_exec, const char *label) {
    return 0;
}

static inline int lxc_seccomp_load(struct lxc_conf *conf) {
    return 0;
}

static inline void lxc_proc_put_context_info(struct lxc_proc_context_info *ctx) {
}

static inline int mount_proc_if_needed(const char *path) {
    return 0;
}

static inline int lsm_process_label_set(const char *label, struct lxc_conf *conf, int default_label, int on_exec) {
    return 0;
}

#define ERROR(fmt) fprintf(stderr, fmt)
#define SYSERROR(fmt) perror(fmt)
#define rexit(code) _exit(code)
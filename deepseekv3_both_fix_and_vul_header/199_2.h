#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/prctl.h>
#include <sys/socket.h>
#include <linux/filter.h>
#include <linux/seccomp.h>
#include <sys/eventfd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <sched.h>
#include <sys/syscall.h>
#include <sys/signalfd.h>
#include <signal.h>
#include <sys/param.h>

#define CLONE_NEWNS 0x00020000
#define CLONE_NEWCGROUP 0x02000000
#define CLONE_NEWUTS 0x04000000
#define CLONE_NEWIPC 0x08000000
#define CLONE_NEWUSER 0x10000000
#define CLONE_NEWPID 0x20000000
#define CLONE_NEWNET 0x40000000

#define MS_REC 16384
#define MS_PRIVATE (1<<18)
#define MS_SLAVE (1<<19)
#define MS_MGC_VAL 0xc0ed0000
#define MS_BIND 4096
#define MS_NODEV 4
#define MS_NOSUID 2

#define O_PATH 2097152
#define O_CLOEXEC 02000000
#define EFD_CLOEXEC O_CLOEXEC
#define EFD_NONBLOCK 04000

#define PRIV_SEP_OP_DONE 0

typedef int pid_t;
typedef unsigned int mode_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;

#define UNUSED __attribute__((unused))
#define cleanup_free __attribute__((cleanup(free_pointer)))
#define cleanup_fd __attribute__((cleanup(close_pointer)))
#define TRUE 1
#define FALSE 0

static uid_t real_uid;
static gid_t real_gid;
static char *argv0;
static char *host_tty_dev;
static char *opt_args_data;
static int requested_caps[2];
static int is_privileged;
static int opt_userns_block_fd;
static int opt_unshare_user;
static int opt_info_fd;
static int opt_unshare_user_try;
static int opt_sandbox_uid;
static int opt_sandbox_gid;
static int opt_unshare_uts;
static char *opt_sandbox_hostname;
static int opt_as_pid_1;
static int opt_unshare_pid;
static char **lock_files;
static int proc_fd;
static int opt_needs_devpts;
static int opt_json_status_fd;
static int opt_unshare_net;
static int opt_unshare_ipc;
static int opt_unshare_cgroup;
static int opt_unshare_cgroup_try;
static int opt_block_fd;
static int opt_seccomp_fd;
static char *opt_chdir_path;
static int opt_new_session;
static char *opt_exec_label;
static int opt_sync_fd;

static inline void free_pointer(void *p) { free(*(void**)p); }
static inline void close_pointer(int *p) { if (*p >= 0) close(*p); }

static void close_extra_fds(void *data, int fd) {
    int *dont_close = (int*)data;
    for (int i = 0; dont_close[i] != -1; i++) {
        if (fd == dont_close[i]) return;
    }
    close(fd);
}

#define TEMP_FAILURE_RETRY(expression) \
    (__extension__({ \
        long int __result; \
        do __result = (long int)(expression); \
        while (__result == -1L && errno == EINTR); \
        __result; \
    }))
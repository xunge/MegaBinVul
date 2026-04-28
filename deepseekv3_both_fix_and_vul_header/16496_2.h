#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sched.h>
#include <linux/sched.h>

#define FUSE_LOG_ERR 1
#define CLONE_NEWPID 0x20000000
#define CLONE_NEWNS  0x00020000
#define CLONE_NEWNET 0x40000000
#define O_PATH 010000000

struct lo_data {
    int proc_self_fd;
};

struct fuse_session {
    int exited;
};

void fuse_log(int level, const char *fmt, ...);
void setup_wait_parent_capabilities(void);
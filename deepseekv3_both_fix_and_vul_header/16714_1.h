#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define BPF_PRELOAD_END 0
#define EPIPE 32

struct pid {
    int wait_pidfd;
};

struct umd_ops_info {
    struct pid *tgid;
    int pipe_to_umh;
};

static struct {
    struct umd_ops_info info;
} umd_ops;

typedef long loff_t;
typedef long ssize_t;

int kernel_write(int pipe, const void *buf, size_t count, loff_t *pos);
void wait_event(int wait_pidfd, int condition);
int thread_group_exited(struct pid *tgid);
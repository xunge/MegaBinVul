#include <sys/types.h>
#include <errno.h>
#include <stddef.h>

typedef long ssize_t;

struct bsg_device {
    char *name;
};

struct file {
    void *private_data;
    int f_mode;
};

typedef unsigned long mm_segment_t;

#define __user
#define segment_eq(a, b) ((a) == (b))
#define get_fs() (current_thread_info()->addr_limit)
#define KERNEL_DS ((mm_segment_t) { ~0UL })
#define unlikely(x) (x)
#define EINVAL 22
#define FMODE_WRITE 0x2
#define dprintk(fmt, ...)

struct thread_info {
    mm_segment_t addr_limit;
};

extern struct thread_info *current_thread_info(void);

static void bsg_set_block(struct bsg_device *bd, struct file *file) {}
static int __bsg_write(struct bsg_device *bd, const char *buf, size_t count, ssize_t *bytes_written, int mode) { return 0; }
static int err_block_err(int ret) { return 0; }
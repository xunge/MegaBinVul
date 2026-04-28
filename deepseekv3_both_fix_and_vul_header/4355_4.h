#include <signal.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

struct pipe_inode_info {
    unsigned int buffers;
    unsigned int curbuf;
    unsigned int nrbufs;
    struct pipe_buffer *bufs;
    int readers;
    int files;
    int wait;
    struct fasync_struct *fasync_readers;
};

struct pipe_buffer {
    void *page;
    unsigned int offset;
    unsigned int len;
    const void *ops;
};

struct pipe_buf_operations {
};

struct fuse_copy_state {
    struct pipe_buffer *pipebufs;
    struct pipe_inode_info *pipe;
    int nr_segs;
};

struct fuse_dev {
    void *fc;
};

struct fuse_conn {
};

struct file {
};

struct fasync_struct {
};

static const struct pipe_buf_operations nosteal_pipe_buf_ops;

static struct fuse_dev *fuse_get_dev(struct file *file) { return NULL; }
static void fuse_copy_init(struct fuse_copy_state *cs, int write, struct file *file) {}
static ssize_t fuse_dev_do_read(void *fc, struct file *file, struct fuse_copy_state *cs, size_t len) { return 0; }
static void pipe_lock(struct pipe_inode_info *pipe) {}
static void pipe_unlock(struct pipe_inode_info *pipe) {}
static void send_sig(int sig, void *current, int flags) {}
static void wake_up_interruptible(int *wq) {}
static int waitqueue_active(int *wq) { return 0; }
static void kill_fasync(struct fasync_struct **fp, int sig, int band) {}
static void page_cache_release(void *page) {}
static void *kmalloc(size_t size, int flags) { return NULL; }
static void kfree(void *p) {}

#define GFP_KERNEL 0
#define EPERM 1
#define ENOMEM 2
#define EPIPE 3
#define EIO 4
#define SIGPIPE 13
#define SIGIO 29
#define POLL_IN 1
#define current NULL
#define smp_mb()
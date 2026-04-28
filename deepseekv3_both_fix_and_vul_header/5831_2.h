#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <signal.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/uio.h>

#define PAGE_SIZE 4096
#define GFP_HIGHUSER 0
#define EPIPE 32
#define EAGAIN 11
#define ERESTARTSYS 512
#define ENOMEM 12
#define PIPE_BUF_FLAG_PACKET (1 << 0)

struct kiocb {
    struct file *ki_filp;
};

struct file {
    void *private_data;
    unsigned int f_flags;
};

struct pipe_inode_info {
    unsigned int nrbufs;
    unsigned int curbuf;
    unsigned int buffers;
    struct pipe_buffer *bufs;
    struct page *tmp_page;
    int readers;
    int waiting_writers;
    struct fasync_struct *fasync_readers;
    int wait;
};

struct pipe_buffer {
    struct page *page;
    const struct pipe_buf_operations *ops;
    unsigned int offset;
    unsigned int len;
    unsigned int flags;
};

struct pipe_buf_operations {
    int (*confirm)(struct pipe_inode_info *, struct pipe_buffer *);
    int can_merge;
};

struct page;
struct fasync_struct;
struct super_block {
    int i_sb;
};
struct inode {
    struct super_block *i_sb;
};
struct task_struct;
struct iovec;

static struct pipe_buf_operations anon_pipe_buf_ops;
static struct pipe_buf_operations packet_pipe_buf_ops;

#define unlikely(x) (x)
#define current ((struct task_struct *)0)

static void __pipe_lock(struct pipe_inode_info *pipe) {}
static void __pipe_unlock(struct pipe_inode_info *pipe) {}
static void pipe_wait(struct pipe_inode_info *pipe) {}
static size_t iov_length(const struct iovec *iov, unsigned long nr_segs) { return 0; }
static void iov_fault_in_pages_read(const struct iovec *iov, int chars) {}
static int pipe_iov_copy_from_user(void *to, const struct iovec *iov, size_t len, int atomic) { return 0; }
static void wake_up_interruptible_sync_poll(int *q, int poll_flag) {}
static void kill_fasync(struct fasync_struct **fp, int sig, int band) {}
static int is_packetized(struct file *filp) { return 0; }
static int sb_start_write_trylock(struct super_block *sb) { return 0; }
static void sb_end_write(struct super_block *sb) {}
static int file_update_time(struct file *file) { return 0; }
static struct inode *file_inode(struct file *file) { return NULL; }
static void send_sig(int sig, struct task_struct *p, int priv) {}
static int signal_pending(struct task_struct *p) { return 0; }
static void *kmap_atomic(struct page *page) { return NULL; }
static void kunmap_atomic(void *addr) {}
static void *kmap(struct page *page) { return NULL; }
static void kunmap(struct page *page) {}
static struct page *alloc_page(int gfp) { return NULL; }
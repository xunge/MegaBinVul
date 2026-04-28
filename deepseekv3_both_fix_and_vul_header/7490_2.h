#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

struct kiocb {
    struct file *ki_filp;
};

struct iov_iter {
    // dummy structure
};

struct file {
    void *private_data;
    int f_flags;
};

struct wait_queue_head {
    int lock;
};

struct fasync_struct {
    // dummy structure
};

struct pipe_inode_info {
    unsigned int head;
    unsigned int tail;
    unsigned int max_usage;
    unsigned int ring_size;
    struct pipe_buffer *bufs;
    int writers;
    struct wait_queue_head rd_wait;
    struct wait_queue_head wr_wait;
    struct fasync_struct *fasync_writers;
    bool note_loss;
};

struct pipe_buffer {
    void *page;
    unsigned int offset;
    size_t len;
    unsigned int flags;
};

struct watch_notification {
    unsigned int type;
    unsigned int subtype;
    unsigned int info;
};

#define CONFIG_WATCH_QUEUE 1
#define PIPE_BUF_FLAG_WHOLE (1 << 0)
#define PIPE_BUF_FLAG_PACKET (1 << 1)
#define PIPE_BUF_FLAG_LOSS (1 << 2)

#define EPOLLOUT 0x004
#define EPOLLWRNORM 0x100
#define EPOLLIN 0x001
#define EPOLLRDNORM 0x040
#define POLL_OUT 0x004
#define SIGIO 29
#define O_NONBLOCK 04000
#define EAGAIN 11
#define EFAULT 14
#define ENOBUFS 105
#define ERESTARTSYS 512
#define WATCH_TYPE_META 0
#define WATCH_META_LOSS_NOTIFICATION 0

#define unlikely(x) (x)
#define __pipe_lock(pipe) 
#define __pipe_unlock(pipe) 
#define pipe_full(head, tail, limit) ((head) - (tail) >= (limit))
#define pipe_empty(head, tail) ((head) == (tail))
#define pipe_readable(pipe) (!pipe_empty((pipe)->head, (pipe)->tail))
#define pipe_buf_confirm(pipe, buf) (0)
#define pipe_buf_release(pipe, buf) 
#define copy_page_to_iter(page, offset, size, iter) (size)
#define copy_to_iter(src, size, iter) (size)
#define wait_event_interruptible_exclusive(wq, condition) (0)
#define wake_up_interruptible_sync_poll(wait, mask) 
#define kill_fasync(list, sig, mask) 
#define file_accessed(file) 
#define spin_lock_irq(lock) 
#define spin_unlock_irq(lock) 
#define watch_sizeof(n) (sizeof(n))

static inline size_t iov_iter_count(struct iov_iter *i) { return 0; }
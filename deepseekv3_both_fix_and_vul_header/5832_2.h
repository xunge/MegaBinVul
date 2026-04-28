#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

struct kiocb {
    struct file *ki_filp;
};

struct file {
    void *private_data;
    int f_flags;
};

struct pipe_inode_info {
    int nrbufs;
    int curbuf;
    struct pipe_buffer *bufs;
    int buffers;
    int writers;
    int waiting_writers;
    void *fasync_writers;
    void *wait;
};

struct pipe_buffer {
    void *page;
    unsigned int offset;
    unsigned int len;
    unsigned int flags;
    const struct pipe_buf_operations *ops;
};

struct pipe_buf_operations {
    int (*confirm)(struct pipe_inode_info *, struct pipe_buffer *);
    void (*release)(struct pipe_inode_info *, struct pipe_buffer *);
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct iov_iter {
    int dummy;
};

#define O_NONBLOCK  04000
#define EAGAIN      11
#define ERESTARTSYS 512
#define EFAULT      14
#define PIPE_BUF_FLAG_PACKET (1 << 0)

#define unlikely(x) (x)
#define __pipe_lock(pipe) 
#define __pipe_unlock(pipe) 
#define wake_up_interruptible_sync_poll(wait, mask) 
#define kill_fasync(list, sig, band) 
#define pipe_wait(pipe) 
#define file_accessed(file) 
#define signal_pending(p) 0
#define current ((void *)0)

static inline size_t iov_length(const struct iovec *iov, unsigned long nr_segs) { return 0; }
static inline void iov_iter_init(struct iov_iter *iter, const struct iovec *iov, 
                               unsigned long nr_segs, size_t len, int flags) {}
static inline size_t copy_page_to_iter(void *page, size_t offset, size_t len, 
                                     struct iov_iter *iter) { return 0; }
static inline void *kmap(void *page) { return NULL; }
static inline void kunmap(void *page) {}
static inline void *kmap_atomic(void *page) { return NULL; }
static inline void kunmap_atomic(void *addr) {}
static inline int iov_fault_in_pages_write(struct iovec *iov, size_t chars) { return 0; }
static inline int pipe_iov_copy_to_user(struct iovec *iov, void *addr, 
                                      size_t chars, int atomic) { return 0; }
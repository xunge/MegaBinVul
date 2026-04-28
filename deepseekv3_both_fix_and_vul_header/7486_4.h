#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <poll.h>

struct wait_queue_head {
    int lock;
};

struct fasync_struct;
struct page;

struct pipe_buf_operations {
    int dummy;
};

struct watch_queue {
    struct pipe_inode_info *pipe;
    bool defunct;
    unsigned long *notes_bitmap;
    unsigned int nr_notes;
    struct page **notes;
};

struct watch_notification {
    unsigned int info;
};

struct pipe_inode_info {
    unsigned int ring_size;
    unsigned int head;
    unsigned int tail;
    struct pipe_buffer *bufs;
    struct wait_queue_head rd_wait;
    struct fasync_struct *fasync_readers;
};

struct pipe_buffer {
    struct page *page;
    unsigned long private;
    const struct pipe_buf_operations *ops;
    unsigned int offset;
    unsigned int len;
    unsigned int flags;
};

#define WATCH_QUEUE_NOTES_PER_PAGE 1
#define WATCH_QUEUE_NOTE_SIZE 1
#define WATCH_INFO_LENGTH 0
#define PIPE_BUF_FLAG_WHOLE 0
#define PIPE_BUF_FLAG_LOSS 0
#define EPOLLIN 0x001
#define EPOLLRDNORM 0x040

static struct pipe_buf_operations watch_queue_pipe_buf_ops = {0};

static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}
static inline bool pipe_full(unsigned int head, unsigned int tail, unsigned int size) { return false; }
static inline unsigned int find_first_bit(const unsigned long *addr, unsigned int size) { return 0; }
static inline void get_page(struct page *page) {}
static inline void *kmap_atomic(struct page *page) { return NULL; }
static inline void kunmap_atomic(void *addr) {}
static inline bool test_and_clear_bit(unsigned int nr, volatile unsigned long *addr) { return false; }
static inline void wake_up_interruptible_sync_poll_locked(struct wait_queue_head *wq, int mask) {}
static inline void kill_fasync(struct fasync_struct **fp, int sig, int band) {}
static inline void BUG() {}
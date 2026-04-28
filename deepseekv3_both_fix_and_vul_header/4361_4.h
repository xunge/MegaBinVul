#include <poll.h>

typedef struct poll_table_struct poll_table;
struct file;

struct wait_queue_head {
    int lock;
};

struct fuse_iqueue {
    struct wait_queue_head waitq;
    int connected;
};

struct fuse_conn {
    struct fuse_iqueue iq;
};

struct fuse_dev {
    struct fuse_conn *fc;
};

static inline struct fuse_dev *fuse_get_dev(struct file *file) { return 0; }
static inline struct fuse_conn *fuse_get_conn(struct file *file) { return 0; }
static inline int request_pending(struct fuse_iqueue *fiq) { return 0; }
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void poll_wait(struct file *file, struct wait_queue_head *waitq, poll_table *wait) {}
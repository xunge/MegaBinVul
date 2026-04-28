#include <stddef.h>

#define EBADF 9

struct io_uring_work {
    void *files;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct io_kiocb {
    struct io_ring_ctx *ctx;
    struct io_uring_work work;
    unsigned int flags;
    struct list_head inflight_entry;
};

struct io_ring_ctx {
    void *ring_file;
    int ring_fd;
    void *inflight_lock;
    struct list_head inflight_list;
};

struct task_struct {
    void *files;
};

extern struct task_struct *current;

#define REQ_F_NO_FILE_TABLE (1U << 0)
#define REQ_F_INFLIGHT (1U << 1)

static inline void io_req_init_async(struct io_kiocb *req) {}
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void spin_lock_irq(void *lock) {}
static inline void spin_unlock_irq(void *lock) {}
static inline void *fcheck(int fd) { return NULL; }
static inline void list_add(struct list_head *new, struct list_head *head) {}
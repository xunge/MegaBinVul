#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef unsigned int __poll_t;
typedef uint16_t u16;
typedef uint32_t u32;

#define EPOLLERR ((__poll_t)0x0008)
#define EPOLLHUP ((__poll_t)0x0010)
#define EINVAL 22
#define EBADF 9
#define EOPNOTSUPP 95

#define IORING_SETUP_IOPOLL (1U << 0)

#define READ_ONCE(x) (x)
#define WRITE_ONCE(x, val) (x = val)
#define unlikely(x) (x)
#define likely(x) (x)

struct list_head {
    struct list_head *next, *prev;
};

struct file {
    struct file_operations *f_op;
};

struct file_operations {
    int (*may_pollfree)(void);
};

struct poll_table_struct {
    void (*_qproc)(struct file *, void *, struct poll_table_struct *);
    __poll_t _key;
};

struct io_poll_table {
    struct poll_table_struct pt;
    void *req;
    int error;
};

struct wait_queue_head {
    void *lock;
};

struct wait_queue_entry {
    struct list_head entry;
};

struct io_poll_iocb {
    __poll_t events;
    struct wait_queue_entry wait;
    bool done;
    bool canceled;
    struct file *file;
    struct wait_queue_head *head;
};

struct io_uring_sqe {
    void *addr;
    u16 ioprio;
    u16 poll_events;
    u32 off;
    u32 len;
    u16 buf_index;
};

struct io_ring_ctx {
    void *completion_lock;
    struct list_head cancel_list;
    unsigned int flags;
};

struct io_kiocb {
    struct io_ring_ctx *ctx;
    struct file *file;
    struct io_poll_iocb poll;
    struct list_head list;
    struct {
        const struct io_uring_sqe *sqe;
    } submit;
    void *work;
};

static void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static void INIT_WORK(void *work, void *func) {}
static void io_poll_complete_work(void *work) {}
static void io_poll_wake(struct wait_queue_entry *wait, unsigned mode, int sync, void *key) {}
static void io_poll_queue_proc(struct file *file, void *head, struct poll_table_struct *p) {}
static __poll_t demangle_poll(u16 events) { return 0; }
static __poll_t vfs_poll(struct file *file, struct poll_table_struct *wait) { return 0; }
static void io_poll_complete(struct io_ring_ctx *ctx, struct io_kiocb *req, __poll_t mask) {}
static void io_cqring_ev_posted(struct io_ring_ctx *ctx) {}
static void io_put_req(struct io_kiocb *req) {}
static void spin_lock_irq(void *lock) {}
static void spin_unlock_irq(void *lock) {}
static void spin_lock(void *lock) {}
static void spin_unlock(void *lock) {}
static void list_del_init(struct list_head *entry) {}
static void list_add_tail(struct list_head *new, struct list_head *head) {}
static int list_empty(const struct list_head *head) { return 1; }
static void init_waitqueue_func_entry(struct wait_queue_entry *wq_entry, void *func) {}
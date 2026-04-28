#include <stdatomic.h>
#include <stdint.h>

struct io_kiocb;
struct io_ring_ctx;
struct io_uring_cqe;
struct task_struct;

struct io_uring {
    _Bool in_idle;
};

struct list_head {
    struct list_head *next, *prev;
};

struct io_uring_cqe {
    uint64_t user_data;
    int32_t res;
    uint32_t flags;
};

struct io_rings {
    uint32_t sq_flags;
    uint32_t cq_overflow;
};

struct io_ring_ctx {
    struct io_rings *rings;
    _Atomic int cached_cq_overflow;
    struct list_head cq_overflow_list;
    unsigned long sq_check_overflow;
    unsigned long cq_check_overflow;
    _Bool cq_overflow_flushed;
};

struct task_struct {
    struct io_uring *io_uring;
};

struct io_kiocb {
    struct io_ring_ctx *ctx;
    uint64_t user_data;
    struct task_struct *task;
    long result;
    struct {
        long cflags;
        struct list_head list;
    } compl;
    _Atomic int refs;
};

#define WRITE_ONCE(x, val) ((x) = (val))
#define likely(x) __builtin_expect(!!(x), 1)
#define IORING_SQ_CQ_OVERFLOW (1U << 0)

static inline void trace_io_uring_complete(struct io_ring_ctx *ctx, uint64_t user_data, long res) {}
static inline struct io_uring_cqe *io_get_cqring(struct io_ring_ctx *ctx) { return 0; }
static inline int atomic_inc_return(_Atomic int *v) { return ++(*v); }
static inline void io_clean_op(struct io_kiocb *req) {}
static inline void refcount_inc(_Atomic int *refs) { ++(*refs); }

static inline void set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
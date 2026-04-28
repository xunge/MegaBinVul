#include <stdatomic.h>

struct io_uring {
    atomic_int inflight_tracked;
};

struct task_struct {
    struct io_uring *io_uring;
};

struct io_kiocb {
    unsigned int flags;
    struct task_struct *task;
};

#define REQ_F_INFLIGHT (1U << 0)

extern struct task_struct *current;

static inline void atomic_inc(atomic_int *v) {
    (*v)++;
}
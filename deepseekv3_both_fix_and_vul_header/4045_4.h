#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>

#define EINVAL 22
#define EOWNERDEAD 130
#define EOVERFLOW 75
#define EAGAIN 11

#define IORING_SETUP_IOPOLL (1U << 0)
#define IORING_SQ_TASKRUN (1U << 0)
#define IOU_ISSUE_SKIP_COMPLETE 0
#define TWA_SIGNAL_NO_IPI 0

struct file {
    void *private_data;
};

struct io_kiocb {
    struct file *file;
};

struct io_ring_ctx {
    bool task_complete;
    struct task_struct *submitter_task;
    unsigned int flags;
    struct {
        atomic_uint sq_flags;
    } *rings;
};

struct io_msg {
    int src_fd;
    int dst_fd;
    int flags;
    uint64_t user_data;
    int len;
    struct {
        void *tw;
    };
};

struct task_struct;

static inline void atomic_or(unsigned int mask, atomic_uint *ptr) {
    atomic_fetch_or(ptr, mask);
}

#define io_kiocb_to_cmd(ptr, type) ((type *)(ptr))

extern struct task_struct *current;
extern void init_task_work(void *, void (*)(void *));
extern bool task_work_add(struct task_struct *, void *, int);
extern bool io_double_lock_ctx(struct io_ring_ctx *, unsigned int);
extern void io_double_unlock_ctx(struct io_ring_ctx *);
extern bool io_post_aux_cqe(struct io_ring_ctx *, uint64_t, int, int);
extern void io_msg_tw_complete(void *);
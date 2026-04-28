#include <stddef.h>
#include <signal.h>
#include <stdbool.h>

struct io_ring_ctx {
    void *private_data;
    struct io_wq *io_wq;
};

struct io_wq;

struct file {
    struct io_ring_ctx *private_data;
};

struct task_struct {
    unsigned int flags;
};

extern struct task_struct *current;
extern int fatal_signal_pending(struct task_struct *p);
extern void io_uring_cancel_files(struct io_ring_ctx *ctx, void *data);
extern void io_wq_cancel_cb(struct io_wq *wq, void (*cancel)(void *), void *data, bool cancel_all);
extern void io_cancel_task_cb(void *data);

#define PF_EXITING 0x00000004
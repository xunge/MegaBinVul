#include <stddef.h>

struct xarray {
    void *data;
};

struct io_uring_task {
    struct xarray xa;
};

struct task_struct {
    struct io_uring_task *io_uring;
};

extern struct task_struct *current;
extern int xa_empty(struct xarray *xa);
extern void __io_uring_task_cancel(void);
extern void __io_uring_cancel(bool);
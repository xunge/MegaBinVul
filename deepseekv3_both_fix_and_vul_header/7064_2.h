#include <stdbool.h>

struct xarray {
    // Minimal dummy definition to make it complete type
    void *data;
};

struct task_struct {
    struct io_uring *io_uring;
};

struct io_uring {
    struct xarray xa;
};

extern struct task_struct *current;
extern void __io_uring_cancel(bool);
extern void __io_uring_task_cancel(void);
extern bool xa_empty(const struct xarray *);
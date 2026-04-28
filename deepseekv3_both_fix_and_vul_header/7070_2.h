#include <stdbool.h>

struct io_uring {
    void *xa;
};

extern struct task_struct {
    struct io_uring *io_uring;
} *current;

extern void __io_uring_cancel(bool);
extern void __io_uring_task_cancel(void);
extern bool xa_empty(void *);
#include <stdbool.h>

struct files_struct;
struct io_uring_task {
    void *xa;
};

extern struct task_struct {
    struct io_uring_task *io_uring;
} *current;

extern void __io_uring_cancel(bool);
extern void __io_uring_files_cancel(struct files_struct *);
extern bool xa_empty(void *);
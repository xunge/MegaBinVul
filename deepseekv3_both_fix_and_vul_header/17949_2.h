#include <stdatomic.h>
#include <stddef.h>

struct task_struct {
    struct io_context *io_context;
};

struct io_context;
struct as_io_context {
    void (*exit)(struct as_io_context *);
};
struct io_context {
    _Atomic int nr_tasks;
    struct as_io_context *aic;
};

extern void cfq_exit(struct io_context *);
extern void put_io_context(struct io_context *);
extern void task_lock(struct task_struct *);
extern void task_unlock(struct task_struct *);
extern struct task_struct *current;

static inline int atomic_dec_and_test(_Atomic int *v) {
    return atomic_fetch_sub(v, 1) == 1;
}
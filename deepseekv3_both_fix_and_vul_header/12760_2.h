#include <stdatomic.h>
#include <stdbool.h>

struct task_work {
    void (*func)(void *);
};

struct percpu_ref {
    _Atomic long count;
};

struct io_wq;
struct task_struct;

struct io_kiocb {
    struct task_work task_work;
    struct {
        struct percpu_ref refs;
        struct io_wq *io_wq;
    } *ctx;
};

#define unlikely(x) __builtin_expect(!!(x), 0)

void init_task_work(struct task_work *, void (*)(void *));
int io_req_task_work_add(struct io_kiocb *, struct task_work *);
struct task_struct *io_wq_get_task(struct io_wq *);
int task_work_add(struct task_struct *, struct task_work *, int);
void wake_up_process(struct task_struct *);
void io_req_task_submit(void *);
void io_req_task_cancel(void *);
void percpu_ref_get(struct percpu_ref *);
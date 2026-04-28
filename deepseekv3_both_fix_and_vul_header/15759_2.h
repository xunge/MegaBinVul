#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct task_work {
    struct task_work *next;
    void (*func)(struct task_work *);
};

struct completion {
    unsigned int done;
    // Simplified completion structure
};

struct task_struct;

struct io_ring_ctx {
    struct io_sq_data *sq_data;
    struct list_head sqd_list;
};

struct io_sq_data {
    struct task_struct *thread;
    struct task_work park_task_work;
};

struct io_tctx_exit {
    struct io_ring_ctx *ctx;
    struct completion completion;
    struct task_work task_work;
};

void io_sq_thread_park(struct io_sq_data *sqd);
void io_sqd_update_thread_idle(struct io_sq_data *sqd);
void io_sq_thread_unpark(struct io_sq_data *sqd);
void io_task_work_add_head(struct task_work *head, struct task_work *work);
void io_sqpoll_cancel_cb(struct task_work *work);
void init_completion(struct completion *c);
void init_task_work(struct task_work *tw, void (*func)(struct task_work *));
void wake_up_process(struct task_struct *tsk);
void wait_for_completion(struct completion *c);
void list_del_init(struct list_head *entry);
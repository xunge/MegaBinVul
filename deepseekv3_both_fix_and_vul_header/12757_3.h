#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct percpu_ref {
    unsigned long count;
};

struct io_wq;

struct io_uring_ctx {
    struct percpu_ref refs;
    struct io_wq *io_wq;
};

struct io_kiocb {
    struct io_uring_ctx *ctx;
    unsigned int opcode;
    unsigned long user_data;
    int result;
    struct callback_head task_work;
};

struct io_poll_iocb {
    unsigned int events;
    bool canceled;
    struct {
        struct list_head entry;
    } wait;
};

struct task_struct;

typedef unsigned int __poll_t;
typedef void (*task_work_func_t)(struct callback_head *);

#define WRITE_ONCE(x, val) (x = val)
#define unlikely(x) (x)

static inline void trace_io_uring_task_add(void *ctx, unsigned int opcode, unsigned long user_data, __poll_t mask) {}
static inline void list_del_init(struct list_head *entry) {}
static inline void init_task_work(struct callback_head *twork, task_work_func_t func) {}
static inline void percpu_ref_get(struct percpu_ref *ref) {}
static inline int io_req_task_work_add(struct io_kiocb *req, struct callback_head *work) { return 0; }
static inline struct task_struct *io_wq_get_task(struct io_wq *wq) { return NULL; }
static inline void task_work_add(struct task_struct *tsk, struct callback_head *work, int flags) {}
static inline void wake_up_process(struct task_struct *tsk) {}
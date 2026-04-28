#include <stddef.h>
#include <stdatomic.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct wait_queue_entry {
    struct list_head entry;
    void *private;
};

struct wait_page_queue {
    struct wait_queue_entry wait;
};

struct io_kiocb {
    struct callback_head task_work;
    atomic_int refs;
    struct {
        _Atomic long refs;
        void *io_wq;
    } *ctx;
};

struct wait_page_key;
struct task_struct;

typedef void (*task_work_func_t)(struct callback_head *);

static inline bool wake_page_match(struct wait_page_queue *wpq, struct wait_page_key *key) {
    return false;
}

static inline void init_task_work(struct callback_head *twork, task_work_func_t func) {
    twork->func = func;
}

static inline int io_req_task_work_add(struct io_kiocb *req, struct callback_head *twork) {
    return 0;
}

static inline void io_req_task_submit(struct callback_head *twork) {
}

static inline void io_req_task_cancel(struct callback_head *twork) {
}

static inline struct task_struct *io_wq_get_task(void *io_wq) {
    return NULL;
}

static inline void percpu_ref_get(_Atomic long *ref) {
    atomic_fetch_add(ref, 1);
}

static inline void task_work_add(struct task_struct *tsk, struct callback_head *twork, int flags) {
}

static inline void wake_up_process(struct task_struct *tsk) {
}

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline void refcount_inc(atomic_int *ref) {
    atomic_fetch_add(ref, 1);
}

#define unlikely(x) (x)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
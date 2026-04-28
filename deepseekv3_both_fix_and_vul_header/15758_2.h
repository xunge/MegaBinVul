#include <stddef.h>

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct completion {
    unsigned int done;
};

struct list_head {
    struct list_head *next, *prev;
};

struct io_sq_data {
    void *thread;
};

struct io_ring_ctx {
    struct io_sq_data *sq_data;
    struct list_head sqd_list;
};

struct io_tctx_exit {
    struct callback_head task_work;
    struct io_ring_ctx *ctx;
    struct completion completion;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void io_uring_cancel_sqpoll(void *target);
void list_del_init(struct list_head *entry);
void complete(struct completion *comp);
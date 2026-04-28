#include <stdbool.h>
#include <stddef.h>

struct io_kiocb {
    struct {
        unsigned int flags;
        struct io_identity *identity;
    } work;
    struct task_struct *task;
};

struct io_identity {
    const void *creds;
    int count;
};

struct io_uring_task {
    struct io_identity *identity;
    struct io_identity __identity;
};

struct task_struct {
    struct io_uring_task *io_uring;
};

extern void *kmemdup(const void *src, size_t len, int gfp);
extern void kfree(const void *objp);
extern void io_init_identity(struct io_identity *id);
extern void refcount_inc(int *count);
extern bool refcount_dec_and_test(int *count);

#define GFP_KERNEL 0
#define IO_WQ_WORK_CREDS 1
#define IO_WQ_WORK_CANCEL 2
#define unlikely(x) (x)
#define current (&dummy_task)
struct task_struct dummy_task;
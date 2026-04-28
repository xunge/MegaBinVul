#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define IORING_SETUP_SQPOLL    (1U << 0)
#define IORING_SETUP_SQ_AFF    (1U << 1)

#define EPERM           1
#define EINVAL          22
#define HZ              100
#define CAP_SYS_ADMIN   21

struct io_ring_ctx {
    unsigned int flags;
    unsigned long sq_thread_idle;
    void *sqo_thread;
};

struct io_uring_params {
    unsigned int flags;
    unsigned int sq_thread_idle;
    unsigned int sq_thread_cpu;
};

extern int io_init_wq_offload(struct io_ring_ctx *ctx, struct io_uring_params *p);
extern void io_finish_async(struct io_ring_ctx *ctx);
extern int io_sq_thread(void *data);
extern int capable(int cap);
extern int cpu_online(unsigned int cpu);
extern unsigned int nr_cpu_ids;
extern unsigned long msecs_to_jiffies(const unsigned int m);
extern void *kthread_create_on_cpu(int (*threadfn)(void *data), void *data, unsigned int cpu, const char *name);
extern void *kthread_create(int (*threadfn)(void *data), void *data, const char *name);
extern int wake_up_process(void *tsk);
extern int IS_ERR(const void *ptr);
extern int PTR_ERR(const void *ptr);
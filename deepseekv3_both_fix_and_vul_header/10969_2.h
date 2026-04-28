#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <sys/mman.h>

struct task_struct {
    void *mm;
};

struct mm_struct;

struct io_ring_ctx {
    unsigned long flags;
    pthread_cond_t sqo_wait;
    struct mm_struct *sqo_mm;
    pthread_t sqo_thread;
    unsigned int sq_thread_idle;
    unsigned int sq_entries;
    void *user;
    const void *creds;
    void *io_wq;
};

struct io_uring_params {
    unsigned int sq_thread_idle;
    unsigned int flags;
    int sq_thread_cpu;
};

struct io_wq_data {
    struct mm_struct *mm;
    void *user;
    const void *creds;
    void *(*get_work)(void);
    void (*put_work)(void *);
};

#define IORING_SETUP_SQPOLL (1 << 0)
#define IORING_SETUP_SQ_AFF (1 << 1)
#define CAP_SYS_ADMIN 0
#define EPERM 1
#define EINVAL 22
#define HZ 100
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000)
#define PTR_ERR(x) ((long)(x))
#define current ((struct task_struct *)0)
#define capable(x) 0
#define msecs_to_jiffies(x) (x)
#define nr_cpu_ids sysconf(_SC_NPROCESSORS_ONLN)
#define cpu_online(cpu) 1
#define num_online_cpus() sysconf(_SC_NPROCESSORS_ONLN)
#define min(a, b) ((a) < (b) ? (a) : (b))

static inline void init_waitqueue_head(pthread_cond_t *cond) {
    pthread_cond_init(cond, NULL);
}

static inline void mmgrab(struct mm_struct *mm) {}
static inline void mmdrop(struct mm_struct *mm) {}

static inline pthread_t kthread_create(void *(*func)(void *), void *arg, const char *name) {
    pthread_t thread;
    pthread_create(&thread, NULL, func, arg);
    return thread;
}

static inline pthread_t kthread_create_on_cpu(void *(*func)(void *), void *arg, int cpu, const char *name) {
    pthread_t thread;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu, &cpuset);
    pthread_create(&thread, NULL, func, arg);
    pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    return thread;
}

static inline void wake_up_process(pthread_t thread) {
    pthread_kill(thread, 0);
}

extern int io_finish_async(struct io_ring_ctx *ctx);
extern void *io_get_work(void);
extern void io_put_work(void *work);
extern void *io_wq_create(unsigned int concurrency, struct io_wq_data *data);
extern void *io_sq_thread(void *arg);
#include <stdatomic.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#define RPC_PRIORITY_LOW 0
#define dprintk(fmt, ...) do {} while (0)
#define task_pid_nr(x) 0
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)

struct list_head {
    struct list_head *next, *prev;
};

struct rpc_task;
struct rpc_task_setup;
struct workqueue_struct;

struct rpc_task {
    atomic_int tk_count;
    unsigned int tk_flags;
    struct rpc_task_ops *tk_ops;
    void *tk_calldata;
    struct list_head tk_task;
    unsigned int tk_garb_retry;
    unsigned int tk_cred_retry;
    unsigned int tk_rebind_retry;
    int tk_priority;
    pid_t tk_owner;
    struct workqueue_struct *tk_workqueue;
    void (*tk_action)(struct rpc_task *);
    long long tk_start;
};

struct rpc_task_setup {
    unsigned int flags;
    struct rpc_task_ops *callback_ops;
    void *callback_data;
    int priority;
    struct workqueue_struct *workqueue;
};

struct rpc_task_ops {
    void (*rpc_call_prepare)(struct rpc_task *);
};

extern struct task_struct {
    pid_t tgid;
} *current;

static inline void atomic_set(atomic_int *v, int i) {
    *v = i;
}

static inline long long ktime_get(void) {
    return 0;
}

static void rpc_prepare_task(struct rpc_task *task) {}
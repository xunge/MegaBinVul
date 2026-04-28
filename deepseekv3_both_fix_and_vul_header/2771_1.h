#include <errno.h>

struct rpc_task;
struct rpc_procinfo;

struct rpc_task {
    int tk_status;
    int tk_pid;
    void (*tk_action)(struct rpc_task *);
    struct {
        struct rpc_procinfo *rpc_proc;
    } tk_msg;
    unsigned int tk_rebind_retry;
};

struct rpc_procinfo {
    unsigned int p_proc;
};

#define RPC_IS_SOFTCONN(task) (0)
#define HZ (1000)

static void dprintk(const char *fmt, ...) {}
static void dprint_status(struct rpc_task *task) {}
static void rpc_delay(struct rpc_task *task, unsigned long delay) {}
static void rpc_exit(struct rpc_task *task, int status) {}
static void call_connect(struct rpc_task *task) {}
static void call_bind(struct rpc_task *task) {}
static void call_timeout(struct rpc_task *task) {}
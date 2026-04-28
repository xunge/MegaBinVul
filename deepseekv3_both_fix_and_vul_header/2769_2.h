#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

#define RPC_ASSASSINATED(task) (0)
#define NLM_LCK_DENIED_GRACE_PERIOD (0)
#define NLM_LCK_GRANTED (0)
#define NLMCLNT_GRACE_WAIT (0)
#define EACCES (-13)
#define EIO (-5)
#define KERN_WARNING ""

typedef uint32_t u32;

struct rpc_task {
    int tk_status;
};
struct nlm_rqst {
    struct {
        uint32_t status;
    } a_res;
    void *a_host;
};
struct nlm_host;

static inline void dprintk(const char *fmt, ...) {}
static void nlm_rebind_host(struct nlm_host *host) {}
static void rpc_delay(struct rpc_task *task, unsigned long delay) {}
static void rpc_restart_call(struct rpc_task *task) {}
static void printk(const char *fmt, ...) {}
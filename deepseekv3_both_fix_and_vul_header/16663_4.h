#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t u32;

#define FASTRPC_INIT_HANDLE 0
#define HZ 100
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define ERESTARTSYS 512
#define ETIMEDOUT 110
#define EINVAL 22
#define EPIPE 32
#define EPERM 1

struct device;
struct rpmsg_device;

struct completion {
    unsigned int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    unsigned int lock;
};

struct fastrpc_invoke_args;

struct fastrpc_session_ctx {
    struct device *dev;
};

struct fastrpc_channel_ctx {
    struct rpmsg_device *rpdev;
};

struct fastrpc_invoke_ctx {
    int nscalars;
    int retval;
    struct completion work;
    struct list_head node;
};

struct fastrpc_user {
    struct fastrpc_session_ctx *sctx;
    struct fastrpc_channel_ctx *cctx;
    struct spinlock lock;
};

static inline void dma_wmb(void) {}
static inline void dma_rmb(void) {}
static inline void spin_lock(struct spinlock *lock) { (void)lock; }
static inline void spin_unlock(struct spinlock *lock) { (void)lock; }
static inline void list_del(struct list_head *entry) { (void)entry; }
static inline int wait_for_completion_timeout(struct completion *x, unsigned long timeout) { (void)x; (void)timeout; return 0; }
static inline int wait_for_completion_interruptible(struct completion *x) { (void)x; return 0; }
static inline void dev_warn_ratelimited(struct device *dev, const char *fmt, ...) { (void)dev; (void)fmt; }
static inline void dev_dbg(struct device *dev, const char *fmt, ...) { (void)dev; (void)fmt; }
static inline void fastrpc_context_put(struct fastrpc_invoke_ctx *ctx) { (void)ctx; }
static inline struct fastrpc_invoke_ctx *fastrpc_context_alloc(struct fastrpc_user *fl, u32 kernel, u32 sc, struct fastrpc_invoke_args *args) { (void)fl; (void)kernel; (void)sc; (void)args; return NULL; }
static inline int fastrpc_get_args(u32 kernel, struct fastrpc_invoke_ctx *ctx) { (void)kernel; (void)ctx; return 0; }
static inline int fastrpc_invoke_send(struct fastrpc_session_ctx *sctx, struct fastrpc_invoke_ctx *ctx, u32 kernel, u32 handle) { (void)sctx; (void)ctx; (void)kernel; (void)handle; return 0; }
static inline int fastrpc_put_args(struct fastrpc_invoke_ctx *ctx, u32 kernel) { (void)ctx; (void)kernel; return 0; }
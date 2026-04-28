#include <stdatomic.h>
#include <stddef.h>
#include <pthread.h>

typedef struct grpc_call grpc_call;
typedef struct grpc_exec_ctx grpc_exec_ctx;
typedef int grpc_error;

#define GRPC_EXEC_CTX_INIT {0}
#define GPR_TIMER_BEGIN(a, b)
#define GPR_TIMER_END(a, b)
#define GRPC_API_TRACE(a, b, c)
#define GPR_ASSERT(a)
#define STATUS_FROM_API_OVERRIDE 0
#define GRPC_ERROR_CANCELLED 0

struct grpc_call {
    grpc_call* parent;
    grpc_call* first_child;
    grpc_call* sibling_next;
    grpc_call* sibling_prev;
    pthread_mutex_t child_list_mu;
    int destroy_called;
    atomic_int any_ops_sent_atm;
    atomic_int received_final_op_atm;
};

struct grpc_exec_ctx {
    int dummy;
};

#define GRPC_CALL_INTERNAL_UNREF(ctx, call, reason)
#define gpr_mu_lock(m) pthread_mutex_lock(m)
#define gpr_mu_unlock(m) pthread_mutex_unlock(m)
#define gpr_atm_acq_load(atm) atomic_load_explicit(atm, memory_order_acquire)

static void cancel_with_error(grpc_exec_ctx* exec_ctx, grpc_call* c, int status, grpc_error error) {}
static void grpc_exec_ctx_finish(grpc_exec_ctx* exec_ctx) {}
#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef enum {
    NJS_PROMISE_PENDING,
    NJS_PROMISE_FULFILL,
    NJS_PROMISE_REJECTED
} njs_promise_state_t;

typedef enum {
    NJS_PROMISE_HANDLE
} njs_promise_tracker_op_t;

typedef struct njs_vm_s {
    void *mem_pool;
} njs_vm_t;

typedef struct njs_value_s {
    /* placeholder for value structure */
} njs_value_t;

typedef struct njs_promise_capability_s {
    njs_value_t promise;
} njs_promise_capability_t;

typedef struct njs_promise_s {
    njs_value_t value;
} njs_promise_t;

typedef struct njs_function_s {
    union {
        void *native;
    } u;
} njs_function_t;

typedef struct njs_queue_s {
    /* placeholder for queue structure */
} njs_queue_t;

typedef struct njs_promise_data_s {
    njs_promise_state_t state;
    int is_handled;
    njs_value_t result;
    njs_queue_t fulfill_queue;
    njs_queue_t reject_queue;
} njs_promise_data_t;

typedef struct njs_promise_reaction_s {
    njs_promise_capability_t *capability;
    njs_value_t handler;
    njs_promise_state_t type;
    njs_queue_t link;
} njs_promise_reaction_t;

typedef struct njs_promise_context_s {
    /* placeholder for context structure */
} njs_promise_context_t;

extern njs_value_t njs_value_undefined;
extern void njs_promise_reaction_job(void);

#define njs_slow_path(cond) (cond)
#define NJS_OK 0
#define NJS_ERROR (-1)

njs_value_t *njs_value_arg(njs_value_t *value);
int njs_is_function(njs_value_t *value);
njs_promise_t *njs_promise(njs_value_t *value);
njs_promise_data_t *njs_data(njs_value_t *value);
void *njs_mp_alloc(void *pool, size_t size);
void njs_memory_error(njs_vm_t *vm);
void njs_queue_insert_tail(njs_queue_t *queue, njs_queue_t *item);
njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size);
njs_int_t njs_promise_host_rejection_tracker(njs_vm_t *vm, njs_promise_t *promise, njs_promise_tracker_op_t op);
njs_int_t njs_promise_add_event(njs_vm_t *vm, njs_function_t *function, njs_value_t *args, int nargs);
void njs_set_data(njs_value_t *value, void *data, int unused);
void njs_vm_retval_set(njs_vm_t *vm, njs_value_t *value);
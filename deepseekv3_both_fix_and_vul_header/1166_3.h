#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

#define NJS_ERROR (-1)
#define NJS_OK 0
#define NJS_AGAIN 1

#define njs_slow_path(cond) (cond)

typedef struct njs_value_s {
    uint64_t data;
} njs_value_t;

typedef struct njs_function_s {
    void *context;
} njs_function_t;

typedef struct njs_promise_capability_s {
    njs_value_t promise;
    njs_value_t resolve;
    njs_value_t reject;
} njs_promise_capability_t;

typedef struct njs_native_frame_s {
    njs_value_t *retval;
    njs_function_t *function;
} njs_native_frame_t;

typedef struct njs_vm_s {
    njs_native_frame_t *top_frame;
    njs_value_t constructors[16];
    njs_value_t retval;
} njs_vm_t;

enum {
    NJS_OBJ_TYPE_PROMISE
};

extern njs_value_t njs_value_undefined;

static inline int njs_is_memory_error(njs_vm_t *vm, njs_value_t *val) { return 0; }
static inline void njs_set_function(njs_value_t *value, njs_value_t *func) {}
static inline njs_function_t* njs_function(njs_value_t *value) { return NULL; }

static njs_promise_capability_t* njs_promise_new_capability(njs_vm_t *vm, njs_value_t *ctor) { return NULL; }
static njs_int_t njs_function_lambda_call(njs_vm_t *vm, ...) { return NJS_OK; }
static njs_int_t njs_function_call(njs_vm_t *vm, njs_function_t *func, njs_value_t *this, 
                                  njs_value_t *args, uint32_t nargs, njs_value_t *retval) { return NJS_OK; }
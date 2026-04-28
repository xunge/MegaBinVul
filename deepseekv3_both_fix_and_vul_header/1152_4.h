#include <stddef.h>
#include <stdint.h>

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_vmcode_await_s njs_vmcode_await_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_promise_s njs_promise_t;
typedef struct njs_function_s njs_function_t;
typedef struct njs_async_ctx_s njs_async_ctx_t;
typedef struct njs_native_frame_s njs_native_frame_t;

typedef ptrdiff_t njs_jump_off_t;
typedef int njs_int_t;
typedef unsigned int njs_uint_t;

#define NJS_ERROR (-1)
#define NJS_OK 0
#define NJS_AGAIN 1
#define njs_slow_path(expr) (expr)

enum {
    NJS_OBJ_TYPE_PROMISE
};

typedef uint8_t u_char;

struct njs_value_s {
    /* value fields */
};

struct njs_promise_s {
    njs_value_t object;
};

struct njs_function_s {
    njs_async_ctx_t *context;
    njs_async_ctx_t *await;
    size_t args_count;
    union {
        void *native;
    } u;
};

struct njs_native_frame_s {
    njs_function_t *function;
    u_char *pc;
};

struct njs_frame_s {
    struct {
        u_char *catch;
    } exception;
    njs_native_frame_t native;
};

struct njs_async_ctx_s {
    struct {
        njs_native_frame_t native;
    } *await;
    void *capability;
    u_char *pc;
    size_t index;
};

struct njs_vm_s {
    struct {
        njs_frame_t *active_frame;
        njs_function_t *constructors[NJS_OBJ_TYPE_PROMISE + 1];
        void *mem_pool;
        njs_value_t retval;
    };
};

struct njs_vmcode_await_s {
    size_t retval;
};

extern njs_value_t *njs_scope_valid_value(njs_vm_t *vm, size_t index);
extern njs_promise_t *njs_promise_resolve(njs_vm_t *vm, njs_value_t *ctor, njs_value_t *value);
extern njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size);
extern njs_int_t njs_function_frame_save(njs_vm_t *vm, void *ctx, void *unused);
extern njs_int_t njs_promise_perform_then(njs_vm_t *vm, njs_value_t *val, njs_value_t *on_fulfilled, njs_value_t *on_rejected, void *unused);
extern njs_jump_off_t njs_vmcode_return(njs_vm_t *vm, void *unused, njs_value_t *retval);
extern void njs_memory_error(njs_vm_t *vm);
extern void *njs_mp_alloc(void *pool, size_t size);
extern size_t njs_function_frame_size(njs_native_frame_t *frame);
extern void njs_set_function(njs_value_t *value, njs_function_t *func);
extern void njs_set_promise(njs_value_t *value, njs_promise_t *promise);
extern void njs_set_object(njs_value_t *value, njs_value_t *obj);
extern njs_jump_off_t njs_await_fulfilled(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs);
extern njs_jump_off_t njs_await_rejected(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs);
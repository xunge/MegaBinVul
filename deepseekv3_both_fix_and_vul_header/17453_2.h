#include <stddef.h>
#include <stdint.h>

typedef intptr_t njs_jump_off_t;
typedef int32_t njs_int_t;

typedef unsigned char u_char;

#define NJS_OK 0
#define NJS_ERROR -1
#define NJS_AGAIN -2
#define NJS_OBJ_TYPE_PROMISE 0

typedef struct njs_value_s njs_value_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_vmcode_await_s njs_vmcode_await_t;
typedef struct njs_promise_capability_s njs_promise_capability_t;
typedef struct njs_async_ctx_s njs_async_ctx_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_promise_s njs_promise_t;
typedef struct njs_function_s njs_function_t;
typedef struct njs_native_frame_s njs_native_frame_t;

struct njs_native_frame_s {
    u_char *pc;
};

struct njs_value_s {
    int type;
    union {
        void *data;
    } u;
};

struct njs_vm_s {
    struct {
        struct {
            struct njs_native_frame_s native;
        } *active_frame;
        njs_value_t retval;
        njs_value_t constructors[1];
        void *mem_pool;
    };
};

struct njs_vmcode_await_s {
    uint32_t retval;
};

struct njs_async_ctx_s {
    struct {
        struct njs_native_frame_s native;
    } *await;
    njs_promise_capability_t *capability;
    u_char *pc;
    uint32_t index;
};

struct njs_frame_s {
    struct {
        void *catch;
    } exception;
};

struct njs_promise_s {};
struct njs_promise_capability_s {};
struct njs_function_s {
    void *context;
    uint32_t args_count;
    union {
        void (*native)(void);
    } u;
};

#define njs_slow_path(cond) (cond)
#define njs_set_function(v, f) do { (v)->type = 1; (v)->u.data = (f); } while (0)
#define njs_set_promise(v, p) do { (v)->type = 2; (v)->u.data = (p); } while (0)
#define njs_memory_error(vm) ((void)0)

void *njs_scope_valid_value(njs_vm_t *vm, uint32_t retval);
njs_promise_t *njs_promise_resolve(njs_vm_t *vm, njs_value_t *ctor, njs_value_t *value);
void *njs_mp_alloc(void *pool, size_t size);
size_t njs_function_frame_size(njs_native_frame_t *frame);
njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size);
njs_int_t njs_function_frame_save(njs_vm_t *vm, void *ctx, void *arg);
njs_int_t njs_promise_perform_then(njs_vm_t *vm, njs_value_t *val, njs_value_t *on_fulfilled, njs_value_t *on_rejected, void *arg);
njs_int_t njs_vmcode_return(njs_vm_t *vm, void *arg, njs_value_t *retval);

void njs_await_fulfilled(void);
void njs_await_rejected(void);
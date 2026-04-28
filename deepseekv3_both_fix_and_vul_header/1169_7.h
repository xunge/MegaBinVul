#include <stddef.h>
#include <stdint.h>

typedef unsigned char u_char;
typedef intptr_t njs_jump_off_t;
typedef int32_t njs_int_t;
typedef uint32_t njs_uint_t;
typedef uint32_t njs_index_t;

#define NJS_OK 0
#define NJS_ERROR -1
#define NJS_AGAIN -2
#define NJS_OBJ_TYPE_PROMISE 0
#define njs_slow_path(expr) (expr)

typedef struct njs_value_s njs_value_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_vmcode_await_s njs_vmcode_await_t;
typedef struct njs_promise_capability_s njs_promise_capability_t;
typedef struct njs_async_ctx_s njs_async_ctx_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_promise_s njs_promise_t;
typedef struct njs_function_s njs_function_t;
typedef struct njs_native_frame_s njs_native_frame_t;

struct njs_vmcode_await_s {
    njs_index_t retval;
};

struct njs_value_s {
    uint64_t data;
};

struct njs_native_frame_s {
    njs_function_t *function;
    struct {
        u_char *pc;
        njs_native_frame_t *context;
    } native;
};

struct njs_function_s {
    njs_native_frame_t *context;
    njs_async_ctx_t *await;
    njs_uint_t args_count;
    union {
        njs_jump_off_t (*native)(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused);
    } u;
};

struct njs_async_ctx_s {
    njs_native_frame_t *await;
    njs_promise_capability_t *capability;
    u_char *pc;
    njs_index_t index;
};

struct njs_frame_s {
    struct {
        u_char *catch;
    } exception;
};

struct njs_vm_s {
    struct {
        njs_native_frame_t native;
    } *active_frame;
    njs_value_t *constructors;
    void *mem_pool;
    njs_value_t retval;
};

struct njs_promise_capability_s {
    njs_value_t promise;
    njs_value_t resolve;
    njs_value_t reject;
};

static njs_jump_off_t njs_await_fulfilled(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused);
static njs_jump_off_t njs_await_rejected(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused);

static njs_value_t* njs_scope_valid_value(njs_vm_t *vm, njs_index_t index);
static void njs_set_function(njs_value_t *value, njs_value_t *func);
static njs_promise_t* njs_promise_resolve(njs_vm_t *vm, njs_value_t *constructor, njs_value_t *value);
static void* njs_mp_alloc(void *pool, size_t size);
static void njs_memory_error(njs_vm_t *vm);
static size_t njs_function_frame_size(njs_native_frame_t *frame);
static njs_function_t* njs_promise_create_function(njs_vm_t *vm, size_t size);
static njs_int_t njs_function_frame_save(njs_vm_t *vm, njs_native_frame_t *frame, void *retval);
static void njs_set_promise(njs_value_t *value, njs_promise_t *promise);
static njs_int_t njs_promise_perform_then(njs_vm_t *vm, njs_value_t *promise, njs_value_t *on_fulfilled, njs_value_t *on_rejected, njs_value_t *result);
static njs_jump_off_t njs_vmcode_return(njs_vm_t *vm, void *unused, njs_value_t *retval);

/* Dummy implementations to satisfy linker */
static njs_jump_off_t njs_await_fulfilled(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused) { return NJS_OK; }
static njs_jump_off_t njs_await_rejected(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused) { return NJS_OK; }
static njs_value_t* njs_scope_valid_value(njs_vm_t *vm, njs_index_t index) { return NULL; }
static void njs_set_function(njs_value_t *value, njs_value_t *func) {}
static njs_promise_t* njs_promise_resolve(njs_vm_t *vm, njs_value_t *constructor, njs_value_t *value) { return NULL; }
static void* njs_mp_alloc(void *pool, size_t size) { return NULL; }
static void njs_memory_error(njs_vm_t *vm) {}
static size_t njs_function_frame_size(njs_native_frame_t *frame) { return 0; }
static njs_function_t* njs_promise_create_function(njs_vm_t *vm, size_t size) { return NULL; }
static njs_int_t njs_function_frame_save(njs_vm_t *vm, njs_native_frame_t *frame, void *retval) { return NJS_OK; }
static void njs_set_promise(njs_value_t *value, njs_promise_t *promise) {}
static njs_int_t njs_promise_perform_then(njs_vm_t *vm, njs_value_t *promise, njs_value_t *on_fulfilled, njs_value_t *on_rejected, njs_value_t *result) { return NJS_OK; }
static njs_jump_off_t njs_vmcode_return(njs_vm_t *vm, void *unused, njs_value_t *retval) { return NJS_OK; }
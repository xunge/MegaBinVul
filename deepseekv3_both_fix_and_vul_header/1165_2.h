#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;
typedef uintptr_t njs_uint_t;
typedef uintptr_t njs_index_t;

typedef struct njs_value_s {
    int dummy;
} njs_value_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_async_ctx_s njs_async_ctx_t;
typedef struct njs_native_frame_s njs_native_frame_t;
typedef struct njs_function_s njs_function_t;

enum {
    NJS_OK,
    NJS_AGAIN,
    NJS_ERROR
};

enum {
    NJS_LEVEL_LOCAL,
    NJS_LEVEL_CLOSURE,
    NJS_LEVEL_TEMP
};

struct njs_function_s {
    njs_async_ctx_t *context;
    njs_async_ctx_t *await;
    njs_value_t **(*closures)(njs_function_t *);
};

struct njs_native_frame_s {
    njs_native_frame_t *previous;
    njs_value_t **local;
    njs_value_t **temp;
    njs_function_t *function;
    njs_value_t *retval;
};

struct njs_frame_s {
    njs_native_frame_t native;
};

struct njs_async_ctx_s {
    njs_frame_t *await;
    njs_value_t *capability;
    njs_value_t *pc;
    njs_index_t index;
};

struct njs_vm_s {
    njs_native_frame_t *top_frame;
    njs_frame_t *active_frame;
    njs_value_t ***levels;
    njs_value_t retval;
};

#define njs_arg(args, nargs, index) (&args[index])
#define njs_is_error(value) (0)
#define njs_function_closures(func) (func->closures(func))
#define njs_scope_value(vm, index) ((njs_value_t*)0)
#define njs_vmcode_interpreter(...) (NJS_OK)
#define njs_function_call(vm, func, this, args, nargs, retval) (NJS_OK)
#define njs_async_context_free(vm, ctx) ((void)0)
#define njs_is_memory_error(vm, value) (0)
#define njs_value_undefined (*((njs_value_t*)0))
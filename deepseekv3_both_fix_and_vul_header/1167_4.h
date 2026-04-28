#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_native_frame_s njs_native_frame_t;

#define NJS_OBJ_TYPE_ASYNC_FUNCTION 0

njs_int_t njs_function_object_type(njs_vm_t *vm, void *function);
njs_int_t njs_async_function_frame_invoke(njs_vm_t *vm, njs_value_t *retval);
njs_int_t njs_function_native_call(njs_vm_t *vm);
njs_int_t njs_function_lambda_call(njs_vm_t *vm, ...);

struct njs_vm_s {
    njs_native_frame_t *top_frame;
};

struct njs_native_frame_s {
    njs_value_t *retval;
    void *function;
    int native;
};
#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_function_s njs_function_t;
typedef struct njs_promise_capability_s njs_promise_capability_t;
typedef struct njs_promise_all_context_s njs_promise_all_context_t;
typedef struct njs_iterator_args_s njs_iterator_args_t;
typedef struct njs_promise_iterator_args_s njs_promise_iterator_args_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define njs_slow_path(cond) (cond)

struct njs_value_s {
    int dummy;
};

struct njs_array_s {
    njs_value_t *start;
};

struct njs_function_s {
    void *context;
    union {
        void *native;
    } u;
    uint8_t magic8;
    int args_count;
};

struct njs_promise_all_context_s {
    int already_called;
    uint32_t index;
    void *values;
    njs_promise_capability_t *capability;
    int *remaining_elements;
};

struct njs_iterator_args_s {
    void *data;
};

struct njs_promise_iterator_args_s {
    njs_iterator_args_t args;
    njs_function_t *function;
    njs_value_t *constructor;
    njs_promise_capability_t *capability;
    int *remaining;
};

static njs_value_t njs_value_undefined;
static njs_value_t *njs_value_arg(njs_value_t *value) { return value; }
static int njs_is_valid(njs_value_t *value) { return 1; }
static njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size) { return NULL; }
static njs_int_t njs_function_call(njs_vm_t *vm, njs_function_t *func, njs_value_t *constructor, njs_value_t *value, int count, njs_value_t *retval) { return NJS_OK; }
static njs_int_t njs_promise_invoke_then(njs_vm_t *vm, njs_value_t *value, njs_value_t *arguments, int count) { return NJS_OK; }
static void njs_set_undefined(njs_value_t *value) {}
static void njs_set_function(njs_value_t *value, njs_function_t *func) {}
static void njs_promise_all_settled_element_functions() {}
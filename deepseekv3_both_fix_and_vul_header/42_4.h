#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef unsigned int njs_uint_t;
typedef int64_t njs_index_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_function_s njs_function_t;
typedef struct njs_promise_capability_s njs_promise_capability_t;
typedef struct njs_promise_all_context_s njs_promise_all_context_t;
typedef struct njs_iterator_args_s njs_iterator_args_t;
typedef struct njs_promise_iterator_args_s njs_promise_iterator_args_t;

struct njs_value_s {
    int type;
    union {
        int64_t integer;
        double number;
        void *data;
    } u;
};

struct njs_array_s {
    njs_value_t *start;
    size_t length;
};

struct njs_function_s {
    union {
        void (*native)(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused);
    } u;
    njs_uint_t args_count;
    njs_promise_all_context_t *context;
};

struct njs_promise_capability_s {
    njs_value_t resolve;
    njs_value_t reject;
};

struct njs_promise_all_context_s {
    uint32_t already_called;
    uint32_t index;
    njs_array_t *values;
    njs_promise_capability_t *capability;
    uint32_t *remaining_elements;
};

struct njs_iterator_args_s {
    void *data;
};

struct njs_promise_iterator_args_s {
    njs_promise_capability_t *capability;
    struct {
        njs_array_t *data;
    } args;
    njs_function_t *function;
    njs_value_t *constructor;
    uint32_t *remaining;
};

#define NJS_OK 0
#define NJS_ERROR (-1)
#define njs_slow_path(cond) (cond)

static njs_value_t njs_value_undefined = {0};
static inline njs_value_t *njs_value_arg(njs_value_t *value) { return value; }
static inline int njs_is_valid(njs_value_t *value) { return value != NULL; }
static inline void njs_set_undefined(njs_value_t *value) { value->type = 0; }
static inline void njs_set_function(njs_value_t *value, njs_function_t *func) { 
    value->type = 1; 
    value->u.data = func; 
}

static njs_int_t njs_function_call(njs_vm_t *vm, njs_function_t *func, njs_value_t *constructor, 
                                 njs_value_t *value, int count, njs_value_t *retval) {
    return NJS_OK;
}

static njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size) {
    return NULL;
}

static njs_int_t njs_promise_invoke_then(njs_vm_t *vm, njs_value_t *value, njs_value_t *arguments, int count) {
    return NJS_OK;
}

static void njs_promise_any_reject_element_functions(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused) {
}
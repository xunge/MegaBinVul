#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;

struct njs_vm_s;
struct njs_value_s;
struct njs_array_s;
struct njs_function_s;
struct njs_promise_capability_s;
struct njs_promise_all_context_s;
struct njs_iterator_args_s;
struct njs_promise_iterator_args_s;

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
        void *ptr;
        int64_t integer;
    } u;
};

struct njs_array_s {
    njs_value_t *start;
};

struct njs_function_s {
    union {
        njs_function_t *native;
    } u;
    njs_promise_all_context_t *context;
    int args_count;
};

struct njs_promise_capability_s {
    njs_value_t reject;
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
    njs_promise_capability_t *capability;
    njs_function_t *function;
    njs_value_t *constructor;
    struct {
        void *data;
    } args;
    int *remaining;
};

#define njs_slow_path(expr) (expr)
#define NJS_ERROR (-1)
#define NJS_OK (0)

static njs_value_t njs_value_undefined;
static njs_function_t *njs_promise_all_resolve_element_functions;

static njs_int_t njs_function_call(njs_vm_t *vm, njs_function_t *func, njs_value_t *constructor, njs_value_t *value, int count, njs_value_t *next);
static njs_function_t *njs_promise_create_function(njs_vm_t *vm, size_t size);
static njs_int_t njs_promise_invoke_then(njs_vm_t *vm, njs_value_t *next, njs_value_t *arguments, int count);

static const njs_value_t *njs_value_arg(const njs_value_t *value);
static int njs_is_valid(const njs_value_t *value);
static void njs_set_undefined(njs_value_t *value);
static void njs_set_function(njs_value_t *value, njs_function_t *func);
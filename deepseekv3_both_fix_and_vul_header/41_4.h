#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;

struct njs_value_s {
    int type;
    union {
        int64_t integer;
        double number;
        void *pointer;
    } data;
};
typedef struct njs_value_s njs_value_t;

struct njs_vm_s {
    int dummy;
};
typedef struct njs_vm_s njs_vm_t;

struct njs_iterator_args_s {
    int dummy;
};
typedef struct njs_iterator_args_s njs_iterator_args_t;

struct njs_promise_capability_s {
    njs_value_t resolve;
    njs_value_t reject;
};
typedef struct njs_promise_capability_s njs_promise_capability_t;

struct njs_promise_iterator_args_s {
    njs_value_t* function;
    njs_value_t* constructor;
    njs_promise_capability_t* capability;
};
typedef struct njs_promise_iterator_args_s njs_promise_iterator_args_t;

#define njs_slow_path(x) (x)
#define NJS_ERROR (-1)
#define NJS_OK (0)

static njs_value_t njs_value_undefined = {0};
static njs_value_t* njs_value_arg(njs_value_t* value) { return value; }
static int njs_is_valid(njs_value_t* value) { return value != NULL; }
static njs_int_t njs_function_call(njs_vm_t* vm, njs_value_t* function, njs_value_t* constructor, njs_value_t* value, int count, njs_value_t* retval) { return NJS_OK; }
static void njs_promise_invoke_then(njs_vm_t* vm, njs_value_t* promise, njs_value_t* arguments, int count) {}
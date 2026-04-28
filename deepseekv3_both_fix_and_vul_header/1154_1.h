#include <stddef.h>

typedef struct njs_vm_s njs_vm_t;
typedef int njs_int_t;

typedef struct {
    /* minimal njs_value_t definition */
    int type;
    union {
        void *data;
        double num;
    } u;
} njs_value_t;

typedef struct njs_object_s njs_object_t;
typedef struct njs_promise_s njs_promise_t;

typedef struct njs_promise_capability_s {
    njs_value_t resolve;
    njs_value_t promise;
} njs_promise_capability_t;

typedef struct njs_function_s njs_function_t;

#define NJS_PROMISE 0
#define NJS_ERROR (-1)
#define NJS_OK 0

#define njs_slow_path(cond) (cond)
#define njs_value_arg(v) (v)
#define njs_string(str) { .type = 1, .u.data = (void *)str }
#define njs_is_object(v) ((v)->type == 2)
#define njs_object(v) ((njs_object_t *)(v)->u.data)
#define njs_object_proto_lookup(obj, type, ret_type) ((ret_type *)NULL)
#define njs_value_property(vm, obj, prop, ret) (NJS_OK)
#define njs_values_same(v1, v2) ((v1)->type == (v2)->type && (v1)->u.data == (v2)->u.data)
#define njs_promise(v) ((njs_promise_t *)(v)->u.data)
#define njs_promise_new_capability(vm, constructor) ((njs_promise_capability_t *)NULL)
#define njs_function(v) ((njs_function_t *)(v)->u.data)
#define njs_function_call(vm, func, this, arg, nargs, ret) (NJS_OK)
#define njs_value_undefined ((njs_value_t){ .type = 0 })
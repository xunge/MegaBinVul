#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef unsigned int njs_uint_t;
typedef int64_t njs_index_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_function_s njs_function_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_DECLINED (-2)
#define NJS_ARRAY_SPARE 0

#define njs_slow_path(expr) (expr)
#define njs_is_function(value) (0)
#define njs_is_null_or_undefined(value) (0)
#define njs_is_array(value) (0)
#define njs_is_object(value) (0)
#define njs_argument(args, index) (&(args)[index])
#define njs_arg(args, nargs, index) ((index) < (nargs) ? &(args)[index] : NULL)
#define njs_type_error(vm, msg) (0)
#define njs_object_length(vm, obj, len) (0)
#define njs_array_alloc(vm, proto, size, spare) (NULL)
#define njs_value_property_i64(vm, obj, index, value) (0)
#define njs_function_frame(vm, func, this, args, length, ctor) (0)
#define njs_function_frame_invoke(vm, retval) (0)

struct njs_value_s {
    union {
        struct {
            njs_array_t *array;
            njs_function_t *function;
        } u;
    } data;
};

struct njs_vm_s {
    njs_frame_t *top_frame;
};

struct njs_frame_s {
    union {
        njs_value_t *retval;
    } native;
    int skip;
};

struct njs_array_s {
    njs_value_t *start;
    int64_t length;
};

static inline njs_function_t* njs_function(njs_value_t *value) {
    return value->data.u.function;
}
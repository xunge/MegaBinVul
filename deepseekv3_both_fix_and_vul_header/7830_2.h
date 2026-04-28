#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int njs_int_t;
typedef unsigned int njs_uint_t;
typedef int64_t njs_index_t;

typedef struct njs_value_s njs_value_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_function_s njs_function_t;

struct njs_value_s {
    int type;
    union {
        int64_t integer;
        double number;
        void *data;
    } u;
};

struct njs_vm_s {
    njs_value_t retval;
    void *mem_pool;
};

struct njs_array_s {
    njs_value_t *start;
    uint32_t length;
};

struct njs_function_s {
    int dummy;
};

typedef struct {
    int separate;
    int pointer;
} njs_strings_t;

typedef struct njs_array_sort_ctx_s {
    njs_function_t *function;
    njs_vm_t *vm;
    njs_strings_t strings;
    int exception;
} njs_array_sort_ctx_t;

typedef struct njs_array_sort_slot_s {
    njs_value_t value;
    int64_t pos;
    void *str;
} njs_array_sort_slot_t;

static int njs_array_compare(const void *a, const void *b, void *ctx) {
    return 0;
}

#define njs_arg(args, nargs, index) (&args[index])
#define njs_argument(args, index) (&args[index])
#define njs_is_defined(value) (1)
#define njs_slow_path(cond) (cond)
#define njs_is_function(value) (1)
#define njs_type_error(vm, msg) (NJS_ERROR)
#define njs_function(value) ((njs_function_t*)value)
#define njs_value_to_object(vm, value) (NJS_OK)
#define njs_value_length(vm, value, len) (NJS_OK)
#define njs_is_fast_array(value) (1)
#define njs_array(value) ((njs_array_t*)value)
#define njs_mp_alloc(pool, size) malloc(size)
#define njs_mp_free(pool, ptr) free(ptr)
#define njs_is_valid(value) (1)
#define njs_is_undefined(value) (0)
#define njs_min(a, b) ((a) < (b) ? (a) : (b))
#define njs_max(a, b) ((a) > (b) ? (a) : (b))
#define njs_value_property_i64(vm, obj, i, value) (NJS_OK)
#define njs_value_property_i64_set(vm, obj, i, value) (NJS_OK)
#define njs_value_property_i64_delete(vm, obj, i, ret) (NJS_OK)
#define njs_arr_init(pool, arr, unused, size, elem_size) malloc((size) * (elem_size))
#define njs_arr_destroy(arr) free(arr)
#define njs_qsort(base, nel, width, compar, arg) qsort_r(base, nel, width, compar, arg)
#define njs_value_undefined (*(njs_value_t*)0)
#define njs_value_arg(ptr) (ptr)
#define njs_cpymem(dst, src, n) memcpy(dst, src, n)

#define NJS_OK 0
#define NJS_ERROR -1
#define NJS_DECLINED -2
#define njs_fast_path(cond) (cond)
#define njs_memory_error(vm) (NJS_ERROR)
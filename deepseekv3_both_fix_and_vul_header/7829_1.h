#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int njs_int_t;
typedef unsigned int njs_uint_t;
typedef int64_t njs_index_t;

#define njs_slow_path(cond) (cond)
#define njs_fast_path(cond) (cond)
#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_MAX_LENGTH INT64_MAX

typedef struct njs_value_s {
    union {
        struct {
            uint32_t type;
            uint32_t data;
        } u;
        double num;
        void *ptr;
    } data;
} njs_value_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

typedef struct njs_array_s {
    njs_value_t *start;
    int64_t length;
    struct {
        int fast_array;
    } object;
} njs_array_t;

static njs_int_t njs_value_to_object(njs_vm_t *vm, njs_value_t *value) { return NJS_OK; }
static njs_int_t njs_object_length(njs_vm_t *vm, njs_value_t *value, int64_t *length) { return NJS_OK; }
static njs_int_t njs_value_to_integer(njs_vm_t *vm, njs_value_t *value, int64_t *result) { return NJS_OK; }
static njs_int_t njs_value_property_i64(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *result) { return NJS_OK; }
static njs_int_t njs_value_property_i64_set(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *setval) { return NJS_OK; }
static njs_int_t njs_value_property_i64_delete(njs_vm_t *vm, njs_value_t *value, int64_t index, void *unused) { return NJS_OK; }
static njs_int_t njs_object_length_set(njs_vm_t *vm, njs_value_t *value, int64_t length) { return NJS_OK; }
static njs_int_t njs_array_expand(njs_vm_t *vm, njs_array_t *array, size_t prepend, size_t append) { return NJS_OK; }
static njs_int_t njs_array_copy_within(njs_vm_t *vm, njs_value_t *value, int64_t dst, int64_t src, int64_t size, int backward) { return NJS_OK; }
static njs_array_t *njs_array_alloc(njs_vm_t *vm, size_t spare, size_t size, size_t offset) { return NULL; }
static void njs_set_array(njs_value_t *value, njs_array_t *array) {}
static int njs_is_fast_array(njs_value_t *value) { return 0; }
static njs_array_t *njs_array(njs_value_t *value) { return NULL; }
static njs_value_t *njs_argument(njs_value_t *args, njs_uint_t index) { return NULL; }
static njs_value_t *njs_arg(njs_value_t *args, njs_uint_t nargs, njs_uint_t index) { return NULL; }
static void njs_type_error(njs_vm_t *vm, const char *msg) {}

#define njs_min(a, b) ((a) < (b) ? (a) : (b))
#define njs_max(a, b) ((a) > (b) ? (a) : (b))
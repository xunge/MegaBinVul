#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef unsigned int njs_uint_t;
typedef int64_t njs_index_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_MAX_LENGTH INT64_MAX
#define NJS_ARRAY_SPARE 0

#define njs_slow_path(cond) (cond)

typedef struct njs_value_s {
    int type;
    union {
        int64_t integer;
        double number;
        void *data;
    } u;
} njs_value_t;

typedef struct njs_array_s {
    njs_value_t *start;
    int64_t length;
} njs_array_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

static njs_int_t njs_value_to_object(njs_vm_t *vm, njs_value_t *value);
static njs_int_t njs_is_concat_spreadable(njs_vm_t *vm, njs_value_t *value);
static njs_int_t njs_object_length(njs_vm_t *vm, njs_value_t *value, int64_t *len);
static njs_int_t njs_value_property_i64(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *retval);
static njs_int_t njs_array_add(njs_vm_t *vm, njs_array_t *array, njs_value_t *value);
static njs_array_t *njs_array_indices(njs_vm_t *vm, njs_value_t *value);
static njs_int_t njs_value_property(njs_vm_t *vm, njs_value_t *value, njs_value_t *key, njs_value_t *retval);
static double njs_string_to_index(njs_value_t *value);
static njs_int_t njs_value_property_i64_set(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *setval);
static void njs_array_destroy(njs_vm_t *vm, njs_array_t *array);
static njs_int_t njs_object_length_set(njs_vm_t *vm, njs_value_t *value, int64_t length);
static njs_array_t *njs_array_alloc(njs_vm_t *vm, uint32_t size, uint32_t spare, uint32_t type);
static void njs_set_array(njs_value_t *value, njs_array_t *array);
static int njs_is_fast_array(njs_value_t *value);
static int njs_fast_object(int64_t len);
static void njs_set_invalid(njs_value_t *value);
static void njs_type_error(njs_vm_t *vm, const char *msg);
static njs_value_t *njs_argument(njs_value_t *args, njs_uint_t index);
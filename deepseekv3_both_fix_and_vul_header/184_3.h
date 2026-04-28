#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_ret_t;
typedef uintptr_t nxt_uint_t;
typedef uintptr_t njs_index_t;

typedef struct njs_vm_s njs_vm_t;

typedef struct {
    union {
        void *function;
        void *object;
    } u;
} njs_value_data_t;

typedef struct {
    union {
        njs_value_data_t data;
    };
} njs_value_t;

typedef struct {
    njs_value_t value;
} njs_object_prop_t;

typedef struct {
    njs_ret_t (*function)(njs_vm_t *, njs_value_t *, nxt_uint_t, njs_index_t);
} njs_continuation_t;

typedef struct {
    uint32_t key_hash;
    const char *key;
} nxt_lvlhsh_query_t;

#define NJS_TO_ISO_STRING_HASH 0
#define NXT_ERROR (-1)

#define nxt_fast_path(cond) (cond)

static njs_continuation_t *njs_vm_continuation(njs_vm_t *vm) { return NULL; }
static njs_ret_t njs_date_prototype_to_json_continuation(njs_vm_t *vm, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval) { return 0; }
static int njs_is_object(njs_value_t *value) { return 0; }
static njs_object_prop_t *njs_object_property(njs_vm_t *vm, void *object, nxt_lvlhsh_query_t *lhq) { return NULL; }
static int njs_is_function(njs_value_t *value) { return 0; }
static njs_ret_t njs_function_apply(njs_vm_t *vm, void *func, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval) { return 0; }
static void njs_type_error(njs_vm_t *vm, const char *msg) {}

static const char *nxt_string_value(const char *str) { return str; }
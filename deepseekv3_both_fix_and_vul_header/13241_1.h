#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;
typedef uint32_t njs_uint_t;
typedef uintptr_t njs_index_t;

typedef struct {
    const char *start;
    uint32_t length;
} njs_value_t;

typedef struct {
    njs_value_t key;
    uint32_t key_hash;
} njs_lvlhsh_query_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

#define njs_string(str) {str, sizeof(str) - 1}
#define njs_is_object(value) (0)
#define njs_is_function(value) (0)
#define njs_function(value) (NULL)
#define njs_slow_path(cond) (cond)
#define NJS_ERROR (-1)
#define NJS_TO_ISO_STRING_HASH (0)

static void njs_object_property_init(njs_lvlhsh_query_t *lhq, const njs_value_t *key, uint32_t hash);
static njs_int_t njs_object_property(njs_vm_t *vm, njs_value_t *value, njs_lvlhsh_query_t *lhq, njs_value_t *retval);
static njs_int_t njs_function_apply(njs_vm_t *vm, void *func, njs_value_t *args, njs_uint_t nargs, njs_value_t *retval);
static void njs_type_error(njs_vm_t *vm, const char *msg);
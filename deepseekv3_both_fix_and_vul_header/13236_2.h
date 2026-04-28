#include <stdint.h>
#include <stddef.h>

typedef int32_t njs_int_t;
typedef uint32_t njs_uint_t;
typedef uint32_t njs_index_t;

typedef struct njs_value_s {
    uint32_t type;
    union {
        void *data;
        double number;
        const char *string;
    } u;
} njs_value_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

typedef struct njs_lvlhsh_query_s {
    njs_value_t key;
    uint32_t hash;
    void *value;
} njs_lvlhsh_query_t;

#define NJS_ERROR (-1)
#define NJS_JOIN_HASH (0)
#define njs_slow_path(expr) (expr)

static inline int njs_is_object(const njs_value_t *value) { return value->type == 1; }
static inline int njs_is_function(const njs_value_t *value) { return value->type == 2; }
static inline void njs_object_property_init(njs_lvlhsh_query_t *lhq, const njs_value_t *key, uint32_t hash) {
    lhq->key = *key;
    lhq->hash = hash;
}
static inline njs_int_t njs_object_property(njs_vm_t *vm, const njs_value_t *obj, njs_lvlhsh_query_t *lhq, njs_value_t *value) { return 0; }
static inline njs_value_t* njs_function(const njs_value_t *value) { return (njs_value_t*)value; }
static inline njs_int_t njs_function_apply(njs_vm_t *vm, njs_value_t *function, njs_value_t *args, njs_uint_t nargs, njs_value_t *retval) { return 0; }
static inline njs_int_t njs_object_prototype_to_string(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused) { return 0; }

#define njs_string(str) { .type = 3, .u.string = str }
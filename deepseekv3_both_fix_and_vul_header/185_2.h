#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_ret_t;
typedef uintptr_t nxt_uint_t;
typedef uintptr_t njs_index_t;

typedef struct {
    uint32_t key_hash;
    void *key;
} nxt_lvlhsh_query_t;

typedef struct njs_value_s njs_value_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_object_prop_s njs_object_prop_t;
typedef struct njs_continuation_s njs_continuation_t;

struct njs_continuation_s {
    void *function;
};

struct njs_value_s {
    union {
        struct {
            union {
                void *object;
                void *function;
            } u;
        } data;
    };
};

struct njs_object_prop_s {
    njs_value_t value;
};

void *nxt_string_value(const char *str);
njs_ret_t njs_array_prototype_to_string_continuation(njs_vm_t *vm, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval);
njs_ret_t njs_object_prototype_to_string(njs_vm_t *vm, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval);
njs_object_prop_t *njs_object_property(njs_vm_t *vm, void *object, nxt_lvlhsh_query_t *lhq);
njs_continuation_t *njs_vm_continuation(njs_vm_t *vm);
njs_ret_t njs_function_apply(njs_vm_t *vm, void *func, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval);
int njs_is_object(njs_value_t *value);
int njs_is_function(njs_value_t *value);

#define NJS_JOIN_HASH 0
#define nxt_fast_path(cond) (cond)
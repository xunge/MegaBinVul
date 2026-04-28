#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_lvlhsh_query_s njs_lvlhsh_query_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_object_prop_s njs_object_prop_t;

struct njs_lvlhsh_s {
    void *data;
};

enum {
    NJS_UNDEFINED,
    NJS_OBJECT,
    NJS_WHITEOUT
};

#define NJS_OK 0
#define NJS_DECLINED -1
#define njs_fast_path(expr) (expr)

#define njs_set_undefined(value) ((value)->type = NJS_UNDEFINED)
#define njs_set_object(value, obj) ((value)->type = NJS_OBJECT, (value)->data.object = obj)

struct njs_object_s {
    struct njs_object_s *__proto__;
    struct njs_lvlhsh_s hash;
    struct njs_lvlhsh_s shared_hash;
};

struct njs_lvlhsh_query_s {
    void *value;
};

struct njs_value_s {
    uint32_t type;
    union {
        njs_object_t *object;
    } data;
};

struct njs_object_prop_s {
    uint32_t type;
};

njs_int_t njs_lvlhsh_find(struct njs_lvlhsh_s *hash, njs_lvlhsh_query_t *lhq);
int njs_is_data_descriptor(njs_object_prop_t *prop);
njs_value_t *njs_prop_value(njs_object_prop_t *prop);
njs_object_t *njs_prop_getter(njs_object_prop_t *prop);
njs_int_t njs_function_apply(njs_vm_t *vm, njs_object_t *function, njs_value_t *args, uint32_t nargs, njs_value_t *retval);
void njs_value_assign(njs_value_t *dst, njs_value_t *src);
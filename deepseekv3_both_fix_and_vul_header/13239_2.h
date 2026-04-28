#include <stddef.h>
#include <string.h>

typedef int njs_int_t;
typedef unsigned char u_char;
typedef size_t njs_bool_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_string_prop_s njs_string_prop_t;
typedef struct njs_lvlhsh_query_s njs_lvlhsh_query_t;

struct njs_value_s {
    size_t size;
    u_char *start;
    size_t length;
};

struct njs_string_prop_s {
    size_t size;
    u_char *start;
    size_t length;
};

struct njs_lvlhsh_query_s {
    const char *key;
    njs_int_t key_hash;
};

#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_NAME_HASH 0
#define NJS_MESSAGE_HASH 0

#define njs_slow_path(cond) (cond)
#define njs_fast_path(cond) (cond)
#define njs_is_object(v) (1)
#define njs_is_string(v) (1)
#define njs_object(v) ((njs_object_t *)(v))
#define njs_value_arg(v) (v)
#define njs_str_value(s) (s)
#define njs_string(s) {sizeof(s)-1, (u_char *)s, sizeof(s)-1}

static const njs_value_t njs_string_name = {0};
static const njs_value_t njs_string_empty = {0};

static njs_int_t njs_error_stack(njs_vm_t *vm, const njs_value_t *error, njs_value_t *retval);
static njs_int_t njs_object_property(njs_vm_t *vm, njs_object_t *object, njs_lvlhsh_query_t *lhq, njs_value_t *value);
static njs_int_t njs_value_to_string(njs_vm_t *vm, njs_value_t *value, const njs_value_t *src);
static void njs_string_prop(njs_string_prop_t *prop, const njs_value_t *value);
static u_char *njs_string_alloc(njs_vm_t *vm, njs_value_t *value, size_t size, size_t length);
static void njs_memory_error(njs_vm_t *vm);
static void njs_object_property_init(njs_lvlhsh_query_t *lhq, const njs_value_t *name, njs_int_t hash);
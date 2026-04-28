#include <stdint.h>
#include <stddef.h>

typedef struct njs_vm_s njs_vm_t;

typedef struct {
    int dummy;
} njs_value_t;

typedef struct {
    int dummy;
} njs_object_t;

typedef struct {
    int dummy;
} njs_function_t;

typedef struct {
    int type;
    int writable;
    int enumerable;
    int configurable;
    njs_value_t* value;
    njs_function_t* getter;
    njs_function_t* setter;
} njs_object_prop_t;

typedef struct {
    njs_value_t* key;
    uint32_t key_hash;
} njs_lvlhsh_query_t;

typedef intptr_t njs_int_t;
typedef uintptr_t njs_bool_t;

#define NJS_ATTRIBUTE_UNSET 0
#define NJS_PROP_PTR_UNSET NULL
#define NJS_GET_HASH 0
#define NJS_SET_HASH 0
#define NJS_VALUE_HASH 0
#define NJS_WRITABABLE_HASH 0
#define NJS_ENUMERABLE_HASH 0
#define NJS_CONFIGURABLE_HASH 0
#define NJS_ACCESSOR 0
#define NJS_ERROR (-1)
#define NJS_OK 0

#define njs_slow_path(expr) (expr)
#define njs_is_object(v) 0
#define njs_is_defined(v) 0
#define njs_is_function(v) 0
#define njs_is_true(v) 0
#define njs_type_error(vm, msg) ((void)0)
#define njs_object_prop_alloc(vm, name, value, attr) NULL
#define njs_object(v) NULL
#define njs_function(v) NULL
#define njs_object_property_init(lhq, key, hash) ((void)0)
#define njs_object_property(vm, obj, lhq, value) 0
#define njs_value_assign(dst, src) ((void)0)
#define njs_prop_value(prop) ((prop)->value)
#define njs_prop_getter(prop) ((prop)->getter)
#define njs_prop_setter(prop) ((prop)->setter)
#define njs_string(str) ((njs_value_t){0})
#define njs_str_value(str) (&(njs_value_t){0})

static const njs_value_t njs_value_invalid = {0};
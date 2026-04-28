#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_json_parse_s njs_json_parse_t;
typedef struct njs_json_state_s njs_json_state_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_object_prop_s njs_object_prop_t;
typedef struct njs_array_s njs_array_t;

#define njs_slow_path(expr) (expr)
#define njs_fast_path(expr) (expr)

enum {
    NJS_OK,
    NJS_ERROR,
    NJS_PROPERTY,
    NJS_PROPERTY_REF,
    NJS_WHITEOUT
};

struct njs_value_s {
    uint32_t type;
    union {
        njs_array_t *array;
        struct {
            union {
                njs_value_t *value;
            } u;
            void *data;
        } data;
    };
};

struct njs_json_parse_s {
    njs_value_t retval;
    njs_value_t *function;
};

struct njs_json_state_s {
    njs_object_prop_t *prop;
    njs_value_t value;
    struct {
        njs_value_t *start;
    } *keys;
    uint32_t index;
};

struct njs_object_prop_s {
    uint32_t type;
    njs_value_t value;
};

struct njs_array_s {
    uint32_t length;
};

njs_int_t njs_function_apply(njs_vm_t *vm, njs_value_t *function, njs_value_t *args, uint32_t nargs, njs_value_t *retval);
njs_int_t njs_value_property_i64_delete(njs_vm_t *vm, njs_value_t *value, int64_t index, void *unused);
njs_int_t njs_value_property_i64_set(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *setval);
void njs_internal_error(njs_vm_t *vm, const char *msg, const char *type);
const char *njs_prop_type_string(uint32_t type);
void njs_set_invalid(njs_value_t *value);
njs_array_t* njs_array(njs_value_t *value);

#define njs_is_undefined(value) ((value)->type == 0)
#define njs_is_fast_array(value) ((value)->type == 1)
#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef unsigned char njs_bool_t;

typedef struct njs_vm_s njs_vm_t;

typedef union {
    double number;
    void *data;
    uint64_t u64;
} njs_value_t;

typedef struct {
    uint32_t length;
    njs_value_t *start;
} njs_array_t;

typedef struct {
    unsigned configurable:1;
    unsigned type:3;
    union {
        njs_value_t value;
        struct {
            njs_value_t getter;
            njs_value_t setter;
        } accessor;
        njs_value_t *ref;
        njs_int_t (*handler)(njs_vm_t *vm, void *prop, njs_value_t *value,
                            njs_value_t *setval, njs_value_t *retval);
    } u;
} njs_object_prop_t;

typedef struct {
    njs_value_t key;
    struct {
        njs_value_t key;
        njs_object_prop_t *value;
    } lhq;
} njs_property_query_t;

#define njs_assert(expr) ((void)0)
#define njs_is_index_or_key(key) (0)
#define njs_fast_path(cond) (cond)
#define njs_slow_path(cond) (cond)
#define njs_is_number(key) (0)
#define njs_is_fast_array(value) (0)
#define njs_number(key) (0.0)
#define njs_number_is_integer_index(num) (0)
#define njs_array(value) (NULL)
#define njs_value_assign(dst, src) 
#define njs_property_query_init(pq, type, own, shared) 
#define njs_property_query(vm, pq, value, key) (0)
#define njs_key_string_get(vm, key, lhq_key) 
#define njs_type_error(vm, fmt, arg1, arg2) 
#define njs_type_string(type) ("")
#define njs_is_object(value) (0)
#define njs_object_slots(value) (NULL)
#define njs_prop_handler(prop) ((prop)->u.handler)
#define njs_set_undefined(value) 
#define njs_function_apply(vm, func, this, nargs, retval) (0)
#define njs_prop_getter(prop) (&(prop)->u.accessor.getter)
#define njs_prop_ref(prop) ((prop)->u.ref)
#define njs_set_invalid(value) 
#define njs_prop_value(prop) (&(prop)->u.value)
#define njs_internal_error(vm, fmt, arg) 
#define njs_prop_type_string(type) ("")

#define NJS_OK (0)
#define NJS_ERROR (-1)
#define NJS_DECLINED (-2)
#define NJS_PROPERTY_QUERY_DELETE (0)
#define NJS_PROPERTY_HANDLER (0)
#define NJS_PROPERTY (1)
#define NJS_ACCESSOR (2)
#define NJS_PROPERTY_REF (3)
#define NJS_PROPERTY_PLACE_REF (4)
#define NJS_WHITEOUT (5)

extern const njs_value_t njs_value_invalid;
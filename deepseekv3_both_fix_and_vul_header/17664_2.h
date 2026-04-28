#include <stdbool.h>
#include <stdint.h>

typedef uintptr_t ecma_value_t;
typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_string_t ecma_string_t;

typedef struct ecma_proxy_object_t {
    ecma_value_t handler;
    ecma_value_t target;
} ecma_proxy_object_t;

typedef struct {
    uint32_t flags;
} ecma_property_descriptor_t;

#define JERRY_ASSERT(expr) ((void)0)
#define ECMA_OBJECT_IS_PROXY(obj) (0)
#define LIT_MAGIC_STRING_HAS (0)
#define ECMA_IS_VALUE_ERROR(val) (0)
#define ECMA_PROP_IS_CONFIGURABLE (1 << 0)
#define ECMA_ERR_MSG(msg) (msg)

ecma_value_t ecma_validate_proxy_object(ecma_value_t handler, int lit_magic_string);
bool ecma_is_value_undefined(ecma_value_t value);
ecma_value_t ecma_op_object_has_property(ecma_object_t *obj_p, ecma_string_t *prop_name_p);
ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
ecma_value_t ecma_make_prop_name_value(ecma_string_t *prop_name_p);
ecma_value_t ecma_op_function_call(ecma_object_t *func_obj_p, ecma_value_t this_value, ecma_value_t args[], uint32_t args_number);
void ecma_deref_object(ecma_object_t *obj_p);
bool ecma_op_to_boolean(ecma_value_t value);
void ecma_free_value(ecma_value_t value);
ecma_value_t ecma_op_object_get_own_property_descriptor(ecma_object_t *obj_p, ecma_string_t *prop_name_p, ecma_property_descriptor_t *out_desc_p);
bool ecma_is_value_true(ecma_value_t value);
void ecma_free_property_descriptor(ecma_property_descriptor_t *prop_desc_p);
ecma_value_t ecma_raise_type_error(const char *msg);
ecma_value_t ecma_builtin_object_object_is_extensible(ecma_object_t *obj_p);
bool ecma_is_value_false(ecma_value_t value);
ecma_value_t ecma_make_boolean_value(bool boolean_value);
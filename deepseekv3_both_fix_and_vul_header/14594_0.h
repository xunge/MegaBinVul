#include <stdint.h>

typedef uintptr_t ecma_value_t;
typedef uintptr_t ecma_object_t;
typedef uint32_t ecma_length_t;
typedef double ecma_number_t;

#define ECMA_IS_VALUE_ERROR(x) (0)
#define ECMA_VALUE_UNDEFINED (0)
#define ECMA_PROPERTY_CONFIGURABLE_ENUMERABLE_WRITABLE (0)
#define JERRY_PROP_SHOULD_THROW (0)

static ecma_value_t ecma_op_object_find_by_index(ecma_object_t *obj, ecma_length_t index);
static int ecma_is_value_found(ecma_value_t value);
static int ecma_is_value_undefined(ecma_value_t value);
static ecma_value_t ecma_make_length_value(ecma_length_t length);
static ecma_value_t ecma_op_function_call(ecma_object_t *func, ecma_value_t this_arg, ecma_value_t args[], uint32_t arg_count);
static void ecma_free_value(ecma_value_t value);
static ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
static ecma_value_t ecma_is_value_array(ecma_value_t value);
static int ecma_is_value_true(ecma_value_t value);
static ecma_value_t ecma_op_object_get_length(ecma_object_t *obj, ecma_length_t *length_p);
static void ecma_deref_object(ecma_object_t *obj);
static ecma_number_t ecma_get_number_from_value(ecma_value_t value);
static ecma_value_t ecma_builtin_helper_def_prop_by_index(ecma_object_t *obj, ecma_length_t index, ecma_value_t value, uint32_t flags);
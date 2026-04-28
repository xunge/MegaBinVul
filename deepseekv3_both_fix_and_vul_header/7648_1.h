#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;
typedef struct ecma_string_t ecma_string_t;
typedef struct ecma_object_t ecma_object_t;
typedef double ecma_number_t;

#define JERRY_UNLIKELY(x) (x)
#define JERRY_ESNEXT 1
#define JERRY_ASSERT(x) ((void)0)

#define ECMA_VALUE_ERROR ((ecma_value_t)0)
#define ECMA_VALUE_NULL ((ecma_value_t)0)
#define LIT_MAGIC_STRING_GLOBAL 0
#define LIT_MAGIC_STRING_UNICODE 0
#define LIT_MAGIC_STRING_LASTINDEX_UL 0
#define ECMA_ERR_MSG(x) (x)
#define ECMA_PROPERTY_CONFIGURABLE_ENUMERABLE_WRITABLE 0
#define ECMA_IS_VALUE_ERROR(x) ((x) == ECMA_VALUE_ERROR)

typedef uint32_t ecma_length_t;

bool ecma_is_value_object(ecma_value_t value);
ecma_value_t ecma_raise_type_error(const char* msg);
ecma_string_t* ecma_op_to_string(ecma_value_t value);
ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
ecma_value_t ecma_op_object_get_by_magic_id(ecma_object_t* obj_p, int magic_id);
bool ecma_op_to_boolean(ecma_value_t value);
void ecma_free_value(ecma_value_t value);
ecma_value_t ecma_op_regexp_exec(ecma_value_t this_arg, ecma_string_t* str_p);
void ecma_deref_ecma_string(ecma_string_t* str_p);
ecma_value_t ecma_op_object_put(ecma_object_t* obj_p, ecma_string_t* prop_name, ecma_value_t value, bool is_throw);
ecma_string_t* ecma_get_magic_string(int magic_id);
ecma_value_t ecma_make_uint32_value(uint32_t num);
ecma_object_t* ecma_op_new_array_object(uint32_t size);
ecma_value_t ecma_make_object_value(ecma_object_t* obj_p);
ecma_value_t ecma_op_object_get_by_index(ecma_object_t* obj_p, uint32_t index);
void ecma_deref_object(ecma_object_t* obj_p);
ecma_value_t ecma_builtin_helper_def_prop_by_index(ecma_object_t* obj_p, uint32_t index, ecma_value_t value, int flags);
bool ecma_string_is_empty(ecma_string_t* str_p);
ecma_value_t ecma_op_to_length(ecma_value_t value, ecma_length_t* length_p);
ecma_length_t ecma_op_advance_string_index(ecma_string_t* str_p, ecma_length_t index, bool full_unicode);
ecma_value_t ecma_make_length_value(ecma_length_t length);
ecma_number_t ecma_get_number_from_value(ecma_value_t value);
ecma_value_t ecma_make_number_value(ecma_number_t num);
bool ecma_is_value_null(ecma_value_t value);
ecma_value_t ecma_make_string_value(ecma_string_t* str_p);
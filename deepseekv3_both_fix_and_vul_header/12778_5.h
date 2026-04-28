#include <stdint.h>
#include <stdbool.h>

typedef uint32_t ecma_value_t;
typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_extended_object_t ecma_extended_object_t;
typedef struct re_compiled_code_t re_compiled_code_t;
typedef struct ecma_compiled_code_t ecma_compiled_code_t;

#define ENABLED(x) (x)
#define JERRY_ESNEXT 1
#define ECMA_BUILTIN_ID_REGEXP_PROTOTYPE 0
#define LIT_MAGIC_STRING_LASTINDEX_UL 0
#define ECMA_PROPERTY_FLAG_WRITABLE 0
#define ECMA_PROP_IS_THROW 0
#define ECMA_ERR_MSG(x) (x)

#define JERRY_ASSERT(x) ((void)0)
#define ECMA_GET_INTERNAL_VALUE_POINTER(type, value) ((type*)(value))
#define ECMA_IS_VALUE_ERROR(x) (0)

struct ecma_extended_object_t {
    union {
        struct {
            struct {
                uintptr_t value;
            } u;
        } class_prop;
    } u;
};

ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
ecma_object_t* ecma_builtin_get(int id);
ecma_value_t ecma_raise_type_error(const char* msg);
ecma_value_t ecma_builtin_helper_def_prop(ecma_object_t* obj, const char* str, ecma_value_t value, int flags);
const char* ecma_get_magic_string(int id);
ecma_value_t ecma_make_uint32_value(uint32_t value);
bool ecma_is_value_undefined(ecma_value_t value);
bool ecma_is_value_true(ecma_value_t value);
bool ecma_object_is_regexp_object(ecma_value_t value);
void ecma_ref_object(ecma_object_t* obj);
void ecma_bytecode_deref(ecma_compiled_code_t* code);
ecma_value_t ecma_op_create_regexp_from_bytecode(ecma_object_t* obj, re_compiled_code_t* bc);
ecma_value_t ecma_op_create_regexp_from_pattern(ecma_object_t* obj, ecma_value_t pattern, ecma_value_t flags);
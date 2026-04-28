#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_environment_record_t ecma_environment_record_t;
typedef struct ecma_string_t ecma_string_t;
typedef struct ecma_property_t ecma_property_t;
typedef struct ecma_property_value_t ecma_property_value_t;

#define JERRY_ASSERT(expr) ((void)0)
#define LIT_INTERNAL_MAGIC_STRING_ENVIRONMENT_RECORD 0
#define ECMA_LEXICAL_ENVIRONMENT_DECLARATIVE 0
#define JMEM_CP_NULL 0
#define ECMA_GET_INTERNAL_VALUE_POINTER(type, value) ((type*)(uintptr_t)(value))
#define ECMA_GET_NON_NULL_POINTER(type, value) ((type*)(uintptr_t)(value))
#define ECMA_PROPERTY_VALUE_PTR(prop) ((ecma_property_value_t*)(prop))

struct ecma_property_value_t {
    uintptr_t value;
};

struct ecma_object_t {
    union {
        uintptr_t outer_reference_cp;
    } u2;
};

ecma_string_t* ecma_get_internal_string(int lit_id);
int ecma_get_lex_env_type(ecma_object_t* obj);
ecma_property_t* ecma_find_named_property(ecma_object_t* obj, ecma_string_t* name);
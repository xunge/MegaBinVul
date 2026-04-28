#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_string_t ecma_string_t;
typedef struct re_compiled_code_t re_compiled_code_t;

typedef enum {
    ECMA_VALUE_ERROR,
    ECMA_VALUE_EMPTY
} ecma_value_t;

#define JERRY_UNLIKELY(x) (x)
#define JERRY_ASSERT(x)

ecma_string_t* ecma_regexp_read_pattern_str_helper(ecma_value_t pattern_value);
bool ecma_is_value_undefined(ecma_value_t value);
ecma_string_t* ecma_op_to_string(ecma_value_t value);
void ecma_deref_ecma_string(ecma_string_t* str_p);
ecma_value_t ecma_regexp_parse_flags(ecma_string_t* flags_str_p, uint16_t* flags);
bool ECMA_IS_VALUE_ERROR(ecma_value_t value);
bool ecma_is_value_empty(ecma_value_t value);
ecma_value_t re_compile_bytecode(const re_compiled_code_t** bc_p, ecma_string_t* pattern_str_p, uint16_t flags);
void ecma_op_regexp_initialize(ecma_object_t* regexp_obj_p, const re_compiled_code_t* bc_p, ecma_string_t* pattern_str_p, uint16_t flags);
ecma_value_t ecma_make_object_value(ecma_object_t* obj_p);
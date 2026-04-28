#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;

typedef struct vm_frame_ctx_t {
    void* lex_env_p;
    ecma_value_t this_binding;
    struct {
        struct {
            struct {
                uint8_t status_flags;
            } *bytecode_header_p;
        } *shared_p;
    };
} vm_frame_ctx_t;

typedef struct ecma_environment_record_t ecma_environment_record_t;
typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_string_t ecma_string_t;

#define CBC_FUNCTION_CONSTRUCTOR 0
#define CBC_EXT_SUPER_PROP_ASSIGNMENT_REFERENCE 0
#define CBC_EXT_SUPER_PROP_LITERAL_ASSIGNMENT_REFERENCE 0
#define CBC_EXT_SUPER_PROP_LITERAL_REFERENCE 0
#define CBC_EXT_SUPER_PROP_REFERENCE 0
#define ECMA_VALUE_EMPTY 0
#define ECMA_VALUE_UNDEFINED 0
#define ECMA_VALUE_ERROR 0
#define ECMA_IS_VALUE_ERROR(x) 0
#define JERRY_ASSERT(x)

#define CBC_FUNCTION_GET_TYPE(x) 0
#define ECMA_ERR_CALL_SUPER_CONSTRUCTOR_DERIVED_CLASS_BEFORE_THIS ""
#define ECMA_ERR_INVOKE_NULLABLE_SUPER_METHOD ""

ecma_value_t ecma_raise_reference_error(const char*);
ecma_value_t ecma_raise_type_error(const char*);
ecma_environment_record_t* ecma_op_get_environment_record(void*);
bool ecma_op_this_binding_is_initialized(ecma_environment_record_t*);
ecma_value_t ecma_op_resolve_super_base(void*);
bool ecma_op_require_object_coercible(ecma_value_t);
ecma_value_t ecma_copy_value(ecma_value_t);
ecma_object_t* ecma_get_object_from_value(ecma_value_t);
ecma_string_t* ecma_op_to_property_key(ecma_value_t);
ecma_value_t ecma_op_object_get_with_receiver(ecma_object_t*, ecma_string_t*, ecma_value_t);
void ecma_deref_object(ecma_object_t*);
void ecma_deref_ecma_string(ecma_string_t*);
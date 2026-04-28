#include <stdint.h>

typedef uintptr_t ecma_value_t;
typedef struct ecma_object_t ecma_object_t;

#define JERRY_ASSERT(expr) ((void)0)
#define JERRY_UNREACHABLE() ((void)0)
#define JERRY_BUILTIN_PROXY 0
#define JERRY_ESNEXT 0

enum ecma_object_type_e {
    ECMA_OBJECT_TYPE_FUNCTION,
    ECMA_OBJECT_TYPE_BUILT_IN_FUNCTION,
    ECMA_OBJECT_TYPE_PROXY,
    ECMA_OBJECT_TYPE_CONSTRUCTOR_FUNCTION,
    ECMA_OBJECT_TYPE_BOUND_FUNCTION,
    ECMA_OBJECT_TYPE_NATIVE_FUNCTION
};

#define ECMA_VALUE_UNDEFINED 0

int ecma_is_lexical_environment(ecma_object_t *obj);
enum ecma_object_type_e ecma_get_object_type(ecma_object_t *obj);
ecma_value_t ecma_op_function_construct_simple(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
ecma_value_t ecma_op_function_construct_built_in(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
ecma_value_t ecma_proxy_object_construct(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
ecma_value_t ecma_op_function_construct_constructor(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
ecma_value_t ecma_op_function_construct_bound(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
ecma_value_t ecma_op_function_construct_native(ecma_object_t *func_obj_p, ecma_object_t *new_target_p, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
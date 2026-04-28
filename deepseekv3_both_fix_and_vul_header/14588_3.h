#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_property_value_t {
    ecma_value_t value;
} ecma_property_value_t;

typedef struct ecma_built_in_t {
    struct {
        uint8_t routine_flags;
    } u2;
} ecma_built_in_t;

typedef struct ecma_promise_all_executor_header_t {
    struct {
        ecma_built_in_t built_in;
    } u;
} ecma_promise_all_executor_header_t;

typedef struct ecma_promise_all_executor_t {
    ecma_promise_all_executor_header_t header;
    uint32_t index;
    ecma_value_t values;
    ecma_value_t remaining_elements;
    ecma_value_t capability;
} ecma_promise_all_executor_t;

typedef struct ecma_promise_capabality_t {
    ecma_value_t resolve;
    ecma_value_t reject;
} ecma_promise_capabality_t;

typedef enum {
    LIT_MAGIC_STRING_REJECTED,
    LIT_MAGIC_STRING_FULFILLED,
    LIT_MAGIC_STRING_REASON,
    LIT_MAGIC_STRING_VALUE,
    LIT_MAGIC_STRING_STATUS
} lit_magic_string_id_t;

typedef enum {
    ECMA_PROMISE_ALL_RESOLVE,
    ECMA_PROMISE_ANY_REJECT,
    ECMA_PROMISE_ALLSETTLED_RESOLVE
} ecma_promise_type_t;

#define JERRY_UNUSED(x) ((void) (x))
#define ECMA_VALUE_UNDEFINED ((ecma_value_t) 0)
#define ECMA_NATIVE_HANDLER_COMMON_FLAGS_SHIFT 0
#define ECMA_BUILTIN_ID_OBJECT_PROTOTYPE 0
#define ECMA_OBJECT_TYPE_GENERAL 0
#define ECMA_PROPERTY_CONFIGURABLE_ENUMERABLE_WRITABLE 0

ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
ecma_value_t ecma_op_object_put_by_index(ecma_object_t *obj_p, uint32_t index, ecma_value_t value, bool is_throw);
ecma_object_t* ecma_create_object(ecma_object_t *prototype_p, uint32_t size, uint8_t type);
ecma_property_value_t* ecma_create_named_data_property(ecma_object_t *obj_p, ecma_value_t name, uint8_t attributes, void *internal_slot_p);
ecma_value_t ecma_make_magic_string_value(lit_magic_string_id_t id);
ecma_value_t ecma_copy_value_if_not_object(ecma_value_t value);
ecma_value_t ecma_make_object_value(ecma_object_t *obj_p);
void ecma_deref_object(ecma_object_t *obj_p);
int ecma_promise_remaining_inc_or_dec(ecma_value_t remaining_elements, bool is_inc);
ecma_value_t ecma_new_aggregate_error(ecma_value_t errors, ecma_value_t message);
ecma_value_t ecma_op_function_call(ecma_object_t *func_obj_p, ecma_value_t this_arg, const ecma_value_t *arguments_list_p, uint32_t arguments_list_len);
void ecma_free_value(ecma_value_t value);
ecma_object_t* ecma_builtin_get(int builtin_id);
ecma_value_t ecma_get_magic_string(lit_magic_string_id_t id);
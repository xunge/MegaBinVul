#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;
typedef struct ecma_string_t ecma_string_t;
typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_property_t ecma_property_t;

struct ecma_module_t {
    ecma_object_t *namespace_object_p;
    ecma_object_t *scope_p;
};

struct ecma_module_record_t {
    struct ecma_module_t *module_p;
    ecma_string_t *name_p;
};

typedef struct ecma_module_t ecma_module_t;
typedef struct ecma_module_record_t ecma_module_record_t;

#define ECMA_VALUE_EMPTY ((ecma_value_t)0)
#define ECMA_IS_VALUE_ERROR(value) ((value) & 0x1)
#define LIT_MAGIC_STRING_DEFAULT 0
#define JERRY_ASSERT(expr) ((void)0)
#define ECMA_PROPERTY_FIXED 0
#define ECMA_PROPERTY_VALUE_PTR(prop) ((ecma_value_t)(prop))

bool ecma_compare_ecma_string_to_magic_id(ecma_string_t *str, uint32_t magic_id);
ecma_property_t *ecma_find_named_property(ecma_object_t *obj, ecma_string_t *name);
ecma_value_t ecma_module_resolve_export(ecma_module_t *module_p, ecma_string_t *export_name_p, ecma_module_record_t *record);
ecma_value_t ecma_op_get_value_lex_env_base(ecma_object_t *scope_p, ecma_object_t **ref_base_lex_env_p, ecma_string_t *name_p);
void ecma_create_named_data_property(ecma_object_t *obj, ecma_string_t *name, uint8_t attributes, ecma_property_t **out_prop);
void ecma_named_data_property_assign_value(ecma_object_t *obj, ecma_value_t prop_value, ecma_value_t value);
void ecma_free_value(ecma_value_t value);
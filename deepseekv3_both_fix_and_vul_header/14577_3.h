#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct ecma_property_t {
    union {
        uintptr_t value;
    };
} ecma_property_t;

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_string_t ecma_string_t;

typedef struct ecma_extended_string_t {
    union {
        ecma_string_t *symbol_descriptor;
    } u;
} ecma_extended_string_t;

typedef union {
    uintptr_t value;
} ecma_value_t;

#define LIT_INTERNAL_MAGIC_STRING_CLASS_PRIVATE_ELEMENTS 0

#define ECMA_GET_INTERNAL_VALUE_POINTER(type, value) ((type *)(uintptr_t)(value))
#define ECMA_PROPERTY_VALUE_PTR(prop) ((ecma_property_t *)(prop))
#define JERRY_ASSERT(expr) ((void)0)

static ecma_string_t *ecma_get_internal_string(int internal_id);
static ecma_property_t *ecma_find_named_property(ecma_object_t *obj_p, ecma_string_t *name_p);
static ecma_value_t *ecma_compact_collection_end(ecma_value_t *collection_p);
static ecma_string_t *ecma_get_prop_name_from_value(ecma_value_t value);
static bool ecma_prop_name_is_symbol(ecma_string_t *string_p);
static ecma_string_t *ecma_get_string_from_value(ecma_extended_string_t *ext_string_p);
static bool ecma_compare_ecma_strings(ecma_string_t *string1_p, ecma_string_t *string2_p);
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;
typedef uintptr_t ecma_number_t;
typedef uintptr_t ecma_length_t;

typedef struct {
    union {
        uintptr_t property_list_cp;
        struct {
            uintptr_t property_list_cp;
        } u1;
    };
} ecma_object_t;

typedef struct {
    ecma_object_t base;
    union {
        struct {
            uintptr_t length_prop_and_hole_count;
            uintptr_t length;
        } array;
    } u;
} ecma_extended_object_t;

#define ECMA_IS_VALUE_ERROR(x) (0)
#define ECMA_VALUE_ERROR (0)
#define ecma_is_value_undefined(x) (0)
#define ecma_is_value_found(x) (0)
#define ecma_is_value_true(x) (0)
#define ecma_make_object_value(x) (0)
#define ecma_free_value_if_not_object(x)
#define ecma_copy_value_if_not_object(x) (0)
#define ecma_free_value(x)
#define ecma_deref_object(x)

#define JERRY_ASSERT(x)
#define JERRY_UNLIKELY(x) (x)
#define JERRY_ESNEXT (0)
#define JMEM_CP_NULL (0)
#define ECMA_FAST_ARRAY_HOLE_ONE (1)
#define ECMA_PROPERTY_CONFIGURABLE_ENUMERABLE_WRITABLE (0)
#define JERRY_PROP_SHOULD_THROW (0)
#define ECMA_GET_NON_NULL_POINTER(type, ptr) ((type)(ptr))

static bool ecma_op_object_is_fast_array(ecma_object_t *obj_p) { return false; }
static ecma_value_t ecma_builtin_helper_array_index_normalize(ecma_value_t arg, ecma_length_t len, ecma_length_t *out) { return 0; }
static ecma_object_t *ecma_op_array_species_create(ecma_object_t *obj_p, ecma_length_t len) { return NULL; }
static ecma_object_t *ecma_op_new_array_object(uint32_t len) { return NULL; }
static ecma_value_t *ecma_fast_array_extend(ecma_object_t *obj_p, uint32_t len) { return NULL; }
static void ecma_delete_fast_array_properties(ecma_object_t *obj_p, uint32_t len) {}
static ecma_value_t ecma_op_object_find_by_index(ecma_object_t *obj_p, ecma_length_t k) { return 0; }
static ecma_value_t ecma_builtin_helper_def_prop_by_index(ecma_object_t *obj_p, ecma_length_t n, ecma_value_t val, uint32_t flags) { return 0; }
static ecma_value_t ecma_builtin_array_prototype_helper_set_length(ecma_object_t *obj_p, ecma_number_t len) { return 0; }
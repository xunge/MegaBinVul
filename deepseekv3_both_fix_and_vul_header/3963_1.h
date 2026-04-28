#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t jmem_cpointer_t;
#define JMEM_CP_NULL ((jmem_cpointer_t) 0)

typedef enum
{
  ECMA_VALUE_ERROR,
  ECMA_VALUE_UNDEFINED,
  ECMA_VALUE_FOUND
} ecma_value_type_t;

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_extended_object_t ecma_extended_object_t;

typedef union
{
  struct
  {
    uint32_t length;
    struct {
      uint32_t hole_count;
    } u;
  } array;
} ecma_object_u_t;

struct ecma_object_t
{
  struct {
    jmem_cpointer_t property_list_cp;
  } u1;
  ecma_object_u_t u;
};

struct ecma_extended_object_t
{
  ecma_object_t object;
  ecma_object_u_t u;
};

typedef uint32_t ecma_value_t;
typedef double ecma_number_t;

#define ECMA_FAST_ARRAY_HOLE_ONE (1u << 31)
#define ECMA_PROPERTY_CONFIGURABLE_ENUMERABLE_WRITABLE (0x07)
#define ENABLED(x) (1)
#define JERRY_ES2015 1
#define JERRY_UNLIKELY(x) (x)
#define JERRY_ASSERT(x) ((void)0)

#define ECMA_IS_VALUE_ERROR(x) ((x) == ECMA_VALUE_ERROR)
#define ECMA_GET_NON_NULL_POINTER(type, cp) ((type *)(uintptr_t)(cp))

static inline bool ecma_is_value_undefined(ecma_value_t value) { return value == ECMA_VALUE_UNDEFINED; }
static inline bool ecma_is_value_found(ecma_value_t value) { return value != ECMA_VALUE_UNDEFINED; }
static inline ecma_object_t *ecma_get_object_from_value(ecma_value_t value) { return (ecma_object_t *)(uintptr_t)value; }
static inline void ecma_free_value(ecma_value_t value) {}
static inline void ecma_free_value_if_not_object(ecma_value_t value) {}
static inline ecma_value_t ecma_copy_value_if_not_object(ecma_value_t value) { return value; }
static inline void ecma_deref_object(ecma_object_t *obj_p) {}

static inline bool ecma_op_object_is_fast_array(ecma_object_t *obj_p) { return false; }
static inline ecma_value_t ecma_op_array_species_create(ecma_object_t *obj_p, uint32_t length) { return ECMA_VALUE_UNDEFINED; }
static inline ecma_value_t ecma_op_create_array_object(void *null, int zero, bool flag) { return ECMA_VALUE_UNDEFINED; }
static inline ecma_value_t *ecma_fast_array_extend(ecma_object_t *obj_p, uint32_t length) { return NULL; }
static inline void ecma_delete_fast_array_properties(ecma_object_t *obj_p, uint32_t length) {}
static inline ecma_value_t ecma_op_object_find_by_uint32_index(ecma_object_t *obj_p, uint32_t index) { return ECMA_VALUE_UNDEFINED; }
static inline ecma_value_t ecma_builtin_helper_def_prop_by_index(ecma_object_t *obj_p, uint32_t index, ecma_value_t value, int flags) { return ECMA_VALUE_UNDEFINED; }
static inline ecma_value_t ecma_builtin_array_prototype_helper_set_length(ecma_object_t *obj_p, ecma_number_t length) { return ECMA_VALUE_UNDEFINED; }
static inline ecma_value_t ecma_builtin_helper_array_index_normalize(ecma_value_t arg, uint32_t len, uint32_t *out) { return ECMA_VALUE_UNDEFINED; }
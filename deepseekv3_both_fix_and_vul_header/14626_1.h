#include <stdint.h>
#include <stdbool.h>

typedef enum
{
  ECMA_BIGINT64_ARRAY,
  ECMA_BIGUINT64_ARRAY
} ecma_typedarray_type_t;

typedef struct
{
  ecma_typedarray_type_t id;
  uint8_t element_size;
  uint32_t offset;
} ecma_typedarray_info_t;

typedef int ecma_value_t;
typedef int ecma_atomics_op_t;
typedef double ecma_number_t;
typedef struct ecma_object_t ecma_object_t;

#define ECMA_IS_VALUE_ERROR(x) (0)
#define ECMA_VALUE_ERROR (0)
#define JERRY_UNUSED(x) ((void)(x))

ecma_value_t ecma_validate_shared_integer_typedarray(ecma_value_t, bool);
ecma_value_t ecma_validate_atomic_access(ecma_value_t, ecma_value_t);
ecma_object_t* ecma_get_object_from_value(ecma_value_t);
ecma_typedarray_info_t ecma_typedarray_get_info(ecma_object_t*);
ecma_value_t ecma_bigint_to_bigint(ecma_value_t, bool);
ecma_value_t ecma_op_to_integer(ecma_value_t, ecma_number_t*);
ecma_value_t ecma_make_number_value(ecma_number_t);
uint32_t ecma_number_to_uint32(ecma_value_t);
void ecma_free_value(ecma_value_t);
ecma_value_t ecma_make_uint32_value(uint32_t);
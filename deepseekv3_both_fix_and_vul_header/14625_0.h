#include <stdbool.h>

typedef enum {
  ECMA_BIGINT64_ARRAY,
  ECMA_INT32_ARRAY,
  ECMA_UINT8_CLAMPED_ARRAY,
  ECMA_FLOAT32_ARRAY,
  ECMA_FLOAT64_ARRAY
} ecma_typedarray_type_t;

typedef struct {
  ecma_typedarray_type_t id;
  void *array_buffer_p;
} ecma_typedarray_info_t;

typedef struct ecma_object_t ecma_object_t;
typedef int ecma_value_t;

#define ECMA_OBJECT_CLASS_SHARED_ARRAY_BUFFER 0
#define ECMA_ERR_ARGUMENT_THIS_NOT_TYPED_ARRAY 0
#define ECMA_ERR_ARGUMENT_NOT_SUPPORTED 0
#define ECMA_ERR_ARGUMENT_THIS_NOT_OBJECT 0
#define ECMA_ERR_ARGUMENT_NOT_SHARED_ARRAY_BUFFER 0

#define JERRY_ASSERT(expr) ((void)0)

bool ecma_is_typedarray(ecma_value_t value);
bool ecma_is_value_object(ecma_value_t value);
ecma_value_t ecma_raise_type_error(int error);
ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
ecma_typedarray_info_t ecma_typedarray_get_info(ecma_object_t *obj);
bool ecma_object_class_is(ecma_object_t *obj, int class_type);
ecma_object_t* ecma_typedarray_get_arraybuffer(ecma_object_t *obj);
ecma_value_t ecma_make_object_value(ecma_object_t *obj);
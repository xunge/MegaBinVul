#include <stdint.h>
#include <stdbool.h>

typedef uint8_t lit_magic_string_id_t;

typedef enum
{
  ECMA_OBJECT_TYPE_ARRAY,
  ECMA_OBJECT_TYPE_BUILT_IN_ARRAY,
  ECMA_OBJECT_TYPE_CLASS,
  ECMA_OBJECT_TYPE_BUILT_IN_CLASS,
  ECMA_OBJECT_TYPE_FUNCTION,
  ECMA_OBJECT_TYPE_NATIVE_FUNCTION,
  ECMA_OBJECT_TYPE_BOUND_FUNCTION,
  ECMA_OBJECT_TYPE_BUILT_IN_FUNCTION,
  ECMA_OBJECT_TYPE_CONSTRUCTOR_FUNCTION,
  ECMA_OBJECT_TYPE_PROXY,
  ECMA_OBJECT_TYPE_BUILT_IN_GENERAL,
  ECMA_OBJECT_TYPE_GENERAL,
  ECMA_OBJECT_TYPE__MAX
} ecma_object_type_t;

typedef enum
{
  ECMA_OBJECT_CLASS_TYPEDARRAY,
  ECMA_OBJECT_CLASS_CONTAINER,
  ECMA_OBJECT_CLASS__MAX
} ecma_object_class_type_t;

typedef enum
{
  ECMA_BUILTIN_ID_MATH,
  ECMA_BUILTIN_ID_REFLECT,
  ECMA_BUILTIN_ID_GENERATOR,
  ECMA_BUILTIN_ID_ASYNC_GENERATOR,
  ECMA_BUILTIN_ID_JSON,
  ECMA_BUILTIN_ID_ATOMICS,
  ECMA_BUILTIN_ID_EVAL_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_RANGE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_REFERENCE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_SYNTAX_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_TYPE_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_URI_ERROR_PROTOTYPE,
  ECMA_BUILTIN_ID_ERROR_PROTOTYPE
} ecma_builtin_id_t;

typedef struct ecma_object_t ecma_object_t;

typedef struct {
  union {
    struct {
      ecma_object_class_type_t type;
      union {
        uint8_t typedarray_type;
      } u1;
      union {
        uint8_t container_id;
      } u2;
    } cls;
    struct {
      ecma_builtin_id_t id;
    } built_in;
  } u;
} ecma_extended_object_t;

typedef struct {
  uintptr_t target;
} ecma_proxy_object_t;

#define LIT_MAGIC_STRING_ARRAY_UL 0
#define LIT_MAGIC_STRING_FUNCTION_UL 1
#define LIT_MAGIC_STRING_OBJECT_UL 2
#define LIT_MAGIC_STRING_MATH_UL 3
#define LIT_MAGIC_STRING_REFLECT_UL 4
#define LIT_MAGIC_STRING_GENERATOR_UL 5
#define LIT_MAGIC_STRING_ASYNC_GENERATOR_UL 6
#define LIT_MAGIC_STRING_JSON_U 7
#define LIT_MAGIC_STRING_ATOMICS_U 8
#define LIT_MAGIC_STRING_ERROR_UL 9
#define LIT_MAGIC_STRING__EMPTY 10

extern ecma_object_type_t ecma_get_object_type (ecma_object_t *obj_p);
extern lit_magic_string_id_t ecma_get_typedarray_magic_string_id (uint8_t typedarray_type);
extern bool ecma_is_value_null (uintptr_t value);
extern bool ecma_is_value_object (uintptr_t value);
extern ecma_object_t *ecma_get_object_from_value (uintptr_t value);
extern bool ecma_object_check_class_name_is_object (ecma_object_t *obj_p);

static const lit_magic_string_id_t ecma_class_object_magic_string_id[ECMA_OBJECT_CLASS__MAX] = {0};

#define JERRY_BUILTIN_TYPEDARRAY 1
#define JERRY_BUILTIN_CONTAINER 1
#define JERRY_BUILTIN_PROXY 1
#define JERRY_BUILTIN_MATH 1
#define JERRY_BUILTIN_REFLECT 1
#define JERRY_ESNEXT 1
#define JERRY_BUILTIN_JSON 1
#define JERRY_BUILTIN_ATOMICS 1
#define JERRY_BUILTIN_ERRORS 1

#define JERRY_ASSERT(x) ((void)0)
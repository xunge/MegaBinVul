#include <stdint.h>
#include <stddef.h>

typedef uint32_t ecma_value_t;
typedef uint32_t jmem_cpointer_t;

typedef struct ecma_object_t ecma_object_t;
typedef struct ecma_string_t ecma_string_t;
typedef struct ecma_property_descriptor_t ecma_property_descriptor_t;
typedef struct ecma_property_value_t ecma_property_value_t;

typedef struct ecma_bound_function_t {
    struct {
        union {
            struct {
                ecma_object_t *target_function;
                ecma_value_t args_len_or_this;
            } bound_function;
        } u;
    } header;
    ecma_value_t target_length;
} ecma_bound_function_t;

typedef int32_t ecma_integer_value_t;
typedef double ecma_number_t;

#define ENABLED(x) 0
#define JERRY_ESNEXT 0
#define JERRY_BUILTIN_PROXY 0
#define ECMA_BUILTIN_ID_FUNCTION_PROTOTYPE 0
#define LIT_MAGIC_STRING_LENGTH 0
#define LIT_MAGIC_STRING_NAME 0
#define LIT_MAGIC_STRING__EMPTY 0
#define JMEM_CP_NULL 0
#define ECMA_VALUE_UNDEFINED 0
#define ECMA_OBJECT_IS_PROXY(x) 0
#define ECMA_IS_VALUE_ERROR(x) 0
#define ECMA_IS_VALUE_TRUE(x) 0
#define ECMA_GET_NON_NULL_POINTER(type, ptr) ((type)(ptr))
#define ECMA_SET_NON_NULL_POINTER_TAG(dest, src, tag) ((dest) = (src))
#define JERRY_ASSERT(x) ((void)0)

enum {
    ECMA_OBJECT_TYPE_BOUND_FUNCTION,
    ECMA_PROPERTY_FLAG_CONFIGURABLE
};
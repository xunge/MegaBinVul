#include <stdint.h>
#include <stddef.h>

typedef uint32_t ecma_length_t;
typedef uint8_t ecma_value_t;

typedef struct ecma_object ecma_object_t;
typedef struct ecma_string ecma_string_t;

struct ecma_collection {
    ecma_value_t *buffer_p;
    uint32_t item_count;
};
typedef struct ecma_collection ecma_collection_t;

#define JERRY_ASSERT(expr)
#define JERRY_ESNEXT 1
#define JERRY_BUILTIN_PROXY 1
#define JERRY_UNLIKELY(expr) (expr)

#define ECMA_IS_VALUE_ERROR(value) 0
#define ECMA_VALUE_ERROR 0
#define ECMA_VALUE_TRUE 1
#define ECMA_ENUMERABLE_PROPERTY_KEYS 0
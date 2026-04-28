#include <stdint.h>

typedef uintptr_t ecma_value_t;
typedef uint8_t lit_magic_string_id_t;

#define LIT_MAGIC_STRING_WEAKMAP_UL 0
#define LIT_MAGIC_STRING_MAP_UL 1

#define JERRY_ASSERT(expr) ((void)0)

typedef struct ecma_collection_t ecma_collection_t;

#define ECMA_CONTAINER_GET_SIZE(container) (0)
#define ECMA_CONTAINER_SET_SIZE(container, size) ((void)0)

static ecma_value_t ecma_copy_value_if_not_object(ecma_value_t value);
static void ecma_collection_push_back(ecma_collection_t *container_p, ecma_value_t value);
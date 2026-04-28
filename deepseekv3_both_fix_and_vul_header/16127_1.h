#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct ecma_collection_t ecma_collection_t;

typedef enum {
    ECMA_VALUE_ERROR,
    ECMA_VALUE_EMPTY,
    ECMA_VALUE_SPREAD_ELEMENT
} ecma_value_t;

#define JERRY_ATTR_NOINLINE
#define ECMA_IS_VALUE_ERROR(x) ((x) == ECMA_VALUE_ERROR)

ecma_collection_t* ecma_new_collection(void);
void ecma_collection_push_back(ecma_collection_t* collection, ecma_value_t value);
void ecma_collection_free(ecma_collection_t* collection);
void ecma_free_value(ecma_value_t value);
ecma_value_t ecma_op_get_iterator(ecma_value_t value, ecma_value_t empty);
ecma_value_t ecma_op_iterator_step(ecma_value_t iterator);
ecma_value_t ecma_op_iterator_value(ecma_value_t next_value);
bool ecma_is_value_false(ecma_value_t value);
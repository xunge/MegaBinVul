#include <stdint.h>
#include <stdbool.h>

#define njs_inline inline
typedef bool njs_bool_t;

#define NJS_ATTRIBUTE_UNSET 0
#define NJS_PROPERTY_HANDLER 0

typedef struct njs_value_s {
    uint64_t data;
} njs_value_t;

typedef struct njs_object_prop_s {
    njs_value_t value;
    uint8_t writable;
    uint8_t type;
} njs_object_prop_t;

njs_bool_t njs_is_valid(const njs_value_t *value);
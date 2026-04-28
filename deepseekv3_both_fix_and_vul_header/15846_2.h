#include <stddef.h>
#include <stdint.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define FLOW_KEYS_HASH_OFFSET 0
#define SIPHASH_ALIGNMENT 8
#define FLOW_KEYS_HASH_START_FIELD dummy_field

typedef uint32_t u32;

struct flow_keys {
    int FLOW_KEYS_HASH_START_FIELD;
};
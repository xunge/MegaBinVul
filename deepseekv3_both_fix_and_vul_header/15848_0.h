#include <stddef.h>
#include <stdint.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

#define FLOW_KEYS_HASH_OFFSET offsetof(struct flow_keys, addrs)

enum flow_dissector_key_type {
    FLOW_DISSECTOR_KEY_IPV4_ADDRS,
    FLOW_DISSECTOR_KEY_IPV6_ADDRS, 
    FLOW_DISSECTOR_KEY_TIPC
};

typedef uint32_t u32;

struct flow_keys {
    struct {
        enum flow_dissector_key_type addr_type;
    } control;
    union {
        struct {
            u32 src;
            u32 dst;
        } v4addrs;
        struct {
            u32 src[4];
            u32 dst[4];
        } v6addrs;
        u32 tipckey;
    } addrs;
};
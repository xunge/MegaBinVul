#include <stdint.h>

typedef uint32_t u32;

struct sk_buff;
struct flow_keys;
typedef struct { uint64_t key[2]; } siphash_key_t;

#define FLOW_DISSECTOR_F_STOP_AT_FLOW_LABEL 0

void skb_flow_dissect_flow_keys(const struct sk_buff *skb, struct flow_keys *keys, int flags);

static inline u32 __flow_hash_from_keys(const struct flow_keys *keys, const siphash_key_t *keyval) {
    return 0;
}

static inline u32 __flow_hash_from_keys_u32(const struct flow_keys *keys, u32 keyval) {
    return 0;
}
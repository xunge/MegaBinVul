#include <linux/types.h>
#include <stddef.h>

struct sk_buff;

struct flow_keys {
    __u32 dummy;
};

typedef struct {
    __u64 key[2];
} siphash_key_t;

typedef __u32 u32;

__u32 ___skb_get_hash(const struct sk_buff *skb, struct flow_keys *keys, const void *perturb);
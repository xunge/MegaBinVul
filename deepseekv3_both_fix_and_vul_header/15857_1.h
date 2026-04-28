#include <stdint.h>

typedef uint32_t u32;

struct sk_buff {
    // minimal definition
};

struct fq {
    u32 perturbation;
    u32 flows_cnt;
};

static inline u32 skb_get_hash_perturb(struct sk_buff *skb, u32 perturbation) {
    return 0;
}

static inline u32 reciprocal_scale(u32 val, u32 ep_ro) {
    return 0;
}
#include <stddef.h>

struct sk_buff {
    unsigned char *data;
    unsigned char cb[48];
};

struct napi_gro_cb {
    void *frag0;
    unsigned int frag0_len;
};

#define NAPI_GRO_CB(skb) ((struct napi_gro_cb *)(skb)->cb)

static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) {
    return 1;
}
#include <stddef.h>

struct sk_buff;
struct net_device;

struct napi_struct {
    struct sk_buff *skb;
    struct net_device *dev;
};

struct ethhdr {
    unsigned short h_proto;
};

struct sk_buff {
    unsigned short protocol;
    void *head;
    void *data;
    void *tail;
    void *end;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    struct net_device *dev;
    char cb[48];
};

struct napi_gro_cb {
    void *frag0;
    unsigned int frag0_len;
};

#define unlikely(x) (x)
#define NAPI_GRO_CB(skb) ((struct napi_gro_cb *)(skb)->cb)
#define net_warn_ratelimited(fmt, ...) 
#define __func__ __FUNCTION__

static inline void skb_reset_mac_header(struct sk_buff *skb) {}
static inline void skb_gro_reset_offset(struct sk_buff *skb) {}
static inline const struct ethhdr *skb_gro_header_fast(struct sk_buff *skb, unsigned int offset) { return 0; }
static inline int skb_gro_header_hard(struct sk_buff *skb, unsigned int hlen) { return 0; }
static inline const struct ethhdr *skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen, unsigned int offset) { return 0; }
static inline void napi_reuse_skb(struct napi_struct *napi, struct sk_buff *skb) {}
static inline void gro_pull_from_frag0(struct sk_buff *skb, unsigned int hlen) {}
static inline void __skb_pull(struct sk_buff *skb, unsigned int len) {}
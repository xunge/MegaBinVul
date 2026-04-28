#include <stdint.h>
#include <stddef.h>

#define CHECKSUM_PARTIAL 1

typedef uint32_t u32;

struct sk_buff {
    unsigned char *data;
    struct sk_buff *next;
    int ip_summed;
    void *dev;
};

struct udphdr {
    uint16_t source;
    uint16_t dest;
    uint16_t check;
};

struct net;

struct udp_offload_priv {
    const struct net *net;
    struct udp_offload *offload;
    struct udp_offload_priv *next;
};

struct udp_offload {
    uint16_t port;
    uint8_t ipproto;
    struct {
        struct sk_buff **(*gro_receive)(struct sk_buff **, struct sk_buff *, struct udp_offload *);
    } callbacks;
};

struct NAPI_GRO_CB {
    int encap_mark;
    int udp_mark;
    int csum_cnt;
    int csum_valid;
    int same_flow;
    int flush;
    uint8_t proto;
};

#define NAPI_GRO_CB(skb) ((struct NAPI_GRO_CB *)0)

extern struct udp_offload_priv *udp_offload_base;

static inline unsigned int skb_gro_offset(struct sk_buff *skb) { return 0; }
static inline void skb_gro_pull(struct sk_buff *skb, unsigned int len) {}
static inline void skb_gro_postpull_rcsum(struct sk_buff *skb, void *ptr, unsigned int len) {}
static inline int net_eq(const struct net *net1, const struct net *net2) { return 0; }
static inline struct net *dev_net(void *dev) { return 0; }
static inline struct net *read_pnet(const struct net * const *pnet) { return 0; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct udp_offload_priv *rcu_dereference(struct udp_offload_priv *p) { return p; }
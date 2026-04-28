#include <stdint.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    struct list_head list;
    char cb[48];
};

struct udphdr {
    uint16_t source;
    uint16_t dest;
    uint16_t len;
    uint16_t check;
};

typedef uint32_t u32;

#define NAPI_GRO_CB(skb) ((struct napi_gro_cb *)(skb)->cb)
#define UDP_GRO_CNT_MAX 8

struct napi_gro_cb {
    int same_flow;
    int flush;
    int count;
};

static inline struct udphdr *udp_hdr(const struct sk_buff *skb) {
    return (struct udphdr *)(skb + 1);
}

static inline void skb_gro_pull(struct sk_buff *skb, unsigned int len) {}
static inline void skb_gro_postpull_rcsum(struct sk_buff *skb, const void *ptr, unsigned int len) {}
static inline int skb_gro_receive(struct sk_buff *p, struct sk_buff *skb) { return 0; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); &pos->member != (head); pos = (typeof(pos))(pos->member.next))
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char *mac_header;
    unsigned char *network_header;
    unsigned char *transport_header;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct batadv_frag_packet {
    uint16_t total_size;
};

struct batadv_frag_list_entry {
    struct hlist_node list;
    struct sk_buff *skb;
};

#define ETH_HLEN 14
#define GFP_ATOMIC 0

static inline uint16_t ntohs(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x >> 8) & 0xFF);
}

static inline void hlist_del(struct hlist_node *n) {}
static inline void kfree(void *p) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int pskb_expand_head(struct sk_buff *skb, int a, int b, int c) { return 0; }
static inline void skb_pull_rcsum(struct sk_buff *skb, int len) {}
static inline unsigned char *skb_mac_header(struct sk_buff *skb) { return skb->mac_header; }
static inline void skb_set_mac_header(struct sk_buff *skb, int offset) {}
static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline unsigned char *skb_put(struct sk_buff *skb, int len) { 
    unsigned char *tmp = skb->data + skb->len;
    skb->len += len;
    return tmp;
}

static inline void batadv_frag_clear_chain(struct hlist_head *chain) {}
static inline int batadv_frag_size_limit() { return 1500; }

#define hlist_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define hlist_for_each_entry(pos, head, member) \
    for (pos = hlist_entry((head)->first, struct batadv_frag_list_entry, member); \
         &pos->member != NULL; \
         pos = hlist_entry(pos->member.next, struct batadv_frag_list_entry, member))
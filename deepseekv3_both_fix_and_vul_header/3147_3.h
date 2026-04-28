#include <stdint.h>
#include <stddef.h>

#define ETH_P_IPV6 0x86DD
#define MSG_DONTWAIT 0x40
#define CHECKSUM_PARTIAL 1
#define SKB_GSO_UDP 1

struct sk_buff;

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sock {
    struct sk_buff_head sk_write_queue;
};

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int transport_header;
    unsigned int network_header;
    uint16_t protocol;
    uint8_t ip_summed;
    uint32_t csum;
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct rt6_info {
    // minimal definition
};

struct frag_hdr {
    uint32_t identification;
};

struct skb_shared_info {
    uint16_t gso_size;
    uint16_t gso_type;
    uint32_t ip6_frag_id;
};

static inline uint16_t htons(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8);
}

// Dummy function declarations
static inline struct sk_buff *skb_peek_tail(const struct sk_buff_head *list) { return NULL; }
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int flags, int *err) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline unsigned char *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline int skb_append_datato_frags(struct sock *sk, struct sk_buff *skb, 
    int (*getfrag)(void *, char *, int, int, int, struct sk_buff *), 
    void *from, int length) { return 0; }
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return NULL; }
static inline void ipv6_select_ident(struct frag_hdr *fhdr, struct rt6_info *rt) {}
static inline void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk) {}
static inline void kfree_skb(struct sk_buff *skb) {}
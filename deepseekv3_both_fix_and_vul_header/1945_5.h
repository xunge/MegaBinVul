#include <stddef.h>

#define NULL ((void *)0)
#define ENOMEM 12
#define MSG_DONTWAIT 0x40
#define CHECKSUM_PARTIAL 1
#define SKB_GSO_UDP 1

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
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
    unsigned char ip_summed;
    unsigned int csum;
    struct skb_shared_info *shinfo;
};

struct skb_shared_info {
    unsigned short gso_size;
    unsigned short gso_type;
    unsigned int ip6_frag_id;
};

struct rt6_info {
    unsigned int dummy;
};

struct frag_hdr {
    unsigned int identification;
};

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return skb->shinfo;
}

static inline void ipv6_select_ident(struct frag_hdr *fhdr, ...) {
    fhdr->identification = 0;
}

static inline void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int skb_append_datato_frags(struct sock *sk, struct sk_buff *skb, 
    int (*getfrag)(void *, char *, int, int, int, struct sk_buff *), 
    void *from, int length) { return 0; }
static inline struct sk_buff *skb_peek_tail(const struct sk_buff_head *list) { return NULL; }
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int flags, int *err) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline void skb_put(struct sk_buff *skb, int len) {}
static inline void skb_reset_network_header(struct sk_buff *skb) {}
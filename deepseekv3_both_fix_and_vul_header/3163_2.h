#include <stddef.h>

struct sock;
struct sk_buff_head;

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned char *transport_header;
    unsigned char *network_header;
    unsigned int ip_summed;
    unsigned int csum;
};

struct skb_shared_info {
    unsigned short gso_size;
    unsigned short gso_type;
};

#define MSG_DONTWAIT   0x40
#define CHECKSUM_PARTIAL 2
#define SKB_GSO_UDP 4

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->end);
}

static inline void skb_reserve(struct sk_buff *skb, int len) {
    skb->data += len;
    skb->tail += len;
}

static inline void skb_put(struct sk_buff *skb, int len) {
    skb->tail += len;
}

static inline void skb_reset_network_header(struct sk_buff *skb) {
    skb->network_header = skb->data;
}

static inline struct sk_buff *skb_peek_tail(struct sk_buff_head *queue) { return NULL; }
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int flags, int *err) { return NULL; }
static inline void __skb_queue_tail(struct sk_buff_head *queue, struct sk_buff *skb) {}
static inline int skb_append_datato_frags(struct sock *sk, struct sk_buff *skb, 
    int (*getfrag)(void *, char *, int, int, int, struct sk_buff *), 
    void *from, int length) { return 0; }
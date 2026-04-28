#include <stdatomic.h>
#include <stddef.h>
#include <string.h>

#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define CHECKSUM_COMPLETE 1
#define IPV6_MAXPLEN 65535
#define KERN_DEBUG ""
#define WARN_ON(cond) ((void)0)
#define pr_debug(fmt, ...) ((void)0)
#define net_ratelimit() 0

struct sk_buff {
    unsigned char *data;
    unsigned char *head;
    unsigned char *mac_header;
    unsigned char *network_header;
    unsigned char *transport_header;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    unsigned short ip_summed;
    unsigned int csum;
    struct sk_buff *next;
    void *dev;
    unsigned long tstamp;
    struct skb_shared_info *shinfo;
    char cb[48];
};

struct skb_shared_info {
    struct sk_buff *frag_list;
    int nr_frags;
    struct {
        int size;
    } frags[0];
};

struct ipv6hdr {
    unsigned short payload_len;
};

struct frag_hdr {
};

struct net_device {
};

struct nf_ct_frag6_queue {
    struct {
        struct sk_buff *fragments;
        int len;
        unsigned long stamp;
    } q;
    int nhoffset;
};

struct nf_ct_frag6_skb_cb {
    struct sk_buff *orig;
    int offset;
};

#define NFCT_FRAG6_CB(skb) ((struct nf_ct_frag6_skb_cb *)((skb)->cb))

static struct nf_init_frags {
    atomic_int mem;
} nf_init_frags;

static inline void fq_kill(struct nf_ct_frag6_queue *fq) {}

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline unsigned char *skb_transport_header(const struct sk_buff *skb) {
    return skb->transport_header;
}

static inline int skb_cloned(const struct sk_buff *skb) {
    return 0;
}

static inline int pskb_expand_head(struct sk_buff *skb, int a, int b, int c) {
    return 0;
}

static inline int skb_has_frags(const struct sk_buff *skb) {
    return skb->shinfo->frag_list != NULL;
}

static inline struct sk_buff *alloc_skb(int size, int flags) {
    return NULL;
}

static inline void skb_frag_list_init(struct sk_buff *skb) {
    skb->shinfo->frag_list = NULL;
}

static inline void skb_reset_transport_header(struct sk_buff *skb) {
    skb->transport_header = skb->data;
}

static inline void skb_push(struct sk_buff *skb, int len) {
    skb->data -= len;
    skb->len += len;
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb_network_header(skb);
}

static inline unsigned short htons(unsigned short val) {
    return (val << 8) | (val >> 8);
}

static inline unsigned int csum_add(unsigned int csum, unsigned int addend) {
    return csum + addend;
}

static inline unsigned int csum_partial(const void *buff, int len, unsigned int sum) {
    return sum;
}

static inline void printk(const char *fmt, ...) {}

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return skb->shinfo;
}

static inline int skb_network_header_len(const struct sk_buff *skb) {
    return skb->transport_header - skb->network_header;
}

static inline void atomic_add(int i, atomic_int *v) {
    *v += i;
}

static inline void atomic_sub(int i, atomic_int *v) {
    *v -= i;
}
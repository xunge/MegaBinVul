#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct sk_buff {
    void *dev;
    unsigned char cb[48];
};

struct net_device;

struct in6_addr {
    uint8_t s6_addr[16];
};

struct frag_hdr {
    uint8_t nexthdr;
    uint8_t reserved;
    uint16_t frag_off;
    uint32_t identification;
};

struct ipv6hdr {
    uint8_t priority:4,
            version:4;
    uint8_t flow_lbl[3];
    uint16_t payload_len;
    uint8_t nexthdr;
    uint8_t hop_limit;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

typedef struct {
    int lock;
} spinlock_t;

struct nf_ct_frag6_queue {
    struct {
        spinlock_t lock;
        unsigned int last_in;
        unsigned int meat;
        unsigned int len;
    } q;
};

struct nf_ct_frag6_skb_cb {
    struct sk_buff *orig;
};

#define NFCT_FRAG6_CB(skb) ((struct nf_ct_frag6_skb_cb *)((skb)->cb))

struct nf_init_frags {
    int mem;
    int high_thresh;
};

extern struct nf_init_frags nf_init_frags;

#define INET_FRAG_FIRST_IN    (1 << 0)
#define INET_FRAG_LAST_IN     (1 << 1)
#define GFP_ATOMIC 0
#define pr_debug(fmt, ...) 

static inline uint16_t htons(uint16_t x) {
    return ((x & 0xff) << 8) | ((x & 0xff00) >> 8);
}

static inline int atomic_read(const int *v) {
    return *v;
}

static inline void spin_lock_bh(spinlock_t *lock) {}
static inline void spin_unlock_bh(spinlock_t *lock) {}

extern int find_prev_fhdr(struct sk_buff *skb, u8 *prevhdr, int *nhoff, int *fhoff);
extern struct sk_buff *skb_clone(struct sk_buff *skb, int gfp_mask);
extern int pskb_may_pull(struct sk_buff *skb, unsigned int len);
extern void skb_set_transport_header(struct sk_buff *skb, int offset);
extern struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb);
extern void *skb_transport_header(const struct sk_buff *skb);
extern void kfree_skb(struct sk_buff *skb);
extern void nf_ct_frag6_evictor(void);
extern struct nf_ct_frag6_queue *fq_find(uint32_t id, u32 user, const struct in6_addr *src, const struct in6_addr *dst);
extern void fq_put(struct nf_ct_frag6_queue *fq);
extern int nf_ct_frag6_queue(struct nf_ct_frag6_queue *fq, struct sk_buff *skb, struct frag_hdr *fhdr, int nhoff);
extern struct sk_buff *nf_ct_frag6_reasm(struct nf_ct_frag6_queue *fq, struct net_device *dev);
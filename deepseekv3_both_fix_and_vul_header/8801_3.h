#include <stdint.h>
#include <stddef.h>

typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint8_t u8;
typedef uint32_t u32;

struct net;
struct inet_frags;

struct in6_addr {
    uint8_t s6_addr[16];
};

struct sk_buff {
    struct net_device *dev;
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
};

struct net_device {
    int ifindex;
};

struct ipv6hdr {
    struct in6_addr saddr;
    struct in6_addr daddr;
    __be16 payload_len;
};

struct frag_hdr {
    __be16 frag_off;
    __be16 identification;
};

typedef struct {
    int lock;
} spinlock_t;

struct inet_frag_queue {
    spinlock_t lock;
    unsigned int flags;
    unsigned int len;
    unsigned int meat;
};

struct frag_queue {
    struct inet_frag_queue q;
};

#define EINVAL 22
#define ENOMEM 12
#define EINPROGRESS 115

#define INET_FRAG_FIRST_IN 0x01
#define INET_FRAG_LAST_IN 0x02

extern int find_prev_fhdr(struct sk_buff *skb, u8 *prevhdr, int *nhoff, int *fhoff);
extern struct frag_queue *fq_find(struct net *net, __be32 id, u32 user, const struct in6_addr *src, const struct in6_addr *dst, int iif, u8 ecn);
extern int nf_ct_frag6_queue(struct frag_queue *fq, struct sk_buff *skb, struct frag_hdr *fhdr, int nhoff);
extern int nf_ct_frag6_reasm(struct frag_queue *fq, struct sk_buff *skb, struct net_device *dev);
extern void inet_frag_put(struct inet_frag_queue *q, struct inet_frags *f);
extern struct inet_frags nf_frags;
extern void spin_lock_bh(spinlock_t *lock);
extern void spin_unlock_bh(spinlock_t *lock);
extern int pskb_may_pull(struct sk_buff *skb, unsigned int len);
extern void skb_set_transport_header(struct sk_buff *skb, int offset);
extern unsigned char *skb_transport_header(const struct sk_buff *skb);
extern struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb);
extern u8 ip6_frag_ecn(const struct ipv6hdr *ipv6h);

#define pr_debug(fmt, ...)
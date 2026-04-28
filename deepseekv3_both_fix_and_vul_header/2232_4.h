#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct dst_entry {
    struct net_device *dev;
};

struct sk_buff {
    struct net_device *dev;
    unsigned char *data;
    unsigned int len;
    u16 ip_summed;
    u32 csum;
    unsigned char *network_header;
    struct sk_buff *next;
    unsigned int truesize;
    void *tstamp;
    char cb[48];
    struct dst_entry *dst;
};

struct net_device {
    int ifindex;
};

struct netns_frags {
    struct list_head lru_list;
    int mem;
};

struct inet_frag_queue {
    unsigned int last_in;
    unsigned int len;
    struct sk_buff *fragments;
    struct sk_buff *fragments_tail;
    struct netns_frags *net;
    unsigned int meat;
    struct list_head lru_list;
    void *stamp;
    int mem;
};

struct frag_queue {
    struct inet_frag_queue q;
    int iif;
    u16 nhoffset;
};

struct frag_hdr {
    u8 nexthdr;
    u8 reserved;
    u16 frag_off;
    u32 identification;
};

struct ipv6hdr {
    u16 payload_len;
};

struct FRAG6_CB {
    u16 offset;
};

#define FRAG6_CB(skb) ((struct FRAG6_CB *)((skb)->cb))

#define INET_FRAG_COMPLETE 4
#define INET_FRAG_LAST_IN 2
#define INET_FRAG_FIRST_IN 1
#define IP6_MF 0x0001
#define IPV6_MAXPLEN 65535
#define CHECKSUM_COMPLETE 3
#define CHECKSUM_NONE 0
#define CHECKSUM_UNNECESSARY 1

#define IPSTATS_MIB_INHDRERRORS 0
#define IPSTATS_MIB_REASMFAILS 1
#define ICMPV6_HDR_FIELD 0

struct ip6_frags {
    struct list_head lru_list;
    int lock;
};

static struct ip6_frags ip6_frags;

static inline void write_lock(int *lock) {}
static inline void write_unlock(int *lock) {}
static inline void list_move_tail(struct list_head *a, struct list_head *b) {}
static inline void atomic_add(int a, int *b) { *b += a; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void frag_kfree_skb(struct netns_frags *net, struct sk_buff *skb) {}
static inline int pskb_pull(struct sk_buff *skb, int len) { return 1; }
static inline int pskb_trim_rcsum(struct sk_buff *skb, int len) { return 0; }
static inline struct dst_entry *skb_dst(struct sk_buff *skb) { return skb->dst; }
static inline struct net *dev_net(struct net_device *dev) { return NULL; }
static inline void *ip6_dst_idev(struct dst_entry *dst) { return NULL; }
static inline void IP6_INC_STATS_BH(struct net *net, void *idev, int mib) {}
static inline void IP6_INC_STATS(struct net *net, void *idev, int mib) {}
static inline void icmpv6_param_prob(struct sk_buff *skb, int code, int pos) {}
static inline struct ipv6hdr *ipv6_hdr(struct sk_buff *skb) { return (struct ipv6hdr *)skb->network_header; }
static inline unsigned char *skb_network_header(struct sk_buff *skb) { return skb->network_header; }
static inline u32 csum_sub(u32 csum, u32 addend) { return 0; }
static inline u32 csum_partial(const void *buff, int len, u32 sum) { return 0; }
static inline int ip6_frag_reasm(struct frag_queue *fq, struct sk_buff *prev, struct net_device *dev) { return 0; }
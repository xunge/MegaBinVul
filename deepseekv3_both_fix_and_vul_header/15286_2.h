#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define CHECKSUM_COMPLETE 1
#define E2BIG 1
#define ENOMEM 2

struct sk_buff {
    struct sk_buff *next;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    uint32_t csum;
    uint8_t ip_summed;
    void *data;
    void *network_header;
    void *dev;
    unsigned long tstamp;
    char cb[0];
};

struct net_device {};
struct net {
    struct {
        struct {
            struct net *frags;
        } ipv4;
    };
    int mem;
};

struct ipq {
    struct {
        struct sk_buff *fragments;
        struct net *net;
        unsigned int len;
        unsigned long stamp;
    } q;
    uint32_t saddr;
};

struct iphdr {
    uint8_t frag_off;
    uint16_t tot_len;
};

struct skb_shared_info {
    struct sk_buff *frag_list;
    struct {
        int size;
    } frags[0];
    int nr_frags;
};

#define skb_shinfo(skb) ((struct skb_shared_info *)((char*)(skb) + sizeof(struct sk_buff)))

struct ipfrag_skb_cb {
    int offset;
};

#define FRAG_CB(skb) ((struct ipfrag_skb_cb *)((skb)->cb))

static inline int ip_hdrlen(const struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) { return NULL; }
static inline void skb_morph(struct sk_buff *dst, struct sk_buff *src) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int skb_cloned(const struct sk_buff *skb) { return 0; }
static inline int pskb_expand_head(struct sk_buff *skb, int a, int b, int c) { return 0; }
static inline int skb_has_frags(const struct sk_buff *skb) { return 0; }
static inline struct sk_buff *alloc_skb(int size, int flags) { return NULL; }
static inline void skb_frag_list_init(struct sk_buff *skb) {}
static inline void skb_push(struct sk_buff *skb, int len) {}
static inline struct net *dev_net(const struct net_device *dev) { return NULL; }
static inline void ipq_kill(struct ipq *qp) {}
static inline uint16_t htons(uint16_t x) { return x; }
static inline void atomic_add(int i, int *v) { *v += i; }
static inline void atomic_sub(int i, int *v) { *v -= i; }
static inline void *skb_network_header(const struct sk_buff *skb) { return NULL; }
static inline uint32_t csum_add(uint32_t csum, uint32_t addend) { return 0; }
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return NULL; }

#define WARN_ON(cond) 
#define LIMIT_NETDEBUG(fmt, ...) 
#define net_ratelimit() 0
#define printk(fmt, ...) 
#define IP_INC_STATS_BH(net, field) 
#define IPSTATS_MIB_REASMOKS 0
#define IPSTATS_MIB_REASMFAILS 0

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
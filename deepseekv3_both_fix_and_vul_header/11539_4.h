#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *network_header;
    unsigned char *transport_header;
    unsigned char *mac_header;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    unsigned short ip_defrag_offset;
    u8 ip_summed;
    u16 csum;
    u8 ignore_df;
    struct sk_buff *next;
    void *sk;
    void *dev;
    unsigned long tstamp;
};

struct skb_shared_info {
    struct sk_buff *frag_list;
    unsigned int nr_frags;
    void *frags;
};

struct skb_frag {
    unsigned int size;
};

struct net_device {
    // minimal definition
};

struct net {
    // minimal definition
};

struct rb_root {
    int dummy;
};

#define RB_ROOT (struct rb_root){0}

struct inet_frag_queue {
    struct sk_buff *fragments;
    struct rb_root rb_fragments;
    struct sk_buff *fragments_tail;
    unsigned int len;
    unsigned int max_size;
    struct net *net;
    unsigned long stamp;
};

struct frag_queue {
    struct inet_frag_queue q;
    u8 ecn;
    int nhoffset;
};

struct frag_hdr {
    u8 nexthdr;
    u8 reserved;
    u16 frag_off;
    u32 identification;
};

struct ipv6hdr {
    u8 priority;
    u8 flow_lbl[3];
    u16 payload_len;
    u8 nexthdr;
    u8 hop_limit;
    u8 saddr[16];
    u8 daddr[16];
};

struct ipv6_cb {
    unsigned int frag_max_size;
};

#define IPV6_MAXPLEN 65535
#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define CHECKSUM_COMPLETE 1

extern u8 ip_frag_ecn_table[];

static inline void WARN_ON(bool condition) {}
static inline bool unlikely(bool x) { return x; }
static inline void inet_frag_kill(struct inet_frag_queue *q) {}
static inline bool skb_unclone(struct sk_buff *skb, int flags) { return false; }
static inline bool skb_has_frag_list(struct sk_buff *skb) { return false; }
static inline void skb_frag_list_init(struct sk_buff *skb) {}
static inline void add_frag_mem_limit(struct net *net, unsigned int size) {}
static inline void sub_frag_mem_limit(struct net *net, unsigned int size) {}
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) { return NULL; }
static inline void skb_morph(struct sk_buff *dst, struct sk_buff *src) {}
static inline void consume_skb(struct sk_buff *skb) {}
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline unsigned char *skb_push(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline u16 htons(u16 val) { return val; }
static inline u32 csum_add(u32 csum, u32 addend) { return csum + addend; }
static inline u32 csum_partial(const void *buff, int len, u32 sum) { return 0; }
static inline void ipv6_change_dsfield(struct ipv6hdr *ipv6h, u8 mask, u8 ecn) {}
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return (void*)0; }
static inline unsigned int skb_frag_size(void *frag) { return 0; }
static inline unsigned char *skb_network_header(struct sk_buff *skb) { return skb->network_header; }
static inline unsigned char *skb_transport_header(struct sk_buff *skb) { return skb->transport_header; }
static inline void net_dbg_ratelimited(const char *fmt, ...) {}
static inline struct sk_buff *alloc_skb(int size, int flags) { return NULL; }
static inline struct ipv6hdr *ipv6_hdr(struct sk_buff *skb) { return (void*)0; }
static inline struct ipv6_cb *IP6CB(struct sk_buff *skb) { return (void*)0; }
static inline unsigned int skb_network_header_len(struct sk_buff *skb) { return 0; }
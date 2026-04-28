#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t __u16;
typedef uint16_t __sum16;
typedef uint8_t u8;

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct net_device;
struct sock;
struct net;

struct netns_frags {
    int dummy;
};

struct skb_frag_struct {
    unsigned int size;
    unsigned int offset;
};

struct sk_buff {
    struct rb_node rbnode;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    __u16 ip_summed;
    __u16 ip_defrag_offset;
    __sum16 csum;
    struct sk_buff *next;
    struct sk_buff *prev;
    struct net_device *dev;
    unsigned long tstamp;
    void *data;
    void *network_header;
    struct skb_shared_info *shinfo;
    struct sock *sk;
    char cb[48];
};

struct skb_shared_info {
    struct sk_buff *frag_list;
    int nr_frags;
    struct skb_frag_struct frags[];
};

struct ipq {
    struct {
        struct net *net;
        struct rb_root rb_fragments;
        struct sk_buff *fragments;
        struct sk_buff *fragments_tail;
        struct sk_buff *last_run_head;
        int len;
        int max_size;
        struct {
            struct {
                uint32_t saddr;
            } v4;
        } key;
        uint32_t ecn;
        uint32_t max_df_size;
        unsigned long stamp;
    } q;
    uint32_t max_df_size;
    uint8_t ecn;
};

struct iphdr {
    uint8_t tos;
    uint16_t tot_len;
    uint16_t frag_off;
};

struct ipfrag_skb_cb {
    struct sk_buff *next_frag;
};

struct net {
    struct {
        struct {
            struct netns_frags frags;
        } ipv4;
    };
};

struct inet_skb_parm {
    int frag_max_size;
    int flags;
};

enum {
    IPSTATS_MIB_REASMOKS,
    IPSTATS_MIB_REASMFAILS
};

#define FRAG_CB(skb) ((struct ipfrag_skb_cb *)((skb)->cb))
#define RB_EMPTY_NODE(node) (0)
#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define CHECKSUM_COMPLETE 1
#define IP_DF 0x4000
#define EINVAL 22
#define ENOMEM 12
#define E2BIG 7
#define RB_ROOT ((struct rb_root){ NULL })
#define WARN_ON(condition) ((void)0)
#define unlikely(x) (x)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define IPSKB_FRAG_PMTU (1 << 0)

static uint8_t ip_frag_ecn_table[256];

static inline struct sk_buff *skb_rb_first(struct rb_root *root) { return NULL; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int gfp) { return NULL; }
static inline void consume_skb(struct sk_buff *skb) {}
static inline int skb_unclone(struct sk_buff *skb, int gfp) { return 0; }
static inline struct sk_buff *alloc_skb(int size, int gfp) { return NULL; }
static inline void skb_frag_list_init(struct sk_buff *skb) {}
static inline void skb_push(struct sk_buff *skb, int len) {}
static inline void rb_replace_node(struct rb_node *old, struct rb_node *new, struct rb_root *root) {}
static inline struct rb_node *rb_next(const struct rb_node *node) { return NULL; }
static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline struct sk_buff *rb_to_skb(struct rb_node *node) { return NULL; }
static inline void ip_send_check(struct iphdr *iph) {}
static inline void __IP_INC_STATS(struct net *net, int stat) {}
static inline void add_frag_mem_limit(struct net *net, int size) {}
static inline void sub_frag_mem_limit(struct net *net, int size) {}
static inline void skb_morph(struct sk_buff *skb, struct sk_buff *new) {}
static inline int ip_hdrlen(const struct sk_buff *skb) { return 0; }
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return NULL; }
static inline int skb_has_frag_list(const struct sk_buff *skb) { return 0; }
static inline uint16_t htons(uint16_t x) { return x; }
static inline void ipq_kill(struct ipq *qp) {}
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return (struct skb_shared_info *)(skb + 1); }
static inline unsigned int skb_frag_size(const struct skb_frag_struct *frag) { return frag->size; }
static inline void *skb_network_header(const struct sk_buff *skb) { return skb->network_header; }
static inline __sum16 csum_add(__sum16 csum, __sum16 addend) { return csum + addend; }
static inline struct inet_skb_parm *IPCB(const struct sk_buff *skb) { return (struct inet_skb_parm *)(skb->cb); }
static inline int max(int a, int b) { return a > b ? a : b; }
static inline void net_dbg_ratelimited(const char *fmt, ...) {}
static inline void net_info_ratelimited(const char *fmt, ...) {}
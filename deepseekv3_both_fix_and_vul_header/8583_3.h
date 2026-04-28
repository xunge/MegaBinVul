#include <stdint.h>
#include <stddef.h>

typedef uint16_t __be16;
typedef uint32_t __wsum;

#define NETIF_F_GRO (1 << 22)
#define CHECKSUM_COMPLETE 1
#define CHECKSUM_UNNECESSARY 2

enum gro_result {
    GRO_NORMAL,
    GRO_MERGED,
    GRO_MERGED_FREE,
    GRO_HELD
};

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (typeof(*pos)*)(head)->next; \
         &pos->member != (head); \
         pos = (typeof(*pos)*)pos->member.next)

struct napi_struct {
    struct sk_buff *gro_list;
    int gro_count;
};

struct packet_offload {
    __be16 type;
    struct list_head list;
    struct {
        struct sk_buff *(*gro_receive)(struct sk_buff **, struct sk_buff *);
    } callbacks;
};

struct sk_buff {
    __be16 protocol;
    struct net_device *dev;
    unsigned int ip_summed;
    unsigned int csum_level;
    unsigned int csum_bad;
    __wsum csum;
    struct sk_buff *next;
    unsigned char *head;
    unsigned char *data;
    unsigned int len;
    struct skb_shared_info *shinfo;
    char cb[48];
};

struct net_device {
    unsigned long features;
};

struct skb_shared_info {
    unsigned int gso_size;
};

struct napi_gro_cb {
    int same_flow;
    int flush;
    int free;
    int encap_mark;
    int udp_mark;
    unsigned int gro_remcsum_start;
    __wsum csum;
    int csum_valid;
    int csum_cnt;
    int count;
    unsigned long age;
    struct sk_buff *last;
};

#define NAPI_GRO_CB(skb) ((struct napi_gro_cb *)(skb)->cb)

#define LIST_HEAD_INIT(name) { &(name), &(name) }
struct list_head offload_base = LIST_HEAD_INIT(offload_base);

#define MAX_GRO_SKBS 8
#define unlikely(x) (x)

static unsigned long jiffies = 0;

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline int skb_is_gso(struct sk_buff *skb) { return 0; }
static inline int skb_has_frag_list(struct sk_buff *skb) { return 0; }
static inline void gro_list_prepare(struct napi_struct *napi, struct sk_buff *skb) {}
static inline void napi_gro_complete(struct sk_buff *skb) {}
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return (struct skb_shared_info *)0; }
static inline unsigned int skb_gro_len(struct sk_buff *skb) { return 0; }
static inline unsigned int skb_gro_offset(struct sk_buff *skb) { return 0; }
static inline unsigned int skb_headlen(struct sk_buff *skb) { return 0; }
static inline void gro_pull_from_frag0(struct sk_buff *skb, int grow) {}
static inline void skb_set_network_header(struct sk_buff *skb, int offset) {}
static inline void skb_reset_mac_len(struct sk_buff *skb) {}
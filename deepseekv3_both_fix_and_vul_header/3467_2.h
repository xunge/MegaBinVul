#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint16_t __be16;
typedef uint32_t __u32;
typedef uint8_t u8;
typedef unsigned int netdev_features_t;
typedef unsigned int gfp_t;

#define NETIF_F_SG 0
#define MAX_SKB_FRAGS 0
#define NUMA_NO_NODE 0
#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define SKBTX_SHARED_FRAG 0
#define ENOMEM 1
#define EINVAL 2

struct sk_buff {
    unsigned int len;
    unsigned int data_len;
    unsigned int mac_len;
    unsigned int truesize;
    unsigned char *data;
    unsigned char *head;
    unsigned char *mac_header;
    __be16 ip_summed;
    __u32 csum;
    struct sk_buff *next;
};

struct skb_shared_info {
    unsigned short nr_frags;
    void *frags;
    struct sk_buff *frag_list;
    unsigned int gso_size;
    unsigned int tx_flags;
};

struct skb_frag_struct {
    unsigned int page_offset;
    unsigned int size;
};
typedef struct skb_frag_struct skb_frag_t;

#define skb_shinfo(skb) ((struct skb_shared_info *)(skb->head))
#define skb_headlen(skb) ((skb)->len - (skb)->data_len)
#define skb_end_offset(skb) (0)
#define skb_headroom(skb) (0)
#define skb_mac_header(skb) ((skb)->mac_header)
#define skb_network_protocol(skb) (0)
#define skb_tnl_header_len(skb) (0)
#define skb_alloc_rx_flag(skb) (0)
#define skb_headers_offset_update(skb, offset) do {} while (0)
#define skb_release_head_state(skb) do {} while (0)

static inline void *ERR_PTR(long error) { return (void *)error; }
static inline long PTR_ERR(const void *ptr) { return (long)ptr; }
static inline bool IS_ERR(const void *ptr) { return (unsigned long)ptr > (unsigned long)-1000L; }

#define unlikely(x) (x)
#define BUG_ON(condition) do { if (condition) {} } while (0)

static inline void __skb_push(struct sk_buff *skb, unsigned int len) {}
static inline void __skb_put(struct sk_buff *skb, unsigned int len) {}
static inline unsigned char *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }

static inline struct sk_buff *skb_clone(struct sk_buff *skb, gfp_t pri) { return NULL; }
static inline int pskb_trim(struct sk_buff *skb, unsigned int len) { return 0; }
static inline int skb_cow_head(struct sk_buff *skb, unsigned int headroom) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void kfree_skb_list(struct sk_buff *segs) {}

static inline void __copy_skb_header(struct sk_buff *new, const struct sk_buff *old) {}
static inline void skb_copy_from_linear_data_offset(const struct sk_buff *skb, int offset, void *to, int len) {}
static inline __u32 skb_copy_and_csum_bits(const struct sk_buff *skb, int offset, u8 *to, int len, __u32 csum) { return 0; }
static inline __u32 skb_checksum(const struct sk_buff *skb, int offset, int len, __u32 csum) { return 0; }
static inline void __skb_frag_ref(skb_frag_t *frag) {}
static inline void skb_frag_size_sub(skb_frag_t *frag, int delta) {}
static inline unsigned int skb_frag_size(const skb_frag_t *frag) { return frag->size; }

static inline bool can_checksum_protocol(netdev_features_t features, __be16 protocol) { return false; }
static inline struct sk_buff *__alloc_skb(unsigned int size, gfp_t priority, int flags, int node) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}

#define net_warn_ratelimited(fmt, ...) do {} while (0)
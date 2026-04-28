#include <stdint.h>
#include <stddef.h>

typedef uint16_t __be16;
typedef uint32_t __be32;

struct sk_buff {
    struct sk_buff *next;
    void *data;
    unsigned int len;
};

struct gre_base_hdr {
    uint16_t flags;
    uint16_t protocol;
};

struct packet_offload {
    struct {
        struct sk_buff **(*gro_receive)(struct sk_buff **, struct sk_buff *);
    } callbacks;
};

struct napi_gro_cb {
    int encap_mark;
    int flush;
    int same_flow;
};

#define GRE_KEY 0x2000
#define GRE_CSUM 0x4000
#define GRE_HEADER_SECTION 4
#define IPPROTO_GRE 47
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

static inline unsigned int skb_gro_offset(const struct sk_buff *skb) { return 0; }
static inline struct gre_base_hdr *skb_gro_header_fast(struct sk_buff *skb, unsigned int off) { return (struct gre_base_hdr *)(skb->data + off); }
static inline int skb_gro_header_hard(struct sk_buff *skb, unsigned int hlen) { return 0; }
static inline struct gre_base_hdr *skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen, unsigned int off) { return (struct gre_base_hdr *)(skb->data + off); }
static inline void skb_gro_pull(struct sk_buff *skb, unsigned int len) { skb->data += len; skb->len -= len; }
static inline void skb_gro_postpull_rcsum(struct sk_buff *skb, const void *hdr, unsigned int len) {}
static inline int skb_gro_checksum_simple_validate(struct sk_buff *skb) { return 0; }
static inline void skb_gro_checksum_try_convert(struct sk_buff *skb, int proto, int offset, void (*compute)(void)) {}
static inline struct packet_offload *gro_find_receive_by_type(uint16_t type) { return NULL; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct napi_gro_cb *NAPI_GRO_CB(struct sk_buff *skb) { return (struct napi_gro_cb *)skb; }
static inline void null_compute_pseudo(void) {}
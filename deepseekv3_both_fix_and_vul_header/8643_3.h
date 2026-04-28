#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint32_t __be32;

struct sk_buff {
    void *data;
    unsigned int len;
};

struct net_device_stats {
    unsigned long rx_dropped;
};

struct net_device {
    struct net_device_stats stats;
};

struct list_head {
    struct list_head *next, *prev;
};

struct fwnet_partial_datagram {
    struct sk_buff *skb;
    u16 ether_type;
    int datagram_size;
    struct list_head pd_link;
};

struct fwnet_peer {
    struct list_head pd_list;
    int pdg_size;
};

typedef struct {
    int lock;
} spinlock_t;

struct fwnet_device {
    struct net_device *netdev;
    spinlock_t lock;
};

struct rfc2734_header {
    uint32_t w0;
    uint32_t w1;
};

#define RFC2374_HDR_UNFRAG 0
#define RFC2374_HDR_FIRSTFRAG 1
#define RFC2374_UNFRAG_HDR_SIZE 4
#define RFC2374_FRAG_HDR_SIZE 8
#define FWNET_MAX_FRAGMENTS 16
#define ENOMEM 12
#define ENOENT 2

static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint32_t ntohl(uint32_t x) { return x; }

static inline u16 fwnet_get_hdr_lf(struct rfc2734_header *hdr) { return 0; }
static inline u16 fwnet_get_hdr_ether_type(struct rfc2734_header *hdr) { return 0; }
static inline int fwnet_get_hdr_fg_off(struct rfc2734_header *hdr) { return 0; }
static inline u16 fwnet_get_hdr_dgl(struct rfc2734_header *hdr) { return 0; }
static inline int fwnet_get_hdr_dg_size(struct rfc2734_header *hdr) { return 0; }
static bool fwnet_frag_overlap(struct fwnet_partial_datagram *pd, int fg_off, int len) { return false; }
static struct fwnet_peer *fwnet_peer_find_by_node_id(struct fwnet_device *dev, int source_node_id, int generation) { return NULL; }
static struct fwnet_partial_datagram *fwnet_pd_find(struct fwnet_peer *peer, u16 datagram_label) { return NULL; }
static void fwnet_pd_delete(struct fwnet_partial_datagram *pd) {}
static struct fwnet_partial_datagram *fwnet_pd_new(struct net_device *net, struct fwnet_peer *peer, u16 datagram_label, int dg_size, __be32 *buf, int fg_off, int len) { return NULL; }
static bool fwnet_pd_update(struct fwnet_peer *peer, struct fwnet_partial_datagram *pd, __be32 *buf, int fg_off, int len) { return false; }
static bool fwnet_pd_is_complete(struct fwnet_partial_datagram *pd) { return false; }
static int fwnet_finish_incoming_packet(struct net_device *net, struct sk_buff *skb, int source_node_id, bool is_broadcast, u16 ether_type) { return 0; }

struct sk_buff *dev_alloc_skb(unsigned int size);
void skb_reserve(struct sk_buff *skb, int len);
void *skb_put(struct sk_buff *skb, unsigned int len);
struct sk_buff *skb_get(struct sk_buff *skb);

#define unlikely(x) (x)
#define LL_RESERVED_SPACE(x) 0

static inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) { (void)lock; (void)flags; }

#define list_first_entry(ptr, type, member) \
    ((type *)((char *)((ptr)->next) - offsetof(type, member)))
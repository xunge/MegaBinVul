#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct mtk_ppe {
    struct hlist_head *foe_flow;
    struct mtk_foe_entry *foe_table;
    void *l2_flows;
};

struct mtk_foe_entry {
    u32 ib1;
};

struct mtk_flow_entry {
    u16 hash;
    u8 type;
    void *data;
    struct hlist_node *list;
};

struct mtk_foe_bridge {
    u8 dest_mac[6];
    u8 src_mac[6];
    u16 vlan;
};

struct sk_buff {
    u8 *data;
    u16 protocol;
    struct net_device *dev;
};

struct net_device {
    void *dsa_ptr;
};

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct rhashtable_params {
    int dummy;
};

extern int ppe_lock;
extern const struct rhashtable_params mtk_flow_l2_ht_params;

#define MTK_FOE_IB1_STATE 0
#define MTK_FOE_STATE_BIND 0
#define MTK_FLOW_TYPE_L2_SUBFLOW 0
#define VLAN_VID_MASK 0
#define ETH_ALEN 6

#define FIELD_GET(mask, reg) 0
#define IS_ENABLED(x) 0
#define fallthrough
#define htons(x) 0
#define ETH_P_XDSA 0
#define ETH_P_8021Q 0
#define DSA_TAG_PROTO_MTK 0
#define unlikely(x) (x)

struct ethhdr {
    u8 h_dest[ETH_ALEN];
    u8 h_source[ETH_ALEN];
};

static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void ether_addr_copy(u8 *dst, const u8 *src) {}
static inline struct ethhdr *eth_hdr(const struct sk_buff *skb) { return NULL; }
static inline bool netdev_uses_dsa(const struct net_device *dev) { return false; }
static inline u16 get_unaligned_be16(const void *p) { return 0; }

static inline void __mtk_foe_entry_clear(struct mtk_ppe *ppe, struct mtk_flow_entry *entry) {}
static inline void __mtk_foe_entry_commit(struct mtk_ppe *ppe, void *data, u16 hash) {}
static inline bool mtk_flow_entry_match(struct mtk_flow_entry *entry, struct mtk_foe_entry *hwe) { return false; }
static inline void mtk_foe_entry_commit_subflow(struct mtk_ppe *ppe, struct mtk_flow_entry *entry, u16 hash) {}

static inline void *rhashtable_lookup_fast(void *ht, const void *key, const struct rhashtable_params params) { return NULL; }

#define hlist_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define hlist_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != NULL; pos = NULL)
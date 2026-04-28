#include <stdint.h>
#include <string.h>

typedef unsigned int netdev_tx_t;
#define NETDEV_TX_OK 0

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char cb[48];
    unsigned short protocol;
    unsigned int priority;
};

struct net_device {
    void *ieee80211_ptr;
};

struct list_head {
    struct list_head *next, *prev;
};

struct cfg80211_chan_def {
    struct {
        unsigned int band;
    } *chan;
};

struct ieee80211_local {
    struct list_head interfaces;
    struct ieee80211_sub_if_data *monitor_sdata;
    int use_chanctx;
    struct {
        void *wiphy;
    } hw;
    struct cfg80211_chan_def _oper_chandef;
};

struct ieee80211_chanctx_conf {
    struct cfg80211_chan_def def;
};

struct ieee80211_tx_info {
    unsigned int flags;
    unsigned int band;
};

struct ieee80211_hdr {
    uint16_t frame_control;
    uint8_t addr2[6];
};

struct ieee80211_sub_if_data {
    struct {
        int type;
        uint8_t addr[6];
        struct ieee80211_chanctx_conf *chanctx_conf;
    } vif;
    struct list_head list;
};

typedef uint16_t __le16;
typedef uint16_t __be16;
typedef uint8_t u8;
typedef uint16_t u16;

#define IEEE80211_SKB_CB(skb) ((struct ieee80211_tx_info *)((skb)->cb))
#define IEEE80211_TX_CTL_REQ_TX_STATUS (1 << 0)
#define IEEE80211_TX_CTL_INJECTED (1 << 1)
#define NL80211_IFTYPE_MONITOR 6
#define NL80211_IFTYPE_AP_VLAN 8

static const uint8_t rfc1042_header[6] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00};

static inline struct ieee80211_local *wdev_priv(void *ptr) { return (struct ieee80211_local *)ptr; }
static inline int ieee80211_parse_tx_radiotap(struct sk_buff *skb, struct net_device *dev) { return 1; }
static inline int ieee80211_get_radiotap_len(const void *data) { return 0; }
static inline void skb_set_mac_header(struct sk_buff *skb, int offset) {}
static inline void skb_set_network_header(struct sk_buff *skb, int offset) {}
static inline void skb_set_transport_header(struct sk_buff *skb, int offset) {}
static inline int ieee80211_hdrlen(__le16 fc) { return 24; }
static inline int ieee80211_is_data(__le16 fc) { return 1; }
static inline int ether_addr_equal(const void *addr1, const void *addr2) { return 1; }
static inline __be16 cpu_to_be16(u16 val) { return val; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void dev_kfree_skb(struct sk_buff *skb) {}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline void ieee80211_xmit(struct ieee80211_sub_if_data *sdata, void *sta, struct sk_buff *skb) {}
static inline void ieee80211_select_queue_80211(struct ieee80211_sub_if_data *sdata, struct sk_buff *skb, struct ieee80211_hdr *hdr) {}
static inline int ieee80211_ac_from_tid(int tid) { return 0; }
static inline int cfg80211_reg_can_beacon(void *wiphy, struct cfg80211_chan_def *chandef, int iftype) { return 1; }
static inline struct ieee80211_sub_if_data *IEEE80211_DEV_TO_SUB_IF(struct net_device *dev) { return NULL; }
static inline int ieee80211_sdata_running(struct ieee80211_sub_if_data *sdata) { return 1; }
static inline void skb_set_queue_mapping(struct sk_buff *skb, int queue_mapping) {}

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (typeof(*pos)*)(head); pos; pos = NULL)
#define rcu_dereference(p) (p)
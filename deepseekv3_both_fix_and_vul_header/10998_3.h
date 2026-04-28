#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t u8;

struct wiphy;
struct net_device;

struct station_parameters {
    struct net_device *vlan;
    unsigned int sta_flags_set;
};

struct ieee80211_local;

struct sta_info {
    struct {
        bool tdls;
        u8 addr[6];
    } sta;
    struct ieee80211_sub_if_data *sdata;
};

struct ieee80211_sub_if_data {
    struct net_device *dev;
    struct {
        int type;
        u8 addr[6];
    } vif;
    union {
        struct {
            bool associated;
        } mgd;
    } u;
};

#define IEEE80211_DEV_TO_SUB_IF(dev) \
    ((struct ieee80211_sub_if_data *)dev)

#define GFP_KERNEL 0
#define EINVAL 1
#define ENOMEM 2

#define BIT(nr) (1U << (nr))

enum {
    NL80211_IFTYPE_AP,
    NL80211_IFTYPE_AP_VLAN,
    NL80211_IFTYPE_STATION,
    NL80211_STA_FLAG_TDLS_PEER,
    WLAN_STA_TDLS_PEER,
    WLAN_STA_ASSOC
};

static inline bool ether_addr_equal(const u8 *addr1, const u8 *addr2)
{
    return false;
}

static inline bool is_multicast_ether_addr(const u8 *addr)
{
    return false;
}

static inline void *wiphy_priv(struct wiphy *wiphy)
{
    return NULL;
}

static inline struct sta_info *sta_info_alloc(struct ieee80211_sub_if_data *sdata, const u8 *mac, int gfp)
{
    return NULL;
}

static inline void sta_info_free(struct ieee80211_local *local, struct sta_info *sta)
{
}

static inline int sta_apply_parameters(struct ieee80211_local *local, struct sta_info *sta, struct station_parameters *params)
{
    return 0;
}

static inline void rate_control_rate_init(struct sta_info *sta)
{
}

static inline int sta_info_insert_rcu(struct sta_info *sta)
{
    return 0;
}

static inline void cfg80211_send_layer2_update(struct net_device *dev, const u8 *addr)
{
}

static inline void rcu_read_unlock(void)
{
}

static inline bool test_sta_flag(struct sta_info *sta, int flag)
{
    return false;
}
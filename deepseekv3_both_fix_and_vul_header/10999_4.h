#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

struct wiphy;
struct ieee80211_local;
struct sta_info;

struct ieee80211_ptr {
    int use_4addr;
};

struct net_device {
    struct ieee80211_ptr *ieee80211_ptr;
};

struct station_parameters {
    struct net_device *vlan;
    unsigned int sta_flags_mask;
};

struct bss_conf {
    void *bssid;
};

struct bss {
    void *req_smps;
};

struct ieee80211_sub_if_data {
    struct {
        struct {
            struct sta_info *sta;
        } vlan;
        struct {
            int user_mpm;
        } mesh;
    } u;
    struct net_device *dev;
    struct {
        int type;
        struct bss_conf bss_conf;
    } vif;
    struct bss *bss;
};

struct sta_info {
    struct ieee80211_sub_if_data *sdata;
    struct {
        u8 addr[6];
    } sta;
    int known_smps_mode;
};

enum cfg80211_station_type {
    CFG80211_STA_MESH_PEER_USER,
    CFG80211_STA_MESH_PEER_KERNEL,
    CFG80211_STA_IBSS,
    CFG80211_STA_AP_STA,
    CFG80211_STA_TDLS_PEER_ACTIVE,
    CFG80211_STA_TDLS_PEER_SETUP,
    CFG80211_STA_AP_CLIENT,
    CFG80211_STA_AP_CLIENT_UNASSOC
};

enum nl80211_iftype {
    NL80211_IFTYPE_MESH_POINT,
    NL80211_IFTYPE_ADHOC,
    NL80211_IFTYPE_STATION,
    NL80211_IFTYPE_AP,
    NL80211_IFTYPE_AP_VLAN
};

#define IEEE80211_DEV_TO_SUB_IF(dev) ((struct ieee80211_sub_if_data *)dev)
#define wiphy_priv(wiphy) ((struct ieee80211_local *)wiphy)
#define ENOENT 2
#define EOPNOTSUPP 95
#define EBUSY 16

#define mutex_lock(lock) 
#define mutex_unlock(lock) 

#define test_sta_flag(sta, flag) (0)
#define WLAN_STA_TDLS_PEER (0)
#define WLAN_STA_AUTHORIZED (0)
#define WLAN_STA_ASSOC (0)
#define BIT(n) (1 << (n))
#define NL80211_STA_FLAG_AUTHORIZED (0)

#define RCU_INIT_POINTER(p, v) (p = v)
#define rcu_assign_pointer(p, v) (p = v)

static inline struct sta_info *sta_info_get_bss(struct ieee80211_sub_if_data *sdata, const u8 *mac) { return NULL; }
static inline int cfg80211_check_station_change(struct wiphy *wiphy, struct station_parameters *params, enum cfg80211_station_type statype) { return 0; }
static inline void __ieee80211_check_fast_rx_iface(struct ieee80211_sub_if_data *sdata) {}
static inline void ieee80211_vif_dec_num_mcast(struct ieee80211_sub_if_data *sdata) {}
static inline void ieee80211_check_fast_xmit(struct sta_info *sta) {}
static inline void ieee80211_vif_inc_num_mcast(struct ieee80211_sub_if_data *sdata) {}
static inline void cfg80211_send_layer2_update(struct net_device *dev, u8 *addr) {}
static inline int sta_apply_parameters(struct ieee80211_local *local, struct sta_info *sta, struct station_parameters *params) { return 0; }
static inline int sta_info_tx_streams(struct sta_info *sta) { return 0; }
static inline void ht_dbg(struct ieee80211_sub_if_data *sdata, const char *fmt, ...) {}
static inline void ieee80211_send_smps_action(struct ieee80211_sub_if_data *sdata, void *req_smps, u8 *addr, void *bssid) {}
static inline void ieee80211_recalc_ps(struct ieee80211_local *local) {}
static inline void ieee80211_recalc_ps_vif(struct ieee80211_sub_if_data *sdata) {}
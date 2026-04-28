#include <stdbool.h>
#include <stdint.h>

enum ieee80211_sta_state {
    IEEE80211_STA_NONE,
    IEEE80211_STA_AUTH,
    IEEE80211_STA_ASSOC,
    IEEE80211_STA_AUTHORIZED
};

enum nl80211_iftype {
    NL80211_IFTYPE_AP_VLAN,
    NL80211_IFTYPE_AP,
};

#define ETH_ALEN 6

struct net_device;

struct vif {
    enum nl80211_iftype type;
    struct net_device *dev;
};

struct sdata {
    struct vif vif;
    struct net_device *dev;
};

struct sta_info {
    uint8_t sta_state;
    struct {
        uint8_t addr[ETH_ALEN];
        bool support_p2p_ps;
    } sta;
    unsigned long _flags;
    struct sdata *sdata;
    void *local;
};

#define WLAN_STA_AUTH (1UL << 0)
#define WLAN_STA_ASSOC (1UL << 1)
#define WLAN_STA_AUTHORIZED (1UL << 2)
#define WLAN_STA_INSERTED (1UL << 3)

#define EINVAL 22

#define might_sleep()
#define WARN(cond, fmt, ...)
#define sta_dbg(sdata, fmt, ...)

static inline bool test_sta_flag(struct sta_info *sta, int flag)
{
    return (sta->_flags & (1UL << flag)) != 0;
}

static inline void set_bit(int nr, unsigned long *addr)
{
    *addr |= (1UL << nr);
}

static inline void clear_bit(int nr, unsigned long *addr)
{
    *addr &= ~(1UL << nr);
}

static int drv_sta_state(void *local, struct sdata *sdata, struct sta_info *sta,
             int old_state, int new_state)
{
    return 0;
}

void ieee80211_recalc_min_chandef(struct sdata *sdata);
void ieee80211_recalc_p2p_go_ps_allowed(struct sdata *sdata);
void ieee80211_vif_dec_num_mcast(struct sdata *sdata);
void ieee80211_vif_inc_num_mcast(struct sdata *sdata);
void ieee80211_clear_fast_xmit(struct sta_info *sta);
void ieee80211_clear_fast_rx(struct sta_info *sta);
void ieee80211_check_fast_xmit(struct sta_info *sta);
void ieee80211_check_fast_rx(struct sta_info *sta);
void cfg80211_send_layer2_update(struct net_device *dev, const uint8_t *addr);
#include <stdint.h>
#include <stddef.h>

#define WLAN_BACK_INITIATOR 0
#define WLAN_BACK_RECIPIENT 1
#define IEEE80211_DELBA_PARAM_TID_MASK 0xF000
#define IEEE80211_DELBA_PARAM_INITIATOR_MASK 0x0800
#define HT_ADDBA_REQUESTED_MSK 0x1
#define HT_AGG_STATE_OPERATIONAL 0x2
#define ETH_ALEN 6
#define CONFIG_MAC80211_HT_DEBUG 1
#define KERN_DEBUG ""
#define net_ratelimit() 1

typedef uint16_t u16;
typedef uint8_t u8;

struct spinlock {
    int dummy;
};
#define spin_lock_bh(lock) (void)0
#define spin_unlock_bh(lock) (void)0

struct sta_ampdu_mlme {
    u8 tid_state_tx[16];
};

struct ieee80211_hw {
    void *priv;
};

struct ieee80211_local {
    struct ieee80211_hw hw;
};

struct ieee80211_sub_if_data {
    struct ieee80211_local *local;
};

struct sta_info {
    struct sta_ampdu_mlme ampdu_mlme;
    struct spinlock lock;
    struct {
        u8 addr[ETH_ALEN];
    } sta;
};

struct ieee80211_mgmt {
    u8 sa[ETH_ALEN];
    union {
        struct {
            union {
                struct {
                    u16 params;
                    u16 reason_code;
                } delba;
            } u;
        } action;
    } u;
};

static inline u16 le16_to_cpu(u16 val) { return val; }

void ieee80211_sta_stop_rx_ba_session(struct ieee80211_sub_if_data *sdata, u8 *addr, u16 tid, int initiator, int dummy);
void ___ieee80211_stop_tx_ba_session(struct sta_info *sta, u16 tid, int recipient);
void ieee80211_stop_tx_ba_session(struct ieee80211_hw *hw, u8 *addr, u16 tid, int recipient);
int printk(const char *fmt, ...);
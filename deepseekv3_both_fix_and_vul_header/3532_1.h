#include <stdbool.h>
#include <stdint.h>

#define WLAN_STA_SP 0
#define IEEE80211_NUM_TIDS 8
#define IEEE80211_NUM_ACS 4
#define IEEE80211_HW_AP_LINK_PS (1 << 0)
#define STA_NOTIFY_AWAKE 0
#define ETH_ALEN 6

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    int qlen;
    int lock;
};

struct ieee80211_sta {
    uint8_t addr[ETH_ALEN];
    int aid;
};

struct ieee80211_hw {
    unsigned int flags;
};

struct ieee80211_bss_conf {
    uint8_t bssid[ETH_ALEN];
};

struct ieee80211_vif {
    struct ieee80211_bss_conf bss_conf;
};

struct ieee80211_bss {
    int req_smps;
};

struct ieee80211_local {
    struct ieee80211_hw hw;
    int total_ps_buffered;
};

struct ieee80211_sub_if_data {
    struct ieee80211_local *local;
    int smps_mode;
    struct ieee80211_bss *bss;
    struct ieee80211_vif vif;
};

struct sta_info {
    struct ieee80211_sub_if_data *sdata;
    struct ieee80211_sta sta;
    unsigned long driver_buffered_tids;
    int ps_lock;
    struct sk_buff_head tx_filtered[IEEE80211_NUM_ACS];
    struct sk_buff_head ps_tx_buf[IEEE80211_NUM_ACS];
    int known_smps_mode;
};

static inline void clear_sta_flag(struct sta_info *sta, int flag) {}
static inline void drv_sta_notify(struct ieee80211_local *local,
                                 struct ieee80211_sub_if_data *sdata,
                                 int notify, struct ieee80211_sta *sta) {}
static inline void skb_queue_head_init(struct sk_buff_head *list) {}
static inline int skb_queue_len(const struct sk_buff_head *list) { return 0; }
static inline void skb_queue_splice_tail_init(struct sk_buff_head *list,
                                            struct sk_buff_head *head) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void ieee80211_add_pending_skbs_fn(struct ieee80211_local *local,
                                                struct sk_buff_head *skbs,
                                                void (*fn)(void *), void *data) {}
static inline void clear_sta_ps_flags(void *data) {}
static inline bool ieee80211_smps_is_restrictive(int a, int b) { return false; }
static inline int sta_info_tx_streams(struct sta_info *sta) { return 0; }
static inline void ht_dbg(struct ieee80211_sub_if_data *sdata, const char *fmt, ...) {}
static inline void ieee80211_send_smps_action(struct ieee80211_sub_if_data *sdata,
                                             int smps, const uint8_t *da, const uint8_t *bssid) {}
static inline void sta_info_recalc_tim(struct sta_info *sta) {}
static inline void ps_dbg(struct ieee80211_sub_if_data *sdata, const char *fmt, ...) {}
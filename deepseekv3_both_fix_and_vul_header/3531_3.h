#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#define IEEE80211_NUM_TIDS 16
#define IEEE80211_NUM_ACS 4
#define ETH_ALEN 6
#define USHRT_MAX 65535
#define GFP_ATOMIC 0
#define NL80211_MESH_POWER_ACTIVE 0
#define IEEE80211_SMPS_OFF 0
#define IEEE80211_SMPS_STATIC 1
#define IEEE80211_SMPS_DYNAMIC 2
#define WLAN_HT_SMPS_CONTROL_DISABLED 0
#define WLAN_HT_SMPS_CONTROL_STATIC 1
#define WLAN_HT_SMPS_CONTROL_DYNAMIC 2
#define IEEE80211_HT_CAP_SM_PS 0
#define IEEE80211_HT_CAP_SM_PS_SHIFT 0
#define IEEE80211_STA_NONE 0
#define CONFIG_MAC80211_MESH 1

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef size_t gfp_t;

enum nl80211_iftype {
    NL80211_IFTYPE_AP,
    NL80211_IFTYPE_AP_VLAN,
};

struct work_struct {
    void *data;
};
struct mutex {
    void *data;
};
struct timer_list {
    void *data;
};
struct sk_buff_head {
    void *data;
};
struct ieee80211_vif {
    enum nl80211_iftype type;
};
struct ieee80211_ht_cap {
    u16 cap;
};
struct ieee80211_tx_latency_bin_ranges {
    u32 n_ranges;
};
struct wiphy {
    void *bands[4];
};
struct mesh_user_mpm {
    bool user_mpm;
};

struct ieee80211_sta {
    u8 addr[ETH_ALEN];
    u8 smps_mode;
};

struct sta_info {
    void *lock;
    void *ps_lock;
    struct work_struct drv_unblock_wk;
    struct {
        struct work_struct work;
        struct mutex mtx;
    } ampdu_mlme;
#ifdef CONFIG_MAC80211_MESH
    struct timer_list plink_timer;
    u8 nonpeer_pm;
#endif
    struct ieee80211_sta sta;
    struct ieee80211_local *local;
    struct ieee80211_sub_if_data *sdata;
    unsigned long last_rx;
    u8 sta_state;
    long last_connected;
    void *avg_signal;
    void *chain_signal_avg[4];
    struct ieee80211_tx_latency_stat *tx_lat;
    u8 timer_to_tid[IEEE80211_NUM_TIDS];
    struct sk_buff_head ps_tx_buf[IEEE80211_NUM_ACS];
    struct sk_buff_head tx_filtered[IEEE80211_NUM_ACS];
    u16 last_seq_ctrl[IEEE80211_NUM_TIDS];
    u8 known_smps_mode;
};

struct ieee80211_tx_latency_stat {
    u32 bin_count;
    u32 *bins;
};

struct ieee80211_sub_if_data {
    struct ieee80211_local *local;
    union {
        struct mesh_user_mpm mesh;
    } u;
    struct ieee80211_vif vif;
};

struct ieee80211_local {
    struct {
        size_t sta_data_size;
        struct wiphy *wiphy;
    } hw;
    struct ieee80211_tx_latency_bin_ranges *tx_latency;
};

struct ieee80211_supported_band {
    struct ieee80211_ht_cap ht_cap;
};

static inline void *kzalloc(size_t size, gfp_t flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void *kcalloc(size_t n, size_t size, gfp_t flags) { return NULL; }
static inline void spin_lock_init(void *lock) {}
static inline void INIT_WORK(struct work_struct *work, void *func) {}
static inline void mutex_init(struct mutex *lock) {}
static inline void init_timer(struct timer_list *timer) {}
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline void *rcu_dereference(void *p) { return p; }
static inline void sta_unblock(struct work_struct *work) {}
static inline void ieee80211_ba_session_work(struct work_struct *work) {}
static inline void sta_dbg(struct ieee80211_sub_if_data *sdata, const char *fmt, ...) {}
static inline int ieee80211_vif_is_mesh(struct ieee80211_vif *vif) { return 0; }
static inline int ieee80211_get_sdata_band(struct ieee80211_sub_if_data *sdata) { return 0; }
static inline int sta_prepare_rate_control(struct ieee80211_local *local, struct sta_info *sta, gfp_t gfp) { return 0; }
static inline void do_posix_clock_monotonic_gettime(struct timespec *ts) { ts->tv_sec = 0; }
static inline void ewma_init(void *avg, unsigned long factor, unsigned long weight) {}
static inline void skb_queue_head_init(struct sk_buff_head *list) {}
static inline u16 cpu_to_le16(u16 val) { return val; }
static inline void WARN_ON(int condition) {}
unsigned long jiffies;
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef uint32_t u32;
typedef int16_t s16;
typedef unsigned long long u64;
typedef unsigned long ulong;
typedef unsigned long gfp_t;

#define ETH_ALEN 6
#define WARN_ON(cond) (cond)
#define fallthrough

static unsigned long jiffies = 0;

#define rcu_assign_pointer(p, v) ((p) = (v))

enum cfg80211_bss_frame_type {
    CFG80211_BSS_FTYPE_UNKNOWN,
    CFG80211_BSS_FTYPE_BEACON,
    CFG80211_BSS_FTYPE_PRESP
};

enum nl80211_band {
    NL80211_BAND_2GHZ,
    NL80211_BAND_5GHZ,
    NL80211_BAND_60GHZ
};

enum cfg80211_signal_type {
    CFG80211_SIGNAL_TYPE_UNSPEC
};

struct ieee80211_channel {
    enum nl80211_band band;
};

struct cfg80211_bss_ies {
    size_t len;
    u64 tsf;
    bool from_beacon;
    u8 data[];
};

struct cfg80211_bss {
    u8 bssid[ETH_ALEN];
    struct ieee80211_channel *channel;
    u16 scan_width;
    s16 signal;
    u16 beacon_interval;
    u16 capability;
    struct cfg80211_bss *transmitted_bss;
    u8 bssid_index;
    u8 max_bssid_indicator;
    struct cfg80211_bss_ies *beacon_ies;
    struct cfg80211_bss_ies *proberesp_ies;
    struct cfg80211_bss_ies *ies;
};

struct cfg80211_internal_bss {
    struct cfg80211_bss pub;
    ulong ts;
    u64 ts_boottime;
    u64 parent_tsf;
    u8 parent_bssid[ETH_ALEN];
};

struct cfg80211_non_tx_bss {
    struct cfg80211_bss *tx_bss;
    u8 bssid_index;
    u8 max_bssid_indicator;
};

struct cfg80211_inform_bss {
    struct ieee80211_channel *chan;
    u16 scan_width;
    s16 signal;
    u64 boottime_ns;
    u64 parent_tsf;
    u8 parent_bssid[ETH_ALEN];
};

struct cfg80211_registered_device {
    ulong bss_lock;
    u32 bss_generation;
};

struct wiphy {
    enum cfg80211_signal_type signal_type;
};

#define WLAN_CAPABILITY_ESS (1<<0)
#define WLAN_CAPABILITY_DMG_TYPE_MASK (0x0F << 4)
#define WLAN_CAPABILITY_DMG_TYPE_AP (0 << 4)
#define WLAN_CAPABILITY_DMG_TYPE_PBSS (1 << 4)

static inline void *kzalloc(size_t size, gfp_t flags) { return NULL; }
static inline void ether_addr_copy(u8 *dst, const u8 *src) {}
static inline void spin_lock_bh(ulong *lock) {}
static inline void spin_unlock_bh(ulong *lock) {}
static inline struct cfg80211_internal_bss *bss_from_pub(struct cfg80211_bss *pub) { return NULL; }
static inline struct cfg80211_registered_device *wiphy_to_rdev(struct wiphy *wiphy) { return NULL; }
static inline struct cfg80211_internal_bss *cfg80211_bss_update(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *tmp, bool signal_valid, ulong ts) { return NULL; }
static inline bool cfg80211_add_nontrans_list(struct cfg80211_bss *tx_bss, struct cfg80211_bss *pub) { return false; }
static inline bool __cfg80211_unlink_bss(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *res) { return false; }
static inline void regulatory_hint_found_beacon(struct wiphy *wiphy, struct ieee80211_channel *channel, gfp_t gfp) {}
static inline struct ieee80211_channel *cfg80211_get_bss_channel(struct wiphy *wiphy, const u8 *ie, size_t ielen, struct ieee80211_channel *chan, u16 scan_width, enum cfg80211_bss_frame_type ftype) { return NULL; }
static inline void trace_cfg80211_return_bss(struct cfg80211_bss *pub) {}
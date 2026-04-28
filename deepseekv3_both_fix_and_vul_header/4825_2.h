#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ETH_ALEN 6
#define IEEE80211_MAX_SSID_LEN 32
#define WLAN_EID_SSID 0
#define WLAN_EID_TIM 5
#define WLAN_EID_SUPP_RATES 1
#define WLAN_EID_EXT_SUPP_RATES 50
#define WLAN_EID_HT_CAPABILITY 45
#define WLAN_EID_RSN 48
#define WLAN_OUI_MICROSOFT 0x0050f2
#define WLAN_OUI_TYPE_MICROSOFT_WMM 2
#define WLAN_OUI_TYPE_MICROSOFT_WPA 1
#define IEEE80211_P2P_ATTR_ABSENCE_NOTICE 0
#define IEEE80211_P2P_OPPPS_ENABLE_BIT 0x80
#define WILC_FW_BSS_TYPE_INFRA 0
#define WILC_MAX_RATES_SUPPORTED 12
#define GFP_KERNEL 0

typedef uint8_t u8;
typedef uint16_t __le16;
typedef uint32_t __le32;

struct element {
    u8 id;
    u8 len;
    u8 data[];
};

struct cfg80211_bss_ies {
    const u8 *data;
    size_t len;
    uint64_t tsf;
};

struct cfg80211_bss {
    uint16_t beacon_interval;
    uint16_t capability;
    struct {
        uint32_t center_freq;
    } *channel;
    u8 bssid[ETH_ALEN];
    struct cfg80211_bss_ies *ies;
};

struct cfg80211_crypto_settings {
    uint32_t cipher_group;
    uint32_t *ciphers_pairwise;
    uint32_t n_ciphers_pairwise;
    uint32_t *akm_suites;
    uint32_t n_akm_suites;
};

struct ieee80211_p2p_noa_attr {
    u8 index;
    u8 oppps_ctwindow;
    struct {
        uint32_t count;
        uint32_t duration;
        uint32_t interval;
        uint32_t start_time;
    } desc[1];
};

struct ieee80211_wmm_param_ie {
    u8 oui_subtype;
    u8 version;
    u8 qos_info;
};

struct wilc_join_bss_param {
    __le16 beacon_period;
    __le16 cap_info;
    u8 bss_type;
    u8 ch;
    u8 bssid[ETH_ALEN];
    u8 ssid[IEEE80211_MAX_SSID_LEN];
    u8 dtim_period;
    u8 p_suites[3];
    u8 akm_suites[3];
    u8 supp_rates[WILC_MAX_RATES_SUPPORTED + 1];
    bool ht_capable;
    __le32 tsf_lo;
    u8 noa_enabled;
    u8 idx;
    u8 opp_enabled;
    union {
        struct {
            u8 ct_window;
            uint32_t cnt;
            uint32_t duration;
            uint32_t interval;
            uint32_t start_time;
        } opp_en;
        struct {
            uint32_t cnt;
            uint32_t duration;
            uint32_t interval;
            uint32_t start_time;
        } opp_dis;
    };
    bool wmm_cap;
    bool uapsd_cap;
    u8 mode_802_11i;
    bool rsn_found;
    u8 rsn_cap[2];
    u8 rsn_grp_policy;
};

static inline __le16 cpu_to_le16(uint16_t val) { return val; }
static inline __le32 cpu_to_le32(uint32_t val) { return val; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void ether_addr_copy(u8 *dst, const u8 *src) { memcpy(dst, src, ETH_ALEN); }
static inline u8 ieee80211_frequency_to_channel(uint32_t freq) { return (freq - 2407) / 5; }
static inline const u8 *cfg80211_find_ie(u8 eid, const u8 *ies, int len) { return NULL; }
static inline const u8 *cfg80211_find_vendor_ie(unsigned int oui, u8 oui_type, const u8 *ies, int len) { return NULL; }
static inline int cfg80211_get_p2p_attr(const u8 *ies, int len, u8 attr, u8 *buf, int bufsize) { return 0; }
#define rcu_dereference(p) (p)
#define BIT(n) (1 << (n))
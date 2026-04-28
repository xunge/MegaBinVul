#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef int32_t s32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define EPERM 1
#define EINVAL 22

#define WLAN_EID_SSID 0
#define WLAN_EID_COUNTRY 7
#define WLAN_EID_RSN 48

#define DOT11_MGMT_HDR_LEN 24
#define DOT11_BCN_PRB_FIXED_LEN 12
#define IEEE80211_MAX_SSID_LEN 32

enum nl80211_iftype {
    NL80211_IFTYPE_AP = 2,
    NL80211_IFTYPE_P2P_GO = 6
};

struct brcmf_tlv {
    u8 id;
    u8 len;
    u8 data[];
};

struct brcmf_vs_tlv {
    u8 id;
    u8 len;
    u8 oui[3];
    u8 oui_type;
    u8 data[];
};

struct brcmf_ssid_le {
    u32 SSID_len;
    u8 SSID[32];
};

struct brcmf_join_params {
    struct brcmf_ssid_le ssid_le;
};

struct brcmf_fil_bss_enable_le {
    u32 bsscfgidx;
    u32 enable;
};

struct wiphy;
struct net_device;
struct cfg80211_ap_settings {
    struct {
        u8 *head;
        u32 head_len;
        u8 *tail;
        u32 tail_len;
    } beacon;
    struct {
        struct {
            u16 hw_value;
        } *chan;
        u32 center_freq1;
        u32 width;
    } chandef;
    u8 *ssid;
    u32 ssid_len;
    u32 auth_type;
    u32 inactivity_timeout;
    u32 beacon_interval;
    u32 dtim_period;
    bool hidden_ssid;
};

struct brcmf_cfg80211_info {
    void *d11inf;
};

struct brcmf_if {
    u32 ifidx;
    u32 bsscfgidx;
    struct {
        bool is_11d;
        bool mbss;
        struct {
            enum nl80211_iftype iftype;
        } wdev;
        u32 sme_state;
    } *vif;
};

#define BRCMF_C_GET_REGULATORY 0
#define BRCMF_C_SET_REGULATORY 1
#define BRCMF_C_SET_BCNPRD 2
#define BRCMF_C_SET_DTIMPRD 3
#define BRCMF_C_DOWN 4
#define BRCMF_C_SET_INFRA 5
#define BRCMF_C_SET_AP 6
#define BRCMF_C_UP 7
#define BRCMF_C_SET_SSID 8

#define BRCMF_FEAT_MBSS 0
#define BRCMF_FEAT_RSDB 1

#define TRACE 0
#define BRCMF_VIF_STATUS_AP_CREATED 0

static inline struct brcmf_cfg80211_info *wiphy_to_cfg(struct wiphy *wiphy) { return NULL; }
static inline void *netdev_priv(struct net_device *dev) { return NULL; }
static inline const struct brcmf_tlv *brcmf_parse_tlvs(const u8 *buf, u32 buflen, u8 key) { return NULL; }
static inline const struct brcmf_vs_tlv *brcmf_find_wpaie(const u8 *parse, u32 len) { return NULL; }
static inline s32 brcmf_configure_wpaie(struct brcmf_if *ifp, const struct brcmf_vs_tlv *wpaie, bool is_rsn) { return 0; }
static inline void brcmf_configure_opensecurity(struct brcmf_if *ifp) {}
static inline void brcmf_config_ap_mgmt_ie(void *vif, void *beacon) {}
static inline s32 brcmf_fil_cmd_int_get(struct brcmf_if *ifp, u32 cmd, int *data) { return 0; }
static inline s32 brcmf_fil_cmd_int_set(struct brcmf_if *ifp, u32 cmd, u32 data) { return 0; }
static inline s32 brcmf_fil_iovar_int_set(struct brcmf_if *ifp, const char *name, u32 data) { return 0; }
static inline s32 brcmf_fil_iovar_data_set(struct brcmf_if *ifp, const char *name, void *data, u32 len) { return 0; }
static inline s32 brcmf_fil_bsscfg_data_set(struct brcmf_if *ifp, const char *name, void *data, u32 len) { return 0; }
static inline s32 brcmf_fil_cmd_data_set(struct brcmf_if *ifp, u32 cmd, void *data, u32 len) { return 0; }
static inline void brcmf_set_mpc(struct brcmf_if *ifp, int mpc) {}
static inline void brcmf_configure_arp_nd_offload(struct brcmf_if *ifp, bool enable) {}
static inline void brcmf_cfg80211_reconfigure_wep(struct brcmf_if *ifp) {}
static inline void brcmf_net_setcarrier(struct brcmf_if *ifp, bool carrier) {}
static inline bool brcmf_feat_is_enabled(struct brcmf_if *ifp, int feat) { return false; }
static inline u16 chandef_to_chanspec(void *d11inf, void *chandef) { return 0; }
static inline void brcmf_dbg(u32 level, const char *fmt, ...) {}
static inline void brcmf_err(const char *fmt, ...) {}
static inline void set_bit(int nr, volatile unsigned long *addr) {}
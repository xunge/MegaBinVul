#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define IEEE80211_MAX_SSID_LEN 32
#define FIRST_VALID_CHANNEL 1
#define S_DS_GEN 4
#define TLV_TYPE_CHANLIST 0x0001
#define WLAN_EID_HT_CAPABILITY 45
#define WLAN_EID_HT_OPERATION 61
#define MWIFIEX_VSIE_MASK_ADHOC 0x1
#define MWIFIEX_802_11_PRIV_FILTER_8021X_WEP 1
#define MWIFIEX_802_11_PRIV_FILTER_ACCEPT_ALL 0
#define WLAN_CAPABILITY_IBSS (1<<0)
#define WLAN_CAPABILITY_PRIVACY (1<<1)
#define WLAN_CAPABILITY_SHORT_SLOT_TIME (1<<10)
#define IEEE80211_HT_CAP_SUP_WIDTH_20_40 (1<<1)
#define IEEE80211_HT_CAP_SGI_40 (1<<4)
#define IEEE80211_HT_PARAM_CHA_SEC_NONE 0
#define IEEE80211_HT_PARAM_CHA_SEC_ABOVE 1
#define IEEE80211_HT_PARAM_CHA_SEC_BELOW 3
#define IEEE80211_HT_PARAM_CHAN_WIDTH_ANY 0x80
#define IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT 0x0004
#define BAND_B 0x01
#define BAND_G 0x02
#define BAND_GN 0x04
#define BAND_AN 0x08
#define HostCmd_CMD_802_11_AD_HOC_START 0x0002
#define HostCmd_CMD_MAC_CONTROL 0x0028
#define HostCmd_ACT_GEN_SET 0x0001
#define HostCmd_BSS_MODE_IBSS 0x0002
#define HostCmd_ACT_MAC_ADHOC_G_PROTECTION_ON 0x0001
#define NL80211_IFTYPE_ADHOC 1
#define INFO 1
#define ERROR 2

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct mwifiex_private;
struct mwifiex_adapter;
struct mwifiex_bssdescriptor;
struct mwifiex_chan_freq_power {
    u8 channel;
};

struct cfg80211_ssid {
    u8 ssid[IEEE80211_MAX_SSID_LEN];
    u8 ssid_len;
};

union ieee_types_phy_param_set {
    struct {
        u8 element_id;
        u8 len;
        u8 current_chan;
    } ds_param_set;
};

union ieee_types_ss_param_set {
    struct {
        u8 element_id;
        u8 len;
        u16 atim_window;
    } ibss_param_set;
};

struct host_cmd_ds_802_11_ad_hoc_start {
    u8 ssid[IEEE80211_MAX_SSID_LEN];
    u16 bss_mode;
    u16 beacon_period;
    union ieee_types_phy_param_set phy_param_set;
    union ieee_types_ss_param_set ss_param_set;
    u8 data_rate[14];
    u16 cap_info_bitmap;
};

struct host_cmd_ds_command {
    u16 command;
    u16 size;
    union {
        struct host_cmd_ds_802_11_ad_hoc_start adhoc_start;
    } params;
};

struct mwifiex_ie_types_header {
    u16 type;
    u16 len;
};

struct mwifiex_chan_scan_param_set {
    u8 chan_number;
    u8 radio_type;
};

struct mwifiex_ie_types_chan_list_param_set {
    struct mwifiex_ie_types_header header;
    struct mwifiex_chan_scan_param_set chan_scan_param[1];
};

struct ieee80211_ht_cap {
    u16 cap_info;
    u8 ampdu_params;
    u8 mcs[16];
    u16 ext_ht_cap;
    u32 tx_bf_cap;
    u8 antenna_selection;
};

struct ieee80211_ht_operation {
    u8 primary_chan;
    u8 ht_param;
    u16 operation_mode;
    u16 basic_set[2];
};

struct mwifiex_ie_types_htcap {
    struct mwifiex_ie_types_header header;
    struct ieee80211_ht_cap ht_cap;
};

struct mwifiex_ie_types_htinfo {
    struct mwifiex_ie_types_header header;
    struct ieee80211_ht_operation ht_oper;
};

struct mwifiex_bssdescriptor {
    struct cfg80211_ssid ssid;
    u8 bss_mode;
    u16 beacon_period;
    u8 channel;
    u16 cap_info_bitmap;
    u8 privacy;
    union ieee_types_phy_param_set phy_param_set;
    union ieee_types_ss_param_set ss_param_set;
};

struct mwifiex_curr_bss_params {
    struct mwifiex_bssdescriptor bss_descriptor;
    u8 band;
    u8 channel;
    u8 num_of_rates;
    u8 data_rates[14];
};

struct mwifiex_sec_info {
    u8 encryption_mode;
    u8 wpa_enabled;
};

struct mwifiex_private {
    struct mwifiex_adapter *adapter;
    struct mwifiex_curr_bss_params curr_bss_params;
    struct mwifiex_bssdescriptor *attempted_bss_desc;
    u16 beacon_period;
    u16 atim_window;
    u8 adhoc_channel;
    u16 curr_pkt_filter;
    struct mwifiex_sec_info sec_info;
    u8 config_bands;
};

struct mwifiex_adapter {
    u8 adhoc_start_band;
    u8 sec_chan_offset;
    bool adhoc_11n_enabled;
};

static inline u16 cpu_to_le16(u16 val) { return val; }
static inline u16 le16_to_cpu(u16 val) { return val; }

#define IS_SUPPORT_MULTI_BANDS(adapter) (1)
#define mwifiex_dbg(adapter, level, fmt, ...) do {} while (0)
#define mwifiex_get_cfp(priv, band, channel, freq) NULL
#define mwifiex_band_to_radio_type(band) 0
#define mwifiex_fill_cap_info(priv, radio_type, ht_cap) do {} while (0)
#define mwifiex_get_active_data_rates(priv, rates) do {} while (0)
#define mwifiex_send_cmd(priv, cmd, act, flags, data, sync) 0
#define mwifiex_cmd_append_vsie_tlv(priv, mask, pos) 0
#define mwifiex_append_rsn_ie_wpa_wpa2(priv, pos) 0
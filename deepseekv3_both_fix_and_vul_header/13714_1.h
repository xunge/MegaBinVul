#include <stdint.h>
#include <string.h>

#define WLAN_OUI_MICROSOFT 0x0050f2
#define WLAN_OUI_TYPE_MICROSOFT_WMM 2
#define MWIFIEX_WMM_SUBTYPE 1
#define MWIFIEX_WMM_VERSION 1

typedef uint8_t u8;

struct ieee_types_header {
    u8 element_id;
    u8 len;
};

struct mwifiex_types_wmm_info {
    u8 oui[4];
    u8 subtype;
    u8 version;
};

struct mwifiex_private {
    int wmm_enabled;
};

struct mwifiex_uap_bss_param {
    struct mwifiex_types_wmm_info wmm_info;
    u8 qos_info;
};

struct cfg80211_ap_settings {
    struct {
        const u8 *tail;
        size_t tail_len;
    } beacon;
};

const u8 *cfg80211_find_vendor_ie(unsigned int oui, u8 oui_type,
                                 const u8 *ie, size_t len);
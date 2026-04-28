#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define WLAN_EID_SUPP_RATES 1
#define WLAN_EID_EXT_SUPP_RATES 50
#define MWIFIEX_SUPPORTED_RATES 32

typedef uint8_t u8;

struct ieee_types_header {
    u8 element_id;
    u8 len;
} __attribute__((packed));

struct mwifiex_uap_bss_param {
    u8 rates[MWIFIEX_SUPPORTED_RATES];
};

struct cfg80211_ap_settings {
    struct {
        const u8 *head;
        int head_len;
        const u8 *tail;
        int tail_len;
    } beacon;
};

struct ieee80211_mgmt {
    union {
        struct {
            uint8_t variable[0];
        } beacon;
    } u;
};

const u8 *cfg80211_find_ie(u8 eid, const u8 *ies, int len);
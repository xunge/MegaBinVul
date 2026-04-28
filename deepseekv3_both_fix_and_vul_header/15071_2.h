#include <stdint.h>
#include <string.h>

#define ETH_ALEN 6
#define MAX_RATES 8
#define MAX_WPA_IE_LEN 64
#define MARVELL_MESH_IE_LENGTH 9
#define WLAN_CAPABILITY_PRIVACY 0x0010
#define WLAN_CAPABILITY_IBSS 0x0002
#define IW_MODE_ADHOC 1
#define IW_MODE_INFRA 2

#define MFIE_TYPE_SSID 0
#define MFIE_TYPE_RATES 1
#define MFIE_TYPE_FH_SET 2
#define MFIE_TYPE_DS_SET 3
#define MFIE_TYPE_CF_SET 4
#define MFIE_TYPE_IBSS_SET 6
#define MFIE_TYPE_COUNTRY 7
#define MFIE_TYPE_RATES_EX 50
#define MFIE_TYPE_GENERIC 221
#define MFIE_TYPE_RSN 48

struct ieeetypes_fhparamset {
    uint8_t datarate;
    uint8_t hopset;
    uint8_t hoppattern;
    uint8_t hopindex;
};

struct ieeetypes_dsparamset {
    uint8_t currentchan;
};

struct ieeetypes_cfparamset {
    uint8_t cfpcnt;
    uint8_t cfpperiod;
    uint16_t cfpmaxduration;
    uint16_t cfpdurationremaining;
};

struct ieeetypes_ibssparamset {
    uint16_t atimwindow;
};

struct ieeetypes_countryinfoset {
    uint8_t len;
    uint8_t countrycode[3];
    uint8_t pad;
    uint8_t triplet[0];
};

struct ieee80211_info_element {
    uint8_t id;
    uint8_t len;
    uint8_t data[0];
};

struct bss_descriptor {
    uint8_t bssid[ETH_ALEN];
    int rssi;
    uint16_t beaconperiod;
    uint16_t capability;
    uint8_t mode;
    uint8_t ssid[32];
    uint8_t ssid_len;
    uint8_t rates[MAX_RATES];
    uint8_t channel;
    struct {
        struct ieeetypes_fhparamset fhparamset;
        struct ieeetypes_dsparamset dsparamset;
    } phyparamset;
    struct {
        struct ieeetypes_cfparamset cfparamset;
        struct ieeetypes_ibssparamset ibssparamset;
    } ssparamset;
    uint16_t atimwindow;
    uint8_t countryinfo[256];
    uint8_t wpa_ie[MAX_WPA_IE_LEN];
    uint8_t wpa_ie_len;
    uint8_t rsn_ie[MAX_WPA_IE_LEN];
    uint8_t rsn_ie_len;
    unsigned long last_scanned;
    uint8_t mesh;
};

static inline uint16_t get_unaligned_le16(const void *p)
{
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

static inline uint16_t le16_to_cpu(uint16_t val)
{
    return val;
}

static inline void lbs_unset_basic_rate_flags(uint8_t *rates, size_t len) {}

#define DECLARE_MAC_BUF(x) char x[18]
#define print_mac(mac, addr) mac
#define escape_essid(ssid, len) ssid
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

#define LBS_DEB_SCAN 0
#define lbs_deb_enter(x) do {} while (0)
#define lbs_deb_leave(x) do {} while (0)
#define lbs_deb_leave_args(x, ...) do {} while (0)
#define lbs_deb_hex(x, ...) do {} while (0)
#define lbs_deb_scan(...) do {} while (0)

static unsigned long jiffies = 0;
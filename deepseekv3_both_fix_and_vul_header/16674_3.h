#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define RTW_SSID_SCAN_AMOUNT 1
#define IW_ESSID_MAX_SIZE 32
#define WEXT_CSCAN_HEADER_SIZE 4
#define WEXT_CSCAN_HEADER "CSCAN"
#define WEXT_CSCAN_SSID_SECTION 0x00
#define WEXT_CSCAN_TYPE_SECTION 0x01
#define WEXT_CSCAN_CHANNEL_SECTION 0x02
#define WEXT_CSCAN_PASV_DWELL_SECTION 0x03
#define WEXT_CSCAN_HOME_DWELL_SECTION 0x04
#define WEXT_CSCAN_ACTV_DWELL_SECTION 0x05
#define IW_SCAN_THIS_ESSID 0x0001
#define IW_SCAN_TYPE_PASSIVE 0x01

typedef uint8_t u8;

struct net_device;
struct iw_request_info;

struct iw_scan_req {
    int essid_len;
    unsigned char essid[IW_ESSID_MAX_SIZE];
    int scan_type;
};

union iwreq_data {
    struct {
        int length;
        int flags;
    } data;
};

struct mlme_priv {
    struct LinkDetectInfo {
        bool bBusyTraffic;
    } LinkDetectInfo;
    int lock;
};

struct adapter {
    struct mlme_priv mlmepriv;
    bool bDriverStopped;
    bool bup;
    bool hw_init_completed;
};

struct ndis_802_11_ssid {
    unsigned int ssid_length;
    unsigned char ssid[32];
};

#define _module_rtl871x_mlme_c_ 0
#define _drv_info_ 0
#define RT_TRACE(module, level, fmt, args...)
#define DBG_88E(fmt, args...)

enum FW_STATE {
    _FW_UNDER_SURVEY,
    _FW_UNDER_LINKING
};

static inline bool check_fwstate(struct mlme_priv *priv, enum FW_STATE state) { return false; }
static inline void indicate_wx_scan_complete_event(struct adapter *adapter) {}
static inline bool rtw_pwr_wakeup(struct adapter *adapter) { return false; }
static inline struct adapter *rtw_netdev_priv(struct net_device *dev) { return NULL; }
static inline bool rtw_sitesurvey_cmd(struct adapter *adapter, struct ndis_802_11_ssid *ssid, int ssid_num, void *arg, int arg_len) { return false; }
static inline bool rtw_set_802_11_bssid_list_scan(struct adapter *adapter, struct ndis_802_11_ssid *ssid, int ssid_num) { return false; }

#define spin_lock_bh(lock) do {} while(0)
#define spin_unlock_bh(lock) do {} while(0)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <linux/types.h>

typedef unsigned short hcf_16;
typedef bool bool_t;
#define FALSE false
#define TRUE true

struct uilreq {
    void *hcfCtx;
    void *data;
    unsigned int len;
    int result;
};

struct wl_private {
    struct {
        hcf_16 len;
        hcf_16 typ;
        union {
            hcf_16 u16[1];
            unsigned char u8[2];
        } u;
    } ltvRecord;
    hcf_16 PortType;
    hcf_16 Channel;
    hcf_16 atimWindow;
    hcf_16 DistanceBetweenAPs;
    hcf_16 PMEnabled;
    hcf_16 MulticastReceive;
    hcf_16 MaxSleepDuration;
    hcf_16 holdoverDuration;
    char StationName[32];
    hcf_16 loadBalancing;
    hcf_16 mediumDistribution;
    hcf_16 txPowLevel;
    hcf_16 srsc[2];
    hcf_16 brsc[2];
    hcf_16 connectionControl;
    hcf_16 DTIMPeriod;
    hcf_16 ownBeaconInterval;
    hcf_16 coexistence;
    struct {
        unsigned char wdsAddress[6];
        hcf_16 rtsThreshold;
        hcf_16 txRateCntl;
    } wds_port[6];
    hcf_16 multicastPMBuffering;
    hcf_16 RejectAny;
    hcf_16 EnableEncryption;
    hcf_16 authentication;
    hcf_16 intraBSSRelay;
    char NetworkName[32];
    hcf_16 CreateIBSS;
    hcf_16 RTSThreshold;
    hcf_16 TxRateControl[2];
    struct {
        struct {
            hcf_16 len;
            unsigned char data[16];
        } key[4];
    } DefaultKeys;
    hcf_16 TransmitKeyID;
    char szEncryption[256];
    hcf_16 driverEnable;
    hcf_16 wolasEnable;
    hcf_16 AuthKeyMgmtSuite;
    void *hcfCtx;
};

typedef struct {
    hcf_16 len;
    hcf_16 typ;
    union {
        hcf_16 u16[1];
        unsigned char u8[2];
    } u;
} ltv_t;
typedef ltv_t *LTVP;

typedef struct {
    hcf_16 wEnabled;
    hcf_16 wTxKeyID;
    struct {
        struct {
            hcf_16 len;
            unsigned char data[16];
        } key[4];
    } EncStr;
} ENCSTRCT;

typedef struct {
    struct {
        hcf_16 len;
        unsigned char data[16];
    } key[4];
} CFG_DEFAULT_KEYS_STRCT;

#define HCF_PORT_0 0
#define HCF_PORT_1 1
#define HCF_PORT_2 2
#define HCF_PORT_3 3
#define HCF_PORT_4 4
#define HCF_PORT_5 5
#define HCF_PORT_6 6

#define UIL_ERR_LEN 1
#define UIL_FAILURE 2
#define UIL_ERR_WRONG_IFB 3

#define CFG_CNF_PORT_TYPE 0xFC00
#define CFG_CNF_OWN_MAC_ADDR 0xFC01
#define CFG_CNF_OWN_CHANNEL 0xFC02
#define CFG_CNF_OWN_SSID 0xFC03
#define CFG_CNF_OWN_ATIM_WINDOW 0xFC04
#define CFG_CNF_SYSTEM_SCALE 0xFC05
#define CFG_CNF_MAX_DATA_LEN 0xFC06
#define CFG_CNF_PM_ENABLED 0xFC07
#define CFG_CNF_MCAST_RX 0xFC08
#define CFG_CNF_MAX_SLEEP_DURATION 0xFC09
#define CFG_CNF_HOLDOVER_DURATION 0xFC0A
#define CFG_CNF_OWN_NAME 0xFC0B
#define CFG_CNF_LOAD_BALANCING 0xFC0C
#define CFG_CNF_MEDIUM_DISTRIBUTION 0xFC0D
#define CFG_CNF_TX_POW_LVL 0xFC0E
#define CFG_CNF_CONNECTION_CNTL 0xFC0F
#define CFG_CNF_OWN_DTIM_PERIOD 0xFC10
#define CFG_CNF_OWN_BEACON_INTERVAL 0xFC11
#define CFG_CNF_WDS_ADDR1 0xFC12
#define CFG_CNF_WDS_ADDR2 0xFC13
#define CFG_CNF_WDS_ADDR3 0xFC14
#define CFG_CNF_WDS_ADDR4 0xFC15
#define CFG_CNF_WDS_ADDR5 0xFC16
#define CFG_CNF_WDS_ADDR6 0xFC17
#define CFG_CNF_MCAST_PM_BUF 0xFC18
#define CFG_CNF_REJECT_ANY 0xFC19
#define CFG_CNF_ENCRYPTION 0xFC1A
#define CFG_CNF_AUTHENTICATION 0xFC1B
#define CFG_CNF_EXCL_UNENCRYPTED 0xFC1C
#define CFG_CNF_MCAST_RATE 0xFC1D
#define CFG_CNF_INTRA_BSS_RELAY 0xFC1E
#define CFG_CNF_MICRO_WAVE 0xFC1F
#define CFG_DESIRED_SSID 0xFC20
#define CFG_GROUP_ADDR 0xFC21
#define CFG_CREATE_IBSS 0xFC22
#define CFG_RTS_THRH 0xFC23
#define CFG_TX_RATE_CNTL 0xFC24
#define CFG_PROMISCUOUS_MODE 0xFC25
#define CFG_RTS_THRH0 0xFC26
#define CFG_TX_RATE_CNTL0 0xFC27
#define CFG_RTS_THRH1 0xFC28
#define CFG_TX_RATE_CNTL1 0xFC29
#define CFG_RTS_THRH2 0xFC2A
#define CFG_TX_RATE_CNTL2 0xFC2B
#define CFG_RTS_THRH3 0xFC2C
#define CFG_TX_RATE_CNTL3 0xFC2D
#define CFG_RTS_THRH4 0xFC2E
#define CFG_TX_RATE_CNTL4 0xFC2F
#define CFG_RTS_THRH5 0xFC30
#define CFG_TX_RATE_CNTL5 0xFC31
#define CFG_RTS_THRH6 0xFC32
#define CFG_TX_RATE_CNTL6 0xFC33
#define CFG_DEFAULT_KEYS 0xFC34
#define CFG_TX_KEY_ID 0xFC35
#define CFG_SCAN_SSID 0xFC36
#define CFG_TICK_TIME 0xFC37
#define CFG_AP_MODE 0xFC38
#define CFG_ENCRYPT_STRING 0xFC39
#define CFG_DRIVER_ENABLE 0xFC3A
#define CFG_WOLAS_ENABLE 0xFC3B
#define CFG_SET_WPA_AUTH_KEY_MGMT_SUITE 0xFC3C
#define CFG_DISASSOCIATE_ADDR 0xFC3D
#define CFG_ADD_TKIP_DEFAULT_KEY 0xFC3E
#define CFG_REMOVE_TKIP_DEFAULT_KEY 0xFC3F
#define CFG_ADD_TKIP_MAPPED_KEY 0xFC40
#define CFG_REMOVE_TKIP_MAPPED_KEY 0xFC41
#define CFG_SUPPORTED_RATE_SET_CNTL 0xFC42
#define CFG_BASIC_RATE_SET_CNTL 0xFC43
#define CFG_COEXISTENSE_BEHAVIOUR 0xFC44
#define CFG_MAX_LOAD_TIME 0xFC45
#define CFG_DL_BUF 0xFC46
#define CFG_NIC_SERIAL_NUMBER 0xFC47
#define CFG_NIC_IDENTITY 0xFC48
#define CFG_NIC_MFI_SUP_RANGE 0xFC49
#define CFG_NIC_CFI_SUP_RANGE 0xFC4A
#define CFG_NIC_TEMP_TYPE 0xFC4B
#define CFG_NIC_PROFILE 0xFC4C
#define CFG_FW_IDENTITY 0xFC4D
#define CFG_FW_SUP_RANGE 0xFC4E
#define CFG_MFI_ACT_RANGES_STA 0xFC4F
#define CFG_CFI_ACT_RANGES_STA 0xFC50
#define CFG_PORT_STAT 0xFC51
#define CFG_CUR_SSID 0xFC52
#define CFG_CUR_BSSID 0xFC53
#define CFG_COMMS_QUALITY 0xFC54
#define CFG_CUR_TX_RATE 0xFC55
#define CFG_CUR_BEACON_INTERVAL 0xFC56
#define CFG_CUR_SCALE_THRH 0xFC57
#define CFG_PROTOCOL_RSP_TIME 0xFC58
#define CFG_CUR_SHORT_RETRY_LIMIT 0xFC59
#define CFG_CUR_LONG_RETRY_LIMIT 0xFC5A
#define CFG_MAX_TX_LIFETIME 0xFC5B
#define CFG_MAX_RX_LIFETIME 0xFC5C
#define CFG_CF_POLLABLE 0xFC5D
#define CFG_AUTHENTICATION_ALGORITHMS 0xFC5E
#define CFG_PRIVACY_OPT_IMPLEMENTED 0xFC5F
#define CFG_NIC_MAC_ADDR 0xFC60
#define CFG_PCF_INFO 0xFC61
#define CFG_PHY_TYPE 0xFC62
#define CFG_CUR_CHANNEL 0xFC63
#define CFG_SUPPORTED_DATA_RATES 0xFC64
#define CFG_MB_INFO 0xFC65
#define CFG_IFB 0xFC66

#define ETH_ALEN 6
#define CNV_INT_TO_LITTLE(x) (x)
#define CRYPT_CODE 0
#define VERIFY_READ 0
#define ENOMEM 12
#define EPERM 1
#define CAP_NET_ADMIN 12

#define HCF_CNTL_ENABLE 0x0001
#define HCF_CNTL_CONNECT 0x0002
#define HCF_CNTL_DISABLE 0x0003
#define HCF_CNTL_DISCONNECT 0x0004

#define DBG_FUNC(x)
#define DBG_ENTER(x)
#define DBG_LEAVE(x)
#define DBG_ERROR(x, y)
#define USE_WDS
#define WARP
#define GFP_KERNEL 0

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
#define strlcpy(dest, src, size) strncpy(dest, src, size)

static inline int verify_area(int type, const void *addr, unsigned long size) { return 0; }
static inline void copy_from_user(void *to, const void *from, unsigned long n) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int hcf_put_info(void *ctx, LTVP ltv) { return 0; }
static inline void hcf_cntl(void *ctx, int cmd) {}
static inline void wl_act_int_off(struct wl_private *lp) {}
static inline void wl_act_int_on(struct wl_private *lp) {}
static inline void wl_wep_decode(int code, ENCSTRCT *enc, char *str) {}
static inline int capable(int cap) { return 1; }
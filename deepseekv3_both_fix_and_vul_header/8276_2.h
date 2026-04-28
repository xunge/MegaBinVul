#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int INT;
typedef unsigned char UCHAR;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef unsigned int guint;

#define FALSE 0
#define TRUE 1

typedef struct _AIRPDCAP_SEC_ASSOCIATION_ID {
    guint8 sta[6];
    guint8 bssid[6];
} AIRPDCAP_SEC_ASSOCIATION_ID;

typedef struct _AIRPDCAP_WPA {
    guint8 ptk[64];
    guint8 nonce[32];
} AIRPDCAP_WPA;

typedef struct _AIRPDCAP_SEC_ASSOCIATION {
    struct _AIRPDCAP_SEC_ASSOCIATION *next;
    AIRPDCAP_WPA wpa;
    guint validKey;
} AIRPDCAP_SEC_ASSOCIATION, *PAIRPDCAP_SEC_ASSOCIATION;

typedef struct _AIRPDCAP_CONTEXT {
    // Context structure definition would go here
} AIRPDCAP_CONTEXT, *PAIRPDCAP_CONTEXT;

typedef struct _AIRPDCAP_MAC_FRAME_ADDR4 {
    // MAC frame structure definition would go here
} AIRPDCAP_MAC_FRAME_ADDR4;

typedef struct _EAPOL_RSN_KEY {
    guint8 type;
    // Other EAPOL key fields would go here
} EAPOL_RSN_KEY;

#define AIRPDCAP_RET_NO_VALID_HANDSHAKE 0
#define AIRPDCAP_RET_REQ_DATA 1
#define AIRPDCAP_RET_SUCCESS_HANDSHAKE 2
#define AIRPDCAP_RET_SUCCESS 3

#define AIRPDCAP_RSN_WPA2_KEY_DESCRIPTOR 2
#define AIRPDCAP_RSN_WPA_KEY_DESCRIPTOR 254

#define AIRPDCAP_MAC_LEN 6
#define GROUP_KEY_PAYLOAD_LEN_MIN 32
#define AIRPDCAP_WPA_NONCE_LEN 32

#define AIRPDCAP_EAP_KEY(x) ((x) & 0x80)
#define AIRPDCAP_EAP_ACK(x) ((x) & 0x40)
#define AIRPDCAP_EAP_MIC(x) ((x) & 0x80)
#define AIRPDCAP_EAP_SEC(x) ((x) & 0x40)

static const guint8 broadcast_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

static guint16 pntoh16(const guint8 *p);
static PAIRPDCAP_SEC_ASSOCIATION AirPDcapGetSaPtr(PAIRPDCAP_CONTEXT ctx, const AIRPDCAP_SEC_ASSOCIATION_ID *id);
static const UCHAR *AirPDcapGetStaAddress(const AIRPDCAP_MAC_FRAME_ADDR4 *frame);
static INT AirPDcapRsna4WHandshake(PAIRPDCAP_CONTEXT ctx, const guint8 *data, PAIRPDCAP_SEC_ASSOCIATION sa, guint offset, guint tot_len);
static INT AirPDcapDecryptWPABroadcastKey(const EAPOL_RSN_KEY *pEAPKey, const guint8 *ptk, PAIRPDCAP_SEC_ASSOCIATION sa, guint len);
static INT AirPDcapTDLSDeriveKey(PAIRPDCAP_SEC_ASSOCIATION sa, const guint8 *data, guint offset_rsne, guint offset_fte, guint offset_timeout, guint offset_link, guint8 action);

#define AIRPDCAP_DEBUG_LEVEL_3 3
#define AIRPDCAP_DEBUG_LEVEL_5 5
#define AIRPDCAP_DEBUG_TRACE_START(x)
#define AIRPDCAP_DEBUG_TRACE_END(x)
#define AIRPDCAP_DEBUG_PRINT_LINE(func, msg, level)

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))
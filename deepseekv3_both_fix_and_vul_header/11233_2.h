#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int INT;
typedef unsigned char UCHAR;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef char CHAR;

#define AIRPDCAP_MAX_CAPLEN 65535
#define AIRPDCAP_MAC_LEN 6
#define AIRPDCAP_WPA_NONCE_LEN 32
#define GROUP_KEY_PAYLOAD_LEN_MIN 40

#define AIRPDCAP_RET_NO_VALID_HANDSHAKE 0
#define AIRPDCAP_RET_REQ_DATA 1
#define AIRPDCAP_RET_SUCCESS_HANDSHAKE 2
#define AIRPDCAP_RET_SUCCESS 3

#define AIRPDCAP_RSN_WPA2_KEY_DESCRIPTOR 2
#define AIRPDCAP_RSN_WPA_KEY_DESCRIPTOR 254

#define AIRPDCAP_EAP_KEY(x) ((x) & 0x80)
#define AIRPDCAP_EAP_ACK(x) ((x) & 0x40)
#define AIRPDCAP_EAP_MIC(x) ((x) & 0x80)
#define AIRPDCAP_EAP_SEC(x) ((x) & 0x01)

#define AIRPDCAP_DEBUG_LEVEL_3 3
#define AIRPDCAP_DEBUG_LEVEL_5 5

#define FALSE 0
#define TRUE 1

typedef struct _AIRPDCAP_MAC_FRAME_ADDR4 {
    UCHAR addr1[AIRPDCAP_MAC_LEN];
    UCHAR addr2[AIRPDCAP_MAC_LEN];
    UCHAR addr3[AIRPDCAP_MAC_LEN];
    UCHAR addr4[AIRPDCAP_MAC_LEN];
} AIRPDCAP_MAC_FRAME_ADDR4;

typedef struct _AIRPDCAP_SEC_ASSOCIATION_ID {
    UCHAR sta[AIRPDCAP_MAC_LEN];
    UCHAR bssid[AIRPDCAP_MAC_LEN];
} AIRPDCAP_SEC_ASSOCIATION_ID;

typedef struct _AIRPDCAP_SEC_ASSOCIATION {
    struct _AIRPDCAP_SEC_ASSOCIATION *next;
    int validKey;
    struct {
        UCHAR ptk[64];
        UCHAR nonce[AIRPDCAP_WPA_NONCE_LEN];
    } wpa;
} AIRPDCAP_SEC_ASSOCIATION, *PAIRPDCAP_SEC_ASSOCIATION;

typedef struct _AIRPDCAP_CONTEXT {
    void *dummy;
} AIRPDCAP_CONTEXT, *PAIRPDCAP_CONTEXT;

typedef struct _EAPOL_RSN_KEY {
    UCHAR type;
    UCHAR info[1];
} EAPOL_RSN_KEY;

extern const UCHAR broadcast_mac[AIRPDCAP_MAC_LEN];

static inline uint16_t pntoh16(const uint8_t *p) {
    return (p[0] << 8) | p[1];
}

#define AIRPDCAP_DEBUG_TRACE_START(func)
#define AIRPDCAP_DEBUG_TRACE_END(func)
#define AIRPDCAP_DEBUG_PRINT_LINE(func, msg, level)

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))

PAIRPDCAP_SEC_ASSOCIATION AirPDcapGetSaPtr(PAIRPDCAP_CONTEXT ctx, const AIRPDCAP_SEC_ASSOCIATION_ID *id);
const UCHAR *AirPDcapGetStaAddress(const AIRPDCAP_MAC_FRAME_ADDR4 *frame);
INT AirPDcapRsna4WHandshake(PAIRPDCAP_CONTEXT ctx, const guint8 *data, PAIRPDCAP_SEC_ASSOCIATION sa, guint offset, guint tot_len);
INT AirPDcapDecryptWPABroadcastKey(const EAPOL_RSN_KEY *pEAPKey, const UCHAR *key, PAIRPDCAP_SEC_ASSOCIATION sa, guint len);
INT AirPDcapTDLSDeriveKey(PAIRPDCAP_SEC_ASSOCIATION sa, const guint8 *data, guint offset_rsne, guint offset_fte, guint offset_timeout, guint offset_link, guint8 action);
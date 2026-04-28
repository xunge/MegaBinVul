#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

typedef int INT;
typedef uint8_t UCHAR;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef char CHAR;

#define FALSE false
#define TRUE true

#define DOT11DECRYPT_CRYPTED_DATA_MINLEN 0
#define DOT11DECRYPT_MAX_CAPLEN 0
#define DOT11DECRYPT_RET_NO_VALID_HANDSHAKE 0
#define DOT11DECRYPT_RET_REQ_DATA 0
#define DOT11DECRYPT_RET_SUCCESS_HANDSHAKE 0
#define DOT11DECRYPT_RET_SUCCESS 0
#define DOT11DECRYPT_RSN_WPA2_KEY_DESCRIPTOR 0
#define DOT11DECRYPT_RSN_WPA_KEY_DESCRIPTOR 0
#define GROUP_KEY_PAYLOAD_LEN_MIN 0
#define DOT11DECRYPT_MAC_LEN 6
#define DOT11DECRYPT_WPA_NONCE_LEN 32
#define DOT11DECRYPT_DEBUG_LEVEL_3 0
#define DOT11DECRYPT_DEBUG_LEVEL_5 0

#define DISSECTOR_ASSERT(x)

typedef struct {
    uint8_t sta[DOT11DECRYPT_MAC_LEN];
    uint8_t bssid[DOT11DECRYPT_MAC_LEN];
} DOT11DECRYPT_SEC_ASSOCIATION_ID;

typedef struct {
    uint8_t type;
} EAPOL_RSN_KEY;

typedef struct DOT11DECRYPT_SEC_ASSOCIATION {
    uint8_t ptk[16];
    uint8_t nonce[DOT11DECRYPT_WPA_NONCE_LEN];
    bool validKey;
    struct DOT11DECRYPT_SEC_ASSOCIATION *next;
    struct {
        uint8_t ptk[16];
        uint8_t nonce[DOT11DECRYPT_WPA_NONCE_LEN];
    } wpa;
} DOT11DECRYPT_SEC_ASSOCIATION;

typedef DOT11DECRYPT_SEC_ASSOCIATION *PDOT11DECRYPT_SEC_ASSOCIATION;

typedef struct {
    uint8_t data[0];
} DOT11DECRYPT_MAC_FRAME_ADDR4;

typedef struct {
    int dummy;
} DOT11DECRYPT_CONTEXT;

typedef DOT11DECRYPT_CONTEXT *PDOT11DECRYPT_CONTEXT;

static const uint8_t broadcast_mac[DOT11DECRYPT_MAC_LEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

#define pntoh16(x) 0
#define DOT11DECRYPT_EAP_KEY(x) 0
#define DOT11DECRYPT_EAP_ACK(x) 0
#define DOT11DECRYPT_EAP_MIC(x) 0
#define DOT11DECRYPT_EAP_SEC(x) 0

#define DOT11DECRYPT_DEBUG
#define MSGBUF_LEN 255
#define DOT11DECRYPT_DEBUG_TRACE_START(x)
#define DOT11DECRYPT_DEBUG_TRACE_END(x)
#define DOT11DECRYPT_DEBUG_PRINT_LINE(x, y, z)

static PDOT11DECRYPT_SEC_ASSOCIATION Dot11DecryptGetSaPtr(PDOT11DECRYPT_CONTEXT ctx, DOT11DECRYPT_SEC_ASSOCIATION_ID *id) { return NULL; }
static INT Dot11DecryptRsna4WHandshake(PDOT11DECRYPT_CONTEXT ctx, const guint8 *data, PDOT11DECRYPT_SEC_ASSOCIATION sa, guint offset, guint tot_len) { return 0; }
static const UCHAR *Dot11DecryptGetStaAddress(const DOT11DECRYPT_MAC_FRAME_ADDR4 *frame) { return NULL; }
static INT Dot11DecryptDecryptWPABroadcastKey(const EAPOL_RSN_KEY *pEAPKey, const uint8_t *key, PDOT11DECRYPT_SEC_ASSOCIATION sa, guint len) { return 0; }
static INT Dot11DecryptTDLSDeriveKey(PDOT11DECRYPT_SEC_ASSOCIATION sa, const guint8 *data, guint offset_rsne, guint offset_fte, guint offset_timeout, guint offset_link, guint8 action) { return 0; }

static PDOT11DECRYPT_SEC_ASSOCIATION g_new(size_t count) {
    return (PDOT11DECRYPT_SEC_ASSOCIATION)malloc(count * sizeof(DOT11DECRYPT_SEC_ASSOCIATION));
}

static int g_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}

#define g_new(type, count) ((type*)malloc((count) * sizeof(type)))
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t subunit_type;
    uint8_t ctype;
} tAVRC_HDR;

typedef struct {
    tAVRC_HDR hdr;
    uint8_t* p_vendor_data;
    uint16_t vendor_len;
} tAVRC_MSG_VENDOR;

typedef struct {
    uint8_t pdu;
    union {
        struct {
            uint8_t status;
        } rsp;
        struct {
            uint8_t capability_id;
            uint8_t status;
            uint8_t count;
            union {
                uint32_t company_id[1];
                uint8_t event_id[1];
            } param;
        } get_caps;
    };
} tAVRC_RESPONSE;

typedef struct {
    union {
        tAVRC_MSG_VENDOR vendor;
    } msg;
} tBTA_AV_RC_MSG;

typedef uint8_t tBTA_AV_EVT;

#define AVRC_RSP_REJ 0
#define AVRC_RSP_NOT_IMPL 1
#define AVRC_RSP_IMPL_STBL 2
#define AVRC_STS_BAD_PARAM 3
#define AVRC_STS_BAD_CMD 4
#define AVRC_STS_NO_ERROR 5
#define AVRC_STS_INTERNAL_ERR 6
#define BTA_AV_STS_NO_RSP 7
#define BTA_AV_META_MSG_EVT 8

#define AVRC_MIN_META_CMD_LEN 5
#define AVRC_META_CMD_BUF_SIZE 512
#define AVRC_SUB_PANEL 0
#define AVRC_PDU_GET_CAPABILITIES 0x10
#define AVRC_PDU_REGISTER_NOTIFICATION 0x11
#define AVRC_CAP_COMPANY_ID 0x02
#define AVRC_CAP_EVENTS_SUPPORTED 0x03

extern int AVRC_IsValidAvcType(uint8_t pdu, uint8_t ctype);
extern int bta_av_chk_notif_evt_id(tAVRC_MSG_VENDOR* p_vendor);
extern void APPL_TRACE_ERROR(const char* fmt, ...);
extern void APPL_TRACE_DEBUG(const char* fmt, ...);

typedef struct {
    uint8_t num_co_ids;
    uint32_t* p_meta_co_ids;
    uint8_t num_evt_ids;
    uint8_t* p_meta_evt_ids;
} tBTA_AV_CFG;

extern tBTA_AV_CFG* p_bta_av_cfg;

#define BE_STREAM_TO_UINT16(u16, p) { \
    (u16) = ((uint16_t)(*(p)) << 8) + (*(p + 1)); \
    (p) += 2; \
}
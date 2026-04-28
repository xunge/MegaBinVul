#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define AVRC_SUB_TYPE_LEN 8
#define AVCT_DATA_CTRL 0x01
#define AVCT_DATA_BROWSE 0x02
#define AVRC_CT_TARGET 0x01
#define AVRC_CT_CONTROL 0x02
#define AVRC_CMD_OPRND_PAD 0x00
#define AVRC_SUBRSP_OPRND_BYTES 5
#define AVRC_SUB_PANEL 0x09
#define AVRC_SUB_PAGE_SHIFT 4
#define AVRC_SUB_PAGE_MASK 0x0F

typedef struct {
    uint16_t len;
    uint16_t offset;
    uint8_t layer_specific;
} BT_HDR;

typedef struct {
    uint8_t ctype;
    uint8_t subunit_type;
    uint8_t subunit_id;
    uint8_t opcode;
} tAVRC_HDR;

typedef struct {
    tAVRC_HDR hdr;
    uint8_t unit_type;
    uint8_t unit;
    uint32_t company_id;
} tAVRC_UNIT;

typedef struct {
    tAVRC_HDR hdr;
    uint8_t page;
    uint8_t subunit_type[AVRC_SUB_TYPE_LEN];
    bool panel;
} tAVRC_SUB;

typedef struct {
    tAVRC_HDR hdr;
    uint8_t* p_vendor_data;
    uint16_t vendor_len;
    uint32_t company_id;
} tAVRC_MSG_VENDOR;

typedef struct {
    tAVRC_HDR hdr;
    bool state;
    uint8_t op_id;
    uint8_t pass_len;
    uint8_t* p_pass_data;
} tAVRC_PASS;

typedef struct {
    tAVRC_HDR hdr;
    uint8_t* p_browse_data;
    uint16_t browse_len;
    BT_HDR* p_browse_pkt;
} tAVRC_BROWSE;

typedef union {
    tAVRC_HDR hdr;
    tAVRC_UNIT unit;
    tAVRC_SUB sub;
    tAVRC_MSG_VENDOR vendor;
    tAVRC_PASS pass;
    tAVRC_BROWSE browse;
} tAVRC_MSG;

#define AVCT_CMD 0
#define AVCT_RSP 1
#define AVCT_REJ 2

#define AVRC_CTYPE_MASK 0x0F
#define AVRC_SUBTYPE_MASK 0xF8
#define AVRC_SUBTYPE_SHIFT 3
#define AVRC_SUBID_MASK 0x07
#define AVRC_PASS_OP_ID_MASK 0x7F
#define AVRC_PASS_STATE_MASK 0x80

#define AVRC_OP_UNIT_INFO 0x30
#define AVRC_OP_SUB_INFO 0x31
#define AVRC_OP_VENDOR 0x00
#define AVRC_OP_PASS_THRU 0x7C
#define AVRC_OP_BROWSE 0x01

#define AVRC_RSP_IMPL_STBL 0x08
#define AVRC_RSP_REJ 0x0A

#define AVRC_CO_METADATA 0x001958

#define AVRC_VENDOR_HDR_SIZE 6
#define AVRC_AVC_HDR_SIZE 3
#define AVRC_MIN_META_HDR_SIZE 3
#define AVRC_OP_UNIT_INFO_RSP_LEN 9
#define AVRC_OP_SUB_UNIT_INFO_RSP_LEN 8
#define AVRC_OP_REJ_MSG_LEN 3
#define AVRC_PACKET_LEN 512

struct {
    struct {
        uint8_t control;
        void* tle;
        uint32_t company_id;
        struct {
            void (*Run)(uint8_t, uint8_t, uint8_t, tAVRC_MSG*);
        } msg_cback;
    } ccb[256];
    struct {
        uint8_t control;
        void* tle;
        uint32_t company_id;
    } ccb_int[256];
} avrc_cb;

void osi_free(void* ptr);
void AVCT_RemoveConn(uint8_t handle);
void AVCT_MsgReq(uint8_t handle, uint8_t label, uint8_t cr, BT_HDR* p_pkt);
BT_HDR* avrc_copy_packet(BT_HDR* p_pkt, uint16_t len);
uint8_t* avrc_get_data_ptr(BT_HDR* p_pkt);
uint8_t avrc_proc_far_msg(uint8_t handle, uint8_t label, uint8_t cr, BT_HDR** p_pkt, tAVRC_MSG_VENDOR* p_msg);
void avrc_send_next_vendor_cmd(uint8_t handle);
void alarm_cancel(void* alarm);
void AVRC_TRACE_DEBUG(const char* fmt, ...);
void AVRC_TRACE_WARNING(const char* fmt, ...);
void AVRC_CO_ID_TO_BE_STREAM(uint8_t** pp, uint32_t id);
void AVRC_BE_STREAM_TO_CO_ID(uint32_t* p_id, uint8_t** pp);
#include <stdint.h>

typedef struct {
    uint8_t cr;
    uint8_t dlci;
    uint8_t type;
    uint8_t pf;
    uint8_t credit;
} MX_FRAME;

typedef struct {
    uint16_t len;
    uint16_t offset;
} BT_HDR;

typedef struct {
    uint8_t is_initiator;
    uint8_t flow;
} tRFC_MCB;

#define RFCOMM_EA 0x01
#define RFCOMM_SHIFT_LENGTH1 1
#define RFCOMM_SHIFT_LENGTH2 8
#define RFCOMM_CTRL_FRAME_LEN 3
#define RFCOMM_MX_DLCI 0
#define PORT_FC_CREDIT 1

#define RFCOMM_SABME 0x2F
#define RFCOMM_UA 0x63
#define RFCOMM_DM 0x0F
#define RFCOMM_DISC 0x43
#define RFCOMM_UIH 0xEF

#define RFC_EVENT_BAD_FRAME 0
#define RFC_EVENT_SABME 1
#define RFC_EVENT_UA 2
#define RFC_EVENT_DM 3
#define RFC_EVENT_DISC 4
#define RFC_EVENT_UIH 5

#define RFCOMM_FRAME_IS_RSP(is_initiator, cr) ((is_initiator) ? !(cr) : (cr))
#define RFCOMM_FRAME_IS_CMD(is_initiator, cr) ((is_initiator) ? (cr) : !(cr))
#define RFCOMM_VALID_DLCI(dlci) ((dlci) <= 0x3F)

#define RFCOMM_PARSE_CTRL_FIELD(ead, cr, dlci, p_data) \
    do { \
        (ead) = *(p_data)&RFCOMM_EA; \
        (cr) = *(p_data)&0x02; \
        (dlci) = *(p_data)++ >> 2; \
    } while (0)

#define RFCOMM_PARSE_TYPE_FIELD(type, pf, p_data) \
    do { \
        (type) = *(p_data)&0xEF; \
        (pf) = *(p_data)&0x10; \
        (p_data)++; \
    } while (0)

#define RFCOMM_TRACE_ERROR(fmt, ...)
#define android_errorWriteLog(a, b)

uint8_t rfc_check_fcs(uint16_t len, uint8_t *p_data, uint8_t fcs);
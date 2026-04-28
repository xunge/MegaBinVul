#include <stdint.h>

typedef struct tRFC_MCB {
    uint8_t flow;
    uint8_t is_initiator;
} tRFC_MCB;

typedef struct MX_FRAME {
    uint8_t cr;
    uint8_t dlci;
    uint8_t type;
    uint8_t pf;
    uint8_t credit;
} MX_FRAME;

typedef struct BT_HDR {
    uint16_t len;
    uint16_t offset;
    uint8_t data[];
} BT_HDR;

#define RFCOMM_EA 0x01
#define RFCOMM_SHIFT_LENGTH1 1
#define RFCOMM_SHIFT_LENGTH2 8
#define RFCOMM_CTRL_FRAME_LEN 3
#define RFCOMM_MX_DLCI 0
#define RFCOMM_VALID_DLCI(dlci) ((dlci) >= 0 && (dlci) <= 30)

#define RFCOMM_SABME 0x2F
#define RFCOMM_UA 0x63
#define RFCOMM_DM 0x0F
#define RFCOMM_DISC 0x43
#define RFCOMM_UIH 0xEF

#define RFC_EVENT_BAD_FRAME 0x00
#define RFC_EVENT_SABME 0x01
#define RFC_EVENT_UA 0x02
#define RFC_EVENT_DM 0x03
#define RFC_EVENT_DISC 0x04
#define RFC_EVENT_UIH 0x05

#define PORT_FC_CREDIT 1

#define RFCOMM_FRAME_IS_CMD(is_initiator, cr) ((is_initiator) ? !(cr) : (cr))
#define RFCOMM_FRAME_IS_RSP(is_initiator, cr) ((is_initiator) ? (cr) : !(cr))

#define RFCOMM_PARSE_CTRL_FIELD(ead, cr, dlci, p_data) \
    do { \
        uint8_t __byte = *(p_data)++; \
        (ead) = __byte & RFCOMM_EA; \
        (cr) = (__byte >> 1) & 0x01; \
        (dlci) = __byte >> 2; \
    } while (0)

#define RFCOMM_PARSE_TYPE_FIELD(type, pf, p_data) \
    do { \
        uint8_t __byte = *(p_data)++; \
        (type) = __byte & 0xEF; \
        (pf) = (__byte >> 4) & 0x01; \
    } while (0)

#define RFCOMM_TRACE_ERROR(fmt, ...) 

uint8_t rfc_check_fcs(uint16_t len, uint8_t* p_data, uint8_t fcs);
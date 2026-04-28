#include <stdint.h>

#define USB_RET_STALL (-1)
#define RNDIS_SET_CMPLT (0x80000002)
#define RNDIS_STATUS_NOT_SUPPORTED (0xC0000000)
#define RNDIS_STATUS_SUCCESS (0x00000000)

typedef struct USBNetState USBNetState;

typedef struct {
    uint32_t MessageType;
    uint32_t MessageLength;
    uint32_t RequestID;
    uint32_t Status;
} rndis_set_cmplt_type;

typedef struct {
    uint32_t MessageType;
    uint32_t MessageLength;
    uint32_t RequestID;
    uint32_t OID;
    uint32_t InformationBufferLength;
    uint32_t InformationBufferOffset;
} rndis_set_msg_type;

static uint32_t le32_to_cpu(uint32_t val) { return val; }
static uint32_t cpu_to_le32(uint32_t val) { return val; }

static rndis_set_cmplt_type *rndis_queue_response(USBNetState *s, unsigned int size);
static int ndis_set(USBNetState *s, uint32_t oid, uint8_t *data, uint32_t len);
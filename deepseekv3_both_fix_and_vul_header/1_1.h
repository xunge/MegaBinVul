#include <stdint.h>
#include <string.h>

typedef struct USBNetState USBNetState;

typedef struct rndis_query_msg_type {
    uint32_t MessageType;
    uint32_t MessageLength;
    uint32_t RequestID;
    uint32_t OID;
    uint32_t InformationBufferLength;
    uint32_t InformationBufferOffset;
} rndis_query_msg_type;

typedef struct rndis_query_cmplt_type {
    uint32_t MessageType;
    uint32_t MessageLength;
    uint32_t RequestID;
    uint32_t Status;
    uint32_t InformationBufferLength;
    uint32_t InformationBufferOffset;
} rndis_query_cmplt_type;

#define RNDIS_QUERY_CMPLT 0x80000002
#define RNDIS_STATUS_SUCCESS 0
#define RNDIS_STATUS_NOT_SUPPORTED 0xC0000001

static uint32_t oid_supported_list[1];

static uint32_t le32_to_cpu(uint32_t val) {
    return val;
}

static uint32_t cpu_to_le32(uint32_t val) {
    return val;
}

static int ndis_query(USBNetState *s, uint32_t oid, uint8_t *buf, uint32_t len, uint8_t *infobuf, uint32_t infobuflen) {
    return 0;
}

static void *rndis_queue_response(USBNetState *s, unsigned int resplen) {
    return NULL;
}

#define USB_RET_STALL 1
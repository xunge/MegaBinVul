#include <stdint.h>

typedef uint16_t btif_sm_event_t;

#define BTA_AV_META_MSG_EVT 0
#define AVRC_OP_VENDOR 0
#define AVRC_OP_BROWSE 0

typedef struct {
    uint8_t opcode;
} tAVRC_HDR;

typedef struct {
    void* p_vendor_data;
} tAVRC_VENDOR;

typedef struct {
    void* p_browse_data;
} tAVRC_BROWSE;

typedef struct {
    tAVRC_HDR hdr;
    tAVRC_VENDOR vendor;
    tAVRC_BROWSE browse;
} tAVRC_MSG;

typedef struct {
    tAVRC_MSG* p_msg;
    void* p_data;
} tBTA_AV_META_MSG;

typedef struct {
    tBTA_AV_META_MSG meta_msg;
} tBTA_AV;

void osi_free(void* ptr);
void osi_free_and_reset(void** ptr);
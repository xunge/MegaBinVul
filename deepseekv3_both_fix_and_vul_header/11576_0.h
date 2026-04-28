#include <stdint.h>
#include <string.h>

#define BTIF_TRACE_DEBUG(fmt, ...)
#define BTA_AV_META_MSG_EVT 0
#define AVRC_OP_VENDOR 0
#define AVRC_OP_BROWSE 0

typedef struct {
    uint8_t opcode;
} tAVRC_HDR;

typedef struct {
    uint8_t* p_vendor_data;
    uint16_t vendor_len;
} tAVRC_VENDOR;

typedef struct {
    uint8_t* p_browse_data;
    uint16_t browse_len;
} tAVRC_BROWSE;

typedef struct {
    tAVRC_HDR hdr;
    tAVRC_VENDOR vendor;
    tAVRC_BROWSE browse;
} tAVRC_MSG;

typedef struct {
    uint8_t* p_data;
    uint16_t len;
    tAVRC_MSG* p_msg;
} tBTA_AV_META_MSG;

typedef struct {
    tBTA_AV_META_MSG meta_msg;
} tBTA_AV;

void* osi_calloc(size_t size);
void maybe_non_aligned_memcpy(void* dest, const void* src, size_t len);
void android_errorWriteLog(uint32_t tag, const char* msg);
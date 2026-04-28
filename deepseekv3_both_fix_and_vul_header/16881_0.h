#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BT_TRACE_LEVEL_DEBUG 0
#define SDP_MAX_REC_ATTR 0
#define SDP_MAX_PAD_LEN 0

typedef struct {
    uint8_t* value_ptr;
    uint16_t id;
    uint8_t type;
    uint32_t len;
} tSDP_ATTRIBUTE;

typedef struct {
    uint32_t record_handle;
    tSDP_ATTRIBUTE attribute[SDP_MAX_REC_ATTR];
    uint16_t num_attributes;
    uint8_t attr_pad[SDP_MAX_PAD_LEN];
    uint16_t free_pad_ptr;
} tSDP_RECORD;

typedef struct {
    struct {
        tSDP_RECORD record[1];
        uint16_t num_records;
    } server_db;
    int trace_level;
} tSDP_CB;

extern tSDP_CB sdp_cb;

#define UINT_DESC_TYPE 0
#define TWO_COMP_INT_DESC_TYPE 0
#define UUID_DESC_TYPE 0
#define DATA_ELE_SEQ_DESC_TYPE 0
#define DATA_ELE_ALT_DESC_TYPE 0
#define BOOLEAN_DESC_TYPE 0
#define TEXT_STR_DESC_TYPE 0
#define URL_DESC_TYPE 0

#define SDP_TRACE_DEBUG(...)
#define SDP_TRACE_WARNING(...)
#define SDP_TRACE_ERROR(...)

bool SDP_DeleteAttribute(uint32_t handle, uint16_t attr_id);
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SDP_DEBUG_RAW TRUE
#define SDP_MAX_LIST_BYTE_COUNT 256
#define SDP_TRACE_WARNING(fmt, ...)

typedef struct {
    uint8_t* raw_data;
    uint32_t raw_size;
    uint32_t raw_used;
} tSDP_DISCOVERY_DB;

typedef struct {
    tSDP_DISCOVERY_DB* p_db;
    uint8_t rsp_list[SDP_MAX_LIST_BYTE_COUNT];
    uint32_t list_len;
} tCONN_CB;

uint8_t* sdpu_get_len_from_type(uint8_t* p, uint8_t type, uint32_t* p_len);
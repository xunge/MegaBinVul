#include <stdint.h>
#include <string.h>

typedef struct LHAInputStream LHAInputStream;
typedef struct LHAFileHeader LHAFileHeader;

#define LEVEL_3_HEADER_LEN 28
#define LEVEL_3_MAX_HEADER_LEN 1024

struct LHAFileHeader {
    uint8_t raw_data[LEVEL_3_MAX_HEADER_LEN];
    size_t raw_data_len;
    char compress_method[6];
    uint32_t compressed_length;
    uint32_t length;
    uint32_t timestamp;
    uint16_t crc;
    uint8_t os_type;
};

#define RAW_DATA(header, offset) ((*header)->raw_data[(offset)])
#define RAW_DATA_LEN(header) ((*header)->raw_data_len)

extern int lha_decode_uint16(const uint8_t *data);
extern uint32_t lha_decode_uint32(const uint8_t *data);
extern int extend_raw_data(LHAFileHeader **header, LHAInputStream *stream, size_t len);
extern int decode_extended_headers(LHAFileHeader **header, unsigned int offset);
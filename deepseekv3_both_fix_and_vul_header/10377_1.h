#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEVEL_3_MAX_HEADER_LEN 1024

typedef struct LHAInputStream LHAInputStream;

typedef struct LHAFileHeader {
    uint8_t *raw_data;
    size_t raw_data_len;
} LHAFileHeader;

#define RAW_DATA_LEN(header) ((*header)->raw_data_len)

bool lha_input_stream_read(LHAInputStream *stream, void *buf, size_t buf_len);
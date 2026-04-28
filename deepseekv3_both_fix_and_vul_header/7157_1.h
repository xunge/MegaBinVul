#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <endian.h>

#define ERR_DECODE (-1)

struct wire_field_hdr {
    uint16_t len;
    uint16_t max_len;
    uint32_t offset;
};

struct ntlm_buffer {
    size_t length;
    uint8_t *data;
};
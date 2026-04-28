#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>

#define ERR_DECODE (-1)
#define ENOMEM (-2)

struct wire_field_hdr {
    uint16_t len;
    uint32_t offset;
};

struct ntlm_buffer {
    uint8_t *data;
    size_t length;
};
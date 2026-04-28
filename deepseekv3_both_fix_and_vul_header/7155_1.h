#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

#define ERR_DECODE (-1)
#define ENOMEM (-2)

struct ntlm_ctx {
    int to_oem;
};

struct wire_field_hdr {
    uint16_t len;
    uint32_t offset;
};

struct ntlm_buffer {
    uint8_t *data;
    size_t length;
};

static int ntlm_str_convert(int to_oem, char *in, char *out, uint16_t str_len, size_t *outlen);

#define safefree(ptr) free(ptr)
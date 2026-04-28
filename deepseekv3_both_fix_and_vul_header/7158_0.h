#include <stdint.h>
#include <stdlib.h>

#define ERR_DECODE (-1)
#define ENOMEM (-2)

#define le16toh(x) (x)
#define le32toh(x) (x)

#define safefree(ptr) free(ptr)

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

int ntlm_str_convert(int to_oem, char *in, char *out, uint16_t str_len, size_t *outlen);
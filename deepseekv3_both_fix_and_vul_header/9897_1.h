#include <stddef.h>
#include <stdint.h>

#define unlikely(x) (x)

typedef struct hb_glyph_info_t {
    uint32_t codepoint;
    uint32_t mask;
    uint32_t cluster;
    uint32_t var1;
    uint32_t var2;
} hb_glyph_info_t;

typedef struct hb_buffer_t {
    hb_glyph_info_t *info;
    hb_glyph_info_t *out_info;
    unsigned int i;
    unsigned int out_len;
    unsigned int have_output : 1;
} hb_buffer_t;

int hb_buffer_ensure(hb_buffer_t *buffer, unsigned int size);
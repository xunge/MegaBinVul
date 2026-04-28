#include <stdint.h>

#define unlikely(x) (x)
#define HB_BUFFER_GLYPH_PROPERTIES_UNKNOWN 0

typedef struct hb_internal_glyph_info_t {
    uint16_t codepoint;
    unsigned int mask;
    unsigned int cluster;
    unsigned short component;
    unsigned short lig_id;
    unsigned int gproperty;
} hb_internal_glyph_info_t;

typedef struct hb_buffer_t {
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    unsigned int out_len;
    unsigned int i;
} hb_buffer_t;

uint16_t hb_be_uint16(uint16_t v);
int hb_buffer_ensure_separate(hb_buffer_t *buffer, unsigned int size);
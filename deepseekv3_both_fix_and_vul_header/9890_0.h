#include <stddef.h>

#define HB_BUFFER_GLYPH_PROPERTIES_UNKNOWN 0
#define unlikely(x) (x)

typedef unsigned int hb_codepoint_t;

typedef struct {
    hb_codepoint_t codepoint;
    unsigned short component;
    unsigned short lig_id;
    unsigned int gproperty;
} hb_internal_glyph_info_t;

typedef struct {
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    unsigned int i;
    unsigned int out_len;
} hb_buffer_t;

int hb_buffer_ensure(hb_buffer_t *buffer, unsigned int size);
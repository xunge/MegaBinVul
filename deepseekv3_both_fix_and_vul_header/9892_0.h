#include <assert.h>
#include <stddef.h>

typedef struct hb_internal_glyph_info_t hb_internal_glyph_info_t;
typedef struct hb_internal_glyph_position_t hb_internal_glyph_position_t;

typedef struct {
    unsigned int have_output;
    unsigned int in_error;
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    hb_internal_glyph_position_t *pos;
    unsigned int len;
    unsigned int out_len;
    unsigned int i;
} hb_buffer_t;

#define unlikely(x) (x)
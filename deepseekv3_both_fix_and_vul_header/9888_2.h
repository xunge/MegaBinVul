#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef bool hb_bool_t;
#define FALSE false
#define TRUE true
#define unlikely(x) (x)

typedef struct hb_internal_glyph_position_t {
    int dummy;
} hb_internal_glyph_position_t;

typedef struct hb_internal_glyph_info_t {
    int dummy;
} hb_internal_glyph_info_t;

typedef struct hb_buffer_t {
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    hb_internal_glyph_position_t *pos;
    unsigned int allocated;
    unsigned int out_len;
    unsigned int have_output;
} hb_buffer_t;

extern hb_bool_t hb_buffer_ensure(hb_buffer_t *buffer, unsigned int size);
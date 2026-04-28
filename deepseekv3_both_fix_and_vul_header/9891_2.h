#include <stdbool.h>
#include <stdlib.h>

#define FALSE false
#define TRUE true

typedef bool hb_bool_t;

struct hb_internal_glyph_position_t {
    int dummy;
};

struct hb_internal_glyph_info_t {
    int dummy;
};

struct hb_buffer_t {
    unsigned int allocated;
    hb_internal_glyph_position_t *pos;
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    bool in_error;
};

#define likely(x) (x)
#define unlikely(x) (x)
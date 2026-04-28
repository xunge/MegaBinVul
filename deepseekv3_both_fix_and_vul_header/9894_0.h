#include <stddef.h>
#include <stdint.h>

typedef uint32_t hb_codepoint_t;

typedef enum {
    HB_BUFFER_GLYPH_PROPERTIES_UNKNOWN
} hb_buffer_glyph_properties_t;

typedef struct {
    hb_codepoint_t codepoint;
    unsigned int mask;
    unsigned int cluster;
    unsigned short component;
    unsigned short lig_id;
    hb_buffer_glyph_properties_t gproperty;
} hb_internal_glyph_info_t;

typedef struct {
    hb_internal_glyph_info_t *info;
    hb_internal_glyph_info_t *out_info;
    unsigned int i;
    unsigned int out_len;
} hb_buffer_t;

#define unlikely(x) (x)

int hb_buffer_ensure_separate(hb_buffer_t *buffer, unsigned int size);
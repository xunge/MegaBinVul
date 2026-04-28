#include <stdint.h>
#include <stddef.h>

typedef uint32_t hb_codepoint_t;
typedef uint32_t hb_mask_t;

#define HB_BUFFER_GLYPH_PROPERTIES_UNKNOWN 0
#define unlikely(x) (x)

typedef struct {
    hb_codepoint_t codepoint;
    hb_mask_t mask;
    unsigned int cluster;
    unsigned int component;
    unsigned int lig_id;
    unsigned int gproperty;
} hb_internal_glyph_info_t;

typedef struct {
    hb_internal_glyph_info_t *info;
    unsigned int len;
} hb_buffer_t;

int hb_buffer_ensure(hb_buffer_t *buffer, unsigned int size);
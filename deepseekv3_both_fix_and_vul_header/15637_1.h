#include <string.h>
#include <stdlib.h>

typedef unsigned short ushort;
typedef unsigned int gs_glyph;
typedef unsigned int gs_char;

typedef struct gs_const_string {
    const unsigned char *data;
    unsigned int size;
} gs_const_string;

typedef struct gs_font_procs {
    int (*decode_glyph)(struct gs_font *font, gs_glyph glyph, gs_char ch, unsigned short *unicode, int length);
    int (*glyph_name)(struct gs_font *font, gs_glyph glyph, gs_const_string *gnstr);
} gs_font_procs;

typedef struct gs_font {
    gs_font_procs procs;
} gs_font;

typedef struct gx_device {
    void *memory;
} gx_device;

typedef struct textw_text_enum {
    gx_device *dev;
} textw_text_enum_t;

typedef struct single_glyph_list {
    const char *Glyph;
    unsigned short Unicode;
} single_glyph_list_t;

typedef struct double_glyph_list {
    const char *Glyph;
    unsigned short Unicode[2];
} double_glyph_list_t;

typedef struct treble_glyph_list {
    const char *Glyph;
    unsigned short Unicode[3];
} treble_glyph_list_t;

typedef struct quad_glyph_list {
    const char *Glyph;
    unsigned short Unicode[4];
} quad_glyph_list_t;

extern single_glyph_list_t SingleGlyphList[];
extern double_glyph_list_t DoubleGlyphList[];
extern treble_glyph_list_t TrebleGlyphList[];
extern quad_glyph_list_t QuadGlyphList[];

#define GS_NO_GLYPH ((gs_glyph)0)
#define ARCH_IS_BIG_ENDIAN 0

void *gs_alloc_bytes(void *memory, size_t size, const char *cname);
void gs_free_object(void *memory, void *ptr, const char *cname);
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint8_t u8;
typedef bool Bool;

#define GF_OK 0
#define GF_OUT_OF_MEM -1
#define GF_NON_COMPLIANT_BITSTREAM -2

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_LOG(level, category, message)

typedef struct {
    u32 x, y;
} SWFRec;

typedef struct {
    u16 fontID;
    u32 nbGlyphs;
    char *fontName;
    Bool has_layout;
    Bool has_shiftJIS;
    Bool is_unicode;
    Bool is_ansi;
    Bool is_italic;
    Bool is_bold;
    s16 ascent;
    s16 descent;
    s16 leading;
    s16 *glyph_adv;
    u16 *glyph_codes;
    void *glyphs;
} SWFFont;

typedef struct {
    void *fonts;
    u32 file_pos;
} SWFReader;

static u32 swf_get_16(SWFReader *read);
static u32 swf_get_32(SWFReader *read);
static s16 swf_get_s16(SWFReader *read);
static u32 swf_read_int(SWFReader *read, u32 bits);
static void swf_align(SWFReader *read);
static u32 swf_get_file_pos(SWFReader *read);
static GF_Err swf_seek_file_to(SWFReader *read, u32 pos);
static void swf_get_rec(SWFReader *read, SWFRec *rc);
static GF_Err swf_parse_shape_def(SWFReader *read, SWFFont *ft, u32 flags);
static void *gf_list_new();
static void gf_list_add(void *list, void *item);
static void *gf_malloc(size_t size);
static void gf_free(void *ptr);
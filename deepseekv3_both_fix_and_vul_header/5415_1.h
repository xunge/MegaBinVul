#include <stdlib.h>
#include <string.h>

typedef long FT_Long;
typedef unsigned char FT_Byte;
typedef int FT_Error;
typedef struct FT_MemoryRec_* FT_Memory;

#define FT_UNUSED(x) (void)(x)
#define FT_THROW(e) (-1)
#define FT_Err_Ok 0
#define FT_ERROR(x) 
#define FT_TRACE2(x) 
#define FT_TRACE4(x) 
#define FT_NEW_ARRAY(p, count) (-1)
#define FT_RENEW_ARRAY(p, oldcnt, newcnt) (-1)
#define FT_FREE(p) free(p)
#define FT_MEM_COPY(dest, src, size) memcpy(dest, src, size)
#define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
#define FT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define FT_MulDiv(a, b, c) ((a) * (b) / (c))

#define _BDF_GLYPHS 0x01
#define _BDF_START 0x02
#define _BDF_GLYPH_BITS 0x04
#define _BDF_GLYPH 0x08
#define _BDF_ENCODING 0x10
#define _BDF_SWIDTH 0x20
#define _BDF_DWIDTH 0x40
#define _BDF_BBX 0x80
#define _BDF_BITMAP 0x100
#define _BDF_GLYPH_WIDTH_CHECK 0x200
#define _BDF_GLYPH_HEIGHT_CHECK 0x400
#define _BDF_SWIDTH_ADJ 0x800

#define ERRMSG1 "line %lu: missing `%s' field\n"
#define ERRMSG4 "line %lu: bitmap dimensions too large\n"
#define ERRMSG5 "line %lu: too many %s\n"
#define ERRMSG8 "line %lu: invalid `%s' field\n"
#define ERRMSG9 "line %lu: syntax error\n"
#define ACMSG9 "line %lu: missing `SWIDTH' field, auto-correcting\n"
#define ACMSG10 "line %lu: missing `DWIDTH' field, auto-correcting\n"
#define ACMSG12 "glyph 0x%X: duplicate encoding moved to unencoded\n"
#define ACMSG13 "glyph 0x%X: too many rows, truncated\n"
#define ACMSG14 "glyph 0x%X: extra columns removed\n"
#define ACMSG16 "glyph 0x%X: missing columns padded with 0\n"
#define DBGMSG1 "line %lu: STARTCHAR %s\n"
#define DBGMSG2 "ENCODING %d\n"

typedef struct {
    short width;
    short height;
    short x_offset;
    short y_offset;
    short ascent;
    short descent;
} bdf_bbx_t;

typedef struct {
    char* name;
    int encoding;
    unsigned short swidth;
    unsigned short dwidth;
    bdf_bbx_t bbx;
    unsigned short bpr;
    unsigned short bytes;
    unsigned char* bitmap;
} bdf_glyph_t;

typedef struct {
    bdf_glyph_t* glyphs;
    unsigned long glyphs_size;
    unsigned long glyphs_used;
    bdf_glyph_t* unencoded;
    unsigned long unencoded_size;
    unsigned long unencoded_used;
    unsigned long* umod;
    unsigned long* nmod;
    int modified;
    int point_size;
    int resolution_x;
    int bpp;
    FT_Memory memory;
} bdf_font_t;

typedef struct {
    char** field;
    unsigned long used;
} _bdf_list_t;

typedef struct {
    bdf_font_t* font;
    _bdf_list_t list;
    unsigned long* have;
    char* glyph_name;
    int glyph_enc;
    unsigned long cnt;
    unsigned long row;
    short maxas;
    short maxds;
    short maxrb;
    short minlb;
    short maxlb;
    short rbearing;
    int flags;
    struct {
        int keep_unencoded;
        int correct_metrics;
    } *opts;
} _bdf_parse_t;

static int _bdf_strncmp(const char* a, const char* b, size_t n) { return strncmp(a, b, n); }
static FT_Error _bdf_list_split(_bdf_list_t* list, char* sep, char* line, unsigned long linelen) { return 0; }
static void _bdf_list_shift(_bdf_list_t* list, int n) {}
static char* _bdf_list_join(_bdf_list_t* list, char sep, unsigned long* len) { return NULL; }
static unsigned long _bdf_atoul(char* s, char** end, int base) { return 0; }
static long _bdf_atol(char* s, char** end, int base) { return 0; }
static short _bdf_atos(char* s, char** end, int base) { return 0; }
static FT_Error _bdf_add_comment(bdf_font_t* font, char* s, unsigned long len) { return 0; }
static int _bdf_glyph_modified(unsigned long* have, int enc) { return 0; }
static void _bdf_set_glyph_modified(unsigned long* have, int enc) {}
static void ft_qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {}
static int by_encoding(const void* a, const void* b) { return 0; }
static int sbitset(const char* set, int c) { return 0; }

static const char hdigits[] = "0123456789ABCDEF";
static const unsigned char a2i[128] = {0};
static const unsigned char nibble_mask[8] = {0};
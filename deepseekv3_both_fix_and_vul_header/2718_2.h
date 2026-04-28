#include <stdlib.h>
#include <string.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef long FT_Long;

typedef struct {
    int width;
    int height;
    int x_offset;
    int y_offset;
    int ascent;
    int descent;
} bdf_bbx_t;

typedef struct bdf_glyph_t {
    char* name;
    int encoding;
    bdf_bbx_t bbx;
    unsigned short swidth;
    unsigned short dwidth;
    unsigned short bpr;
    unsigned short bytes;
    unsigned char* bitmap;
} bdf_glyph_t;

typedef struct {
    int keep_unencoded;
    int correct_metrics;
} bdf_options_t;

typedef struct {
    bdf_glyph_t* glyphs;
    unsigned long glyphs_size;
    unsigned long glyphs_used;
    bdf_glyph_t* unencoded;
    unsigned long unencoded_size;
    unsigned long unencoded_used;
    FT_Memory memory;
    int point_size;
    int resolution_x;
    int modified;
    void* umod;
    void* nmod;
    int bpp;
} bdf_font_t;

typedef struct {
    char** field;
    unsigned long used;
} bdf_list_t;

typedef struct {
    bdf_font_t* font;
    bdf_list_t list;
    unsigned long cnt;
    int flags;
    int glyph_enc;
    char* glyph_name;
    unsigned long row;
    void* have;
    bdf_options_t* opts;
    short maxas;
    short maxds;
    short rbearing;
    short maxrb;
    short minlb;
    short maxlb;
} _bdf_parse_t;

#define FT_UNUSED(x) (void)(x)
#define FT_NEW_ARRAY(var, count) ((var = malloc((count) * sizeof(*var))) == NULL)
#define FT_RENEW_ARRAY(var, old_count, new_count) ((var = realloc(var, (new_count) * sizeof(*var))) == NULL)
#define FT_FREE(var) do { free(var); var = NULL; } while (0)
#define FT_MEM_COPY(dest, src, size) memcpy(dest, src, size)
#define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
#define FT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define FT_MulDiv(a, b, c) ((a) * (b) / (c))

#define BDF_Err_Ok 0
#define BDF_Err_Missing_Chars_Field 1
#define BDF_Err_Invalid_Argument 2
#define BDF_Err_Missing_Startchar_Field 3
#define BDF_Err_Invalid_File_Format 4
#define BDF_Err_Missing_Encoding_Field 5
#define BDF_Err_Missing_Bbx_Field 6
#define BDF_Err_Bbx_Too_Big 7

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

static const char hdigits[] = "0123456789ABCDEF";
static const unsigned char a2i[128] = {0};
static const unsigned char nibble_mask[8] = {0};

static int ft_memcmp(const char *s1, const char *s2, size_t n) {
    return memcmp(s1, s2, n);
}

static int sbitset(const char *s, int c) {
    return strchr(s, c) != NULL;
}

static void ft_qsort(void *base, size_t nmemb, size_t size, 
                    int (*compar)(const void *, const void *)) {
    qsort(base, nmemb, size, compar);
}

static int by_encoding(const void *a, const void *b) {
    return ((const bdf_glyph_t*)a)->encoding - ((const bdf_glyph_t*)b)->encoding;
}

static unsigned long _bdf_atoul(const char *s, int base, int size) {
    return strtoul(s, NULL, base);
}

static int _bdf_atol(const char *s, int base, int size) {
    return strtol(s, NULL, base);
}

static short _bdf_atos(const char *s, int base, int size) {
    return (short)strtol(s, NULL, base);
}

static FT_Error _bdf_add_comment(bdf_font_t *font, char *s, unsigned long linelen) {
    return BDF_Err_Ok;
}

static FT_Error _bdf_list_split(bdf_list_t *list, char *delim, char *line, unsigned long linelen) {
    return BDF_Err_Ok;
}

static void _bdf_list_shift(bdf_list_t *list, int n) {
}

static char *_bdf_list_join(bdf_list_t *list, char delim, unsigned long *slen) {
    return NULL;
}

static int _bdf_glyph_modified(const void *have, int enc) {
    return 0;
}

static void _bdf_set_glyph_modified(void *have, int enc) {
}

#define FT_ERROR(args) 
#define FT_TRACE2(args) 
#define FT_TRACE4(args) 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct bdf_property_t_ bdf_property_t;
typedef struct bdf_font_t_ bdf_font_t;
typedef struct _bdf_parse_t_ _bdf_parse_t;
typedef struct hashtable_ {
    int dummy;
} hashtable;
typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;

typedef FT_Error (*_bdf_line_func_t)( char*,
                                     unsigned long,
                                     unsigned long,
                                     void*,
                                     void* );

#define FT_Err_Ok 0
#define Missing_Startfont_Field 1
#define Missing_Fontboundingbox_Field 2
#define Missing_Size_Field 3
#define Missing_Font_Field 4
#define Invalid_File_Format 5
#define FT_THROW(e) (e)
#define FT_NEW(p) (0)
#define FT_NEW_ARRAY(p, n) (0)
#define FT_ALLOC(p, s) (0)
#define FT_FREE(p) free(p)
#define FT_MEM_COPY(d, s, n) memcpy(d, s, n)
#define FT_UNUSED(x) (void)(x)
#define FT_ERROR(x) 
#define FT_TRACE2(x)

#define _BDF_START 0x01
#define _BDF_FONT_NAME 0x02
#define _BDF_SIZE 0x04
#define _BDF_FONT_BBX 0x08
#define _BDF_PROPS 0x10

#define ERRMSG1 "Missing `%s' field.\n"
#define ERRMSG8 "Invalid `%s' field.\n"
#define ERRMSG9 "Syntax error at line %ld.\n"
#define ACMSG1 "Setting font ascent to %hd.\n"
#define ACMSG2 "Setting font descent to %hd.\n"
#define ACMSG11 "Setting bpp to %hd.\n"

struct bdf_property_t_ {
    char* name;
};

struct bdf_font_t_ {
    FT_Memory memory;
    void* internal;
    short spacing;
    int default_char;
    int modified;
    int font_ascent;
    int font_descent;
    struct {
        short width;
        short height;
        short x_offset;
        short y_offset;
        short ascent;
        short descent;
    } bbx;
    char* name;
    unsigned short bpp;
    unsigned long point_size;
    unsigned long resolution_x;
    unsigned long resolution_y;
    size_t props_size;
    bdf_property_t* props;
    hashtable proptbl;
};

struct _bdf_parse_t_ {
    bdf_font_t* font;
    FT_Memory memory;
    unsigned long flags;
    struct {
        char** field;
        unsigned long used;
    } list;
    unsigned long cnt;
    struct {
        int keep_comments;
        short font_spacing;
    }* opts;
};

static bdf_property_t _bdf_properties[] = {0};
static size_t _num_bdf_properties = 0;

static int _bdf_strncmp(const char* s1, const char* s2, size_t n) { return 0; }
static int ft_strncmp(const char* s1, const char* s2, size_t n) { return 0; }
static unsigned long _bdf_atoul(const char* s, char** end, int base) { return 0; }
static short _bdf_atos(const char* s, char** end, int base) { return 0; }
static FT_Error _bdf_add_comment(bdf_font_t* font, char* s, unsigned long linelen) { return 0; }
static FT_Error _bdf_list_split(void* list, char* sep, char* line, unsigned long linelen) { return 0; }
static void _bdf_list_shift(void* list, int shift) {}
static char* _bdf_list_join(void* list, char sep, unsigned long* slen) { return 0; }
static FT_Error _bdf_set_default_spacing(bdf_font_t* font, void* opts, unsigned long lineno) { return 0; }
static FT_Error _bdf_add_property(bdf_font_t* font, char* name, char* value, unsigned long lineno) { return 0; }
static FT_Error _bdf_parse_glyphs(char* line, unsigned long linelen, unsigned long lineno, void* call_data, void* client_data) { return 0; }
static FT_Error _bdf_parse_properties(char* line, unsigned long linelen, unsigned long lineno, void* call_data, void* client_data) { return 0; }
static FT_Error hash_init(hashtable* table, FT_Memory memory) { return 0; }
static FT_Error hash_insert(char* name, size_t idx, hashtable* table, FT_Memory memory) { return 0; }
static int ft_sprintf(char* buf, const char* fmt, ...) { return 0; }
#include <stddef.h>

typedef int FT_Error;
#define FT_Err_Ok 0
#define FT_UNUSED(x) (void)(x)
#define FT_TRACE2(x)
#define ACMSG1 ""
#define ACMSG2 ""
#define _BDF_PROPS 0x01

struct _bdf_bbx_t {
    short ascent;
    short descent;
};

struct _bdf_font_t {
    struct _bdf_bbx_t bbx;
    short font_ascent;
    short font_descent;
    int modified;
};

struct _bdf_list_t {
    char** field;
};

struct _bdf_parse_t {
    struct _bdf_font_t* font;
    struct _bdf_list_t list;
    unsigned int flags;
};

typedef FT_Error (*_bdf_line_func_t)(char*, unsigned long, unsigned long, void*, void*);

extern int ft_strncmp(const char*, const char*, size_t);
extern int ft_sprintf(char*, const char*, ...);
extern void* bdf_get_font_property(struct _bdf_font_t*, const char*);
extern FT_Error _bdf_add_property(struct _bdf_font_t*, char*, char*, unsigned long);
extern int _bdf_is_atom(char*, unsigned long, char**, char**, struct _bdf_font_t*);
extern FT_Error _bdf_list_split(struct _bdf_list_t*, char*, char*, unsigned long);
extern void _bdf_list_shift(struct _bdf_list_t*, int);
extern char* _bdf_list_join(struct _bdf_list_t*, char, unsigned long*);
extern FT_Error _bdf_parse_glyphs(char*, unsigned long, unsigned long, void*, void*);

typedef struct _bdf_parse_t _bdf_parse_t;
typedef struct _bdf_font_t _bdf_font_t;
typedef struct _bdf_list_t _bdf_list_t;
typedef struct _bdf_bbx_t _bdf_bbx_t;
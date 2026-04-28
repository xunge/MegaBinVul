#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct hashnode_ {
    size_t data;
    struct hashnode_* next;
} *hashnode;

typedef struct hashtable_ {
    hashnode* table;
    size_t size;
} *hashtable;

typedef enum {
    BDF_ATOM,
    BDF_INTEGER,
    BDF_CARDINAL
} bdf_property_format;

typedef struct {
    char* name;
    bdf_property_format format;
    int builtin;
    union {
        char* atom;
        long l;
        unsigned long ul;
    } value;
} bdf_property_t;

typedef struct {
    void* memory;
    hashtable internal;
    hashtable proptbl;
    bdf_property_t* props;
    size_t props_used;
    size_t props_size;
    bdf_property_t* user_props;
    long default_char;
    long font_ascent;
    long font_descent;
    int spacing;
} bdf_font_t;

typedef int FT_Error;
typedef void* FT_Memory;

#define FT_UNUSED(x) (void)(x)
#define FT_Err_Ok 0
#define Invalid_File_Format 1
#define FT_THROW(x) (x)
#define FT_FREE(x) free(x)
#define FT_STRDUP(dest, src) (dest = strdup(src)) ? 0 : 1
#define FT_NEW_ARRAY(p, count) (p = malloc(sizeof(*(p)) * (count))) ? 0 : 1
#define FT_RENEW_ARRAY(p, old, new) (p = realloc(p, sizeof(*(p)) * (new))) ? 0 : 1
#define FT_MEM_ZERO(p, size) memset(p, 0, size)
#define ERRMSG8 "error message"
#define FT_ERROR(args) fprintf(stderr, args)

enum {
    BDF_PROPORTIONAL,
    BDF_MONOWIDTH,
    BDF_CHARCELL
};

extern size_t _num_bdf_properties;
extern bdf_property_t _bdf_properties[];

extern FT_Error bdf_create_property(char* name, bdf_property_format format, bdf_font_t* font);
extern long _bdf_atol(char* s, char** end, int base);
extern unsigned long _bdf_atoul(char* s, char** end, int base);
extern int _bdf_strncmp(const char* s1, const char* s2, size_t n);
extern int ft_strncmp(const char* s1, const char* s2, size_t n);
extern hashnode hash_lookup(char* name, hashtable tbl);
extern FT_Error hash_insert(char* name, size_t data, hashtable tbl, FT_Memory memory);
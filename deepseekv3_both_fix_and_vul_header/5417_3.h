#include <stddef.h>
#include <string.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;
typedef unsigned short FT_UShort;
typedef int FT_Int;
typedef unsigned char FT_Byte;
typedef char FT_String;

typedef struct T42_FaceRec_* T42_Face;
typedef struct T42_ParserRec_* T42_Parser;
typedef struct T1_FontRec_* T1_Font;
typedef struct PSAux_ServiceRec_* PSAux_Service;

typedef struct {
    FT_Byte* block;
    FT_Byte** elements;
    size_t* lengths;
    int init;
} T42_CharStrings;

typedef struct {
    FT_Byte* block;
    void** elements;
    size_t max_elems;
} T42_Table;

typedef struct T42_ParserRec_ {
    void* base_dict;
    size_t base_len;
} T42_ParserRec;

typedef struct T42_LoaderRec_ {
    T42_Table encoding_table;
    T42_CharStrings charstrings;
    T42_Table glyph_names;
    int num_glyphs;
    int num_chars;
    T42_ParserRec parser;
} T42_LoaderRec;

typedef struct {
    FT_UShort* char_index;
    char** char_name;
    int code_first;
    int code_last;
    int num_chars;
} T1_Encoding;

typedef struct T1_FontRec_ {
    int font_type;
    int num_glyphs;
    FT_Byte* charstrings_block;
    FT_Byte** charstrings;
    size_t* charstrings_len;
    FT_Byte* glyph_names_block;
    FT_String** glyph_names;
    int encoding_type;
    T1_Encoding encoding;
} T1_FontRec;

typedef struct FT_FaceRec_ {
    FT_Memory memory;
    void* stream;
} FT_FaceRec;

typedef struct T42_FaceRec_ {
    FT_FaceRec root;
    T1_FontRec type1;
    void* psaux;
    FT_Byte* ttf_data;
    size_t ttf_size;
} T42_FaceRec;

#define FT_ALLOC(ptr, size) (0)
#define FT_THROW(err) (err)
#define FT_ERROR(args)

static int ft_strcmp(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

static void t42_loader_init(T42_LoaderRec* loader, T42_Face face) {}
static void t42_loader_done(T42_LoaderRec* loader) {}
static FT_Error t42_parser_init(T42_Parser parser, void* stream, FT_Memory memory, PSAux_Service psaux) { return 0; }
static FT_Error t42_parse_dict(T42_Face face, T42_LoaderRec* loader, void* base_dict, size_t base_len) { return 0; }

enum {
    T1_ENCODING_TYPE_ARRAY,
    T42_FONT_TYPE = 42,
    Unknown_File_Format,
    Invalid_File_Format
};
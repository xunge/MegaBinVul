#include <string.h>
#include <ctype.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef long FT_PtrDist;

typedef struct PS_Table_ {
    FT_Byte** elements;
    size_t* lengths;
} *PS_Table;

typedef struct FT_StreamRec_ {
    FT_Memory memory;
    FT_Byte* cursor;
    FT_Byte* limit;
    FT_Error error;
} FT_StreamRec;

typedef struct T42_Parser_ {
    FT_StreamRec root;
} *T42_Parser;

typedef struct T42_Loader_ {
    FT_UInt num_glyphs;
    struct PS_Table_ charstrings;
    struct PS_Table_ glyph_names;
    struct PS_Table_ swap_table;
    struct T42_Parser_ parser;
} *T42_Loader;

typedef struct PSAux_Service_ {
    struct {
        FT_Error (*init)(PS_Table, FT_UInt, FT_Memory);
    } *ps_table_funcs;
} *PSAux_Service;

typedef struct T42_Face_ {
    struct PSAux_Service_* psaux;
} *T42_Face;

#define FT_THROW(e) (-1)
#define FT_ERROR(x)

static int ft_isdigit(int c) { return isdigit(c); }
static int ft_strcmp(const char* s1, const char* s2) { return strcmp(s1, s2); }
static int t42_is_space(FT_Byte c) { return isspace(c); }

static int T1_ToInt(T42_Parser parser) { return 0; }
static void T1_Skip_Spaces(T42_Parser parser) {}
static void T1_Skip_PS_Token(T42_Parser parser) {}
static FT_Error T1_Add_Table(PS_Table table, FT_UInt idx, FT_Byte* data, size_t len) { return 0; }
#include <string.h>
#include <stddef.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef int FT_Int;
typedef unsigned int FT_UInt;
typedef long FT_Long;
typedef ptrdiff_t FT_PtrDist;

struct T1_ParserRec_ {
    struct {
        FT_Memory memory;
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Error error;
    } root;
};

struct PS_Table_ {
    FT_Byte** elements;
    int* lengths;
};

struct T1_LoaderRec_ {
    struct T1_ParserRec_ parser;
    struct PS_Table_ charstrings;
    struct PS_Table_ glyph_names;
    struct PS_Table_ swap_table;
    FT_Int num_glyphs;
};

struct T1_FaceRec_ {
    void* psaux;
    struct {
        struct {
            int lenIV;
        } private_dict;
    } type1;
};

struct PSAux_ServiceRec_ {
    struct {
        int (*init)(struct PS_Table_*, int, FT_Memory);
    }* ps_table_funcs;
    void (*t1_decrypt)(FT_Byte*, int, int);
};

typedef struct T1_FaceRec_* T1_Face;
typedef struct T1_LoaderRec_* T1_Loader;
typedef struct T1_ParserRec_* T1_Parser;
typedef struct PS_Table_* PS_Table;
typedef struct PSAux_ServiceRec_* PSAux_Service;

#define FT_THROW(e) (-1)
#define TABLE_EXTEND 5
#define IS_PS_DELIM(c) (0)
#define IS_INCREMENTAL 0
#define FT_ALLOC(p, s) (0)
#define FT_FREE(p)
#define FT_MEM_COPY(d, s, l) memcpy(d, s, l)

static int T1_ToInt(T1_Parser parser) { return 0; }
static void T1_Skip_Spaces(T1_Parser parser) {}
static void T1_Skip_PS_Token(T1_Parser parser) {}
static int read_binary_data(T1_Parser parser, FT_Long* size, FT_Byte** base, int incremental) { return 0; }
static int T1_Add_Table(PS_Table table, int idx, void* element, int length) { return 0; }
#define ft_strcmp strcmp
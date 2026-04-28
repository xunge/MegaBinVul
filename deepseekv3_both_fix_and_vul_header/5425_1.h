#include <string.h>
#include <stddef.h>

typedef struct T1_Face_* T1_Face;
typedef struct T1_Loader_* T1_Loader;
typedef struct T1_Parser_* T1_Parser;
typedef struct PS_Table_* PS_Table;
typedef struct FT_MemoryRec_* FT_Memory;
typedef struct PSAux_ServiceRec_* PSAux_Service;

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef int FT_Int;
typedef unsigned int FT_UInt;
typedef long FT_Long;
typedef ptrdiff_t FT_PtrDist;

#define FT_THROW(e) (-1)
#define IS_PS_DELIM(c) (0)
#define IS_INCREMENTAL 0
#define TABLE_EXTEND 0
#define FT_ALLOC(p, s) (0)
#define FT_FREE(p) free(p)
#define FT_MEM_COPY(d, s, n) memcpy(d, s, n)
#define ft_strcmp strcmp

struct T1_Parser_ {
    struct {
        FT_Memory memory;
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Error error;
    } root;
};

struct PS_Table_ {
    FT_Byte** elements;
    FT_Int* lengths;
};

struct T1_Loader_ {
    T1_Parser parser;
    PS_Table charstrings;
    PS_Table glyph_names;
    PS_Table swap_table;
    FT_Int num_glyphs;
};

struct T1_Face_ {
    struct {
        struct {
            FT_Int lenIV;
        } private_dict;
    } type1;
    PSAux_Service psaux;
};

struct PSAux_ServiceRec_ {
    struct {
        FT_Error (*init)(PS_Table, FT_Int, FT_Memory);
    }* ps_table_funcs;
    void (*t1_decrypt)(FT_Byte*, FT_Long, FT_UInt);
};

FT_Int T1_ToInt(T1_Parser parser);
void T1_Skip_Spaces(T1_Parser parser);
void T1_Skip_PS_Token(T1_Parser parser);
FT_Error T1_Add_Table(PS_Table table, FT_Int idx, void* element, FT_Int length);
int read_binary_data(T1_Parser parser, FT_Long* size, FT_Byte** base, int is_incremental);
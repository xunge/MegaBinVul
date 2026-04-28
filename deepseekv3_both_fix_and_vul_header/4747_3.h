#include <stddef.h>
#include <ctype.h>
#include <string.h>

typedef unsigned char FT_Byte;
typedef int FT_Int;
typedef int FT_Bool;
typedef unsigned int FT_UInt;
typedef size_t FT_PtrDist;
typedef int FT_Error;

typedef struct FT_MemoryRec_* FT_Memory;

struct PS_TableRec_ {
    char** elements;
};

struct T1_EncodingRec_ {
    FT_Int num_chars;
    FT_UInt* char_index;
    char** char_name;
};

struct PSAux_ServiceRec_ {
    struct {
        FT_Error (*init)(struct PS_TableRec_*, FT_Int, FT_Memory);
    } *ps_table_funcs;
};

struct T42_ParserRec_ {
    struct {
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Memory memory;
        FT_Error error;
    } root;
};

struct T42_LoaderRec_ {
    struct T42_ParserRec_ parser;
    struct PS_TableRec_ encoding_table;
    FT_Int num_chars;
};

struct T42_FaceRec_ {
    struct {
        struct {
            struct T1_EncodingRec_ encoding;
            int encoding_type;
        } type1;
        struct PSAux_ServiceRec_* psaux;
    };
};

enum {
    T1_ENCODING_TYPE_ARRAY,
    T1_ENCODING_TYPE_STANDARD,
    T1_ENCODING_TYPE_EXPERT,
    T1_ENCODING_TYPE_ISOLATIN1
};

enum {
    FT_THROW_Invalid_File_Format,
    FT_THROW_Unknown_File_Format,
    FT_THROW_Ignore
};

#define FT_ERROR(x)
#define FT_TRACE6(x)
#define FT_NEW_ARRAY(p, n) 0
#define FT_SET_ERROR(x) (x)
#define FT_THROW(x) FT_THROW_##x

typedef struct T42_FaceRec_* T42_Face;
typedef struct T42_LoaderRec_* T42_Loader;
typedef struct T42_ParserRec_* T42_Parser;
typedef struct PS_TableRec_* PS_Table;
typedef struct T1_EncodingRec_* T1_Encoding;
typedef struct PSAux_ServiceRec_* PSAux_Service;

static int ft_isdigit(int c) { return isdigit(c); }
static FT_Bool t42_is_space(FT_Byte c) { return isspace(c); }
static int ft_strncmp(const char* s1, const char* s2, size_t n) { return strncmp(s1, s2, n); }

static void T1_Skip_Spaces(T42_Parser parser) {}
static FT_Int T1_ToInt(T42_Parser parser) { return 0; }
static void T1_Skip_PS_Token(T42_Parser parser) {}
static FT_Error T1_Add_Table(PS_Table table, FT_Int idx, void* data, FT_UInt length) { return 0; }
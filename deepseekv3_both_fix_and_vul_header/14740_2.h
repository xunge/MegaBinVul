#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char FT_Byte;
typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Error;
typedef int FT_Bool;
typedef int FT_Int;
typedef ptrdiff_t FT_PtrDist;

#define FT_THROW(e) (-1)
#define FT_ERR(e) (-1)
#define Invalid_File_Format 1
#define Unknown_File_Format 2
#define Ignore 3

typedef struct T1_Parser_Root_ {
    FT_Byte* cursor;
    FT_Byte* limit;
    FT_Memory memory;
    FT_Error error;
} T1_Parser_Root;

typedef struct T1_Parser_ {
    T1_Parser_Root root;
} *T1_Parser;

typedef struct T1_Encoding_ {
    int num_chars;
    int* char_index;
    char** char_name;
} *T1_Encoding;

typedef struct PS_Table_ {
    char** elements;
} *PS_Table;

typedef struct T1_Loader_ {
    PS_Table encoding_table;
    struct T1_Parser_ parser;
    int num_chars;
} *T1_Loader;

typedef struct T1_Type1_ {
    struct T1_Encoding_ encoding;
    int encoding_type;
} T1_Type1;

typedef struct T1_Face_ {
    T1_Type1 type1;
    void* psaux;
} *T1_Face;

typedef struct PSAux_Service_ {
    struct {
        FT_Error (*init)(PS_Table, FT_Int, FT_Memory);
    }* ps_table_funcs;
} *PSAux_Service;

#define FT_NEW_ARRAY(p, count) 0
#define FT_SET_ERROR(code) (code)
#define FT_ERROR(x)
#define FT_TRACE6(x)
#define IS_PS_DELIM(c) (isspace(c) || (c) == '\0')

enum {
    T1_ENCODING_TYPE_ARRAY,
    T1_ENCODING_TYPE_STANDARD,
    T1_ENCODING_TYPE_EXPERT,
    T1_ENCODING_TYPE_ISOLATIN1
};

static int ft_isdigit(int c) { return isdigit(c); }
static int ft_strncmp(const char* s1, const char* s2, size_t n) { return strncmp(s1, s2, n); }
static int T1_ToInt(T1_Parser parser) { return 0; }
static void T1_Skip_Spaces(T1_Parser parser) {}
static void T1_Skip_PS_Token(T1_Parser parser) {}
static FT_Error T1_Add_Table(PS_Table table, FT_Int idx, const char* name, size_t len) { return 0; }
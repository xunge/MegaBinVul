#include <stddef.h>

typedef long FT_Pos;
typedef long FT_Fixed;
typedef long FT_Long;
typedef unsigned long FT_ULong;
typedef unsigned int FT_UInt;
typedef unsigned short FT_UShort;
typedef unsigned char FT_Byte;
typedef char FT_Char;
typedef int FT_Int;
typedef int FT_Error;
typedef unsigned long FT_UInt32;
typedef const char* FT_String;
typedef void* FT_Pointer;
typedef struct FT_MemoryRec_* FT_Memory;

struct FT_BBox_ {
    FT_Pos xMin;
    FT_Pos yMin;
    FT_Pos xMax;
    FT_Pos yMax;
};
typedef struct FT_BBox_ FT_BBox;

typedef enum {
    T1_FIELD_TYPE_BOOL,
    T1_FIELD_TYPE_FIXED,
    T1_FIELD_TYPE_FIXED_1000,
    T1_FIELD_TYPE_INTEGER,
    T1_FIELD_TYPE_STRING,
    T1_FIELD_TYPE_KEY,
    T1_FIELD_TYPE_BBOX,
    T1_FIELD_TYPE_MM_BBOX
} T1_FieldType;

typedef enum {
    T1_TOKEN_TYPE_NONE,
    T1_TOKEN_TYPE_ARRAY,
    T1_TOKEN_TYPE_KEY,
    T1_TOKEN_TYPE_STRING
} T1_TokenType;

struct T1_Field_ {
    T1_FieldType type;
    size_t offset;
    size_t size;
    const char* ident;
};
typedef struct T1_Field_* T1_Field;

struct T1_TokenRec_ {
    T1_TokenType type;
    FT_Byte* start;
    FT_Byte* limit;
};
typedef struct T1_TokenRec_ T1_TokenRec;

struct PS_Parser_ {
    FT_Byte* cursor;
    FT_Byte* limit;
    FT_Memory memory;
};
typedef struct PS_Parser_* PS_Parser;

#define FT_LOCAL_DEF(x) x
#define FT_THROW(e) (-(e))
#define FT_Err_Ok 0
#define FT_CHAR_BIT 8
#define FT_TRACE0(x) do {} while (0)
#define FT_ERROR(x) do {} while (0)
#define FT_UNUSED(x) (void)(x)
#define FT_ALLOC(ptr, size) (0)
#define FT_FREE(ptr) do {} while (0)
#define FT_NEW_ARRAY(ptr, count) (0)
#define FT_MEM_COPY(dest, src, len) do {} while (0)

#define Invalid_File_Format 1

extern FT_Error ps_parser_to_token(PS_Parser parser, T1_TokenRec* token);
extern void skip_spaces(FT_Byte** cur, FT_Byte* limit);
extern FT_Long ps_tobool(FT_Byte** cur, FT_Byte* limit);
extern FT_Fixed PS_Conv_ToFixed(FT_Byte** cur, FT_Byte* limit, FT_Int power);
extern FT_Long PS_Conv_ToInt(FT_Byte** cur, FT_Byte* limit);
extern FT_Int ps_tofixedarray(FT_Byte** cur, FT_Byte* limit, FT_Int count, FT_Fixed* values, FT_Int power);
extern FT_Fixed FT_RoundFix(FT_Fixed x);
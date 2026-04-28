#include <stddef.h>
#include <ctype.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef unsigned char FT_Byte;
typedef unsigned long FT_ULong;
typedef long FT_Long;
typedef int FT_Int;
typedef int FT_Error;
typedef int FT_Bool;

#define FT_PEEK_ULONG(p) ((FT_ULong)(((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3]))
#define FT_REALLOC(ptr,oldsz,newsz) 0
#define FT_FREE(ptr) ((void)0)
#define FT_ERROR(msg) ((void)0)
#define T42_Err_Invalid_File_Format 0

typedef enum {
    BEFORE_START,
    BEFORE_TABLE_DIR,
    OTHER_TABLES
} T42_Load_Status;

typedef struct T42_ParserRoot_ {
    FT_Memory memory;
    FT_Byte* cursor;
    FT_Byte* limit;
    FT_Error error;
} T42_ParserRoot;

typedef struct T42_ParserRec_ {
    T42_ParserRoot root;
} *T42_Parser;

typedef struct T42_LoaderRec_ {
    T42_Parser parser;
} *T42_Loader;

typedef struct T42_FaceRec_ {
    FT_Byte* ttf_data;
    FT_ULong ttf_size;
} *T42_Face;

static void T1_Skip_Spaces(T42_Parser parser);
static void T1_Skip_PS_Token(T42_Parser parser);
static FT_Long T1_ToInt(T42_Parser parser);
static FT_Long T1_ToBytes(T42_Parser parser, FT_Byte* buf, FT_Long size, FT_Long* real_size, FT_Bool is_hex);
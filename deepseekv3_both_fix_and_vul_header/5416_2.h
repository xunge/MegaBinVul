#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char FT_Byte;
typedef unsigned long FT_ULong;
typedef long FT_Long;
typedef int FT_Int;
typedef int FT_Bool;
typedef int FT_Error;

typedef struct FT_MemoryRec_* FT_Memory;

typedef struct T42_ParserRec_ {
    struct {
        FT_Memory memory;
        FT_Byte* cursor;
        FT_Byte* limit;
        FT_Error error;
    } root;
} *T42_Parser;

typedef struct T42_LoaderRec_ {
    T42_Parser parser;
} *T42_Loader;

typedef struct T42_FaceRec_ {
    FT_Byte* ttf_data;
    FT_ULong ttf_size;
} *T42_Face;

typedef enum {
    BEFORE_START,
    BEFORE_TABLE_DIR,
    OTHER_TABLES
} T42_Load_Status;

#define FT_THROW(e) (-1)
#define FT_REALLOC(p, os, ns) ((p) = realloc((p), (ns)) ? (p) : NULL, (p) ? 0 : 1)
#define FT_FREE(p) free((p))
#define FT_PEEK_ULONG(p) (*(FT_ULong*)(p))
#define FT_ERROR(args)

static void T1_Skip_Spaces(T42_Parser parser);
static void T1_Skip_PS_Token(T42_Parser parser);
static FT_Int T1_ToInt(T42_Parser parser);
static FT_Int T1_ToBytes(T42_Parser parser, FT_Byte* buffer, FT_Long max_bytes, FT_Long* pnum_bytes, FT_Bool is_hex);
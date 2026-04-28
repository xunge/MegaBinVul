#include <stddef.h>

typedef unsigned long FT_ULong;
typedef unsigned int FT_UInt32;
typedef unsigned char FT_Byte;

typedef struct FT_ValidatorRec_* FT_Validator;
typedef int FT_Error;

struct FT_ValidatorRec_ {
    FT_Byte* limit;
    FT_Byte* base;
    int level;
};

#define FT_VALIDATE_TIGHT 1
#define FT_INVALID_TOO_SHORT 1
#define FT_INVALID_DATA 2
#define FT_INVALID_GLYPH_ID 3
#define FT_Err_Ok 0

#define FT_CALLBACK_DEF(x) x
#define TT_NEXT_ULONG(p) (*(FT_ULong*)(p)), (p) += sizeof(FT_ULong)
#define TT_VALID_GLYPH_COUNT(valid) ((FT_UInt32)((valid)->limit - (valid)->base))
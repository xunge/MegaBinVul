#include <stddef.h>

typedef unsigned char  FT_Byte;
typedef unsigned long FT_ULong;
typedef unsigned int  FT_UInt;
typedef int           FT_Error;

#define FT_CALLBACK_DEF(x)  x
#define TT_NEXT_ULONG(p)    (*(FT_ULong*)(p), (p) += 4)
#define TT_NEXT_USHORT(p)   (*(FT_UInt*)(p), (p) += 2)
#define FT_INVALID_TOO_SHORT 1
#define FT_INVALID_GLYPH_ID  2
#define FT_Err_Ok           0
#define FT_VALIDATE_TIGHT    1

typedef struct FT_ValidatorRec_*  FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte* limit;
    int      level;
};

#define TT_VALID_GLYPH_COUNT(valid) (1 << 16)
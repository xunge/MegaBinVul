#include <stddef.h>

typedef unsigned long FT_ULong;
typedef unsigned char FT_Byte;

typedef struct FT_ValidatorRec_* FT_Validator;
typedef int FT_Error;

#define FT_INVALID_TOO_SHORT
#define FT_INVALID_DATA
#define FT_INVALID_GLYPH_ID
#define FT_VALIDATE_TIGHT 1
#define FT_Err_Ok 0
#define TT_NEXT_ULONG(p) (*(p)++)

struct FT_ValidatorRec_ {
    FT_Byte* limit;
    int level;
};

#define TT_VALID_GLYPH_COUNT(valid) (0)
#define FT_CALLBACK_DEF(x) x
#include <stddef.h>

typedef unsigned char   FT_Byte;
typedef unsigned int    FT_UInt;
typedef unsigned long   FT_ULong;
typedef int             FT_Error;
typedef unsigned short  FT_UShort;

#define FT_INVALID_TOO_SHORT  1
#define FT_INVALID_DATA       2
#define FT_INVALID_GLYPH_ID   3
#define FT_Err_Ok             0

#define TT_NEXT_ULONG(p)  ( (p) += 4, (FT_ULong)( (p)[-4] << 24 | (p)[-3] << 16 | (p)[-2] << 8 | (p)[-1] ) )
#define TT_NEXT_UINT24(p) ( (p) += 3, (FT_ULong)( (p)[-3] << 16 | (p)[-2] << 8 | (p)[-1] ) )
#define TT_NEXT_USHORT(p) ( (p) += 2, (FT_UShort)( (p)[-2] << 8 | (p)[-1] ) )
#define FT_NEXT_BYTE(p)   ( *(p)++ )

#define FT_VALIDATE_TIGHT 1

typedef struct FT_ValidatorRec_*  FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte*  limit;
    FT_UInt   level;
    FT_UInt   glyph_count;
};

#define TT_VALID_GLYPH_COUNT(valid)  ((valid)->glyph_count)
#define FT_CALLBACK_DEF(ret)  ret
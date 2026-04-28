#include <stddef.h>

typedef unsigned char  FT_Byte;
typedef unsigned long  FT_ULong;
typedef unsigned int   FT_UInt;
typedef unsigned short FT_UShort;
typedef int            FT_Error;

typedef struct FT_ValidatorRec_*  FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte*  limit;
    FT_UInt   level;
};

#define FT_CALLBACK_DEF( x )  x
#define TT_NEXT_ULONG( p )       ( (p) += 4, (FT_ULong)( ( (FT_ULong)(p)[-4] << 24 ) | \
                                                         ( (FT_ULong)(p)[-3] << 16 ) | \
                                                         ( (FT_ULong)(p)[-2] <<  8 ) | \
                                                           (FT_ULong)(p)[-1]       ) )
#define TT_NEXT_UINT24( p )      ( (p) += 3, (FT_ULong)( ( (FT_ULong)(p)[-3] << 16 ) | \
                                                         ( (FT_ULong)(p)[-2] <<  8 ) | \
                                                           (FT_ULong)(p)[-1]       ) )
#define TT_NEXT_USHORT( p )      ( (p) += 2, (FT_UShort)( ( (FT_UShort)(p)[-2] << 8 ) | \
                                                            (FT_UShort)(p)[-1]       ) )
#define FT_NEXT_BYTE( p )        ( (p) += 1, (FT_Byte)(p)[-1] )

#define FT_INVALID_TOO_SHORT     -1
#define FT_INVALID_DATA          -2
#define FT_INVALID_GLYPH_ID      -3

#define FT_VALIDATE_TIGHT        1
#define TT_VALID_GLYPH_COUNT( v ) 0xFFFF

#define SFNT_Err_Ok              0
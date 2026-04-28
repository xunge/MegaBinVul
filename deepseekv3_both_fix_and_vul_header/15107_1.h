#include <stdint.h>

typedef uint32_t FT_UInt32;
typedef uint16_t FT_UInt;
typedef uint16_t FT_UInt16;
typedef uint8_t  FT_Byte;
typedef uint32_t FT_Error;

#define FT_CALLBACK_DEF(x) x

typedef struct FT_ValidatorRec_*  FT_Validator;
typedef struct FT_ValidatorRec_
{
  FT_Byte*  limit;
  int       level;
} FT_ValidatorRec;

#define FT_INVALID_TOO_SHORT  1
#define FT_INVALID_DATA       2
#define FT_INVALID_GLYPH_ID   3

#define TT_NEXT_ULONG(p)  ( (p) += 4, (FT_UInt32)( (p)[-4] << 24 | (p)[-3] << 16 | (p)[-2] << 8 | (p)[-1] ) )

#define TT_VALID_GLYPH_COUNT(valid)  (1 << 16)

#define FT_VALIDATE_TIGHT  1

#define SFNT_Err_Ok  0
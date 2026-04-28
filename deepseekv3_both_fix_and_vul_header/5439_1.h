#include <stdint.h>

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef uint32_t FT_UInt32;
typedef unsigned int FT_UInt;

typedef struct FT_ValidatorRec_* FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte* limit;
    int level;
};

#define FT_INVALID_TOO_SHORT do {} while(0)
#define FT_INVALID_DATA do {} while(0)
#define FT_INVALID_GLYPH_ID do {} while(0)
#define FT_VALIDATE_TIGHT 1
#define FT_Err_Ok 0

#define TT_NEXT_ULONG(p) ( (p) += 4, (FT_UInt32)( ( (FT_UInt32)(p)[-4] << 24 ) | \
                                                 ( (FT_UInt32)(p)[-3] << 16 ) | \
                                                 ( (FT_UInt32)(p)[-2] <<  8 ) | \
                                                   (FT_UInt32)(p)[-1] ) )

#define TT_VALID_GLYPH_COUNT(valid) (1 << 24)

#define FT_CALLBACK_DEF(ret) ret
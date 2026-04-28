#include <stddef.h>

typedef unsigned long FT_ULong;
typedef unsigned char FT_Byte;

typedef struct FT_ValidatorRec_* FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte* limit;
    int level;
};

#define FT_CALLBACK_DEF(x) x
#define FT_INVALID_TOO_SHORT 1
#define FT_INVALID_DATA 2
#define FT_INVALID_GLYPH_ID 3
#define FT_VALIDATE_TIGHT 1

#define TT_NEXT_ULONG(p) ( (p) += 4, (FT_ULong)( ( (FT_ULong)(*( (p) - 4 ) ) << 24 ) | \
                                                ( (FT_ULong)(*( (p) - 3 ) ) << 16 ) | \
                                                ( (FT_ULong)(*( (p) - 2 ) ) << 8  ) | \
                                                ( (FT_ULong)(*( (p) - 1 ) )       ) ) )

#define TT_VALID_GLYPH_COUNT(valid) ( ( (valid)->limit - (FT_Byte*)0 ) / sizeof(FT_Byte) )

typedef enum {
    SFNT_Err_Ok = 0
} FT_Error;
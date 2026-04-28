#include <stddef.h>

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef int FT_Int;

typedef struct FT_ValidatorRec_* FT_Validator;
struct FT_ValidatorRec_ {
    FT_Byte* limit;
    int level;
};

#define FT_CALLBACK_DEF(x) x
#define FT_Err_Ok 0
#define FT_INVALID_TOO_SHORT do {} while(0)
#define FT_VALIDATE_TIGHT 1
#define FT_VALIDATE_PARANOID 2
#define FT_INVALID_DATA do {} while(0)
#define TT_CMAP_FLAG_UNSORTED (1 << 0)
#define TT_CMAP_FLAG_OVERLAPPING (1 << 1)
#define FT_INVALID_GLYPH_ID do {} while(0)

#define TT_NEXT_USHORT(p) (*(p)++ << 8 | *(p)++)
#define TT_PEEK_USHORT(p) (*(p) << 8 | *((p)+1))
#define TT_NEXT_SHORT(p) ((short)(*(p)++ << 8 | *(p)++))
#define FT_NEXT_USHORT(p) TT_NEXT_USHORT(p)
#define TT_VALID_GLYPH_COUNT(valid) 0xFFFF
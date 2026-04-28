#include <stddef.h>

typedef long FT_Long;
typedef unsigned int FT_UInt;
typedef long FT_Fixed;

typedef struct TT_Blend_ {
    FT_UInt num_axis;
    FT_Fixed* normalizedcoords;
} TT_Blend;

typedef struct TT_Face_ {
    TT_Blend* blend;
} TT_Face;

typedef struct TT_ExecContext_ {
    TT_Face* face;
    FT_UInt stackSize;
    FT_UInt top;
    int error;
} *TT_ExecContext;

#define BOUNDS(a,b) ((a) > (b))
#define FT_THROW(e) (e)
#define Stack_Overflow 1
#include <stddef.h>

#define FT_UNUSED(x) (void)(x)
#define FT_GET_BYTE() 0
#define FT_GET_USHORT() 0
#define FT_NEW_ARRAY(p, n) 0
#define TT_Err_Ok 0
#define ALL_POINTS NULL
#define GX_PT_POINTS_ARE_WORDS 0x80
#define GX_PT_POINT_RUN_COUNT_MASK 0x7F

typedef unsigned short FT_UShort;
typedef unsigned int FT_UInt;
typedef int FT_Int;
typedef int FT_Error;

typedef struct FT_Memory_ {
    void* user;
} FT_Memory;

typedef struct FT_Stream_ {
    FT_Memory memory;
} *FT_Stream;
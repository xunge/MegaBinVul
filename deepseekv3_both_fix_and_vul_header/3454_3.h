#include <string.h>
#include <stddef.h>

typedef int CF2_Int;
typedef unsigned int CF2_UInt;

typedef struct CF2_Buffer_ {
    void* start;
    void* ptr;
    void* end;
} *CF2_Buffer;

#define FT_LOCAL_DEF(x) x
#define FT_ASSERT(x) ((void)0)
#define FT_ZERO(x) memset((x), 0, sizeof(struct CF2_Buffer_))
#define TRUE 1
#define FALSE 0

typedef struct CFF_Decoder_ {
    void** globals;
    CF2_UInt globals_bias;
    CF2_UInt num_globals;
} CFF_Decoder;
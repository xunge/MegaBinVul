#include <stddef.h>
#include <string.h>

#define FT_LOCAL_DEF(type) static type
#define CF2_Int int
#define CF2_UInt unsigned int
#define CF2_Buffer struct CF2_Buffer_*
#define CFF_Decoder struct CFF_Decoder_
#define TRUE 1
#define FALSE 0

struct CF2_Buffer_ {
    void* start;
    void* ptr;
    void* end;
};

struct CFF_Decoder_ {
    void** locals;
    unsigned int locals_bias;
    unsigned int num_locals;
};

#define FT_ASSERT(cond) ((void)0)
#define FT_ZERO(buf) memset((buf), 0, sizeof(*(buf)))
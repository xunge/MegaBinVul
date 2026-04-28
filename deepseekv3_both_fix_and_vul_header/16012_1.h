#include <stdint.h>

typedef int32_t Fixed;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;

typedef struct {
    unsigned int coord_bits;
} GF_LASeRCodec;

#define INT2FIX(x) ((Fixed)((x) << 8))
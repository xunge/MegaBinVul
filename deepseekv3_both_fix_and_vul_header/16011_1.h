#include <stdint.h>

typedef int32_t Fixed;
typedef int64_t s64;
typedef int32_t s32;
typedef uint32_t u32;

#define GPAC_FIXED_POINT
#define FIX_ONE (1<<16)
#define INT2FIX(x) ((Fixed)((x)<<16))

typedef struct GF_LASeRCodec {
    Fixed res_factor;
} GF_LASeRCodec;

Fixed gf_divfix(Fixed a, Fixed b);
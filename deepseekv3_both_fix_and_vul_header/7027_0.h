#include <stdlib.h>
#include <math.h>

typedef int GF_Err;
typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct GF_BitStream GF_BitStream;
typedef int Fixed;
typedef unsigned int u32;
typedef int s32;

#define GF_BAD_PARAM 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_OK 0

#define GF_PI 3.14159265358979323846

Fixed Q_InverseQuantize(u32 a, u32 b, u32 c, s32 d);
Fixed gf_tan(Fixed angle);
Fixed gf_mulfix(Fixed a, Fixed b);
Fixed gf_divfix(Fixed a, Fixed b);
Fixed gf_sqrt(Fixed val);
int gf_bs_read_int(GF_BitStream *bs, u32 numBits);
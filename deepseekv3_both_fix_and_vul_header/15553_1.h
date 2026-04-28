#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;

typedef struct GF_BitStream GF_BitStream;
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
void gf_bs_log(GF_BitStream *bs, u32 numBits, const char *fname, u32 value);
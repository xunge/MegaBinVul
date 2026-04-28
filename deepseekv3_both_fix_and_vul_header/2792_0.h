#include <stdint.h>

typedef struct SWFReader SWFReader;
typedef struct GF_BitStream GF_BitStream;

typedef int16_t s16;
typedef uint8_t u8;
typedef uint16_t u16;

s16 swf_read_sint(SWFReader *read, int bits);
u8 swf_read_int(SWFReader *read, int bits);
u16 gf_bs_read_u16_le(GF_BitStream *bs);

struct SWFReader {
    GF_BitStream *bs;
};
#include <stdio.h>
#include <stdint.h>

typedef struct __gf_bitstream GF_BitStream;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;
typedef int Bool;

#define GF_BITSTREAM_READ 0

GF_BitStream *gf_bs_new(const void *buffer, u64 BufferSize, u32 mode);
void gf_bs_del(GF_BitStream *bs);
u32 gf_bs_read_int(GF_BitStream *bs, u32 nBits);
u16 gf_bs_read_u16(GF_BitStream *bs);
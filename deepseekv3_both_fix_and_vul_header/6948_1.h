#include <stdint.h>

typedef uint8_t Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_M4ADecSpecInfo GF_M4ADecSpecInfo;

#define LATM_DMX_MAX_SIZE 0

u32 gf_bs_read_u8(GF_BitStream *bs);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
u64 gf_bs_get_position(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
void gf_bs_seek(GF_BitStream *bs, u64 position);
void gf_bs_read_data(GF_BitStream *bs, char *buffer, u32 size);
u32 gf_bs_peek_bits(GF_BitStream *bs, u32 numBits, u32 byte_offset);
u32 gf_latm_get_value(GF_BitStream *bs);
void gf_m4a_parse_config(GF_BitStream *bs, GF_M4ADecSpecInfo *acfg, Bool flag);
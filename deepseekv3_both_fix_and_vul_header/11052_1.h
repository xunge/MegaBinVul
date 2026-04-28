#include <stdint.h>

typedef uint8_t Bool;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_FALSE 0
#define GF_NON_COMPLIANT_BITSTREAM -1
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef struct {
    u32 obu_start_offset;
    u32 size;
} AV1Tile;

typedef struct {
    AV1Tile tiles[256];
    u32 nb_tiles_in_obu;
} AV1FrameState;

typedef struct {
    u32 tileCols;
    u32 tileRows;
    u32 tileColsLog2;
    u32 tileRowsLog2;
    u32 tile_size_bytes;
    AV1FrameState frame_state;
} AV1State;

typedef struct GF_BitStream GF_BitStream;

u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
void gf_bs_align(GF_BitStream *bs);
u64 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_skip_bytes(GF_BitStream *bs, u32 nbBytes);
u64 aom_av1_le(GF_BitStream *bs, u32 bytes);
void av1_decode_frame_wrapup(AV1State *state);
void GF_LOG(u32 level, u32 category, const char *fmt, ...);
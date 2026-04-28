#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

typedef uint8_t Bool;
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_OK 0
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint8_t u8;

typedef struct {
    uint32_t lfon;
    uint32_t bsid;
    uint32_t bsmod;
    uint32_t acmod;
    uint32_t fscod;
    uint32_t nb_dep_sub;
    uint32_t chan_loc;
} GF_AC3StreamInfo;

typedef struct {
    uint32_t framesize;
    uint32_t sample_rate;
    uint32_t brcode;
    uint32_t nb_streams;
    uint32_t is_ec3;
    uint32_t atmos_ec3_ext;
    uint32_t complexity_index_type;
    GF_AC3StreamInfo streams[16];
} GF_AC3Config;

typedef struct {
    uint32_t framesize;
    uint32_t sample_rate;
    uint32_t brcode;
    GF_AC3StreamInfo streams[1];
} GF_AC3Header;

typedef struct GF_BitStream GF_BitStream;

uint32_t gf_bs_get_position(GF_BitStream *bs);
uint32_t gf_bs_seek(GF_BitStream *bs, uint64_t pos);
uint32_t gf_bs_read_u16(GF_BitStream *bs);
uint32_t gf_bs_peek_bits(GF_BitStream *bs, uint32_t num_bits, uint32_t byte_offset);
uint32_t gf_bs_read_int(GF_BitStream *bs, uint32_t nBits);
uint32_t gf_bs_read_int_log(GF_BitStream *bs, uint32_t nBits, const char *name);
void gf_bs_skip_bytes(GF_BitStream *bs, uint32_t nbBytes);
void gf_bs_align(GF_BitStream *bs);
uint32_t AC3_FindSyncCodeBS(GF_BitStream *bs);
uint32_t gf_ac3_parser_bs(GF_BitStream *bs, GF_AC3Header *hdr, Bool full_parse);
uint32_t gf_ac3_get_bitrate(uint32_t brcode);
void eac3_update_channels(GF_AC3Config *hdr);
void GF_LOG(int level, int coding, const char *fmt, ...);
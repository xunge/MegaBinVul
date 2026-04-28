#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1

#define GF_BITSTREAM_READ 0
#define GF_BITSTREAM_WRITE 1

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_INFO 3
#define GF_LOG_DEBUG 4
#define GF_LOG_CODING 0x100

#define GF_AVC_NALU_SEI 6

typedef struct GF_BitStream GF_BitStream;
typedef struct AVCState AVCState;

GF_BitStream* gf_bs_new(void* buffer, u32 size, u32 mode);
void gf_bs_del(GF_BitStream* bs);
void gf_bs_enable_emulation_byte_removal(GF_BitStream* bs, Bool enable);
u32 gf_bs_read_int(GF_BitStream* bs, u32 nBits);
void gf_bs_write_int(GF_BitStream* bs, u32 value, u32 nBits);
u32 gf_bs_get_position(GF_BitStream* bs);
u32 gf_bs_available(GF_BitStream* bs);
void gf_bs_seek(GF_BitStream* bs, u32 offset);
u8 gf_bs_read_u8(GF_BitStream* bs);
void gf_bs_write_u8(GF_BitStream* bs, u8 value);
void gf_bs_get_content(GF_BitStream* bs, u8** output, u32* outSize);

void GF_LOG(u32 log_level, u32 log_tool, const char* format, ...);
u32 gf_media_nalu_emulation_bytes_add_count(u8* buffer, u32 size);
u32 gf_media_nalu_add_emulation_bytes(u8* dst, u8* src, u32 size);
void gf_free(void* ptr);

void avc_parse_recovery_point_sei(GF_BitStream* bs, AVCState* avc);
void avc_parse_pic_timing_sei(GF_BitStream* bs, AVCState* avc);
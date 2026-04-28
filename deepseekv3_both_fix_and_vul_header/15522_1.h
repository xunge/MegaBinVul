#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef enum {
    GF_CODECID_AVC
} GF_CodecID;

typedef enum {
    GF_BITSTREAM_READ,
    GF_BITSTREAM_WRITE
} GF_BitStreamMode;

typedef struct {
    int sps_active_idx;
} AVCState;

typedef struct {
    char *data;
    u32 size;
} GF_AVCConfigSlot;

typedef struct {
    void *sequenceParameterSets;
} GF_AVCConfig;

typedef struct {
    // VUI info fields would be defined here
} GF_VUIInfo;

typedef struct GF_BitStream GF_BitStream;

GF_BitStream *gf_bs_new(const void *buffer, u64 size, GF_BitStreamMode mode);
void gf_bs_del(GF_BitStream *bs);
void gf_bs_seek(GF_BitStream *bs, u64 offset);
u32 gf_bs_read_int(GF_BitStream *bs, u32 nBits);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nBits);
u64 gf_bs_bits_available(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, void *data, u32 size);
void gf_bs_get_content(GF_BitStream *bs, u8 **output, u32 *outSize);

void *gf_list_enum(void *list, u32 *pos);
void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);

s32 gf_avc_read_sps(const u8 *data, u32 size, AVCState *avc, u32 discard_parameter_sets, u32 *bit_offset);
u32 gf_media_nalu_remove_emulation_bytes(const u8 *src, u8 *dst, u32 size);
u32 gf_media_nalu_emulation_bytes_add_count(const u8 *buffer, u32 size);
u32 gf_media_nalu_add_emulation_bytes(const u8 *src, u8 *dst, u32 size);

void avc_hevc_vvc_rewrite_vui(GF_VUIInfo *vui_info, GF_BitStream *orig, GF_BitStream *mod, GF_CodecID codec_id);
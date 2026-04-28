#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef bool Bool;

typedef struct GF_BitStream GF_BitStream;

typedef struct {
    u32 nal_unit_size;
    u32 ptl_present;
    u32 ols_idx;
    u32 numTemporalLayers;
    u32 constantFrameRate;
    u32 chroma_format;
    u32 bit_depth;
    u32 num_constraint_info;
    u32 general_profile_idc;
    u32 general_tier_flag;
    u8 general_level_idc;
    u32 ptl_frame_only_constraint;
    u32 ptl_multilayer_enabled;
    u8* general_constraint_info;
    u32 ptl_sublayer_present_mask;
    u8 sublayer_level_idc[8];
    u8 num_sub_profiles;
    u32* sub_profiles_idc;
    u16 maxPictureWidth;
    u16 maxPictureHeight;
    u16 avgFrameRate;
    void* param_array;
} GF_VVCConfig;

typedef struct {
    u32 array_completeness;
    u32 type;
    void* nalus;
} GF_NALUFFParamArray;

typedef struct {
    u32 size;
    char* data;
} GF_NALUFFParam;

#define GF_EXPORT
#define GF_LOG_ERROR 0
#define GF_LOG_CODING 0
#define GF_LOG_WARNING 0
#define GF_VVC_NALU_DEC_PARAM 0
#define GF_VVC_NALU_OPI 1
#define GF_VVC_NALU_VID_PARAM 2
#define GF_VVC_NALU_SEQ_PARAM 3
#define GF_VVC_NALU_PIC_PARAM 4
#define GF_VVC_NALU_SEI_PREFIX 5
#define GF_VVC_NALU_SEI_SUFFIX 6

#define GF_FALSE false
#define GF_TRUE true

GF_VVCConfig *gf_odf_vvc_cfg_new(void);
void gf_odf_vvc_cfg_del(GF_VVCConfig *cfg);
u8 gf_bs_read_u8(GF_BitStream *bs);
u16 gf_bs_read_u16(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
void gf_bs_read_data(GF_BitStream *bs, void *data, u32 size);
u32 gf_bs_available(GF_BitStream *bs);
void gf_bs_skip_bytes(GF_BitStream *bs, u32 size);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
void GF_LOG(int level, int category, const char *fmt, ...);
void *gf_list_new(void);
void gf_list_add(void *list, void *item);
void *gf_safemalloc(size_t size);
#define GF_SAFEALLOC(ptr, type) ptr = (type *)gf_safemalloc(sizeof(type))
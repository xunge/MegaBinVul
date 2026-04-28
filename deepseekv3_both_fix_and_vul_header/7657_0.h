#include <stdlib.h>
#include <stdint.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_NON_COMPLIANT_BITSTREAM 3
#define GF_OK 0
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct {
    void *buffer;
    size_t size;
    size_t position;
} GF_BitStream;

typedef struct {
    u16 scalability_mask;
    void *profile_tier_levels;
    void *operating_points;
    void *dependency_layers;
} GF_OperatingPointsInformation;

typedef struct {
    u8 general_profile_space;
    u8 general_tier_flag;
    u8 general_profile_idc;
    u32 general_profile_compatibility_flags;
    uint64_t general_constraint_indicator_flags;
    u8 general_level_idc;
} LHEVC_ProfileTierLevel;

typedef struct {
    u8 ptl_idx;
    u8 layer_id;
    u8 is_outputlayer;
    u8 is_alternate_outputlayer;
} LayerInfo;

typedef struct {
    u16 output_layer_set_idx;
    u8 max_temporal_id;
    u8 layer_count;
    LayerInfo layers_info[16];
    u16 minPicWidth;
    u16 minPicHeight;
    u16 maxPicWidth;
    u16 maxPicHeight;
    u8 maxChromaFormat;
    u8 maxBitDepth;
    u8 frame_rate_info_flag;
    u8 bit_rate_info_flag;
    u16 avgFrameRate;
    u8 constantFrameRate;
    u32 maxBitRate;
    u32 avgBitRate;
} LHEVC_OperatingPoint;

typedef struct {
    u8 dependent_layerID;
    u8 num_layers_dependent_on;
    u8 dependent_on_layerID[16];
    u8 dimension_identifier[16];
} LHEVC_DependentLayer;

u16 gf_bs_read_u16(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
uint64_t gf_bs_read_long_int(GF_BitStream *bs, int bits);
void gf_list_add(void *list, void *item);
void gf_free(void *ptr);
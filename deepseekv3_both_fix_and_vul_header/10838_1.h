#include <stdint.h>
#include <stdlib.h>

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef uint32_t u32;

typedef struct {
    uint16_t scalability_mask;
    void *profile_tier_levels;
    void *operating_points;
    void *dependency_layers;
} GF_OperatingPointsInformation;

typedef struct {
    uint8_t general_profile_space;
    uint8_t general_tier_flag;
    uint8_t general_profile_idc;
    uint32_t general_profile_compatibility_flags;
    uint64_t general_constraint_indicator_flags;
    uint8_t general_level_idc;
} LHEVC_ProfileTierLevel;

typedef struct {
    uint8_t ptl_idx;
    uint8_t layer_id;
    uint8_t is_outputlayer;
    uint8_t is_alternate_outputlayer;
} LHEVC_LayerInfo;

typedef struct {
    uint16_t output_layer_set_idx;
    uint8_t max_temporal_id;
    uint8_t layer_count;
    LHEVC_LayerInfo layers_info[16];
    uint16_t minPicWidth;
    uint16_t minPicHeight;
    uint16_t maxPicWidth;
    uint16_t maxPicHeight;
    uint8_t maxChromaFormat;
    uint8_t maxBitDepth;
    uint8_t frame_rate_info_flag;
    uint8_t bit_rate_info_flag;
    uint16_t avgFrameRate;
    uint8_t constantFrameRate;
    uint32_t maxBitRate;
    uint32_t avgBitRate;
} LHEVC_OperatingPoint;

typedef struct {
    uint8_t dependent_layerID;
    uint8_t num_layers_dependent_on;
    uint8_t dependent_on_layerID[16];
    uint8_t dimension_identifier[16];
} LHEVC_DependentLayer;

typedef struct GF_BitStream GF_BitStream;

uint16_t gf_bs_read_u16(GF_BitStream *bs);
uint32_t gf_bs_read_u32(GF_BitStream *bs);
uint8_t gf_bs_read_u8(GF_BitStream *bs);
uint64_t gf_bs_read_long_int(GF_BitStream *bs, int bits);
int gf_bs_read_int(GF_BitStream *bs, int bits);
void gf_list_add(void *list, void *item);
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_TRUE 1
#define GF_FALSE 0
#define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))
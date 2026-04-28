#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint32_t u32;
typedef uint64_t u64;
#define LLX PRIX64

typedef struct {
    u32 general_profile_space;
    u32 general_tier_flag;
    u32 general_profile_idc;
    u32 general_profile_compatibility_flags;
    u64 general_constraint_indicator_flags;
} LHEVC_ProfileTierLevel;

typedef struct {
    u32 output_layer_set_idx;
    u32 max_temporal_id;
    u32 layer_count;
    u32 minPicWidth;
    u32 minPicHeight;
    u32 maxPicWidth;
    u32 maxPicHeight;
    u32 maxChromaFormat;
    u32 maxBitDepth;
    u32 frame_rate_info_flag;
    u32 bit_rate_info_flag;
    u32 avgFrameRate;
    u32 constantFrameRate;
    u32 maxBitRate;
    u32 avgBitRate;
} LHEVC_OperatingPoint;

typedef struct {
    u32 dependent_layerID;
    u32 num_layers_dependent_on;
    u32 *dependent_on_layerID;
    u32 dimension_identifier[16];
} LHEVC_DependentLayer;

typedef struct {
    u32 scalability_mask;
    void *profile_tier_levels;
    void *operating_points;
    void *dependency_layers;
} GF_OperatingPointsInformation;

u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
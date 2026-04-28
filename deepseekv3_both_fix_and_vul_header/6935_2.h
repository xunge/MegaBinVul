#include <stdint.h>
#include <stdlib.h>

typedef int32_t GF_Err;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define GF_OK 0
#define GF_SERVICE_ERROR 1
#define GF_OUT_OF_MEM 2
#define GF_FALSE 0
#define GF_TRUE 1
#define MAX_LHVC_LAYERS 64
#define GF_BITSTREAM_WRITE 1

typedef struct {
    u8 profile_space;
    u8 tier_flag;
    u8 profile_idc;
    u64 profile_compatibility_flag;
    u8 general_progressive_source_flag;
    u8 general_interlaced_source_flag;
    u8 general_non_packed_constraint_flag;
    u8 general_frame_only_constraint_flag;
    u64 general_reserved_44bits;
    u8 level_idc;
} HEVC_ProfileTierLevel;

typedef struct {
    u32 pic_width_luma_samples;
    u32 pic_height_luma_samples;
    u8 chroma_format_idc;
    u8 bit_depth_luma;
    u8 bit_depth_chroma;
} HEVC_RepFormat;

typedef struct {
    u8 vps_extension_found;
    u32 max_layers;
    u8 scalability_mask[16];
    u32 num_profile_tier_level;
    HEVC_ProfileTierLevel ptl;
    HEVC_ProfileTierLevel *ext_ptl;
    u32 num_output_layer_sets;
    u32 *num_necessary_layers;
    u32 **profile_tier_level_idx;
    u8 **output_layer_flag;
    u32 *rep_format_idx;
    HEVC_RepFormat *rep_formats;
    u32 max_sub_layers;
    u8 *layer_id_in_nuh;
    u8 **direct_dependency_flag;
    u8 **dimension_id;
} HEVC_VPS;

typedef struct {
    HEVC_VPS *vps;
} HEVC_State;

typedef struct {
    u32 id;
} GF_NALUFFParam;

typedef struct {
    u8 general_profile_space;
    u8 general_tier_flag;
    u8 general_profile_idc;
    u64 general_profile_compatibility_flags;
    u64 general_constraint_indicator_flags;
    u8 general_level_idc;
} LHEVC_ProfileTierLevel;

typedef struct {
    u32 ptl_idx;
    u32 layer_id;
    u8 is_outputlayer;
    u8 is_alternate_outputlayer;
} LHEVC_LayerInfo;

typedef struct {
    u32 output_layer_set_idx;
    u32 layer_count;
    LHEVC_LayerInfo layers_info[16];
    u8 max_temporal_id;
    u16 minPicWidth;
    u16 minPicHeight;
    u16 maxPicWidth;
    u16 maxPicHeight;
    u8 maxChromaFormat;
    u8 maxBitDepth;
    u8 frame_rate_info_flag;
    u8 bit_rate_info_flag;
} LHEVC_OperatingPoint;

typedef struct {
    u32 dependent_layerID;
    u32 num_layers_dependent_on;
    u32 dependent_on_layerID[16];
    u8 dimension_identifier[16];
} LHEVC_DependentLayer;

typedef struct {
    u32 scalability_mask;
    void *profile_tier_levels;
    void *operating_points;
    void *dependency_layers;
} GF_OperatingPointsInformation;

typedef struct {
    void *vps;
    HEVC_State *hevc_state;
    void *opid;
} GF_NALUDmxCtx;

typedef struct {
    void *data;
    u32 size;
} PROP_DATA_NO_COPY;

#define PROP_DATA_NO_COPY(_data, _size) ((PROP_DATA_NO_COPY){_data, _size})

typedef struct {
    void *buffer;
    u32 size;
    u32 position;
    u8 mode;
} GF_BitStream;

GF_OperatingPointsInformation *gf_isom_oinf_new_entry();
void gf_isom_oinf_write_entry(GF_OperatingPointsInformation *oinf, GF_BitStream *bs);
void gf_isom_oinf_del_entry(GF_OperatingPointsInformation *oinf);
GF_BitStream *gf_bs_new(void *buffer, u32 size, u8 mode);
void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *data_size);
void gf_bs_del(GF_BitStream *bs);
void *gf_list_get(void *list, u32 index);
void gf_list_add(void *list, void *item);
void gf_filter_pid_set_info_str(void *pid, const char *name, PROP_DATA_NO_COPY *data);
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
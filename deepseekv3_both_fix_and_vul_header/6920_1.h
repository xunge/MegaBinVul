#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int Bool;

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    u8 *data;
    u32 id;
} GF_NALUFFParam;

typedef struct {
    GF_NALUFFParam **nalus;
} GF_NALUFFParamArray;

typedef struct {
    u32 avgFrameRate;
    u32 constantFrameRate;
    u32 numTemporalLayers;
    Bool temporalIdNested;
    u8 configurationVersion;
    u8 profile_space;
    Bool tier_flag;
    u8 profile_idc;
    u32 general_profile_compatibility_flags;
    Bool progressive_source_flag;
    Bool interlaced_source_flag;
    Bool non_packed_constraint_flag;
    Bool frame_only_constraint_flag;
    u64 constraint_indicator_flags;
    u8 level_idc;
    u8 chromaFormat;
    u8 luma_bit_depth;
    u8 chroma_bit_depth;
    u32 nal_unit_size;
    Bool is_lhvc;
    GF_NALUFFParamArray **param_array;
} GF_HEVCConfig;

typedef struct {
    u32 width;
    u32 height;
    u32 sar_width;
    u32 sar_height;
    u8 chroma_format_idc;
    u8 bit_depth_luma;
    u8 bit_depth_chroma;
    Bool aspect_ratio_info_present_flag;
    Bool has_timing_info;
    u32 time_scale;
    u32 num_units_in_tick;
    struct {
        u8 profile_space;
        Bool tier_flag;
        u8 profile_idc;
        u32 profile_compatibility_flag;
        Bool general_progressive_source_flag;
        Bool general_interlaced_source_flag;
        Bool general_non_packed_constraint_flag;
        Bool general_frame_only_constraint_flag;
        u64 general_reserved_44bits;
        u8 level_idc;
    } ptl;
} HEVC_SPS;

typedef struct {
    u32 max_sub_layers;
    Bool temporal_id_nesting;
    struct {
        u32 avg_pic_rate;
        u32 constant_pic_rate_idc;
    } rates[1];
} HEVC_VPS;

typedef struct {
    HEVC_VPS *vps;
    HEVC_SPS *sps;
} HEVC_State;

typedef struct {
    u32 nal_length;
    Bool analyze;
    Bool explicit;
    Bool notime;
    Bool interlaced;
    GF_Fraction fps;
    GF_Fraction cur_fps;
    u32 dts;
    HEVC_State *hevc_state;
    GF_NALUFFParamArray *vps;
    GF_NALUFFParamArray *sps;
    GF_NALUFFParamArray *pps;
} GF_NALUDmxCtx;

#define GF_FALSE 0
#define GF_TRUE 1
#define GPAC_DISABLE_HEVC 0

enum {
    GF_HEVC_NALU_VID_PARAM,
    GF_HEVC_NALU_SEQ_PARAM,
    GF_HEVC_NALU_PIC_PARAM
};

GF_HEVCConfig *gf_odf_hevc_cfg_new();
void gf_odf_hevc_cfg_del(GF_HEVCConfig *cfg);
void gf_odf_hevc_cfg_write(GF_HEVCConfig *cfg, u8 **dsi, u32 *dsi_size);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_reset(void *list);
void naludmx_add_param_nalu(GF_NALUFFParamArray *array, GF_NALUFFParam *sl, int type);
void naludmx_hevc_set_parall_type(GF_NALUDmxCtx *ctx, GF_HEVCConfig *cfg);
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Bool;

#define GF_TRUE 1
#define GF_FALSE 0

enum {
    GF_VVC_NALU_VID_PARAM,
    GF_VVC_NALU_SEQ_PARAM,
    GF_VVC_NALU_PIC_PARAM,
    GF_VVC_NALU_DEC_PARAM,
    GF_VVC_NALU_OPI,
    GF_VVC_NALU_APS_PREFIX
};

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    u32 avgFrameRate;
    u32 constantFrameRate;
    u32 numTemporalLayers;
    u32 nal_unit_size;
    u32 ptl_present;
    u32 num_constraint_info;
    u32 general_profile_idc;
    u32 general_tier_flag;
    u32 general_level_idc;
    u32 ptl_frame_only_constraint;
    u32 ptl_multilayer_enabled;
    u8 *general_constraint_info;
    u32 ptl_sublayer_present_mask;
    u32 num_sub_profiles;
    u32 ols_idx;
    u32 chroma_format;
    u32 bit_depth;
    u32 maxPictureWidth;
    u32 maxPictureHeight;
    void *param_array;
} GF_VVCConfig;

typedef struct {
    u32 vps_id;
    u32 max_sublayers;
    u32 chroma_format_idc;
    u32 bitdepth;
    u32 width;
    u32 height;
    u32 aspect_ratio_info_present_flag;
    u32 sar_width;
    u32 sar_height;
    u32 has_timing_info;
    u32 time_scale;
    u32 num_units_in_tick;
} VVC_SPS;

typedef struct {
    u32 id;
    u32 max_sub_layers;
    u32 num_ptl;
    struct {
        u32 general_profile_idc;
        u32 general_tier_flag;
        u32 general_level_idc;
        u32 frame_only_constraint;
        u32 multilayer_enabled;
        u8 *gci;
        u32 gci_present;
    } ptl[1];
    struct {
        u32 avg_pic_rate;
        u32 constant_pic_rate_idc;
    } rates[1];
} VVC_VPS;

typedef struct {
    VVC_VPS *vps;
    VVC_SPS *sps;
} VVC_State;

typedef struct {
    u8 *data;
    u32 id;
} GF_NALUFFParam;

typedef struct {
    void *nalus;
} GF_NALUFFParamArray;

typedef struct {
    u32 nal_length;
    void *sps;
    void *pps;
    void *vps;
    void *vvc_dci;
    void *vvc_opi;
    void *vvc_aps_pre;
    VVC_State *vvc_state;
    Bool analyze;
    Bool explicit;
    Bool notime;
    GF_Fraction fps;
    GF_Fraction cur_fps;
    u32 dts;
} GF_NALUDmxCtx;

GF_VVCConfig *gf_odf_vvc_cfg_new();
void gf_odf_vvc_cfg_write(GF_VVCConfig *cfg, u8 **dsi, u32 *dsi_size);
void gf_odf_vvc_cfg_del(GF_VVCConfig *cfg);
void *gf_list_get(void *list, u32 index);
u32 gf_list_count(void *list);
void gf_list_reset(void *list);
void naludmx_add_param_nalu(void *param_array, GF_NALUFFParam *sl, u32 type);
void gf_media_get_reduced_frame_rate(u32 *num, u32 *den);
#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;

#define MAX_LHVC_LAYERS 16
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef struct {
    int w;
    int h;
} HEVC_SAR;

typedef struct {
    u32 pic_width_luma_samples;
    u32 pic_height_luma_samples;
    u32 chroma_format_idc;
    u32 bit_depth_luma;
    u32 bit_depth_chroma;
    u32 separate_colour_plane_flag;
} HEVC_RepFormat;

typedef struct {
    u32 dummy;
} HEVC_ProfileTierLevel;

typedef struct {
    u32 state;
    u32 id;
    u32 vps_id;
    HEVC_ProfileTierLevel ptl;
    u32 max_sub_layers_minus1;
    u32 sps_ext_or_max_sub_layers_minus1;
    u32 chroma_format_idc;
    u32 separate_colour_plane_flag;
    u32 width;
    u32 height;
    u32 cw_flag;
    u32 cw_left;
    u32 cw_right;
    u32 cw_top;
    u32 cw_bottom;
    u32 bit_depth_luma;
    u32 bit_depth_chroma;
    u32 log2_max_pic_order_cnt_lsb;
    u32 sub_layer_ordering_info_present_flag;
    u32 log2_min_luma_coding_block_size;
    u32 log2_diff_max_min_luma_coding_block_size;
    u32 max_CU_width;
    u32 max_CU_height;
    u32 log2_min_transform_block_size;
    u32 log2_max_transform_block_size;
    u32 max_transform_hierarchy_depth_inter;
    u32 max_transform_hierarchy_depth_intra;
    u32 max_CU_depth;
    u32 bitsSliceSegmentAddress;
    u32 scaling_list_enable_flag;
    u32 infer_scaling_list_flag;
    u32 scaling_list_ref_layer_id;
    u32 scaling_list_data_present_flag;
    u32 asymmetric_motion_partitions_enabled_flag;
    u32 sample_adaptive_offset_enabled_flag;
    u32 pcm_enabled_flag;
    u32 pcm_sample_bit_depth_luma_minus1;
    u32 pcm_sample_bit_depth_chroma_minus1;
    u32 log2_min_pcm_luma_coding_block_size_minus3;
    u32 log2_diff_max_min_pcm_luma_coding_block_size;
    u32 pcm_loop_filter_disable_flag;
    u32 num_short_term_ref_pic_sets;
    u32 long_term_ref_pics_present_flag;
    u32 num_long_term_ref_pic_sps;
    u32 temporal_mvp_enable_flag;
    u32 strong_intra_smoothing_enable_flag;
    u32 vui_parameters_present_flag;
    u32 aspect_ratio_info_present_flag;
    u32 sar_idc;
    u32 sar_width;
    u32 sar_height;
    u32 overscan_info_present;
    u32 overscan_appropriate;
    u32 video_signal_type_present_flag;
    u32 video_format;
    u32 video_full_range_flag;
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 transfer_characteristic;
    u32 matrix_coeffs;
    u32 chroma_loc_info_present_flag;
    u32 chroma_sample_loc_type_top_field;
    u32 chroma_sample_loc_type_bottom_field;
    u32 neutral_chroma_indication_flag;
    u32 field_seq_flag;
    u32 frame_field_info_present_flag;
    u32 default_display_window_flag;
    u32 left_offset;
    u32 right_offset;
    u32 top_offset;
    u32 bottom_offset;
    u32 has_timing_info;
    u32 num_units_in_tick;
    u32 time_scale;
    u32 poc_proportional_to_timing_flag;
    u32 num_ticks_poc_diff_one_minus1;
    u32 hrd_parameters_present_flag;
    u32 update_rep_format_flag;
    u32 rep_format_idx;
} HEVC_SPS;

typedef struct {
    u32 layer_id_in_vps[MAX_LHVC_LAYERS];
    u32 rep_format_idx[MAX_LHVC_LAYERS];
    HEVC_RepFormat rep_formats[16];
    HEVC_ProfileTierLevel ext_ptl[1];
} HEVC_VPS;

typedef struct {
    HEVC_SPS sps[16];
    HEVC_VPS vps[16];
} HEVCState;

typedef struct {
    u32 dummy;
} GF_BitStream;

extern int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
extern int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
extern int gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, int idx);
extern int gf_bs_read_int_log_idx(GF_BitStream *bs, int bits, const char *name, int idx);
extern void hevc_profile_tier_level(GF_BitStream *bs, int profile_present, int max_sub_layers_minus1, HEVC_ProfileTierLevel *ptl, int dummy);
extern void hevc_scaling_list_data(GF_BitStream *bs);
extern Bool hevc_parse_short_term_ref_pic_set(GF_BitStream *bs, HEVC_SPS *sps, int i);
extern u32 gf_bs_get_bit_offset(GF_BitStream *bs);
extern Bool gf_bs_is_overflow(GF_BitStream *bs);
extern void GF_LOG(int level, int category, const char *format, ...);

extern HEVC_SAR hevc_sar[17];
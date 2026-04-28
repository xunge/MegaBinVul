#include <stdint.h>
#include <string.h>

#define IHEVCD_SUCCESS_VAL 0
#define IHEVCD_UNSUPPORTED_SPS_ID_VAL 1
#define IHEVCD_UNSUPPORTED_CHROMA_FMT_IDC_VAL 2
#define IHEVCD_INVALID_PARAMETER_VAL 3
#define IHEVCD_UNSUPPORTED_BIT_DEPTH_VAL 4
#define IVD_RES_CHANGED_VAL 5

#define MAX_VPS_CNT 16
#define MAX_SPS_CNT 16
#define MAX_DPB_SIZE 16
#define MAX_STREF_PICS_SPS 64
#define CHROMA_FMT_IDC_YUV420 1
#define CHROMA_FMT_IDC_YUV444_PLANES 3
#define PAD_WD 64

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef uint8_t UWORD8;
typedef int16_t WORD16;
typedef uint16_t UWORD16;
typedef int8_t WORD8;
typedef uint8_t UWORD8;

typedef enum {
    IHEVCD_SUCCESS = IHEVCD_SUCCESS_VAL,
    IHEVCD_UNSUPPORTED_SPS_ID = IHEVCD_UNSUPPORTED_SPS_ID_VAL,
    IHEVCD_UNSUPPORTED_CHROMA_FMT_IDC = IHEVCD_UNSUPPORTED_CHROMA_FMT_IDC_VAL,
    IHEVCD_INVALID_PARAMETER = IHEVCD_INVALID_PARAMETER_VAL,
    IHEVCD_UNSUPPORTED_BIT_DEPTH = IHEVCD_UNSUPPORTED_BIT_DEPTH_VAL,
    IVD_RES_CHANGED = IVD_RES_CHANGED_VAL
} IHEVCD_ERROR_T;

typedef struct {
    WORD8 profile_space;
    WORD8 tier_flag;
    WORD8 profile_idc;
    WORD8 profile_compatibility_flag[32];
    WORD8 progressive_source_flag;
    WORD8 interlaced_source_flag;
    WORD8 non_packed_constraint_flag;
    WORD8 frame_only_constraint_flag;
    WORD8 level_idc;
} profile_tier_lvl_info_t;

typedef struct {
    UWORD32 *pu4_buf;
    UWORD8 *pu1_buf_max;
} bitstrm_t;

typedef struct {
    WORD8 i1_sps_id;
    WORD8 i1_vps_id;
    WORD8 i1_sps_max_sub_layers;
    WORD8 i1_sps_temporal_id_nesting_flag;
    WORD8 i1_chroma_format_idc;
    WORD8 i1_separate_colour_plane_flag;
    WORD16 i2_pic_width_in_luma_samples;
    WORD16 i2_pic_height_in_luma_samples;
    WORD8 i1_pic_cropping_flag;
    WORD16 i2_pic_crop_left_offset;
    WORD16 i2_pic_crop_right_offset;
    WORD16 i2_pic_crop_top_offset;
    WORD16 i2_pic_crop_bottom_offset;
    WORD8 i1_log2_max_pic_order_cnt_lsb;
    WORD8 i1_sps_sub_layer_ordering_info_present_flag;
    WORD8 ai1_sps_max_dec_pic_buffering[MAX_DPB_SIZE];
    WORD8 ai1_sps_max_num_reorder_pics[MAX_DPB_SIZE];
    WORD8 ai1_sps_max_latency_increase[MAX_DPB_SIZE];
    WORD8 i1_log2_min_coding_block_size;
    WORD8 i1_log2_diff_max_min_coding_block_size;
    WORD8 i1_log2_min_transform_block_size;
    WORD8 i1_log2_diff_max_min_transform_block_size;
    WORD8 i1_log2_max_transform_block_size;
    WORD8 i1_log2_ctb_size;
    WORD8 i1_log2_min_pcm_coding_block_size;
    WORD8 i1_log2_diff_max_min_pcm_coding_block_size;
    WORD8 i1_max_transform_hierarchy_depth_inter;
    WORD8 i1_max_transform_hierarchy_depth_intra;
    WORD8 i1_scaling_list_enable_flag;
    WORD8 i1_sps_scaling_list_data_present_flag;
    WORD16 pi2_scaling_mat[6][16];
    WORD8 i1_amp_enabled_flag;
    WORD8 i1_sample_adaptive_offset_enabled_flag;
    WORD8 i1_pcm_enabled_flag;
    WORD8 i1_pcm_sample_bit_depth_luma;
    WORD8 i1_pcm_sample_bit_depth_chroma;
    WORD8 i1_pcm_loop_filter_disable_flag;
    WORD8 i1_num_short_term_ref_pic_sets;
    struct {
        WORD8 num_negative_pics;
        WORD8 num_positive_pics;
        WORD16 delta_poc_s0_minus1[16];
        WORD16 delta_poc_s1_minus1[16];
        WORD8 used_by_curr_pic_s0_flag[16];
        WORD8 used_by_curr_pic_s1_flag[16];
    } as_stref_picset[MAX_STREF_PICS_SPS];
    WORD8 i1_long_term_ref_pics_present_flag;
    WORD8 i1_num_long_term_ref_pics_sps;
    WORD16 ai1_lt_ref_pic_poc_lsb_sps[MAX_STREF_PICS_SPS];
    WORD8 ai1_used_by_curr_pic_lt_sps_flag[MAX_STREF_PICS_SPS];
    WORD8 i1_sps_temporal_mvp_enable_flag;
    WORD8 i1_strong_intra_smoothing_enable_flag;
    WORD8 i1_vui_parameters_present_flag;
    struct {
        WORD8 aspect_ratio_info_present_flag;
        WORD8 aspect_ratio_idc;
        WORD16 sar_width;
        WORD16 sar_height;
        WORD8 overscan_info_present_flag;
        WORD8 overscan_appropriate_flag;
        WORD8 video_signal_type_present_flag;
        WORD8 video_format;
        WORD8 video_full_range_flag;
        WORD8 colour_description_present_flag;
        WORD8 colour_primaries;
        WORD8 transfer_characteristics;
        WORD8 matrix_coefficients;
        WORD8 chroma_loc_info_present_flag;
        WORD8 chroma_sample_loc_type_top_field;
        WORD8 chroma_sample_loc_type_bottom_field;
        WORD8 neutral_chroma_indication_flag;
        WORD8 field_seq_flag;
        WORD8 frame_field_info_present_flag;
        WORD8 default_display_window_flag;
        WORD16 def_disp_win_left_offset;
        WORD16 def_disp_win_right_offset;
        WORD16 def_disp_win_top_offset;
        WORD16 def_disp_win_bottom_offset;
        WORD8 vui_timing_info_present_flag;
        WORD32 vui_num_units_in_tick;
        WORD32 vui_time_scale;
        WORD8 vui_poc_proportional_to_timing_flag;
        WORD32 vui_num_ticks_poc_diff_one_minus1;
        WORD8 vui_hrd_parameters_present_flag;
        WORD8 bitstream_restriction_flag;
        WORD8 tiles_fixed_structure_flag;
        WORD8 motion_vectors_over_pic_boundaries_flag;
        WORD8 restricted_ref_pic_lists_flag;
        WORD16 min_spatial_segmentation_idc;
        WORD8 max_bytes_per_pic_denom;
        WORD8 max_bits_per_min_cu_denom;
        WORD8 log2_max_mv_length_horizontal;
        WORD8 log2_max_mv_length_vertical;
    } s_vui_parameters;
    profile_tier_lvl_info_t s_ptl;
    WORD16 i2_pic_wd_in_ctb;
    WORD16 i2_pic_ht_in_ctb;
    WORD32 i4_pic_size_in_ctb;
    WORD16 i2_pic_wd_in_min_cb;
    WORD16 i2_pic_ht_in_min_cb;
} sps_t;

typedef struct {
    WORD32 i4_sps_done;
    WORD32 i4_first_pic_done;
    WORD32 i4_wd;
    WORD32 i4_ht;
    WORD32 i4_disp_wd;
    WORD32 i4_disp_ht;
    WORD32 i4_strd;
    WORD32 i4_disp_strd;
    WORD32 i4_share_disp_buf;
    WORD32 i4_sps_id;
    WORD32 i4_reset_flag;
    struct {
        bitstrm_t s_bitstrm;
        WORD32 i4_error_code;
        WORD32 i4_next_ctb_indx;
        sps_t *ps_sps_base;
    } s_parse;
} codec_t;

#define CLIP3(var, min, max) ((var) < (min) ? (min) : ((var) > (max) ? (max) : (var)))
#define ALIGN8(var) (((var) + 7) & ~7)
#define ALIGN32(var) (((var) + 31) & ~31)
#define BITS_PARSE(str, val, bitstrm, bits) (val) = 0
#define UEV_PARSE(str, val, bitstrm) (val) = 0
#define COPY_DEFAULT_SCALING_LIST(mat)
#define COPY_FLAT_SCALING_LIST(mat)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

IHEVCD_ERROR_T ihevcd_profile_tier_level(bitstrm_t *ps_bitstrm, profile_tier_lvl_info_t *ps_ptl, WORD32 flag, WORD32 max_sub_layers);
IHEVCD_ERROR_T ihevcd_scaling_list_data(codec_t *ps_codec, WORD16 pi2_scaling_mat[6][16]);
IHEVCD_ERROR_T ihevcd_short_term_ref_pic_set(bitstrm_t *ps_bitstrm, void *p_base, WORD32 num_sets, WORD32 idx, void *p_set);
IHEVCD_ERROR_T ihevcd_parse_vui_parameters(bitstrm_t *ps_bitstrm, void *ps_vui, WORD32 max_sub_layers);
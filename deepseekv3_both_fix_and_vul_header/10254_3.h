#include <stdint.h>
#include <string.h>

#define MAX_VPS_CNT 16
#define MAX_SPS_CNT 16
#define MAX_DPB_SIZE 16
#define MAX_STREF_PICS_SPS 64
#define CHROMA_FMT_IDC_YUV420 1
#define CHROMA_FMT_IDC_YUV444_PLANES 3
#define PAD_WD 64

typedef enum {
    IHEVCD_SUCCESS = 0,
    IHEVCD_FAIL = 1,
    IHEVCD_UNSUPPORTED_SPS_ID = 2,
    IHEVCD_UNSUPPORTED_CHROMA_FMT_IDC = 3,
    IHEVCD_INVALID_PARAMETER = 4,
    IHEVCD_UNSUPPORTED_DIMENSIONS = 5,
    IHEVCD_UNSUPPORTED_BIT_DEPTH = 6,
    IVD_RES_CHANGED = 7
} IHEVCD_ERROR_T;

typedef int32_t WORD32;
typedef int16_t WORD16;
typedef int8_t WORD8;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;

typedef struct bitstrm_t {
    // bitstream fields
} bitstrm_t;

typedef struct profile_tier_lvl_info_t {
    // profile tier level fields
} profile_tier_lvl_info_t;

typedef struct sps_t {
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
        // stref_picset fields
    } as_stref_picset[MAX_STREF_PICS_SPS];
    WORD8 i1_long_term_ref_pics_present_flag;
    WORD8 i1_num_long_term_ref_pics_sps;
    WORD32 ai1_lt_ref_pic_poc_lsb_sps[MAX_STREF_PICS_SPS];
    WORD8 ai1_used_by_curr_pic_lt_sps_flag[MAX_STREF_PICS_SPS];
    WORD8 i1_sps_temporal_mvp_enable_flag;
    WORD8 i1_strong_intra_smoothing_enable_flag;
    WORD8 i1_vui_parameters_present_flag;
    struct {
        // vui_parameters fields
    } s_vui_parameters;
    WORD16 i2_pic_wd_in_ctb;
    WORD16 i2_pic_ht_in_ctb;
    WORD32 i4_pic_size_in_ctb;
    WORD16 i2_pic_wd_in_min_cb;
    WORD16 i2_pic_ht_in_min_cb;
    profile_tier_lvl_info_t s_ptl;
} sps_t;

typedef struct {
    WORD32 i4_sps_done;
    WORD32 i4_max_wd;
    WORD32 i4_max_ht;
    WORD32 i4_new_max_wd;
    WORD32 i4_new_max_ht;
    WORD32 i4_wd;
    WORD32 i4_ht;
    WORD32 i4_disp_wd;
    WORD32 i4_disp_ht;
    WORD32 i4_strd;
    WORD32 i4_disp_strd;
    WORD32 i4_share_disp_buf;
    WORD32 i4_first_pic_done;
    WORD32 i4_reset_flag;
    WORD32 i4_error_code;
    WORD32 i4_sps_id;
    struct {
        bitstrm_t s_bitstrm;
        WORD32 i4_error_code;
        sps_t *ps_sps_base;
        WORD32 i4_next_ctb_indx;
    } s_parse;
} codec_t;

#define CLIP3(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))
#define ALIGN8(x) (((x) + 7) & ~7)
#define ALIGN32(x) (((x) + 31) & ~31)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define BITS_PARSE(str, val, bitstrm, bits) 
#define UEV_PARSE(str, val, bitstrm) 
#define COPY_DEFAULT_SCALING_LIST(mat) 
#define COPY_FLAT_SCALING_LIST(mat) 

IHEVCD_ERROR_T ihevcd_profile_tier_level(bitstrm_t *ps_bitstrm, profile_tier_lvl_info_t *ps_ptl, WORD32 i1_profile_present_flag, WORD32 i1_max_sub_layers_minus1);
IHEVCD_ERROR_T ihevcd_scaling_list_data(codec_t *ps_codec, WORD16 pi2_scaling_mat[6][16]);
IHEVCD_ERROR_T ihevcd_short_term_ref_pic_set(bitstrm_t *ps_bitstrm, void *ps_stref_picset_base, WORD32 i1_num_short_term_ref_pic_sets, WORD32 i, void *ps_stref_picset);
IHEVCD_ERROR_T ihevcd_parse_vui_parameters(bitstrm_t *ps_bitstrm, void *ps_vui_parameters, WORD32 i1_sps_max_sub_layers_minus1);
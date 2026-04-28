#include <stdint.h>
#include <stdarg.h>

typedef int32_t s32;
typedef uint32_t u32;

#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef struct {
    int state;
    s32 id;
    u32 sps_id;
    u32 dependent_slice_segments_enabled_flag;
    u32 output_flag_present_flag;
    u32 num_extra_slice_header_bits;
    u32 sign_data_hiding_flag;
    u32 cabac_init_present_flag;
    u32 num_ref_idx_l0_default_active;
    u32 num_ref_idx_l1_default_active;
    s32 pic_init_qp_minus26;
    u32 constrained_intra_pred_flag;
    u32 transform_skip_enabled_flag;
    u32 cu_qp_delta_enabled_flag;
    u32 diff_cu_qp_delta_depth;
    s32 pic_cb_qp_offset;
    s32 pic_cr_qp_offset;
    u32 slice_chroma_qp_offsets_present_flag;
    u32 weighted_pred_flag;
    u32 weighted_bipred_flag;
    u32 transquant_bypass_enable_flag;
    u32 tiles_enabled_flag;
    u32 entropy_coding_sync_enabled_flag;
    u32 num_tile_columns;
    u32 num_tile_rows;
    u32 uniform_spacing_flag;
    u32 column_width[22];
    u32 row_height[20];
    u32 loop_filter_across_tiles_enabled_flag;
    u32 loop_filter_across_slices_enabled_flag;
    u32 deblocking_filter_control_present_flag;
    u32 deblocking_filter_override_enabled_flag;
    u32 pic_disable_deblocking_filter_flag;
    s32 beta_offset_div2;
    s32 tc_offset_div2;
    u32 pic_scaling_list_data_present_flag;
    u32 lists_modification_present_flag;
    u32 log2_parallel_merge_level_minus2;
    u32 slice_segment_header_extension_present_flag;
} HEVC_PPS;

typedef struct {
    HEVC_PPS pps[64];
    u32 sps_active_idx;
} HEVCState;

typedef struct GF_BitStream GF_BitStream;

s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_int_log(GF_BitStream *bs, u32 nbits, const char *name);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
u32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
void hevc_scaling_list_data(GF_BitStream *bs);
void GF_LOG(u32 level, u32 tool, const char *fmt, ...);
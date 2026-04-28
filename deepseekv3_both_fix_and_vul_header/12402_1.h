#include <stdint.h>
#include <stdarg.h>

#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef int32_t s32;
typedef uint32_t u32;

typedef struct {
    int state;
    int id;
    int sps_id;
    int dependent_slice_segments_enabled_flag;
    int output_flag_present_flag;
    int num_extra_slice_header_bits;
    int sign_data_hiding_flag;
    int cabac_init_present_flag;
    int num_ref_idx_l0_default_active;
    int num_ref_idx_l1_default_active;
    int pic_init_qp_minus26;
    int constrained_intra_pred_flag;
    int transform_skip_enabled_flag;
    int cu_qp_delta_enabled_flag;
    int diff_cu_qp_delta_depth;
    int pic_cb_qp_offset;
    int pic_cr_qp_offset;
    int slice_chroma_qp_offsets_present_flag;
    int weighted_pred_flag;
    int weighted_bipred_flag;
    int transquant_bypass_enable_flag;
    int tiles_enabled_flag;
    int entropy_coding_sync_enabled_flag;
    int num_tile_columns;
    int num_tile_rows;
    int uniform_spacing_flag;
    int column_width[20];
    int row_height[20];
    int loop_filter_across_tiles_enabled_flag;
    int loop_filter_across_slices_enabled_flag;
    int deblocking_filter_control_present_flag;
    int deblocking_filter_override_enabled_flag;
    int pic_disable_deblocking_filter_flag;
    int beta_offset_div2;
    int tc_offset_div2;
    int pic_scaling_list_data_present_flag;
    int lists_modification_present_flag;
    int log2_parallel_merge_level_minus2;
    int slice_segment_header_extension_present_flag;
} HEVC_PPS;

typedef struct {
    HEVC_PPS pps[64];
    int sps_active_idx;
} HEVCState;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_se_log(GF_BitStream *bs, const char *name);
int gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, int idx);
void hevc_scaling_list_data(GF_BitStream *bs);
void GF_LOG(int level, int category, const char *fmt, ...);
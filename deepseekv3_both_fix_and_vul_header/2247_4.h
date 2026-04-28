#include <stdint.h>

#define MAX_PPS_CNT 64
#define MAX_SPS_CNT 32
#define MIN_TILE_WD 256
#define MIN_TILE_HT 256

typedef enum {
    IHEVCD_SUCCESS,
    IHEVCD_INVALID_HEADER,
    IHEVCD_UNSUPPORTED_PPS_ID,
    IHEVCD_INVALID_PARAMETER
} IHEVCD_ERROR_T;

typedef int32_t WORD32;
typedef uint8_t UWORD8;
typedef uint32_t UWORD32;
typedef int16_t WORD16;
typedef uint16_t UWORD16;
typedef int8_t WORD8;

typedef struct bitstrm_t {
    UWORD8 *pu1_buf_max;
    UWORD32 *pu4_buf;
} bitstrm_t;

typedef struct tile_t {
    UWORD8 u1_pos_x;
    UWORD8 u1_pos_y;
    UWORD16 u2_wd;
    UWORD16 u2_ht;
} tile_t;

typedef struct sps_t {
    WORD8 i1_sps_valid;
    WORD8 i1_log2_ctb_size;
    WORD16 i2_pic_width_in_luma_samples;
    WORD16 i2_pic_height_in_luma_samples;
    WORD16 i2_pic_wd_in_ctb;
    WORD16 i2_pic_ht_in_ctb;
} sps_t;

typedef struct pps_t {
    WORD8 i1_pps_id;
    WORD8 i1_sps_id;
    WORD8 i1_dependent_slice_enabled_flag;
    WORD8 i1_output_flag_present_flag;
    WORD8 i1_num_extra_slice_header_bits;
    WORD8 i1_sign_data_hiding_flag;
    WORD8 i1_cabac_init_present_flag;
    WORD8 i1_num_ref_idx_l0_default_active;
    WORD8 i1_num_ref_idx_l1_default_active;
    WORD8 i1_pic_init_qp;
    WORD8 i1_constrained_intra_pred_flag;
    WORD8 i1_transform_skip_enabled_flag;
    WORD8 i1_cu_qp_delta_enabled_flag;
    WORD8 i1_diff_cu_qp_delta_depth;
    WORD8 i1_log2_min_cu_qp_delta_size;
    WORD8 i1_pic_cb_qp_offset;
    WORD8 i1_pic_cr_qp_offset;
    WORD8 i1_pic_slice_level_chroma_qp_offsets_present_flag;
    WORD8 i1_weighted_pred_flag;
    WORD8 i1_weighted_bipred_flag;
    WORD8 i1_transquant_bypass_enable_flag;
    WORD8 i1_tiles_enabled_flag;
    WORD8 i1_entropy_coding_sync_enabled_flag;
    WORD8 i1_loop_filter_across_tiles_enabled_flag;
    WORD8 i1_num_tile_columns;
    WORD8 i1_num_tile_rows;
    WORD8 i1_uniform_spacing_flag;
    WORD8 i1_loop_filter_across_slices_enabled_flag;
    WORD8 i1_deblocking_filter_control_present_flag;
    WORD8 i1_pic_disable_deblocking_filter_flag;
    WORD8 i1_deblocking_filter_override_enabled_flag;
    WORD8 i1_beta_offset_div2;
    WORD8 i1_tc_offset_div2;
    WORD8 i1_pps_scaling_list_data_present_flag;
    WORD8 i1_lists_modification_present_flag;
    WORD8 i1_log2_parallel_merge_level;
    WORD8 i1_slice_header_extension_present_flag;
    WORD16 *pi2_scaling_mat;
    tile_t *ps_tile;
} pps_t;

typedef struct {
    WORD32 i4_sps_done;
    WORD32 i4_pps_done;
    WORD32 i4_wd;
    WORD32 i4_ht;
    struct {
        bitstrm_t s_bitstrm;
        pps_t *ps_pps_base;
        sps_t *ps_sps_base;
    } s_parse;
} codec_t;

#define UEV_PARSE(str, val, bitstrm) 
#define SEV_PARSE(str, val, bitstrm) 
#define BITS_PARSE(str, val, bitstrm, bits) 
#define CLIP3(val, min, max) ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))
#define ALIGN64(val) (((val) + 63) & ~63)
#define COPY_DEFAULT_SCALING_LIST(mat) 

static inline WORD8 clip3(WORD8 val, WORD8 min, WORD8 max) {
    return val < min ? min : (val > max ? max : val);
}
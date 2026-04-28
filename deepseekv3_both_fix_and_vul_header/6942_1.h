#include <stdint.h>
#include <stdarg.h>

#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2
#define VVC_MAX_TILE_COLS 20
#define VVC_MAX_TILE_ROWS 22

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    int state;
    u32 id;
    u32 sps_id;
    u32 mixed_nal_types;
    u32 width;
    u32 height;
    u32 conf_window;
    u32 cw_left;
    u32 cw_right;
    u32 cw_top;
    u32 cw_bottom;
    u32 output_flag_present_flag;
    u32 no_pic_partition_flag;
    u32 subpic_id_mapping_present_flag;
    u32 single_slice_per_subpic_flag;
    u32 num_slices_in_pic;
    u32 num_tiles_in_pic;
    u32 pic_width_in_ctbsY;
    u32 pic_height_in_ctbsY;
    u32 num_tile_cols;
    u32 num_tile_rows;
    u32 tile_cols_width_ctb[VVC_MAX_TILE_COLS];
    u32 tile_rows_height_ctb[VVC_MAX_TILE_ROWS];
    u32 slice_address_len;
    u32 rect_slice_flag;
    u32 cabac_init_present_flag;
    u32 num_ref_idx_default_active[2];
    u32 rpl1_idx_present_flag;
    u32 weighted_pred_flag;
    u32 weighted_bipred_flag;
    u32 cu_qp_delta_enabled_flag;
    u32 chroma_tool_offsets_present_flag;
    u32 slice_chroma_qp_offsets_present_flag;
    u32 cu_chroma_qp_offset_list_enabled_flag;
    u32 dbf_info_in_ph_flag;
    u32 deblocking_filter_disabled_flag;
    u32 deblocking_filter_override_enabled_flag;
    u32 wp_info_in_ph_flag;
    u32 qp_delta_info_in_ph_flag;
    u32 sao_info_in_ph_flag;
    u32 rpl_info_in_ph_flag;
    u32 alf_info_in_ph_flag;
    u32 picture_header_extension_present_flag;
    u32 slice_header_extension_present_flag;
} VVC_PPS;

typedef struct {
    VVC_PPS pps[64];
    u32 sps_active_idx;
} VVCState;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_int_log_idx(GF_BitStream *bs, int bits, const char *name, u32 idx);
int gf_bs_read_int_log_idx2(GF_BitStream *bs, int bits, const char *name, u32 idx1, u32 idx2);
int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
int gf_bs_read_ue_log_idx2(GF_BitStream *bs, const char *name, u32 idx1, u32 idx2);
int gf_bs_read_se_log(GF_BitStream *bs, const char *name);
int gf_bs_read_se_log_idx(GF_BitStream *bs, const char *name, u32 idx);
int gf_bs_read_ue(GF_BitStream *bs);
int gf_get_bit_size(u32 val);
void GF_LOG(int level, int sub, const char *fmt, ...);
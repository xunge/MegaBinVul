#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1

#define GF_LOG_WARNING 1
#define GF_LOG_CODING 2
#define GF_HEVC_NALU_SLICE_IDR_W_DLP 19
#define GF_HEVC_NALU_SLICE_IDR_N_LP 20
#define GF_HEVC_NALU_SLICE_BLA_W_LP 16
#define GF_HEVC_NALU_SLICE_BLA_W_DLP 17
#define GF_HEVC_NALU_SLICE_BLA_N_LP 18
#define GF_HEVC_NALU_SLICE_CRA 21
#define GF_HEVC_SLICE_TYPE_P 0
#define GF_HEVC_SLICE_TYPE_B 1

typedef struct {
    u32 bitsSliceSegmentAddress;
    u32 log2_max_pic_order_cnt_lsb;
    u32 num_short_term_ref_pic_sets;
    u32 long_term_ref_pics_present_flag;
    u32 num_long_term_ref_pic_sps;
    u32 separate_colour_plane_flag;
    u32 chroma_format_idc;
    u32 temporal_mvp_enable_flag;
    u32 sample_adaptive_offset_enabled_flag;
} HEVC_SPS;

typedef struct {
    u32 sps_id;
    u32 dependent_slice_segments_enabled_flag;
    u32 num_extra_slice_header_bits;
    u32 output_flag_present_flag;
    u32 num_ref_idx_l0_default_active;
    u32 num_ref_idx_l1_default_active;
    u32 lists_modification_present_flag;
    u32 cabac_init_present_flag;
    u32 weighted_pred_flag;
    u32 weighted_bipred_flag;
    u32 tiles_enabled_flag;
    u32 entropy_coding_sync_enabled_flag;
    u32 slice_segment_header_extension_present_flag;
    u32 deblocking_filter_override_enabled_flag;
    u32 loop_filter_across_slices_enabled_flag;
    u32 slice_chroma_qp_offsets_present_flag;
} HEVC_PPS;

typedef struct {
    u32 nal_unit_type;
    u32 first_slice_segment_in_pic_flag;
    u32 dependent_slice_segment_flag;
    u32 slice_segment_address;
    u32 slice_type;
    u32 poc_lsb;
    HEVC_SPS *sps;
    HEVC_PPS *pps;
    u32 entry_point_start_bits;
    u32 header_size_bits;
    s32 slice_qp_delta;
    s32 slice_qp_delta_start_bits;
    s32 payload_start_offset;
} HEVCSliceInfo;

typedef struct {
    HEVC_PPS pps[64];
    HEVC_SPS sps[16];
    Bool full_slice_header_parse;
} HEVCState;

typedef struct GF_BitStream GF_BitStream;

static u32 gf_bs_read_int_log(GF_BitStream *bs, u32 bits, const char *name);
static u32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
static s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
static u32 gf_bs_read_int_log_idx(GF_BitStream *bs, u32 bits, const char *name, u32 idx);
static u32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
static u32 gf_bs_get_position(GF_BitStream *bs);
static u32 gf_bs_get_bit_position(GF_BitStream *bs);
static void gf_bs_align(GF_BitStream *bs);
static u32 gf_bs_read_int(GF_BitStream *bs, u32 bits);
static u32 gf_get_bit_size(u32 val);
static void GF_LOG(u32 level, u32 category, const char *fmt, ...);
static Bool hevc_parse_short_term_ref_pic_set(GF_BitStream *bs, HEVC_SPS *sps, u32 num_sets);
static Bool ref_pic_lists_modification(GF_BitStream *bs, u32 slice_type, u32 num_ref_idx_l0_active, u32 num_ref_idx_l1_active);
static void hevc_pred_weight_table(GF_BitStream *bs, HEVCState *hevc, HEVCSliceInfo *si, HEVC_PPS *pps, HEVC_SPS *sps, u32 num_ref_idx_l0_active, u32 num_ref_idx_l1_active);
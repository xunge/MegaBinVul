#include <stdint.h>
#include <math.h>

typedef int32_t s32;
typedef uint32_t u32;

#define GF_TRUE 1
#define GF_SVC_SSPS_ID_SHIFT 16

typedef struct GF_BitStream GF_BitStream;

typedef struct {
    s32 state;
} AVCSPS;

typedef struct {
    s32 id;
    s32 status;
    s32 sps_id;
    s32 entropy_coding_mode_flag;
    s32 pic_order_present;
    s32 slice_group_count;
    s32 mb_slice_group_map_type;
    s32 pic_size_in_map_units_minus1;
    s32 num_ref_idx_l0_default_active_minus1;
    s32 num_ref_idx_l1_default_active_minus1;
    s32 weighted_pred_flag;
    s32 deblocking_filter_control_present_flag;
    s32 redundant_pic_cnt_present;
} AVC_PPS;

typedef struct {
    AVC_PPS pps[256];
    AVCSPS sps[32 + GF_SVC_SSPS_ID_SHIFT];
    s32 pps_active_idx;
    s32 sps_active_idx;
} AVCState;

s32 gf_bs_enable_emulation_byte_removal(GF_BitStream *bs, s32 enable);
s32 gf_bs_read_int_log(GF_BitStream *bs, s32 nBits, const char *name);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
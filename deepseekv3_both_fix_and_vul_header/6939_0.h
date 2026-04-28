#include <stdint.h>
#include <math.h>

typedef int32_t s32;
typedef uint32_t u32;

#define GF_TRUE 1
#define GF_SVC_SSPS_ID_SHIFT 16

typedef struct {
    int state;
} AVC_SPS;

typedef struct {
    s32 id;
    s32 status;
    s32 sps_id;
    u32 entropy_coding_mode_flag;
    u32 pic_order_present;
    u32 slice_group_count;
    u32 mb_slice_group_map_type;
    u32 pic_size_in_map_units_minus1;
    u32 num_ref_idx_l0_default_active_minus1;
    u32 num_ref_idx_l1_default_active_minus1;
    u32 weighted_pred_flag;
    u32 deblocking_filter_control_present_flag;
    u32 redundant_pic_cnt_present;
} AVC_PPS;

typedef struct {
    AVC_PPS pps[255];
    AVC_SPS sps[32 + GF_SVC_SSPS_ID_SHIFT];
    s32 pps_active_idx;
    s32 sps_active_idx;
} AVCState;

typedef struct GF_BitStream GF_BitStream;

void gf_bs_enable_emulation_byte_removal(GF_BitStream *bs, int flag);
u32 gf_bs_read_int_log(GF_BitStream *bs, u32 nBits, const char *name);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
u32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
u32 gf_bs_read_int_log_idx(GF_BitStream *bs, u32 nBits, const char *name, u32 idx);
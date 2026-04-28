#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0

typedef struct {
    u32 pt_present;
    u32 ptl_max_tid;
} VVC_ProfileTierLevel;

typedef struct {
    u32 state;
    u32 num_ptl;
    u32 max_layers;
    u32 all_layers_independent;
    VVC_ProfileTierLevel ptl[1];
} VVC_VPS;

typedef struct {
    u32 state;
    u32 id;
    u32 vps_id;
    u32 max_sublayers;
    u32 chroma_format_idc;
    u32 log2_ctu_size;
    u32 gdr_enabled;
    u32 ref_pic_resampling;
    u32 res_change_in_clvs;
    u32 width;
    u32 height;
    u32 conf_window;
    u32 cw_left;
    u32 cw_right;
    u32 cw_top;
    u32 cw_bottom;
    u32 subpic_info_present;
    u32 nb_subpics;
    u32 independent_subpic_flags;
    u32 subpic_same_size;
    u32 subpicid_len;
    u32 subpicid_mapping_explicit;
    u32 subpicid_mapping_present;
    u32 bitdepth;
    u32 entropy_coding_sync_enabled_flag;
    u32 entry_point_offsets_present_flag;
    u32 log2_max_poc_lsb;
    u32 poc_msb_cycle_flag;
    u32 poc_msb_cycle_len;
    u32 ph_num_extra_bits;
    u32 sh_num_extra_bits;
    u32 transform_skip_enabled_flag;
    u32 joint_cbcr_enabled_flag;
    u32 sao_enabled_flag;
    u32 alf_enabled_flag;
    u32 ccalf_enabled_flag;
    u32 lmcs_enabled_flag;
    u32 weighted_pred_flag;
    u32 weighted_bipred_flag;
    u32 long_term_ref_pics_flag;
    u32 inter_layer_prediction_enabled_flag;
    u32 idr_rpl_present_flag;
    u32 num_ref_pic_lists[2];
    struct {
        // Placeholder for RPS structure
    } rps[2][16];
    u32 temporal_mvp_enabled_flag;
    u32 bdof_control_present_in_ph_flag;
    u32 dmvr_control_present_in_ph_flag;
    u32 mmvd_fullpel_only_enabled_flag;
    u32 prof_control_present_in_ph_flag;
    u32 aspect_ratio_info_present_flag;
    u32 sar_idc;
    u32 sar_width;
    u32 sar_height;
    u32 overscan_info_present_flag;
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 transfer_characteristics;
    u32 matrix_coefficients;
    u32 video_full_range_flag;
    u32 explicit_scaling_list_enabled_flag;
    u32 dep_quant_enabled_flag;
    u32 sign_data_hiding_enabled_flag;
    u32 virtual_boundaries_enabled_flag;
    u32 virtual_boundaries_present_flag;
    u32 partition_constraints_override_enabled_flag;
} VVC_SPS;

typedef struct {
    VVC_VPS vps[16];
    VVC_SPS sps[16];
} VVCState;

typedef struct GF_BitStream GF_BitStream;

s32 gf_bs_read_int_log(GF_BitStream *bs, u32 bits, const char *name);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_int_log_idx(GF_BitStream *bs, u32 bits, const char *name, u32 idx);
s32 gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
s32 gf_bs_read_se_log_idx(GF_BitStream *bs, const char *name, u32 idx);
s32 gf_bs_read_ue_log_idx2(GF_BitStream *bs, const char *name, u32 idx1, u32 idx2);
u32 gf_bs_get_bit_offset(GF_BitStream *bs);
Bool gf_bs_is_align(GF_BitStream *bs);
u32 gf_get_bit_size(u32 val);

void vvc_profile_tier_level(GF_BitStream *bs, VVC_ProfileTierLevel *ptl, u32 profilePresent);
void vvc_parse_general_timing_hrd_parameters(GF_BitStream *bs, VVC_SPS *sps, void *unused, Bool *nal_present, Bool *vcl_present, Bool *du_present, u32 *hrd_cnt);
void vvc_parse_ols_timing_hrd_parameters(GF_BitStream *bs, u32 first, u32 last, Bool nal_present, Bool vcl_present, Bool du_present, u32 hrd_cnt);
s32 vvc_parse_ref_pic_list_struct(GF_BitStream *bs, VVC_SPS *sps, u32 list_idx, u32 rpl_idx, void *rpl);
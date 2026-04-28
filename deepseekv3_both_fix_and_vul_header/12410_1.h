#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    u8 pt_present;
    u32 ptl_max_tid;
} VVC_ProfileTierLevel;

typedef struct {
    int state;
    u32 num_ptl;
    u32 max_layers;
    u8 all_layers_independent;
    VVC_ProfileTierLevel ptl[1];
} VVC_VPS;

typedef struct {
    int state;
    u32 id;
    u32 vps_id;
    u32 max_sublayers;
    u32 chroma_format_idc;
    u32 log2_ctu_size;
    u8 gdr_enabled;
    u8 ref_pic_resampling;
    u8 res_change_in_clvs;
    u32 width;
    u32 height;
    u8 conf_window;
    u32 cw_left;
    u32 cw_right;
    u32 cw_top;
    u32 cw_bottom;
    u8 subpic_info_present;
    u32 nb_subpics;
    u8 independent_subpic_flags;
    u8 subpic_same_size;
    u32 subpicid_len;
    u8 subpicid_mapping_explicit;
    u8 subpicid_mapping_present;
    u32 bitdepth;
    u8 poc_msb_cycle_flag;
    u32 poc_msb_cycle_len;
    u32 log2_max_poc_lsb;
    u32 ph_num_extra_bits;
    u32 sh_num_extra_bits;
    u8 alf_enabled_flag;
} VVC_SPS;

typedef struct {
    VVC_VPS vps[16];
    VVC_SPS sps[16];
} VVCState;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_se_log(GF_BitStream *bs, const char *name);
int gf_bs_read_int_log_idx(GF_BitStream *bs, int bits, const char *name, u32 idx);
int gf_bs_read_ue_log_idx(GF_BitStream *bs, const char *name, u32 idx);
int gf_bs_read_se_log_idx(GF_BitStream *bs, const char *name, u32 idx);
int gf_bs_read_ue_log_idx2(GF_BitStream *bs, const char *name, u32 idx1, u32 idx2);
u32 gf_get_bit_size(u32 val);
void vvc_profile_tier_level(GF_BitStream *bs, VVC_ProfileTierLevel *ptl, u32 profile_present);
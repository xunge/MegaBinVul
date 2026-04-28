#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int8_t Bool;

#define GF_AVC_NALU_IDR_SLICE 5
#define GF_AVC_TYPE_B 1
#define GF_AVC_TYPE_P 0
#define GF_AVC_TYPE_SP 2
#define GF_AVC_TYPE_I 3
#define GF_AVC_TYPE_SI 4
#define GF_LOG_ERROR 1
#define GF_LOG_CODING 2

typedef struct {
    int log2_max_frame_num;
    int poc_type;
    int log2_max_poc_lsb;
    int delta_pic_order_always_zero_flag;
    int frame_mbs_only_flag;
    int ChromaArrayType;
} AVCSPS;

typedef struct {
    int sps_id;
    int slice_group_count;
    int pic_order_present;
    int redundant_pic_cnt_present;
    int weighted_pred_flag;
    int weighted_bipred_idc;
    int entropy_coding_mode_flag;
    int deblocking_filter_control_present_flag;
    int mb_slice_group_map_type;
    int pic_size_in_map_units_minus1;
    int slice_group_change_rate_minus1;
    int num_ref_idx_l0_default_active_minus1;
    int num_ref_idx_l1_default_active_minus1;
} AVCPPS;

typedef struct {
    int slice_type;
    AVCSPS *sps;
    AVCPPS *pps;
    int frame_num;
    int field_pic_flag;
    int bottom_field_flag;
    int nal_unit_type;
    int idr_pic_id;
    int poc_lsb;
    int delta_poc_bottom;
    int delta_poc[2];
    int redundant_pic_cnt;
    int nal_ref_idc;
} AVCSliceInfo;

typedef struct {
    AVCSPS sps[32];
    AVCPPS pps[256];
    int sps_active_idx;
    int pps_active_idx;
} AVCState;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_se_log(GF_BitStream *bs, const char *name);
int gf_bs_read_se(GF_BitStream *bs);
void ref_pic_list_modification(GF_BitStream *bs, int slice_type);
void pred_weight_table(GF_BitStream *bs, int slice_type, int ChromaArrayType, int num_ref_idx_l0_active_minus1, int num_ref_idx_l1_active_minus1);
void dec_ref_pic_marking(GF_BitStream *bs, int is_idr);
void GF_LOG(int level, int category, const char *format);
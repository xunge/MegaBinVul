#include <stdint.h>

typedef int32_t s32;

typedef struct {
    int log2_max_frame_num;
    int frame_mbs_only_flag;
    int poc_type;
    int log2_max_poc_lsb;
    int delta_pic_order_always_zero_flag;
} AVCSPS;

typedef struct {
    int id;
    int sps_id;
    int slice_group_count;
    int pic_order_present;
    int redundant_pic_cnt_present;
} AVCPPS;

typedef struct {
    int slice_type;
    AVCPPS *pps;
    AVCSPS *sps;
    int frame_num;
    int field_pic_flag;
    int bottom_field_flag;
    int nal_unit_type;
    int idr_pic_id;
    int poc_lsb;
    int delta_poc_bottom;
    int delta_poc[2];
    int redundant_pic_cnt;
    struct {
        int idr_pic_flag;
    } svc_nalhdr;
} AVCSliceInfo;

typedef struct {
    AVCPPS pps[256];
    AVCSPS sps[256];
} AVCState;

typedef struct GF_BitStream GF_BitStream;

int gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
int gf_bs_read_int_log(GF_BitStream *bs, int bits, const char *name);
int gf_bs_read_se_log(GF_BitStream *bs, const char *name);

#define GF_AVC_NALU_IDR_SLICE 5
#define GF_SVC_SSPS_ID_SHIFT 0
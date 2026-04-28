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
    int idr_pic_flag;
} AVC_NAL_HEADER;

typedef struct {
    int slice_type;
    AVCPPS *pps;
    AVCSPS *sps;
    int frame_num;
    int field_pic_flag;
    int bottom_field_flag;
    int nal_unit_type;
    AVC_NAL_HEADER NalHeader;
    int idr_pic_id;
    int poc_lsb;
    int delta_poc_bottom;
    int delta_poc[2];
    int redundant_pic_cnt;
} AVCSliceInfo;

typedef struct {
    AVCPPS pps[256];
    AVCSPS sps[256];
} AVCState;

typedef struct {
    int (*read_ue_log)(void*, const char*);
    int (*read_int_log)(void*, int, const char*);
    int (*read_se_log)(void*, const char*);
} GF_BitStream;

#define GF_AVC_NALU_IDR_SLICE 5
#define GF_SVC_SSPS_ID_SHIFT 0
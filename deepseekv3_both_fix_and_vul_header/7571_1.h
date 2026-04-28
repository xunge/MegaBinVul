#include <stdint.h>
#include <assert.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int64_t s64;
typedef uint64_t u64;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_SVC_SSPS_ID_SHIFT 0
#define GF_ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 1
#define GF_LOG_INFO 2
#define GF_LOG_CODING 0
#define AVC_SPS_PARSED 1
#define AVC_SUBSPS_PARSED 2

typedef struct {
    int left, right, top, bottom;
} GF_Rect;

typedef struct {
    u32 w;
    u32 h;
} GF_Fraction;

typedef struct {
    u32 aspect_ratio_info_present_flag;
    u32 aspect_ratio_idc;
    u32 par_num;
    u32 par_den;
    u32 overscan_info_present_flag;
    u32 overscan_appropriate_flag;
    u32 video_signal_type_present_flag;
    u32 video_format;
    u32 video_full_range_flag;
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 transfer_characteristics;
    u32 matrix_coefficients;
    u32 timing_info_present_flag;
    u32 num_units_in_tick;
    u32 time_scale;
    u32 fixed_frame_rate_flag;
    u32 nal_hrd_parameters_present_flag;
    u32 vcl_hrd_parameters_present_flag;
    u32 low_delay_hrd_flag;
    u32 pic_struct_present_flag;
    void* hrd;
} GF_VUIInfo;

typedef struct {
    u32 profile_idc;
    u32 level_idc;
    u32 prof_compat;
    u32 log2_max_frame_num;
    u32 poc_type;
    u32 log2_max_poc_lsb;
    u32 delta_pic_order_always_zero_flag;
    s32 offset_for_non_ref_pic;
    s32 offset_for_top_to_bottom_field;
    u32 poc_cycle_length;
    s32 offset_for_ref_frame[256];
    u32 max_num_ref_frames;
    u32 gaps_in_frame_num_value_allowed_flag;
    u32 frame_mbs_only_flag;
    u32 mb_adaptive_frame_field_flag;
    u32 width;
    u32 height;
    u32 ChromaArrayType;
    u32 chroma_format;
    u32 luma_bit_depth_m8;
    u32 chroma_bit_depth_m8;
    GF_Rect crop;
    u32 vui_parameters_present_flag;
    GF_VUIInfo vui;
    u32 state;
} AVC_SPS;

typedef struct {
    AVC_SPS sps[32];
} AVCState;

typedef struct GF_BitStream GF_BitStream;

static GF_Fraction avc_hevc_sar[] = {
    {0, 0}, {1, 1}, {12, 11}, {10, 11}, {16, 11}, {40, 33}, {24, 11}, {20, 11}, {32, 11}, {80, 33}, {18, 11}, {15, 11}, {64, 33}, {160, 99}, {4, 3}, {3, 2}, {2, 1}
};

void gf_bs_enable_emulation_byte_removal(GF_BitStream *bs, u32 enable);
u32 gf_bs_read_int_log(GF_BitStream *bs, u32 nBits, const char *name);
u32 gf_bs_read_int_log_idx(GF_BitStream *bs, u32 nBits, const char *name, u32 idx);
s32 gf_bs_read_ue_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_se(GF_BitStream *bs);
s32 gf_bs_read_se_log(GF_BitStream *bs, const char *name);
s32 gf_bs_read_se_log_idx(GF_BitStream *bs, const char *name, u32 idx);
u32 gf_bs_get_bit_offset(GF_BitStream *bs);
void GF_LOG(u32 level, u32 sub, const char *fmt, ...);
s32 avc_parse_hrd_parameters(GF_BitStream *bs, void *hrd);
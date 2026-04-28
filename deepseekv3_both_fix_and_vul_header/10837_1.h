#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

#define GF_EXPORT
#define GF_SVC_SSPS_ID_SHIFT 0
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof(a[0]))
#define GF_BITSTREAM_READ 0
#define AVC_SPS_PARSED 1
#define AVC_SUBSPS_PARSED 2
#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_CODING 3

typedef struct {
    int w;
    int h;
} avc_sar_t;

static const avc_sar_t avc_sar[14];

typedef struct {
    u32 left;
    u32 right;
    u32 top;
    u32 bottom;
} GF_AVCCrop;

typedef struct {
    u32 aspect_ratio_info_present_flag;
    u32 par_num;
    u32 par_den;
    u32 overscan_info_present_flag;
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
} GF_AVCVUI;

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
    u32 chroma_format;
    u32 luma_bit_depth_m8;
    u32 chroma_bit_depth_m8;
    GF_AVCCrop crop;
    u32 vui_parameters_present_flag;
    GF_AVCVUI vui;
    u32 state;
} AVC_SPS;

typedef struct {
    AVC_SPS sps[32];
} AVCState;

typedef struct GF_BitStream GF_BitStream;

GF_BitStream* gf_bs_new(const char*, u32, u32);
void gf_bs_del(GF_BitStream*);
u32 gf_bs_get_bit_offset(GF_BitStream*);
u32 gf_bs_read_int(GF_BitStream*, u32);
s32 bs_get_ue(GF_BitStream*);
s32 bs_get_se(GF_BitStream*);
u32 avc_remove_emulation_bytes(const char*, char*, u32);
void avc_parse_hrd_parameters(GF_BitStream*, void*);
void* gf_malloc(size_t);
void gf_free(void*);
void GF_LOG(int level, int category, const char* fmt, ...);
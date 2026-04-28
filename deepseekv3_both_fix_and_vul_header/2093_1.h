#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SPS_COUNT 32
#define MAX_PICTURE_COUNT 36
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define FF_DEBUG_PICT_INFO 1
#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48

typedef struct GetBitContext {
    unsigned int index;
    const uint8_t *buffer;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int debug;
} AVCodecContext;

typedef struct MpegEncContext {
    GetBitContext gb;
    AVCodecContext *avctx;
} MpegEncContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct SPS {
    int profile_idc;
    int constraint_set_flags;
    int level_idc;
    int chroma_format_idc;
    int residual_color_transform_flag;
    int bit_depth_luma;
    int bit_depth_chroma;
    int transform_bypass;
    int log2_max_frame_num;
    int poc_type;
    int log2_max_poc_lsb;
    int delta_pic_order_always_zero_flag;
    int offset_for_non_ref_pic;
    int offset_for_top_to_bottom_field;
    int poc_cycle_length;
    int offset_for_ref_frame[256];
    int ref_frame_count;
    int gaps_in_frame_num_allowed_flag;
    int mb_width;
    int mb_height;
    int frame_mbs_only_flag;
    int mb_aff;
    int direct_8x8_inference_flag;
    int crop;
    int crop_left;
    int crop_right;
    int crop_top;
    int crop_bottom;
    int vui_parameters_present_flag;
    int timing_info_present_flag;
    int num_units_in_tick;
    int time_scale;
    int full_range;
    int scaling_matrix_present;
    int colorspace;
    int scaling_matrix4[16];
    int scaling_matrix8[64];
    int time_offset_length;
    AVRational sar;
} SPS;

typedef struct H264Context {
    MpegEncContext s;
    SPS *sps_buffers[MAX_SPS_COUNT];
    SPS sps;
} H264Context;

int get_bits(GetBitContext *s, int n);
int get_bits1(GetBitContext *s);
int get_ue_golomb(GetBitContext *gb);
int get_ue_golomb_31(GetBitContext *gb);
int get_se_golomb(GetBitContext *gb);
void *av_mallocz(size_t size);
void av_free(void *ptr);
void av_log(void *avctx, int level, const char *fmt, ...);
int decode_vui_parameters(H264Context *h, SPS *sps);
int decode_scaling_matrices(H264Context *h, SPS *sps, void *p, int b, int *matrix4, int *matrix8);
int av_image_check_size(unsigned int w, unsigned int h, int log_offset, void *log_ctx);
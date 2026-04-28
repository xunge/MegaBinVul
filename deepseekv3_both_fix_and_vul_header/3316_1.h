#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SPS_COUNT 32
#define MAX_PICTURE_COUNT 36
#define MIN_LOG2_MAX_FRAME_NUM 4
#define MAX_LOG2_MAX_FRAME_NUM 16
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48
#define FF_DEBUG_PICT_INFO 0x0001
#define AVERROR_INVALIDDATA (-1)

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    void *avctx;
    int debug;
} AVCodecContext;

typedef struct MpegEncContext {
    GetBitContext gb;
    AVCodecContext *avctx;
} MpegEncContext;

typedef struct SPS {
    int profile_idc;
    int constraint_set_flags;
    int level_idc;
    int chroma_format_idc;
    int residual_color_transform_flag;
    int bit_depth_luma;
    int bit_depth_chroma;
    int transform_bypass;
    int scaling_matrix4[6][16];
    int scaling_matrix8[6][64];
    int scaling_matrix_present;
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
    AVRational sar;
    int timing_info_present_flag;
    int num_units_in_tick;
    int time_scale;
    int new;
    int time_offset_length;
} SPS;

typedef struct H264Context {
    MpegEncContext s;
    SPS *sps_buffers[MAX_SPS_COUNT];
    SPS sps;
    int current_sps_id;
} H264Context;

static inline int get_bits(GetBitContext *s, int n) { return 0; }
static inline int get_bits1(GetBitContext *s) { return 0; }
static unsigned int get_ue_golomb_31(GetBitContext *gb) { return 0; }
static int get_ue_golomb(GetBitContext *gb) { return 0; }
static int get_se_golomb(GetBitContext *gb) { return 0; }
static void *av_mallocz(size_t size) { return calloc(1, size); }
static void av_free(void *ptr) { free(ptr); }
static int av_image_check_size(int w, int h, int log_offset, void *log_ctx) { return 0; }
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static int decode_vui_parameters(H264Context *h, SPS *sps) { return 0; }
static int decode_scaling_matrices(H264Context *h, SPS *sps, void *pSPS, int is_sps, int (*scaling_matrix4)[16], int (*scaling_matrix8)[64]) { return 0; }
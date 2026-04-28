#include <stdint.h>
#include <stdlib.h>

#define HAVE_THREADS 1
#define FF_THREAD_SLICE 1
#define H264_MAX_THREADS 16
#define FF_API_CAP_VDPAU 1
#define AV_CODEC_CAP_HWACCEL_VDPAU (1 << 0)
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AVERROR_INVALIDDATA (-1)

typedef struct AVCodec {
    int capabilities;
} AVCodec;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    int active_thread_type;
    int thread_count;
    int pix_fmt;
    AVRational framerate;
    int ticks_per_frame;
    AVCodec *codec;
    int bits_per_raw_sample;
    int codec_id;
} AVCodecContext;

typedef struct H264SPS {
    int sar;
    int timing_info_present_flag;
    int time_scale;
    int num_units_in_tick;
    int bit_depth_luma;
    int bit_depth_chroma;
    int chroma_format_idc;
} H264SPS;

typedef struct H264SliceContext {
    struct H264Context *h264;
    int *intra4x4_pred_mode;
    int *mvd_table[2];
} H264SliceContext;

typedef struct H264Context {
    AVCodecContext *avctx;
    H264SPS sps;
    int chroma_x_shift;
    int chroma_y_shift;
    unsigned int x264_build;
    int first_field;
    int prev_interlaced_frame;
    int mb_height;
    int mb_stride;
    int max_contexts;
    int slice_context_count;
    int context_initialized;
    int pixel_shift;
    int cur_bit_depth_luma;
    int cur_chroma_format_idc;
    int chroma_format_idc;
    int bit_depth_luma;
    int *intra4x4_pred_mode;
    int *mvd_table[2];
    H264SliceContext slice_ctx[H264_MAX_THREADS];
    struct {
        int (*init)(void);
    } h264dsp;
    struct {
        int (*init)(void);
    } h264chroma;
    struct {
        int (*init)(void);
    } h264qpel;
    struct {
        int (*init)(void);
    } hpc;
    struct {
        int (*init)(void);
    } vdsp;
} H264Context;

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

int ff_set_sar(AVCodecContext *avctx, int sar);
void av_pix_fmt_get_chroma_sub_sample(int pix_fmt, int *x_shift, int *y_shift);
int av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);
void ff_h264_free_tables(H264Context *h);
void init_scan_tables(H264Context *h);
int ff_h264_alloc_tables(H264Context *h);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int ff_h264_slice_context_init(H264Context *h, H264SliceContext *sl);
void ff_h264dsp_init(void *h264dsp, int bit_depth, int chroma_format_idc);
void ff_h264chroma_init(void *h264chroma, int bit_depth);
void ff_h264qpel_init(void *h264qpel, int bit_depth);
void ff_h264_pred_init(void *hpc, int codec_id, int bit_depth, int chroma_format_idc);
void ff_videodsp_init(void *vdsp, int bit_depth);
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef struct SliceInfo {
    int start;
    int end;
    int type;
    int width;
    int height;
    int pts;
} SliceInfo;

typedef struct AVFrame {
    uint8_t *data[8];
    int f;
} AVFrame;

typedef struct Picture {
    AVFrame f;
} Picture;

typedef struct MpegEncContext {
    int low_delay;
    Picture *next_picture_ptr;
    Picture *last_picture_ptr;
    Picture *current_picture_ptr;
    int width;
    int height;
    int mb_width;
    int mb_height;
    int mb_num_left;
    int mb_x;
    int mb_y;
    int pict_type;
    int linesize;
    int uvlinesize;
    struct AVCodecContext *avctx;
    void *gb;
    int active_thread_type;
} MpegEncContext;

typedef struct RV34DecContext {
    MpegEncContext s;
    SliceInfo si;
    int (*parse_slice_header)(struct RV34DecContext *r, void *gb, SliceInfo *si);
    int (*loop_filter)(struct RV34DecContext *r, int mb_y);
    void *tmp_b_block_base;
    void *tmp_b_block_y[2];
    void *tmp_b_block_uv[4];
    int cur_pts;
    int last_pts;
    int next_pts;
    int weight1;
    int weight2;
} RV34DecContext;

typedef struct AVCodecContext {
    void *priv_data;
    int slice_count;
    int skip_frame;
    int active_thread_type;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_INFO 32
#define AVDISCARD_NONREF 0
#define AVDISCARD_NONKEY 0
#define AVDISCARD_ALL 0
#define AV_PICTURE_TYPE_I 1
#define AV_PICTURE_TYPE_B 2
#define FF_THREAD_FRAME 1
#define HAVE_THREADS 1
#define GET_PTS_DIFF(a, b) ((a) - (b))

extern int get_slice_offset(AVCodecContext *avctx, const uint8_t *slices_hdr, int i);
extern int rv34_decode_slice(RV34DecContext *r, int end, const uint8_t *buf, int size);
extern int finish_frame(AVCodecContext *avctx, AVFrame *pict);
extern void ff_er_frame_end(MpegEncContext *s);
extern void ff_MPV_frame_end(MpegEncContext *s);
extern void ff_MPV_common_end(MpegEncContext *s);
extern int ff_MPV_common_init(MpegEncContext *s);
extern int ff_MPV_frame_start(MpegEncContext *s, AVCodecContext *avctx);
extern void ff_er_frame_start(MpegEncContext *s);
extern void ff_thread_finish_setup(AVCodecContext *avctx);
extern void ff_thread_report_progress(AVFrame *f, int max, int min);
extern void av_log_missing_feature(AVCodecContext *avctx, const char *feature, int sample);
extern void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
extern void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height);
extern void *av_malloc(size_t size);
extern void init_get_bits(void *gb, const uint8_t *buffer, int bit_size);
extern int rv34_decoder_realloc(RV34DecContext *r);
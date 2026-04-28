#include <stdatomic.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define av_always_inline inline
#define av_uninit(x) x
#define av_assert0(x) ((void)0)

enum AVPixelFormat {
    AV_PIX_FMT_YUVA420P,
    AV_PIX_FMT_YUV420P
};

enum AVColorSpace {
    AVCOL_SPC_BT470BG
};

enum AVColorRange {
    AVCOL_RANGE_JPEG,
    AVCOL_RANGE_MPEG
};

enum AVLogLevel {
    AV_LOG_WARNING
};

enum AVDiscard {
    AVDISCARD_NONREF,
    AVDISCARD_NONKEY,
    AVDISCARD_ALL
};

enum AVPictureType {
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P
};

#define VP56_FRAME_CURRENT 0
#define VP56_FRAME_PREVIOUS 1
#define VP56_FRAME_GOLDEN 2
#define VP56_FRAME_GOLDEN2 3
#define VP56_FRAME_NONE -1
#define DC_PRED 0
#define MARGIN 16
#define MAX_THREADS 16
#define FF_THREAD_FRAME 1
#define AVERROR_INVALIDDATA (-1)

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVCodecContext {
    void *priv_data;
    int pix_fmt;
    int skip_frame;
    int skip_loop_filter;
    int colorspace;
    int color_range;
    int thread_count;
    int active_thread_type;
    struct {
        void (*update_thread_context)(void);
    } *codec;
    int (*execute2)(void *, void *, void *, void *, int);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int key_frame;
    int pict_type;
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct VP8Frame {
    ThreadFrame tf;
} VP8Frame;

typedef struct VP8ThreadData {
    atomic_int thread_mb_pos;
    atomic_int wait_mb_pos;
} VP8ThreadData;

typedef struct VP8Context {
    VP8Frame *framep[4];
    VP8Frame *next_framep[4];
    VP8Frame frames[5];
    VP8ThreadData thread_data[MAX_THREADS];
    int invisible;
    int keyframe;
    int update_last;
    int update_golden;
    int update_altref;
    int colorspace;
    int fullrange;
    int mb_width;
    int mb_height;
    int mb_layout;
    int num_coeff_partitions;
    int num_jobs;
    int deblock_filter;
    int *top_nnz;
    void *macroblocks;
    int *intra4x4_pred_mode_top;
    int ref_count[4];
    struct {
        int level;
    } filter;
    struct {
        int enabled;
        int update_map;
    } segmentation;
    int prob[2];
    int update_probabilities;
    int linesize;
    int uvlinesize;
    VP8Frame *curframe;
    VP8Frame *prev_frame;
    struct {
        struct {
            int y;
        } mv_min, mv_max;
    } mv_bounds;
} VP8Context;

static void av_log(void *avctx, int level, const char *fmt, ...) {}
static int vp7_decode_frame_header(VP8Context *s, uint8_t *data, int size) { return 0; }
static int vp8_decode_frame_header(VP8Context *s, uint8_t *data, int size) { return 0; }
static void vp8_release_frame(VP8Context *s, VP8Frame *frame) {}
static VP8Frame *vp8_find_free_buffer(VP8Context *s) { return NULL; }
static int vp8_alloc_frame(VP8Context *s, VP8Frame *frame, int referenced) { return 0; }
static void ff_thread_finish_setup(AVCodecContext *avctx) {}
static void ff_thread_await_progress(ThreadFrame *tf, int n, int field) {}
static void vp7_decode_mv_mb_modes(AVCodecContext *avctx, VP8Frame *curframe, VP8Frame *prev_frame) {}
static void vp8_decode_mv_mb_modes(AVCodecContext *avctx, VP8Frame *curframe, VP8Frame *prev_frame) {}
static void vp7_decode_mb_row_sliced(AVCodecContext *avctx, void *arg1, void *arg2, void *arg3, int arg4) {}
static void vp8_decode_mb_row_sliced(AVCodecContext *avctx, void *arg1, void *arg2, void *arg3, int arg4) {}
static void ff_thread_report_progress(ThreadFrame *tf, int n, int field) {}
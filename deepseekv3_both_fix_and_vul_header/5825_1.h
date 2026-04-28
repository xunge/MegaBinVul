#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 4
#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AVERROR_BUG -3
#define AVERROR(ENOMEM) -4
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1
#define AV_CODEC_ID_AMV 0
#define AV_PIX_FMT_BGR24 0
#define AV_PIX_FMT_BGR48 0
#define AV_PIX_FMT_GBRP 0
#define AV_PIX_FMT_GBRP16 0
#define AV_PIX_FMT_YUV444P 0
#define AV_PIX_FMT_YUVJ444P 0
#define AV_PIX_FMT_YUV444P16 0
#define AV_PIX_FMT_ABGR 0
#define AV_PIX_FMT_RGBA64 0
#define AV_PIX_FMT_GBRAP 0
#define AV_PIX_FMT_YUVA444P 0
#define AV_PIX_FMT_YUVA444P16 0
#define AV_PIX_FMT_YUVA420P 0
#define AV_PIX_FMT_YUVA420P16 0
#define AV_PIX_FMT_GRAY8 0
#define AV_PIX_FMT_GRAY16 0
#define AV_PIX_FMT_YUV440P 0
#define AV_PIX_FMT_YUVJ440P 0
#define AV_PIX_FMT_YUV422P 0
#define AV_PIX_FMT_YUVJ422P 0
#define AV_PIX_FMT_YUV422P16 0
#define AV_PIX_FMT_YUV420P 0
#define AV_PIX_FMT_YUVJ420P 0
#define AV_PIX_FMT_YUV420P16 0
#define AV_PIX_FMT_YUV411P 0
#define AV_PIX_FMT_YUVJ411P 0
#define AV_PIX_FMT_RGB24 0
#define AV_PIX_FMT_PAL8 0
#define AVCOL_RANGE_MPEG 0
#define AVCOL_RANGE_JPEG 1
#define AV_PICTURE_TYPE_I 0
#define AV_GET_BUFFER_FLAG_REF 0

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct AVFrame {
    int width, height;
    int interlaced_frame;
    int top_field_first;
    int pict_type;
    int key_frame;
    int linesize[4];
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int dummy;
} AVPixFmtDescriptor;

typedef struct AVCodecContext {
    int width, height;
    int bits_per_raw_sample;
    int codec_id;
    int lowres;
    int pix_fmt;
    int color_range;
    int cs_itu601;
} AVCodecContext;

typedef struct MJpegDecodeContext {
    int cur_scan;
    int upscale_h, upscale_v;
    GetBitContext gb;
    AVCodecContext *avctx;
    int pegasus_rct;
    int rct;
    int lossless;
    int width, height;
    int bits;
    int h_count[MAX_COMPONENTS];
    int v_count[MAX_COMPONENTS];
    int interlaced;
    int got_picture;
    int first_picture;
    int org_height;
    int interlace_polarity;
    int bottom_field;
    AVFrame *picture_ptr;
    int progressive;
    int rgb;
    int nb_components;
    int component_id[MAX_COMPONENTS];
    int quant_index[MAX_COMPONENTS];
    int h_max, v_max;
    int ls;
    int adobe_transform;
    int palette_index;
    AVPixFmtDescriptor *pix_desc;
    int linesize[4];
    int block_stride[MAX_COMPONENTS];
    int16_t *blocks[MAX_COMPONENTS];
    int *last_nnz[MAX_COMPONENTS];
    uint8_t coefs_finished[MAX_COMPONENTS];
    int cs_itu601;
} MJpegDecodeContext;

static inline int get_bits(GetBitContext *s, int n) { return 0; }
static void av_log(void *avcl, int level, const char *fmt, ...) {}
static void avpriv_request_sample(void *avctx, const char *msg) {}
static void avpriv_report_missing_feature(void *avctx, const char *msg) {}
static int av_image_check_size(int w, int h, int log_offset, void *log_ctx) { return 0; }
static int ff_set_dimensions(void *avctx, int width, int height) { return 0; }
static void av_frame_unref(AVFrame *frame) {}
static int ff_get_buffer(void *avctx, AVFrame *frame, int flags) { return 0; }
static AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }
static void *av_mallocz_array(size_t nmemb, size_t size) { return NULL; }
static void av_freep(void *ptr) {}
static void av_assert0(int condition) {}
static void av_dlog(void *avcl, const char *fmt, ...) {}
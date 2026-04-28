#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMPONENTS 4

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int bits_per_raw_sample;
    int codec_id;
    int lowres;
    int pix_fmt;
    int color_range;
    int height;
} AVCodecContext;

typedef struct AVFrame {
    int interlaced_frame;
    int top_field_first;
    int pict_type;
    int key_frame;
    int linesize[4];
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int dummy;
} AVPixFmtDescriptor;

typedef struct MJpegDecodeContext {
    int cur_scan;
    int upscale_h;
    int upscale_v;
    GetBitContext gb;
    AVCodecContext *avctx;
    int bits;
    int pegasus_rct;
    int rct;
    int lossless;
    int width;
    int height;
    int interlaced;
    int bottom_field;
    int interlace_polarity;
    int nb_components;
    int ls;
    int component_id[MAX_COMPONENTS];
    int h_max;
    int v_max;
    int quant_index[MAX_COMPONENTS];
    int h_count[MAX_COMPONENTS];
    int v_count[MAX_COMPONENTS];
    int first_picture;
    int org_height;
    AVFrame *picture_ptr;
    int got_picture;
    int progressive;
    int rgb;
    int cs_itu601;
    int adobe_transform;
    int chroma_height;
    int palette_index;
    const AVPixFmtDescriptor *pix_desc;
    int block_stride[MAX_COMPONENTS];
    int16_t *blocks[MAX_COMPONENTS];
    int *last_nnz[MAX_COMPONENTS];
    uint8_t coefs_finished[MAX_COMPONENTS];
    int linesize[4];
} MJpegDecodeContext;

enum AVCodecID {
    AV_CODEC_ID_AMV,
};

enum AVPixelFormat {
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_BGR48,
    AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBRP16,
    AV_PIX_FMT_YUV444P,
    AV_PIX_FMT_YUVJ444P,
    AV_PIX_FMT_YUV444P16,
    AV_PIX_FMT_ABGR,
    AV_PIX_FMT_RGBA64,
    AV_PIX_FMT_GBRAP,
    AV_PIX_FMT_YUVA444P,
    AV_PIX_FMT_YUVA444P16,
    AV_PIX_FMT_YUVA420P,
    AV_PIX_FMT_YUVA420P16,
    AV_PIX_FMT_YUV440P,
    AV_PIX_FMT_YUVJ440P,
    AV_PIX_FMT_YUV422P,
    AV_PIX_FMT_YUVJ422P,
    AV_PIX_FMT_YUV422P16,
    AV_PIX_FMT_YUV420P,
    AV_PIX_FMT_YUVJ420P,
    AV_PIX_FMT_YUV420P16,
    AV_PIX_FMT_YUV411P,
    AV_PIX_FMT_YUVJ411P,
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_GRAY16,
    AV_PIX_FMT_RGB24,
    AV_PIX_FMT_PAL8,
};

enum AVColorRange {
    AVCOL_RANGE_MPEG,
    AVCOL_RANGE_JPEG,
};

enum AVPictureType {
    AV_PICTURE_TYPE_I,
};

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1

#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AVERROR_BUG -3
#define AVERROR(ENOMEM) -4

#define AV_GET_BUFFER_FLAG_REF 0

int get_bits(GetBitContext *s, int n);
void av_log(void *avcl, int level, const char *fmt, ...);
int av_image_check_size(int w, int h, int log_offset, void *log_ctx);
void avpriv_request_sample(void *avctx, const char *msg);
void avpriv_report_missing_feature(void *avctx, const char *msg);
int ff_set_dimensions(void *s, int width, int height);
const AVPixFmtDescriptor *av_pix_fmt_desc_get(enum AVPixelFormat pix_fmt);
void av_frame_unref(AVFrame *frame);
int ff_get_buffer(void *avctx, AVFrame *frame, int flags);
void *av_mallocz_array(size_t nmemb, size_t size);
void av_freep(void *ptr);
void av_assert0(int cond);
void av_dlog(void *avcl, const char *fmt, ...);
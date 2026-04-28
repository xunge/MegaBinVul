#include <stdint.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct MpegEncContext MpegEncContext;
typedef struct AVCodec AVCodec;

enum AVPixelFormat {
    AV_PIX_FMT_YUV420P,
    AV_PIX_FMT_GRAY8
};

enum AVCodecID {
    AV_CODEC_ID_MSS2
};

enum AVColorRange {
    AVCOL_RANGE_UNSPECIFIED,
    AVCOL_RANGE_MPEG
};

#define AV_CODEC_FLAG_GRAY (1 << 0)
#define CONFIG_GRAY 1

struct AVCodec {
    enum AVCodecID id;
    enum AVPixelFormat *pix_fmts;
};

struct AVCodecContext {
    struct AVCodec *codec;
    void *priv_data;
    int bits_per_raw_sample;
    enum AVPixelFormat pix_fmt;
    int flags;
    enum AVColorRange color_range;
};

struct MpegEncContext {
    int studio_profile;
};

extern enum AVPixelFormat ff_get_format(AVCodecContext *avctx, enum AVPixelFormat *pix_fmts);
#define av_assert1(cond) ((void)0)
#include <stdint.h>
#include <stdlib.h>

#define AV_RB16(x) ((((const uint8_t*)(x))[0] << 8) | ((const uint8_t*)(x))[1])
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define AV_INPUT_BUFFER_PADDING_SIZE 64

enum {
    BIT_PLANAR,
    BIT_LINE,
    CHUNKY
};

enum AVPixelFormat {
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_RGB24
};

enum AVPictureType {
    AV_PICTURE_TYPE_I
};

#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AVERROR(ENOMEM) -3

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    enum AVPixelFormat pix_fmt;
} AVCodecContext;

typedef struct AVFrame {
    enum AVPictureType pict_type;
} AVFrame;

typedef struct AVPacket {
    int size;
    const uint8_t *data;
} AVPacket;

typedef struct CDXLVideoContext {
    int format;
    int bpp;
    int palette_size;
    const uint8_t *palette;
    const uint8_t *video;
    int video_size;
    AVCodecContext *avctx;
    uint8_t *new_video;
    int new_video_size;
    int padded_bits;
} CDXLVideoContext;

static int ff_set_dimensions(AVCodecContext *avctx, int w, int h);
static int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags);
static void avpriv_request_sample(AVCodecContext *avctx, const char *msg, ...);
static void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size);
static void cdxl_decode_ham8(CDXLVideoContext *c, AVFrame *p);
static void cdxl_decode_ham6(CDXLVideoContext *c, AVFrame *p);
static void cdxl_decode_rgb(CDXLVideoContext *c, AVFrame *p);
static void cdxl_decode_raw(CDXLVideoContext *c, AVFrame *p);
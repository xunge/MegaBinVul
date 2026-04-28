#include <stdint.h>
#include <string.h>

#define AV_RB16(x) ((((const uint8_t*)(x))[0] << 8) | ((const uint8_t*)(x))[1])
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVCodecContext {
    void *priv_data;
    int height;
    int width;
    int bits_per_coded_sample;
    int pix_fmt;
    unsigned int codec_tag;
    int (*get_buffer)(struct AVCodecContext *c, void *frame);
    int (*reget_buffer)(struct AVCodecContext *c, void *frame);
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int dummy;
} AVPixFmtDescriptor;

typedef struct IffContext {
    AVFrame frame;
    int init;
    int bpp;
    int planesize;
    int ham;
    uint8_t *ham_buf;
    uint32_t *ham_palbuf;
} IffContext;

enum {
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_BGR32
};

enum {
    AV_LOG_ERROR
};

#define AVERROR_INVALIDDATA (-1)

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static void av_log_ask_for_sample(AVCodecContext *avctx, const char *msg) {}
static int extract_header(AVCodecContext *avctx, AVPacket *avpkt) { return 0; }
static int ff_cmap_read_palette(AVCodecContext *avctx, uint32_t *palette) { return 0; }
static void decodeplane8(uint8_t *dst, const uint8_t *src, int size, int plane) {}
static void decodeplane32(uint32_t *dst, const uint8_t *src, int size, int plane) {}
static void decode_ham_plane32(uint32_t *dst, const uint8_t *src, uint32_t *palette, int planesize) {}
static const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }
static int av_get_bits_per_pixel(const AVPixFmtDescriptor *desc) { return 0; }
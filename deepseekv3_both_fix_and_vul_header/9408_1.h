#include <stdint.h>
#include <string.h>

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int bits_per_coded_sample;
    int pix_fmt;
    unsigned int codec_tag;
    int (*reget_buffer)(struct AVCodecContext *, AVFrame *);
} AVCodecContext;

typedef struct AVPixFmtDescriptor {
    int dummy;
} AVPixFmtDescriptor;

typedef struct GetByteContext {
    const uint8_t *buffer;
    int buffer_end;
    int buffer_start;
} GetByteContext;

typedef struct IffContext {
    AVFrame frame;
    int init;
    int compression;
    int bpp;
    int planesize;
    int ham;
    uint32_t *ham_palbuf;
    uint8_t *ham_buf;
    uint32_t *mask_palbuf;
    uint32_t *mask_buf;
    uint8_t *planebuf;
    int tvdc;
} IffContext;

#define AV_LOG_ERROR 0
#define AV_PIX_FMT_PAL8 0
#define AV_PIX_FMT_GRAY8 0
#define AV_PIX_FMT_BGR32 0
#define AV_PIX_FMT_RGB32 0
#define AV_PIX_FMT_RGB444 0

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AV_RB16(x) 0
#define FFMIN(a,b) ((a) < (b) ? (a) : (b))

static int extract_header(AVCodecContext *avctx, AVPacket *avpkt) { return 0; }
static int cmap_read_palette(AVCodecContext *avctx, uint32_t *pal) { return 0; }
static void decodeplane8(uint8_t *dst, const uint8_t *src, int size, int plane) {}
static void decodeplane32(uint32_t *dst, const uint8_t *src, int size, int plane) {}
static void decode_ham_plane32(uint32_t *dst, const uint8_t *src, uint32_t *pal, int size) {}
static int unsupported(AVCodecContext *avctx) { return 0; }
static int decode_byterun(uint8_t *dst, int size, const uint8_t *src, const uint8_t *end) { return 0; }
static void lookup_pal_indicies(uint32_t *dst, uint32_t *src, uint32_t *pal, int size) {}
static void decode_deep_rle32(uint8_t *dst, const uint8_t *src, int size, int width, int height, int linesize) {}
static void decode_deep_tvdc32(uint8_t *dst, const uint8_t *src, int size, int width, int height, int linesize, int tvdc) {}
static void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size) {}
static void decode_rgb8(GetByteContext *gb, uint8_t *dst, int width, int height, int linesize) {}
static void decode_rgbn(GetByteContext *gb, uint8_t *dst, int width, int height, int linesize) {}
static int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame) { return 0; }
static int av_get_bits_per_pixel(const AVPixFmtDescriptor *desc) { return 0; }
static const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define SEEK_SET 0

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct AVCodecContext {
    void *priv_data;
    int err_recognition;
    int pix_fmt;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct GetByteContext {
    const uint8_t *buffer;
    int buffer_size;
} GetByteContext;

typedef struct TiffContext {
    GetByteContext gb;
    int le;
    int bppcount;
    int bpp;
    int photometric;
    int compr;
    int fill_order;
    unsigned stripsizesoff;
    unsigned strippos;
    int geotag_count;
    struct {
        int key;
        int type;
        char *val;
    } *geotags;
    int planar;
    int height;
    int rps;
    int subsampling[2];
    int predictor;
    int width;
    int strips;
    unsigned stripsize;
    unsigned stripoff;
    int sstype;
    int sot;
    AVCodecContext *avctx;
} TiffContext;

enum {
    TIFF_PHOTOMETRIC_NONE,
    TIFF_PHOTOMETRIC_WHITE_IS_ZERO,
    TIFF_PHOTOMETRIC_YCBCR,
    TIFF_RAW
};

#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AV_EF_EXPLODE (1<<9)

#define AV_PIX_FMT_RGB48LE 25
#define AV_PIX_FMT_RGBA64LE 26
#define AV_PIX_FMT_GRAY16LE 27
#define AV_PIX_FMT_YA16LE 28
#define AV_PIX_FMT_GBRP16LE 29
#define AV_PIX_FMT_GBRAP16LE 30
#define AV_PIX_FMT_RGB48BE 31
#define AV_PIX_FMT_RGBA64BE 32
#define AV_PIX_FMT_GRAY16BE 33
#define AV_PIX_FMT_YA16BE 34
#define AV_PIX_FMT_GBRP16BE 35
#define AV_PIX_FMT_GBRAP16BE 36
#define AV_PIX_FMT_PAL8 37

#define AV_WL16(p, v) do { \
    ((uint8_t*)(p))[0] = (v); \
    ((uint8_t*)(p))[1] = (v)>>8; \
} while(0)

#define AV_RL16(p) \
    (((uint8_t*)(p))[0] | ((uint8_t*)(p))[1]<<8)

#define AV_WB16(p, v) do { \
    ((uint8_t*)(p))[1] = (v); \
    ((uint8_t*)(p))[0] = (v)>>8; \
} while(0)

#define AV_RB16(p) \
    (((uint8_t*)(p))[1] | ((uint8_t*)(p))[0]<<8)

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

static void av_log(void *avctx, int level, const char *fmt, ...) {}

static void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size) {
    gb->buffer = buf;
    gb->buffer_size = buf_size;
}

static void bytestream2_seek(GetByteContext *gb, int offset, int whence) {}
static int bytestream2_get_bytes_left(GetByteContext *gb) { return 0; }

static int ff_tdecode_header(GetByteContext *gb, int *le, unsigned *off) { return 0; }
static int ff_tget_short(GetByteContext *gb, int le) { return 0; }
static unsigned ff_tget(GetByteContext *gb, int type, int le) { return 0; }

static void free_geotags(TiffContext *s) {}
static int tiff_decode_tag(TiffContext *s, AVFrame *p) { return 0; }
static const char *get_geokey_name(int key) { return NULL; }
static int get_geokey_type(int key) { return 0; }
static int av_dict_set(void **metadatap, const char *key, const char *val, int flags) { return 0; }
static void **avpriv_frame_get_metadatap(AVFrame *f) { return NULL; }
static int init_image(TiffContext *s, ThreadFrame *frame) { return 0; }
static int tiff_unpack_strip(TiffContext *s, AVFrame *p, uint8_t *dst, int stride, const uint8_t *src, int size, int lines, int rows) { return 0; }
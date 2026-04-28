#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>

#define SEEK_SET 0

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
    void *metadata;
    int color_trc;
} AVFrame;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct TiffContext {
    AVCodecContext *avctx;
    GetByteContext gb;
    int le;
    int tiff_type;
    int is_thumbnail;
    int bppcount;
    int bpp;
    int photometric;
    int compr;
    int fill_order;
    int white_level;
    int is_bayer;
    int is_tiled;
    int is_jpeg;
    int cur_page;
    int last_tag;
    uint16_t dng_lut[65536];
    int stripsizesoff;
    int strippos;
    int sub_ifd;
    int get_thumbnail;
    int get_subimage;
    int get_page;
    int planar;
    int black_level;
    int strips;
    int stripoff;
    int rps;
    int sot;
    int sstype;
    int stripsize;
    int width;
    int height;
    int predictor;
    int subsampling[2];
    int tile_byte_counts_offset;
    int tile_offsets_offset;
    int tile_width;
    int tile_length;
    int tile_count;
    int geotag_count;
    struct {
        int key;
        int type;
        char *val;
    } *geotags;
} TiffContext;

enum {
    TIFF_TYPE_TIFF,
    TIFF_TYPE_DNG,
    TIFF_TYPE_CINEMADNG
};

enum {
    TIFF_PHOTOMETRIC_NONE,
    TIFF_PHOTOMETRIC_WHITE_IS_ZERO,
    TIFF_PHOTOMETRIC_BLACK_IS_ZERO,
    TIFF_PHOTOMETRIC_RGB,
    TIFF_PHOTOMETRIC_PALETTE,
    TIFF_PHOTOMETRIC_MASK,
    TIFF_PHOTOMETRIC_SEPARATED,
    TIFF_PHOTOMETRIC_YCBCR,
    TIFF_PHOTOMETRIC_CFA,
    TIFF_PHOTOMETRIC_LINEAR_RAW
};

enum {
    TIFF_RAW,
    TIFF_PACKBITS,
    TIFF_LZW,
    TIFF_DEFLATE,
    TIFF_JPEG,
    TIFF_CCITT_RLE,
    TIFF_CCITT_T4,
    TIFF_CCITT_T6,
    TIFF_NEWJPEG,
    TIFF_SGI_LOG,
    TIFF_SGI_LOG24,
    TIFF_ADOBE_DEFLATE,
    TIFF_DEFLATE_ZLIB,
    TIFF_LZMA,
    TIFF_ZSTD,
    TIFF_WEBP,
    TIFF_JXL
};

enum {
    AV_PIX_FMT_RGBA,
    AV_PIX_FMT_RGB0,
    AV_PIX_FMT_RGBA64BE,
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_RGB48LE,
    AV_PIX_FMT_RGBA64LE,
    AV_PIX_FMT_GRAY16LE,
    AV_PIX_FMT_YA16LE,
    AV_PIX_FMT_GBRP16LE,
    AV_PIX_FMT_GBRAP16LE,
    AV_PIX_FMT_RGB48BE,
    AV_PIX_FMT_GRAY16BE,
    AV_PIX_FMT_YA16BE,
    AV_PIX_FMT_GBRP16BE,
    AV_PIX_FMT_GBRAP16BE
};

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR_EOF (-3)
#define AVERROR(ENOMEM) (-4)
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_INFO 32
#define AV_EF_EXPLODE (1 << 0)
#define AVCOL_TRC_LINEAR 1
#define AVCOL_TRC_GAMMA22 2

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

static inline uint16_t AV_RL16(const uint8_t *p) {
    return p[0] | (p[1] << 8);
}

static inline void AV_WL16(uint8_t *p, uint16_t v) {
    p[0] = v;
    p[1] = v >> 8;
}

static inline uint16_t AV_RB16(const uint8_t *p) {
    return (p[0] << 8) | p[1];
}

static inline void AV_WB16(uint8_t *p, uint16_t v) {
    p[0] = v >> 8;
    p[1] = v;
}

static void bytestream2_init(GetByteContext *g, const uint8_t *buf, int buf_size) {
    g->buffer = g->buffer_start = buf;
    g->buffer_end = buf + buf_size;
}

static void bytestream2_seek(GetByteContext *g, int offset, int whence) {
    if (whence == SEEK_SET)
        g->buffer = g->buffer_start + offset;
}

static int bytestream2_get_bytes_left(GetByteContext *g) {
    return g->buffer_end - g->buffer;
}

static int ff_tdecode_header(GetByteContext *gb, int *le, unsigned *off) {
    return 0;
}

static int ff_tget_short(GetByteContext *gb, int le) {
    return 0;
}

static unsigned ff_tget_long(GetByteContext *gb, int le) {
    return 0;
}

static unsigned ff_tget(GetByteContext *gb, int type, int le) {
    return 0;
}

static int tiff_decode_tag(TiffContext *s, AVFrame *frame) {
    return 0;
}

static void free_geotags(TiffContext *s) {
}

static const char *get_geokey_name(int key) {
    return NULL;
}

static int get_geokey_type(int key) {
    return 0;
}

static int init_image(TiffContext *s, ThreadFrame *frame) {
    return 0;
}

static int tiff_unpack_strip(TiffContext *s, AVFrame *p, uint8_t *dst, int stride, const uint8_t *src, int size, int lines, int last_line) {
    return 0;
}

static int dng_decode_tiles(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    return 0;
}

static void av_log(void *avcl, int level, const char *fmt, ...) {
}

static void avpriv_request_sample(void *avctx, const char *msg) {
}

static void avpriv_report_missing_feature(void *avctx, const char *msg) {
}

static int av_dict_set(void **pm, const char *key, const char *value, int flags) {
    return 0;
}

static void *av_malloc(size_t size) {
    return malloc(size);
}

static void av_freep(void *ptr) {
    free(*(void**)ptr);
    *(void**)ptr = NULL;
}
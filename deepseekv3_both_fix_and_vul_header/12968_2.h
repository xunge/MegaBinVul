#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

typedef struct AVCodecContext {
    int profile;
    int width;
    int height;
    int pix_fmt;
    int bits_per_raw_sample;
} AVCodecContext;

typedef struct Jpeg2000Tile {
    void *comp;
} Jpeg2000Tile;

typedef struct Jpeg2000DecoderContext {
    AVCodecContext *avctx;
    uint32_t width;
    uint32_t height;
    uint32_t image_offset_x;
    uint32_t image_offset_y;
    uint32_t tile_width;
    uint32_t tile_height;
    uint32_t tile_offset_x;
    uint32_t tile_offset_y;
    int ncomponents;
    int cbps[4];
    int precision;
    int sgnd[4];
    int cdx[4];
    int cdy[4];
    int numXtiles;
    int numYtiles;
    Jpeg2000Tile *tile;
    int reduction_factor;
    int colour_space;
    int pal8;
    struct {
        unsigned char *g;
    } g;
} Jpeg2000DecoderContext;

enum AVPixelFormat {
    AV_PIX_FMT_NONE,
    FF_PROFILE_JPEG2000_DCINEMA_2K,
    FF_PROFILE_JPEG2000_DCINEMA_4K
};

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(E) (-(E))
#define AV_LOG_ERROR 1

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))

static const enum AVPixelFormat xyz_pix_fmts[] = {AV_PIX_FMT_NONE};
static const enum AVPixelFormat rgb_pix_fmts[] = {AV_PIX_FMT_NONE};
static const enum AVPixelFormat gray_pix_fmts[] = {AV_PIX_FMT_NONE};
static const enum AVPixelFormat yuv_pix_fmts[] = {AV_PIX_FMT_NONE};
static const enum AVPixelFormat all_pix_fmts[] = {AV_PIX_FMT_NONE};

static int pix_fmt_match(enum AVPixelFormat fmt, int ncomponents, int precision, uint32_t log2_chroma_wh, int pal8) {
    return 0;
}

static int ff_jpeg2000_ceildiv(int a, int b) {
    return (a + b - 1) / b;
}

static int ff_jpeg2000_ceildivpow2(int a, int b) {
    return (a + (1 << b) - 1) >> b;
}

static void *av_mallocz_array(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static void *av_mallocz(size_t size) {
    return calloc(1, size);
}

static void avpriv_request_sample(AVCodecContext *avctx, const char *msg, ...) {}
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}

#define bytestream2_get_bytes_left(g) 0
#define bytestream2_get_be16u(g) 0
#define bytestream2_get_be32u(g) 0
#define bytestream2_get_byteu(g) 0
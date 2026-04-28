#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

typedef struct Jpeg2000DecoderContext Jpeg2000DecoderContext;
typedef struct Jpeg2000Tile Jpeg2000Tile;

enum AVPixelFormat {
    AV_PIX_FMT_NONE
};

struct AVCodecContext {
    int profile;
    int width;
    int height;
    enum AVPixelFormat pix_fmt;
};

#define FF_PROFILE_JPEG2000_DCINEMA_2K 0
#define FF_PROFILE_JPEG2000_DCINEMA_4K 1

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR_EINVAL (-EINVAL)
#define AVERROR_ENOMEM (-ENOMEM)

#define AV_LOG_ERROR 0

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))

struct Jpeg2000Tile {
    void *comp;
};

struct Jpeg2000DecoderContext {
    struct AVCodecContext *avctx;
    uint32_t width, height;
    uint32_t image_offset_x, image_offset_y;
    uint32_t tile_width, tile_height;
    uint32_t tile_offset_x, tile_offset_y;
    int ncomponents;
    uint8_t cbps[4];
    uint8_t sgnd[4];
    uint8_t cdx[4], cdy[4];
    int precision;
    int reduction_factor;
    int colour_space;
    int pal8;
    int numXtiles, numYtiles;
    Jpeg2000Tile *tile;
    struct {
        int profile;
        int width, height;
        enum AVPixelFormat pix_fmt;
    } g;
};

static int ff_jpeg2000_ceildiv(int a, int b) {
    return (a + b - 1) / b;
}

static int ff_jpeg2000_ceildivpow2(int a, int b) {
    return (a + (1 << b) - 1) >> b;
}

static int bytestream2_get_bytes_left(void *s) {
    return 0;
}

static uint16_t bytestream2_get_be16u(void *s) {
    return 0;
}

static uint32_t bytestream2_get_be32u(void *s) {
    return 0;
}

static uint8_t bytestream2_get_byteu(void *s) {
    return 0;
}

static void *av_mallocz_array(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static void *av_mallocz(size_t size) {
    return calloc(1, size);
}

static void av_log(void *avctx, int level, const char *fmt, ...) {
}

static void avpriv_request_sample(void *avctx, const char *fmt, ...) {
}

static const enum AVPixelFormat xyz_pix_fmts[] = { AV_PIX_FMT_NONE };
static const enum AVPixelFormat rgb_pix_fmts[] = { AV_PIX_FMT_NONE };
static const enum AVPixelFormat gray_pix_fmts[] = { AV_PIX_FMT_NONE };
static const enum AVPixelFormat yuv_pix_fmts[] = { AV_PIX_FMT_NONE };
static const enum AVPixelFormat all_pix_fmts[] = { AV_PIX_FMT_NONE };

static int pix_fmt_match(enum AVPixelFormat fmt, int ncomponents, int precision, uint32_t log2_chroma_wh, int pal8) {
    return 0;
}
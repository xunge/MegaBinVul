#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

typedef enum AVPixelFormat {
    AV_PIX_FMT_NONE
} AVPixelFormat;

typedef struct AVCodecContext {
    int profile;
    int width;
    int height;
    AVPixelFormat pix_fmt;
    int bits_per_raw_sample;
} AVCodecContext;

typedef struct Jpeg2000Tile {
    void *comp;
} Jpeg2000Tile;

typedef struct Jpeg2000DecoderContext {
    AVCodecContext *avctx;
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
    int numXtiles, numYtiles;
    Jpeg2000Tile *tile;
    int pal8;
    struct {
        int get_bytes_left;
        uint16_t (*get_be16u)(void*);
        uint32_t (*get_be32u)(void*);
        uint8_t (*get_byteu)(void*);
    } g;
} Jpeg2000DecoderContext;

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(e) (-e)
#define AV_LOG_ERROR 0
#define FF_ARRAY_ELEMS(x) (sizeof(x) / sizeof((x)[0]))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

enum {
    FF_PROFILE_JPEG2000_DCINEMA_2K,
    FF_PROFILE_JPEG2000_DCINEMA_4K
};

static const AVPixelFormat xyz_pix_fmts[] = {AV_PIX_FMT_NONE};
static const AVPixelFormat rgb_pix_fmts[] = {AV_PIX_FMT_NONE};
static const AVPixelFormat gray_pix_fmts[] = {AV_PIX_FMT_NONE};
static const AVPixelFormat yuv_pix_fmts[] = {AV_PIX_FMT_NONE};
static const AVPixelFormat all_pix_fmts[] = {AV_PIX_FMT_NONE};

static inline int bytestream2_get_bytes_left(void *g) { return 0; }
static inline uint16_t bytestream2_get_be16u(void *g) { return 0; }
static inline uint32_t bytestream2_get_be32u(void *g) { return 0; }
static inline uint8_t bytestream2_get_byteu(void *g) { return 0; }

static int ff_jpeg2000_ceildiv(int a, int b) { return (a + b - 1) / b; }
static int ff_jpeg2000_ceildivpow2(int a, int b) { return (a + (1<<b) - 1) >> b; }
static int pix_fmt_match(AVPixelFormat fmt, int n, int p, uint32_t w, int pal) { return 0; }

static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void avpriv_request_sample(void *avctx, const char *fmt, ...) {}
static void *av_mallocz_array(size_t nmemb, size_t size) { return calloc(nmemb, size); }
static void *av_mallocz(size_t size) { return calloc(1, size); }
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <errno.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    int index;
    int size;
} GetByteContext;

typedef struct TiffGeoTag {
    int key;
    int type;
    int count;
    union {
        char *val;
        int offset;
    };
} TiffGeoTag;

typedef struct AVFrame {
    void *data;
} AVFrame;

typedef struct AVCodecContext {
    int err_recognition;
} AVCodecContext;

typedef struct TiffContext {
    GetByteContext gb;
    int le;
    int width;
    int height;
    int bpp;
    int bppcount;
    int compr;
    int predictor;
    int fax_opts;
    int rps;
    int strippos;
    int stripoff;
    int strips;
    int sot;
    int stripsizesoff;
    int stripsize;
    int sstype;
    int photometric;
    int fill_order;
    uint32_t palette[256];
    int palette_is_set;
    int planar;
    int subsampling[2];
    AVCodecContext *avctx;
    int geotag_count;
    TiffGeoTag *geotags;
} TiffContext;

enum TiffTags {
    TIFF_WIDTH,
    TIFF_HEIGHT,
    TIFF_BPP,
    TIFF_SAMPLES_PER_PIXEL,
    TIFF_COMPR,
    TIFF_ROWSPERSTRIP,
    TIFF_STRIP_OFFS,
    TIFF_STRIP_SIZE,
    TIFF_XRES,
    TIFF_YRES,
    TIFF_TILE_BYTE_COUNTS,
    TIFF_TILE_LENGTH,
    TIFF_TILE_OFFSETS,
    TIFF_TILE_WIDTH,
    TIFF_PREDICTOR,
    TIFF_PHOTOMETRIC,
    TIFF_FILL_ORDER,
    TIFF_PAL,
    TIFF_PLANAR,
    TIFF_YCBCR_SUBSAMPLING,
    TIFF_T4OPTIONS,
    TIFF_T6OPTIONS,
    TIFF_MODEL_PIXEL_SCALE,
    TIFF_MODEL_TRANSFORMATION,
    TIFF_MODEL_TIEPOINT,
    TIFF_GEO_KEY_DIRECTORY,
    TIFF_GEO_DOUBLE_PARAMS,
    TIFF_GEO_ASCII_PARAMS,
    TIFF_ARTIST,
    TIFF_COPYRIGHT,
    TIFF_DATE,
    TIFF_DOCUMENT_NAME,
    TIFF_HOST_COMPUTER,
    TIFF_IMAGE_DESCRIPTION,
    TIFF_MAKE,
    TIFF_MODEL,
    TIFF_PAGE_NAME,
    TIFF_PAGE_NUMBER,
    TIFF_SOFTWARE_NAME
};

enum TiffCompr {
    TIFF_RAW,
    TIFF_PACKBITS,
    TIFF_LZW,
    TIFF_CCITT_RLE,
    TIFF_G3,
    TIFF_G4,
    TIFF_DEFLATE,
    TIFF_ADOBE_DEFLATE,
    TIFF_JPEG,
    TIFF_NEWJPEG,
    TIFF_LZMA
};

enum TiffPhotometric {
    TIFF_PHOTOMETRIC_WHITE_IS_ZERO,
    TIFF_PHOTOMETRIC_BLACK_IS_ZERO,
    TIFF_PHOTOMETRIC_RGB,
    TIFF_PHOTOMETRIC_PALETTE,
    TIFF_PHOTOMETRIC_YCBCR,
    TIFF_PHOTOMETRIC_ALPHA_MASK,
    TIFF_PHOTOMETRIC_SEPARATED,
    TIFF_PHOTOMETRIC_CIE_LAB,
    TIFF_PHOTOMETRIC_ICC_LAB,
    TIFF_PHOTOMETRIC_ITU_LAB,
    TIFF_PHOTOMETRIC_CFA,
    TIFF_PHOTOMETRIC_LOG_L,
    TIFF_PHOTOMETRIC_LOG_LUV,
    TIFF_PHOTOMETRIC_LINEAR_RAW
};

enum TiffType {
    TIFF_BYTE,
    TIFF_SHORT,
    TIFF_LONG,
    TIFF_RATIONAL,
    TIFF_STRING
};

#define SEEK_SET 0
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR_ENOSYS (-3)
#define AVERROR_ENOMEM (-4)
#define AV_EF_EXPLODE (1 << 0)
#define ENOSYS 38
#define ENOMEM 12

#define AVERROR(e) (-(e))

static const int type_sizes[] = {
    [TIFF_BYTE] = 1,
    [TIFF_SHORT] = 2,
    [TIFF_LONG] = 4,
    [TIFF_RATIONAL] = 8,
    [TIFF_STRING] = 1
};

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

static inline int bytestream2_tell(const GetByteContext *gb) {
    return gb->index;
}

static inline int bytestream2_get_bytes_left(const GetByteContext *gb) {
    return gb->size - gb->index;
}

static inline void bytestream2_skip(GetByteContext *gb, int size) {
    gb->index += size;
}

static inline void bytestream2_seek(GetByteContext *gb, int index, int whence) {
    if (whence == SEEK_SET)
        gb->index = index;
}

static inline void bytestream2_get_bufferu(GetByteContext *gb, uint8_t *dst, int size) {
    memcpy(dst, gb->buffer + gb->index, size);
    gb->index += size;
}

static int ff_tread_tag(GetByteContext *gb, int le, unsigned *tag, unsigned *type, unsigned *count, int *start) {
    return 0;
}

static unsigned ff_tget(GetByteContext *gb, int type, int le) {
    return 0;
}

static unsigned ff_tget_short(GetByteContext *gb, int le) {
    return 0;
}

static double ff_tget_double(GetByteContext *gb, int le) {
    return 0.0;
}

static void av_log(void *avctx, int level, const char *fmt, ...) {
}

static void avpriv_report_missing_feature(void *avctx, const char *feature, ...) {
}

static void set_sar(TiffContext *s, unsigned tag, unsigned value, unsigned value2) {
}

static int add_metadata(int count, int type, const char *name, const char *sep, TiffContext *s, AVFrame *frame) {
    return 0;
}

static char *get_geokey_val(int key, int val) {
    return NULL;
}

static char *doubles2str(double *dp, int count, const char *sep) {
    return NULL;
}

static void *av_malloc(size_t size) {
    return malloc(size);
}

static void *av_malloc_array(size_t nmemb, size_t size) {
    return malloc(nmemb * size);
}

static void *av_mallocz_array(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static void av_freep(void *ptr) {
    free(*(void**)ptr);
    *(void**)ptr = NULL;
}
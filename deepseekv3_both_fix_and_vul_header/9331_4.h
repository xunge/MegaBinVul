#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* TIFF Tag Constants */
#define TIFF_WIDTH 256
#define TIFF_HEIGHT 257
#define TIFF_BPP 258
#define TIFF_SAMPLES_PER_PIXEL 277
#define TIFF_COMPR 259
#define TIFF_ROWSPERSTRIP 278
#define TIFF_STRIP_OFFS 273
#define TIFF_STRIP_SIZE 279
#define TIFF_XRES 282
#define TIFF_YRES 283
#define TIFF_TILE_BYTE_COUNTS 325
#define TIFF_TILE_LENGTH 323
#define TIFF_TILE_OFFSETS 324
#define TIFF_TILE_WIDTH 322
#define TIFF_PREDICTOR 317
#define TIFF_PHOTOMETRIC 262
#define TIFF_FILL_ORDER 266
#define TIFF_PAL 320
#define TIFF_PLANAR 284
#define TIFF_YCBCR_SUBSAMPLING 530
#define TIFF_T4OPTIONS 292
#define TIFF_T6OPTIONS 293
#define TIFF_MODEL_PIXEL_SCALE 33550
#define TIFF_MODEL_TRANSFORMATION 34264
#define TIFF_MODEL_TIEPOINT 33922
#define TIFF_GEO_KEY_DIRECTORY 34735
#define TIFF_GEO_DOUBLE_PARAMS 34736
#define TIFF_GEO_ASCII_PARAMS 34737
#define TIFF_ARTIST 315
#define TIFF_COPYRIGHT 33432
#define TIFF_DATE 306
#define TIFF_DOCUMENT_NAME 269
#define TIFF_HOST_COMPUTER 316
#define TIFF_IMAGE_DESCRIPTION 270
#define TIFF_MAKE 271
#define TIFF_MODEL 272
#define TIFF_PAGE_NAME 285
#define TIFF_PAGE_NUMBER 297
#define TIFF_SOFTWARE_NAME 305

/* TIFF Type Constants */
#define TIFF_BYTE 1
#define TIFF_SHORT 3
#define TIFF_LONG 4
#define TIFF_RATIONAL 5
#define TIFF_STRING 2

/* TIFF Compression Constants */
#define TIFF_RAW 1
#define TIFF_PACKBITS 32773
#define TIFF_LZW 5
#define TIFF_CCITT_RLE 2
#define TIFF_G3 3
#define TIFF_G4 4
#define TIFF_DEFLATE 32946
#define TIFF_ADOBE_DEFLATE 8
#define TIFF_JPEG 6
#define TIFF_NEWJPEG 7
#define TIFF_LZMA 34925

/* TIFF Photometric Constants */
#define TIFF_PHOTOMETRIC_WHITE_IS_ZERO 0
#define TIFF_PHOTOMETRIC_BLACK_IS_ZERO 1
#define TIFF_PHOTOMETRIC_RGB 2
#define TIFF_PHOTOMETRIC_PALETTE 3
#define TIFF_PHOTOMETRIC_YCBCR 6
#define TIFF_PHOTOMETRIC_ALPHA_MASK 4
#define TIFF_PHOTOMETRIC_SEPARATED 5
#define TIFF_PHOTOMETRIC_CIE_LAB 8
#define TIFF_PHOTOMETRIC_ICC_LAB 9
#define TIFF_PHOTOMETRIC_ITU_LAB 10
#define TIFF_PHOTOMETRIC_CFA 32803
#define TIFF_PHOTOMETRIC_LOG_L 32844
#define TIFF_PHOTOMETRIC_LOG_LUV 32845
#define TIFF_PHOTOMETRIC_LINEAR_RAW 34892

/* Error Constants */
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_EF_EXPLODE (1 << 9)
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(ENOSYS) (-3)
#define ENOSYS 38
#define ENOMEM 12
#define SEEK_SET 0

/* Utility Macro */
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

/* Type Sizes */
static const int type_sizes[] = {
    [TIFF_BYTE] = 1,
    [TIFF_SHORT] = 2,
    [TIFF_LONG] = 4,
    [TIFF_RATIONAL] = 8,
    [TIFF_STRING] = 1,
    [TIFF_GEO_ASCII_PARAMS] = 1,
    [TIFF_GEO_DOUBLE_PARAMS] = 8
};

/* Structure Definitions */
typedef struct GetByteContext {
    const uint8_t *buffer;
    int index;
    int size;
} GetByteContext;

typedef struct TiffGeoTag {
    uint16_t key;
    uint16_t type;
    uint32_t count;
    union {
        char *val;
        uint32_t offset;
    };
} TiffGeoTag;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width;
    int height;
    int format;
} AVFrame;

typedef struct AVCodecContext {
    int err_recognition;
} AVCodecContext;

typedef struct TiffContext {
    GetByteContext gb;
    int le;
    unsigned width;
    unsigned height;
    unsigned bpp;
    unsigned bppcount;
    unsigned compr;
    unsigned predictor;
    unsigned fax_opts;
    unsigned photometric;
    unsigned fill_order;
    uint32_t *palette;
    int palette_is_set;
    int planar;
    unsigned subsampling[2];
    unsigned rps;
    unsigned strips;
    unsigned strippos;
    unsigned stripoff;
    unsigned stripsize;
    unsigned stripsizesoff;
    unsigned sot;
    unsigned sstype;
    unsigned geotag_count;
    TiffGeoTag *geotags;
    AVCodecContext *avctx;
} TiffContext;

/* Function Prototypes */
static int ff_tread_tag(GetByteContext *gb, int le, unsigned *tag, unsigned *type, 
                       unsigned *count, int *start);
static int bytestream2_tell(const GetByteContext *gb);
static unsigned ff_tget(GetByteContext *gb, int type, int le);
static void av_log(void *avctx, int level, const char *fmt, ...);
static int bytestream2_get_bytes_left(const GetByteContext *gb);
static void avpriv_report_missing_feature(void *avctx, const char *feature, ...);
static void set_sar(TiffContext *s, unsigned tag, unsigned value, unsigned value2);
static void bytestream2_skip(GetByteContext *gb, int size);
static int add_metadata(unsigned count, unsigned type, const char *name, 
                       const char *sep, TiffContext *s, AVFrame *frame);
static unsigned ff_tget_short(GetByteContext *gb, int le);
static void *av_mallocz_array(size_t nmemb, size_t size);
static char *get_geokey_val(uint16_t key, uint16_t val);
static void *av_malloc_array(size_t nmemb, size_t size);
static double ff_tget_double(GetByteContext *gb, int le);
static char *doubles2str(const double *dp, int count, const char *sep);
static void av_freep(void *ptr);
static void bytestream2_seek(GetByteContext *gb, int index, int whence);
static void *av_malloc(size_t size);
static void bytestream2_get_bufferu(GetByteContext *gb, void *dst, int size);
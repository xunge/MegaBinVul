#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct AVCodecContext {
    int width;
    void *priv_data;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct GetByteContext {
    uint8_t *buffer;
} GetByteContext;

typedef struct EXRThreadData {
    uint8_t *tmp;
    unsigned int tmp_size;
    uint8_t *uncompressed_data;
    unsigned int uncompressed_size;
    int ysize;
    int xsize;
    int channel_line_size;
} EXRThreadData;

typedef struct EXRContext {
    AVFrame *picture;
    EXRThreadData *thread_data;
    uint8_t *buf;
    int buf_size;
    GetByteContext gb;
    int is_tile;
    int xmax;
    int xmin;
    int ymin;
    int ymax;
    int ydelta;
    int xdelta;
    int scan_lines_per_block;
    int compression;
    int pixel_type;
    float gamma;
    int apply_trc_type;
    int *channel_offsets;
    uint16_t *gamma_table;
    int current_channel_offset;
    struct {
        int ySize;
        int xSize;
    } tile_attr;
    AVCodecContext *avctx;
    struct {
        int nb_components;
    } *desc;
} EXRContext;

typedef float (*avpriv_trc_function)(float);

union av_intfloat32 {
    uint32_t i;
    float f;
};

enum {
    EXR_RAW,
    EXR_ZIP1,
    EXR_ZIP16,
    EXR_PIZ,
    EXR_PXR24,
    EXR_RLE,
    EXR_B44,
    EXR_B44A,
    EXR_FLOAT
};

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(ENOMEM) (-3)
#define AV_LOG_ERROR 0
#define AV_RL16(p) (*(const uint16_t*)(p))
#define AV_RL32(p) (*(const uint32_t*)(p))
#define AV_RL64(p) (*(const uint64_t*)(p))
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

static uint16_t exr_flt2uint(uint32_t i) { return 0; }
static uint16_t exr_halflt2uint(uint16_t h) { return 0; }
static avpriv_trc_function avpriv_get_trc_function_from_trc(int trc_type) { return NULL; }
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static void avpriv_report_missing_feature(AVCodecContext *avctx, const char *feature) {}
static void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size) {}

static int zip_uncompress(const uint8_t *src, uint32_t data_size, uint64_t uncompressed_size, EXRThreadData *td) { return 0; }
static int piz_uncompress(EXRContext *s, const uint8_t *src, uint32_t data_size, uint64_t uncompressed_size, EXRThreadData *td) { return 0; }
static int pxr24_uncompress(EXRContext *s, const uint8_t *src, uint32_t data_size, uint64_t uncompressed_size, EXRThreadData *td) { return 0; }
static int rle_uncompress(const uint8_t *src, uint32_t data_size, uint64_t uncompressed_size, EXRThreadData *td) { return 0; }
static int b44_uncompress(EXRContext *s, const uint8_t *src, uint32_t data_size, uint64_t uncompressed_size, EXRThreadData *td) { return 0; }

static inline uint16_t bytestream_get_le16(const uint8_t **p) {
    uint16_t v = AV_RL16(*p);
    *p += 2;
    return v;
}

static inline uint32_t bytestream_get_le32(const uint8_t **p) {
    uint32_t v = AV_RL32(*p);
    *p += 4;
    return v;
}
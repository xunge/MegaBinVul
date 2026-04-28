#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define AV_CODEC_ID_PNG 0
#define AV_CODEC_ID_APNG 0
#define FF_DEBUG_STARTCODE 0
#define FF_COMPLIANCE_NORMAL 0
#define AVDISCARD_ALL 0
#define AV_PKT_FLAG_KEY 0
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AV_LOG_WARNING 0
#define AV_STEREO3D_SIDEBYSIDE 0
#define AV_STEREO3D_FLAG_INVERT 0
#define PNG_COLOR_TYPE_PALETTE 0
#define PNG_IDAT 0
#define PNG_ALLIMAGE 0
#define CONFIG_APNG_DECODER 0
#define CONFIG_PNG_DECODER 0
#define AVERROR_INVALIDDATA 0
#define INT_MAX 0x7FFFFFFF

typedef struct AVCodecContext {
    int codec_id;
    int skip_frame;
    int strict_std_compliance;
    int debug;
    int codec_tag;
} AVCodecContext;

typedef struct AVPacket {
    int flags;
} AVPacket;

typedef struct AVFrame {
    int width;
    int height;
    int format;
    uint8_t *data[8];
} AVFrame;

typedef struct AVDictionary AVDictionary;

typedef struct AVStereo3D {
    int type;
    int flags;
} AVStereo3D;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct PNGDecContext {
    GetByteContext gb;
    int state;
    int bits_per_pixel;
    int has_trns;
    int bit_depth;
    int bpp;
    int height;
    int width;
    int color_type;
    uint8_t *image_buf;
    int image_linesize;
    uint8_t *transparent_color_be;
    struct {
        AVFrame *f;
    } last_picture;
    struct {
        AVFrame *f;
    } picture;
    struct {
        AVFrame *f;
    } previous_picture;
} PNGDecContext;

static inline uint32_t bytestream2_get_bytes_left(GetByteContext *gb) {
    return gb->buffer_end - gb->buffer;
}

static inline uint32_t bytestream2_get_be32(GetByteContext *gb) {
    uint32_t val = ((uint32_t)gb->buffer[0] << 24) |
                   ((uint32_t)gb->buffer[1] << 16) |
                   ((uint32_t)gb->buffer[2] << 8) |
                   gb->buffer[3];
    gb->buffer += 4;
    return val;
}

static inline uint32_t bytestream2_get_le32(GetByteContext *gb) {
    uint32_t val = gb->buffer[0] |
                   ((uint32_t)gb->buffer[1] << 8) |
                   ((uint32_t)gb->buffer[2] << 16) |
                   ((uint32_t)gb->buffer[3] << 24);
    gb->buffer += 4;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, int size) {
    gb->buffer += size;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline uint32_t AV_RL32(const uint8_t *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}

static void av_log(void *avcl, int level, const char *fmt, ...) {}

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
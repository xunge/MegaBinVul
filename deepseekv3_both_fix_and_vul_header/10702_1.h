#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AV_PIX_FMT_NONE 0
#define AV_PIX_FMT_MONOWHITE 1
#define AV_PIX_FMT_GRAY8 2
#define AV_PIX_FMT_PAL8 3
#define AV_PIX_FMT_RGB555BE 4
#define AV_PIX_FMT_RGB555LE 5
#define AV_PIX_FMT_BGR555BE 6
#define AV_PIX_FMT_BGR555LE 7
#define AV_PIX_FMT_RGB565BE 8
#define AV_PIX_FMT_RGB565LE 9
#define AV_PIX_FMT_BGR565BE 10
#define AV_PIX_FMT_BGR565LE 11
#define AV_PIX_FMT_RGB24 12
#define AV_PIX_FMT_BGR24 13
#define AV_PIX_FMT_ARGB 14
#define AV_PIX_FMT_BGRA 15
#define AV_PIX_FMT_ABGR 16
#define AV_PIX_FMT_RGBA 17
#define AV_PICTURE_TYPE_I 1
#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define XWD_HEADER_SIZE 100
#define XWD_VERSION 7
#define XWD_Z_PIXMAP 2
#define XWD_STATIC_GRAY 0
#define XWD_GRAY_SCALE 1
#define XWD_STATIC_COLOR 2
#define XWD_PSEUDO_COLOR 3
#define XWD_TRUE_COLOR 4
#define XWD_DIRECT_COLOR 5
#define XWD_CMAP_SIZE 12

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    void *priv_data;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int key_frame;
    int pict_type;
} AVFrame;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

static inline void bytestream2_init(GetByteContext *g, const uint8_t *buf, int buf_size) {}
static inline uint32_t bytestream2_get_be32u(GetByteContext *g) { return 0; }
static inline void bytestream2_skipu(GetByteContext *g, int size) {}
static inline uint8_t bytestream2_get_byteu(GetByteContext *g) { return 0; }
static inline void bytestream2_get_bufferu(GetByteContext *g, uint8_t *dst, int size) {}
static inline int bytestream2_get_bytes_left(GetByteContext *g) { return 0; }

static inline int av_image_check_size(int width, int height, int log_offset, void *log_ctx) { return 0; }
static inline int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags) { return 0; }
static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static inline void avpriv_request_sample(AVCodecContext *avctx, const char *msg, ...) {}
static inline void avpriv_report_missing_feature(AVCodecContext *avctx, const char *msg, ...) {}

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
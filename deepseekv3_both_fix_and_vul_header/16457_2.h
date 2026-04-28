#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define SEEK_SET 0

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int pix_fmt;
    int color_trc;
    int (*execute2)(struct AVCodecContext *c, int (*func)(struct AVCodecContext *c2, void *arg, int jobnr, int threadnr), void *arg2, void *arg3, int ret);
} AVCodecContext;

typedef struct ThreadFrame {
    void *f;
} ThreadFrame;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int pict_type;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct PutByteContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
    uint8_t *buffer_start;
} PutByteContext;

typedef struct EXRContext {
    struct AVCodecContext *avctx;
    void *priv_data;
    void *gb;
    int pixel_type;
    int channel_offsets[4];
    int is_luma;
    int compression;
    int scan_lines_per_block;
    int xmin, xmax, ymin, ymax;
    unsigned xdelta, ydelta;
    int w, h;
    int is_tile;
    struct {
        int xSize, ySize;
    } tile_attr;
    struct AVPixFmtDescriptor *desc;
    uint8_t *buf;
    int buf_size;
    AVFrame *picture;
    void *thread_data;
    int apply_trc_type;
} EXRContext;

typedef struct AVPixFmtDescriptor {
    int flags;
    int nb_components;
} AVPixFmtDescriptor;

enum {
    AVCOL_TRC_UNSPECIFIED,
    AV_PICTURE_TYPE_I,
    AV_PIX_FMT_GBRAPF32,
    AV_PIX_FMT_GBRPF32,
    AV_PIX_FMT_GRAYF32,
    AV_PIX_FMT_RGBA64,
    AV_PIX_FMT_YA16,
    AV_PIX_FMT_RGB48,
    AV_PIX_FMT_GRAY16,
    EXR_FLOAT,
    EXR_HALF,
    EXR_UINT,
    EXR_RAW,
    EXR_RLE,
    EXR_ZIP1,
    EXR_PXR24,
    EXR_ZIP16,
    EXR_PIZ,
    EXR_B44,
    EXR_B44A,
    AV_LOG_ERROR,
    AV_LOG_DEBUG,
    AVERROR_INVALIDDATA = -1,
    AVERROR_PATCHWELCOME = -2
};

#define AV_PIX_FMT_FLAG_FLOAT (1 << 0)

static inline void bytestream2_init(void *s, const uint8_t *buf, int buf_size) {}
static inline uint64_t bytestream2_peek_le64(void *s) { return 0; }
static inline uint64_t bytestream2_tell(void *s) { return 0; }
static inline void bytestream2_init_writer(void *s, uint8_t *buf, int buf_size) {}
static inline void bytestream2_put_le64(void *s, uint64_t val) {}
static inline void bytestream2_seek(void *s, int pos, int whence) {}
static inline uint32_t bytestream2_get_le32(void *s) { return 0; }
static inline int bytestream2_get_bytes_left(void *s) { return 0; }

static inline int decode_header(EXRContext *s, AVFrame *picture) { return 0; }
static inline int decode_block(AVCodecContext *c, void *arg, int jobnr, int threadnr) { return 0; }
static inline int ff_set_dimensions(AVCodecContext *avctx, int w, int h) { return 0; }
static inline const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }
static inline int ff_thread_get_buffer(AVCodecContext *avctx, ThreadFrame *f, int flags) { return 0; }
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}
static inline void avpriv_report_missing_feature(void *avctx, const char *fmt, ...) {}
static inline int FFMIN(int a, int b) { return a < b ? a : b; }
static inline int FFMAX(int a, int b) { return a > b ? a : b; }
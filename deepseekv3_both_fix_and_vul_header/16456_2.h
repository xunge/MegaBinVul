#include <stdint.h>
#include <string.h>

#define AV_PIX_FMT_GBRAPF32 0
#define AV_PIX_FMT_GBRPF32 1
#define AV_PIX_FMT_GRAYF32 2
#define AV_PIX_FMT_RGBA64 3
#define AV_PIX_FMT_YA16 4
#define AV_PIX_FMT_RGB48 5
#define AV_PIX_FMT_GRAY16 6

#define EXR_FLOAT 0
#define EXR_HALF 1
#define EXR_UINT 2

#define EXR_RAW 0
#define EXR_RLE 1
#define EXR_ZIP1 2
#define EXR_PXR24 3
#define EXR_ZIP16 4
#define EXR_PIZ 5
#define EXR_B44 6
#define EXR_B44A 7

#define AVCOL_TRC_UNSPECIFIED 0
#define AV_PICTURE_TYPE_I 0
#define AV_PIX_FMT_FLAG_FLOAT (1 << 0)
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1
#define SEEK_SET 0

typedef struct PutByteContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
    uint8_t *buffer_start;
} PutByteContext;

typedef struct AVPixFmtDescriptor {
    int flags;
    int nb_components;
} AVPixFmtDescriptor;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int pict_type;
} AVFrame;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int pix_fmt;
    int color_trc;
    void (*execute2)(struct AVCodecContext *, int (*)(struct AVCodecContext *, void *, void *, int, int), void *, void *, int);
} AVCodecContext;

typedef struct EXRContext {
    PutByteContext gb;
    int pixel_type;
    int channel_offsets[4];
    int is_luma;
    int apply_trc_type;
    int compression;
    int scan_lines_per_block;
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    uint32_t ydelta;
    uint32_t xdelta;
    int w;
    int h;
    int is_tile;
    struct {
        int xSize;
        int ySize;
    } tile_attr;
    const struct AVPixFmtDescriptor *desc;
    uint8_t *buf;
    int buf_size;
    AVFrame *picture;
    void *thread_data;
    AVCodecContext *avctx;
} EXRContext;

static inline void bytestream2_init(PutByteContext *pbc, const uint8_t *buf, int buf_size) {}
static inline void bytestream2_init_writer(PutByteContext *pbc, uint8_t *buf, int buf_size) {}
static inline uint64_t bytestream2_peek_le64(PutByteContext *pbc) { return 0; }
static inline uint64_t bytestream2_tell(PutByteContext *pbc) { return 0; }
static inline void bytestream2_seek(PutByteContext *pbc, int offset, int whence) {}
static inline uint32_t bytestream2_get_le32(PutByteContext *pbc) { return 0; }
static inline void bytestream2_put_le64(PutByteContext *pbc, uint64_t value) {}
static inline int bytestream2_get_bytes_left(PutByteContext *pbc) { return 0; }

static int decode_header(EXRContext *s, AVFrame *picture) { return 0; }
static int decode_block(AVCodecContext *avctx, void *arg1, void *arg2, int arg3, int arg4) { return 0; }
static int ff_set_dimensions(AVCodecContext *avctx, int width, int height) { return 0; }
static int ff_thread_get_buffer(AVCodecContext *avctx, ThreadFrame *f, int flags) { return 0; }
static const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }
static void av_log(void *avcl, int level, const char *fmt, ...) {}
static void avpriv_report_missing_feature(void *avctx, const char *feature, int sample) {}

#define FFMIN(a,b) ((a) < (b) ? (a) : (b))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
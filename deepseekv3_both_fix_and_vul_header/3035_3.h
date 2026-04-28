#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct AVPacket AVPacket;
typedef struct AVFrame AVFrame;
typedef struct GifState GifState;
typedef struct bytestream2 bytestream2;

#define AV_PICTURE_TYPE_I 1
#define AV_PICTURE_TYPE_P 2
#define AV_LOG_ERROR 16
#define GCE_DISPOSAL_NONE 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVERROR_INVALIDDATA (-0x636572726F72)

static const uint8_t gif87a_sig[6] = "GIF87a";
static const uint8_t gif89a_sig[6] = "GIF89a";

struct AVFrame {
    uint8_t *data[8];
    int64_t pts;
    int64_t pkt_pts;
    int64_t pkt_dts;
    int pict_type;
    int key_frame;
};

struct AVPacket {
    uint8_t *data;
    int size;
    int64_t pts;
    int64_t dts;
    int64_t duration;
};

struct AVCodecContext {
    void *priv_data;
    void (*release_buffer)(AVCodecContext *, AVFrame *);
    int (*reget_buffer)(AVCodecContext *, AVFrame *);
};

struct bytestream2 {
    const uint8_t *buffer;
    int buffer_size;
    int index;
};

struct GifState {
    bytestream2 gb;
    AVFrame picture;
    int keyframe;
    int keyframe_ok;
    int gce_prev_disposal;
    int screen_width;
    int screen_height;
    uint8_t *idx_line;
    unsigned int idx_line_size;
};

static inline void bytestream2_init(bytestream2 *gb, const uint8_t *buf, int buf_size) {
    gb->buffer = buf;
    gb->buffer_size = buf_size;
    gb->index = 0;
}

static inline void av_frame_set_pkt_duration(AVFrame *frame, int64_t duration) {
}

static inline int av_image_check_size(int width, int height, int log_offset, void *avctx) {
    return 0;
}

static inline void avcodec_set_dimensions(void *avctx, int width, int height) {
}

static inline int ff_get_buffer(void *avctx, AVFrame *frame) {
    return 0;
}

static inline void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size) {
}

static inline void av_log(void *avctx, int level, const char *fmt, ...) {
}
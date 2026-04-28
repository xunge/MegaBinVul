#include <stdint.h>
#include <string.h>
#include <errno.h>

#define AV_LOG_ERROR 16
#define AVERROR(e) (-(e))

typedef struct AVCodecContext {
    void *priv_data;
    int (*get_buffer)(struct AVCodecContext *, void *);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
    int nb_samples;
} AVFrame;

typedef struct WSSndContext {
    AVFrame frame;
} WSSndContext;

static const int8_t ws_adpcm_4bit[16] = {0};

static inline uint16_t AV_RL16(const uint8_t *p) {
    return p[0] | (p[1] << 8);
}

static inline uint8_t av_clip_uint8(int a) {
    if (a&(~0xFF)) return (~a)>>31;
    else           return a;
}

static void av_log(void *avctx, int level, const char *fmt, ...) {}
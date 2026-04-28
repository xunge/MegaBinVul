#include <stdint.h>
#include <stdlib.h>

#define AV_CODEC_FLAG_GLOBAL_HEADER (1 << 22)
#define PIX_FMT_PAL8 0
#define av_cold

typedef struct AVCodecContext {
    int pix_fmt;
    void *priv_data;
} AVCodecContext;

typedef struct AVFrame {
    // AVFrame fields would go here
} AVFrame;

typedef struct AvsContext {
    AVFrame picture;
} AvsContext;

static inline void avcodec_get_frame_defaults(AVFrame *frame) {
    // Implementation would go here
}
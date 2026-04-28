#include <stdint.h>
#include <limits.h>

typedef struct AVFrame {
    // Minimal dummy definition
    int dummy;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int pix_fmt;
    int width;
    int height;
} AVCodecContext;

typedef struct WebPContext {
    int initialized;
    int has_alpha;
    int lossless;
    uint8_t *alpha_data;
    unsigned int alpha_data_size;
} WebPContext;

#define AV_PIX_FMT_YUVA420P 0
#define AV_PIX_FMT_YUV420P 1
#define AV_LOG_ERROR 0
#define AVERROR_PATCHWELCOME (-1)

void av_init_packet(AVPacket *pkt);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int ff_vp8_decode_init(AVCodecContext *avctx);
int ff_vp8_decode_frame(AVCodecContext *avctx, AVFrame *p, int *got_frame, AVPacket *pkt);
void update_canvas_size(AVCodecContext *avctx, int width, int height);
int vp8_lossy_decode_alpha(AVCodecContext *avctx, AVFrame *p, uint8_t *alpha_data, unsigned int alpha_data_size);
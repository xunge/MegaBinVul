#include <stdint.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct AVFrame AVFrame;

struct AVFrame {
    int width;
    int height;
};

#define AV_LOG_ERROR 0

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int get_buffer_internal(AVCodecContext *avctx, AVFrame *frame, int flags);
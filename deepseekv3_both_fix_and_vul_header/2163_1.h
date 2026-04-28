#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct Plane {
    int pitch;
    int width;
    int height;
    uint8_t *buffers[2];
    uint8_t *pixels[2];
} Plane;

typedef struct Indeo3DecodeContext {
    int width;
    int height;
    Plane planes[3];
} Indeo3DecodeContext;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define av_cold

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
void *av_malloc(size_t size);
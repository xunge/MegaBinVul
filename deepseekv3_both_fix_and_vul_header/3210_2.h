#include <stddef.h>
#include <stdint.h>

typedef struct AVFilterContext AVFilterContext;
typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;

struct AVFilterLink {
    AVFilterContext *dst;
};

struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width, height;
};

typedef struct PadContext PadContext;

struct PadContext {
    int w;
    int in_w;
    int h;
    int in_h;
    int x;
    int y;
    struct {
        int hsub[4];
        int vsub[4];
        int pixelstep[4];
    } draw;
};

AVFrame *ff_get_video_buffer(void *outputs, int width, int height);
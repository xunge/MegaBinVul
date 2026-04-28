#include <stdint.h>

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct FieldMatchContext {
    // 假设这里包含必要的字段
} FieldMatchContext;

static int get_width(const FieldMatchContext *fm, const AVFrame *f, int plane);
static int get_height(const FieldMatchContext *fm, const AVFrame *f, int plane);
void av_image_copy_plane(uint8_t *dst, int dst_linesize,
                         const uint8_t *src, int src_linesize,
                         int width, int height);
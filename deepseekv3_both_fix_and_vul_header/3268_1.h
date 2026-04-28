#include <string.h>
#include <stdint.h>

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

typedef struct Vp3DecodeContext {
    AVCodecContext *avctx;
    int width;
    int height;
    int fragment_width[2];
    int fragment_height[2];
    int qps[3];
    void *motion_val[2];
    void *qmat[3];
    void *bounding_values_array;
    int superblock_count;
    struct {
        uint8_t *data[4];
    } current_frame, golden_frame, keyframe;
    void *dsp;
} Vp3DecodeContext;

static int allocate_tables(AVCodecContext *dst);
static void update_frames(AVCodecContext *dst);
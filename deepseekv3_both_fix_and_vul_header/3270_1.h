#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef struct AVFrame {
    uint8_t *data[3];
    int ref_index[0][0];
} AVFrame;

typedef struct MpegEncContext {
    int mb_x;
    int mb_y;
    int mb_stride;
    int linesize;
    int uvlinesize;
    int chroma_x_shift;
    int chroma_y_shift;
    int codec_id;
    struct {
        AVFrame f;
    } current_picture;
    uint8_t *dest[3];
    int mv[0][0][0];
    void *block;
} MpegEncContext;

typedef struct H264Context {
    int mb_xy;
    int ref_count[0];
    uint8_t non_zero_count_cache[0];
    uint8_t ref_cache[0][0];
    int mv_cache[0][0];
} H264Context;

#define CONFIG_H264_DECODER 1
#define CODEC_ID_H264 0
#define FRAME_MBAFF 0
static const int scan8[16+2*8] = {0};

static int pack16to32(int a, int b);
static void fill_rectangle(void *p, int w, int h, int stride, int val, int size);
static void MPV_decode_mb(MpegEncContext *s, void *block);
static void ff_h264_hl_decode_mb(H264Context *h);
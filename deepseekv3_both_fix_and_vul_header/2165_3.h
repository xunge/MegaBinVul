#include <stdint.h>
#include <stdlib.h>

#define av_cold 

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct DCTELEM {
    int dummy;
} DCTELEM;

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

typedef struct Indeo3DecodeContext {
    AVCodecContext *avctx;
    int width;
    int height;
    AVFrame frame;
    DCTELEM dsp;
} Indeo3DecodeContext;

#define PIX_FMT_YUV410P 0

static void build_requant_tab(void) {}
static void avcodec_get_frame_defaults(AVFrame *frame) {}
static void ff_dsputil_init(DCTELEM *dsp, AVCodecContext *avctx) {}
static int allocate_frame_buffers(Indeo3DecodeContext *ctx, AVCodecContext *avctx, ...) { return 0; }
#include <stdint.h>
#include <inttypes.h>

typedef struct AVCodecContext {
    void *priv_data;
    int extradata_size;
    uint8_t *extradata;
    unsigned int codec_tag;
    int width;
    int height;
    int pix_fmt;
    int colorspace;
} AVCodecContext;

typedef struct BswapDSPContext {
    // dummy structure
} BswapDSPContext;

typedef struct UtvideoContext {
    AVCodecContext *avctx;
    BswapDSPContext bdsp;
    int frame_info_size;
    uint32_t flags;
    int slices;
    int compression;
    int interlaced;
    int slice_bits_size;
    int planes;
} UtvideoContext;

#define av_cold
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AV_PIX_FMT_RGB24 0
#define AV_PIX_FMT_RGBA 0
#define AV_PIX_FMT_YUV420P 0
#define AV_PIX_FMT_YUV422P 0
#define AVCOL_SPC_BT470BG 0
#define AVCOL_SPC_BT709 0

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AV_RB32(x) (*(uint32_t*)(x))
#define AV_RL32(x) (*(uint32_t*)(x))
#define PRIX32 "X"

static inline void ff_bswapdsp_init(BswapDSPContext *bdsp) {}
static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static inline void avpriv_request_sample(AVCodecContext *avctx, const char *fmt, ...) {}
static inline void av_pix_fmt_get_chroma_sub_sample(int fmt, int *h_shift, int *v_shift) {
    *h_shift = 1;
    *v_shift = 1;
}
#include <stdint.h>
#include <inttypes.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct UtvideoContext UtvideoContext;

struct AVCodecContext {
    void *priv_data;
    unsigned int codec_tag;
    int pix_fmt;
    int colorspace;
    int width;
    int height;
    int extradata_size;
    uint8_t *extradata;
};

struct UtvideoContext {
    AVCodecContext *avctx;
    void *utdsp;
    void *bdsp;
    void *llviddsp;
    int slice_bits_size;
    int planes;
    int pack;
    int compression;
    int slices;
    int frame_info_size;
    int flags;
    int interlaced;
    int pro;
};

#define av_cold
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AV_PIX_FMT_GBRP 0
#define AV_PIX_FMT_GBRAP 0
#define AV_PIX_FMT_YUV420P 0
#define AV_PIX_FMT_YUV422P 0
#define AV_PIX_FMT_YUV444P 0
#define AV_PIX_FMT_YUV422P10 0
#define AV_PIX_FMT_GBRP10 0
#define AV_PIX_FMT_GBRAP10 0
#define AVCOL_SPC_BT470BG 0
#define AVCOL_SPC_BT709 0
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AVERROR_INVALIDDATA 0
#define AVERROR_PATCHWELCOME 0
#define PRIX32 "X"

static inline uint32_t AV_RB32(const uint8_t *x) { return 0; }
static inline uint32_t AV_RL32(const uint8_t *x) { return 0; }
static inline void ff_utvideodsp_init(void *utdsp) {}
static inline void ff_bswapdsp_init(void *bdsp) {}
static inline void ff_llviddsp_init(void *llviddsp) {}
static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static inline void avpriv_request_sample(AVCodecContext *avctx, const char *msg) {}
static inline void av_pix_fmt_get_chroma_sub_sample(int fmt, int *h_shift, int *v_shift) {}
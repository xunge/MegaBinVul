#include <stdint.h>
#include <string.h>

#define CONTEXT_SIZE 32
#define MAX_SLICES 256
#define AVERROR_INVALIDDATA -1
#define AVERROR(ENOSYS) -1
#define AV_LOG_ERROR 0
#define AV_PIX_FMT_NONE 0
#define AV_PIX_FMT_GRAY8 0
#define AV_PIX_FMT_GRAY16 0
#define AV_PIX_FMT_YUV444P 0
#define AV_PIX_FMT_YUV440P 0
#define AV_PIX_FMT_YUV422P 0
#define AV_PIX_FMT_YUV420P 0
#define AV_PIX_FMT_YUV411P 0
#define AV_PIX_FMT_YUV410P 0
#define AV_PIX_FMT_YUVA444P 0
#define AV_PIX_FMT_YUVA422P 0
#define AV_PIX_FMT_YUVA420P 0
#define AV_PIX_FMT_YUV444P9 0
#define AV_PIX_FMT_YUV422P9 0
#define AV_PIX_FMT_YUV420P9 0
#define AV_PIX_FMT_YUVA444P9 0
#define AV_PIX_FMT_YUVA422P9 0
#define AV_PIX_FMT_YUVA420P9 0
#define AV_PIX_FMT_YUV444P10 0
#define AV_PIX_FMT_YUV422P10 0
#define AV_PIX_FMT_YUV420P10 0
#define AV_PIX_FMT_YUVA444P10 0
#define AV_PIX_FMT_YUVA422P10 0
#define AV_PIX_FMT_YUVA420P10 0
#define AV_PIX_FMT_YUV444P16 0
#define AV_PIX_FMT_YUV422P16 0
#define AV_PIX_FMT_YUV420P16 0
#define AV_PIX_FMT_YUVA444P16 0
#define AV_PIX_FMT_YUVA422P16 0
#define AV_PIX_FMT_YUVA420P16 0
#define AV_PIX_FMT_GBRP9 0
#define AV_PIX_FMT_GBRP10 0
#define AV_PIX_FMT_GBRP12 0
#define AV_PIX_FMT_GBRP14 0
#define AV_PIX_FMT_RGB32 0
#define AV_PIX_FMT_0RGB32 0

typedef struct RangeCoder {
    uint8_t *bytestream_start;
    uint8_t *bytestream_end;
    uint8_t *bytestream;
    int one_state[256];
} RangeCoder;

typedef struct PlaneContext {
    int quant_table_index;
    uint8_t quant_table[CONTEXT_SIZE];
    int context_count;
    uint8_t *state;
    uint8_t *vlc_state;
} PlaneContext;

typedef struct FFV1Context {
    int version;
    int ac;
    int state_transition[256];
    int plane_count;
    int colorspace;
    int chroma_planes;
    int chroma_h_shift;
    int chroma_v_shift;
    int transparency;
    int packed_at_lsb;
    int quant_table_count;
    uint8_t quant_tables[5][CONTEXT_SIZE];
    int context_count[5];
    int slice_count;
    int max_slice_count;
    int width;
    int height;
    int num_h_slices;
    int num_v_slices;
    struct FFV1Context **slice_context;
    struct AVCodecContext *avctx;
    uint8_t quant_table[CONTEXT_SIZE];
    int ec;
    int slice_damaged;
    int slice_x;
    int slice_y;
    int slice_width;
    int slice_height;
    PlaneContext plane[4];
    RangeCoder c;
} FFV1Context;

typedef struct AVCodecContext {
    int coder_type;
    int bits_per_raw_sample;
    int skip_alpha;
    int pix_fmt;
    void (*av_log)(void *, int, const char *, ...);
} AVCodecContext;

static int get_symbol(RangeCoder *c, uint8_t *state, int is_signed);
static int get_rac(RangeCoder *c, uint8_t *state);
static int read_quant_tables(RangeCoder *c, uint8_t *quant_table);
static void av_dlog(void *avctx, const char *fmt, ...);
static void av_freep(void *ptr);
static void av_assert0(int condition);
#define AV_RB24(p) (((p)[0] << 16) | ((p)[1] << 8) | (p)[2])
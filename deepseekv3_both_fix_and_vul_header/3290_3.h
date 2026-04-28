#include <stdint.h>
#include <string.h>
#include <assert.h>

#define CONTEXT_SIZE 32
#define MAX_SLICES 256
#define AVERROR_INVALIDDATA -1
#define AVERROR(ENOSYS) -1
#define AV_LOG_ERROR 0
#define AV_PIX_FMT_GRAY8 0
#define AV_PIX_FMT_GRAY16 1
#define AV_PIX_FMT_YUV444P 2
#define AV_PIX_FMT_YUV440P 3
#define AV_PIX_FMT_YUV422P 4
#define AV_PIX_FMT_YUV420P 5
#define AV_PIX_FMT_YUV411P 6
#define AV_PIX_FMT_YUV410P 7
#define AV_PIX_FMT_YUVA444P 8
#define AV_PIX_FMT_YUVA422P 9
#define AV_PIX_FMT_YUVA420P 10
#define AV_PIX_FMT_YUV444P9 11
#define AV_PIX_FMT_YUV422P9 12
#define AV_PIX_FMT_YUV420P9 13
#define AV_PIX_FMT_YUV444P10 14
#define AV_PIX_FMT_YUV422P10 15
#define AV_PIX_FMT_YUV420P10 16
#define AV_PIX_FMT_YUV444P16 17
#define AV_PIX_FMT_YUV422P16 18
#define AV_PIX_FMT_YUV420P16 19
#define AV_PIX_FMT_GBRP9 20
#define AV_PIX_FMT_GBRP10 21
#define AV_PIX_FMT_GBRP12 22
#define AV_PIX_FMT_GBRP14 23
#define AV_PIX_FMT_RGB32 24
#define AV_PIX_FMT_0RGB32 25

typedef struct RangeCoder {
    uint8_t *bytestream_start;
    uint8_t *bytestream_end;
    uint8_t one_state[256];
    int c;
} RangeCoder;

typedef struct PlaneContext {
    int quant_table_index;
    int context_count;
    uint8_t quant_table[CONTEXT_SIZE];
    void *state;
    void *vlc_state;
} PlaneContext;

typedef struct FFV1Context {
    int version;
    int ac;
    int plane_count;
    int colorspace;
    int chroma_planes;
    int chroma_h_shift;
    int chroma_v_shift;
    int transparency;
    int packed_at_lsb;
    int width;
    int height;
    int num_h_slices;
    int num_v_slices;
    int slice_count;
    int quant_table_count;
    int ec;
    int *context_count;
    uint8_t **quant_tables;
    uint8_t quant_table[CONTEXT_SIZE];
    uint8_t state_transition[256];
    struct FFV1Context **slice_context;
    struct {
        int coder_type;
        int bits_per_raw_sample;
        int pix_fmt;
        void (*log)(void*, int, const char*, ...);
    } *avctx;
    int slice_x;
    int slice_y;
    int slice_width;
    int slice_height;
    int slice_damaged;
    PlaneContext plane[4];
    RangeCoder c;
} FFV1Context;

static int get_symbol(RangeCoder *c, uint8_t *state, int is_signed) { return 0; }
static int get_rac(RangeCoder *c, uint8_t *state) { return 0; }
static int read_quant_tables(RangeCoder *c, uint8_t *quant_table) { return 0; }
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void av_dlog(void *avctx, const char *fmt, ...) {}
static unsigned AV_RB24(const uint8_t *p) { return 0; }
static void av_freep(void *ptr) {}
#define av_assert0(cond) assert(cond)
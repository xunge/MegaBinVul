#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STORED_Q 16
#define CFACTOR_Y444 3

enum {
    AV_LOG_ERROR,
};

#define AVERROR_BUFFER_TOO_SMALL (-1)

typedef struct AVCodecContext {
    int width;
    int height;
    void *priv_data;
} AVCodecContext;

typedef struct AVFrame {
    int linesize[4];
    uint8_t *data[4];
    int top_field_first;
} AVFrame;

typedef struct PutBitContext {
    int dummy;
} PutBitContext;

typedef struct ProresContext {
    int pictures_per_frame;
    int cur_picture_idx;
    int force_quant;
    uint16_t *quants[MAX_STORED_Q];
    uint16_t *custom_q;
    uint16_t quant_mat[64];
    int num_planes;
    int chroma_factor;
    void *blocks[1];
    void *emu_buf;
    int alpha_bits;
} ProresContext;

static int av_log2(int v) { return 0; }
static int put_bits_left(PutBitContext *pb) { return 0; }
static void av_log(AVCodecContext *avctx, int level, const char *fmt) {}

static void get_slice_data(ProresContext *ctx, const uint16_t *src, int linesize, int xp, int yp,
                          int pwidth, int height, void *blocks, void *emu_buf,
                          int mbs_per_slice, int num_cblocks, int is_chroma) {}

static int encode_slice_plane(ProresContext *ctx, PutBitContext *pb, const uint16_t *src, int linesize,
                             int mbs_per_slice, void *blocks, int num_cblocks,
                             int plane_factor, uint16_t *qmat) { return 0; }

static void get_alpha_data(ProresContext *ctx, const uint16_t *src, int linesize, int xp, int yp,
                          int pwidth, int height, void *blocks, int mbs_per_slice, int alpha_bits) {}

static int encode_alpha_plane(ProresContext *ctx, PutBitContext *pb,
                             int mbs_per_slice, void *blocks, int quant) { return 0; }
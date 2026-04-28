#include <stdint.h>
#include <string.h>

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int key_frame;
    int pict_type;
    int reference;
    int qstride;
    int *qscale_table;
    int qscale_type;
} AVFrame;

typedef struct AVCodecContext {
    void *priv_data;
    int (*release_buffer)(struct AVCodecContext *, AVFrame *);
    int (*get_buffer)(struct AVCodecContext *, AVFrame *);
} AVCodecContext;

typedef struct VP56Block {
    int ref_frame;
    int dc_coeff;
    int not_null_dc;
} VP56Block;

typedef struct VP56Macroblock {
    int type;
} VP56Macroblock;

typedef struct VP56Context {
    int has_alpha;
    AVFrame *framep[6];
    AVFrame frames[4];
    int mb_height;
    int mb_width;
    int flip;
    int frbi;
    int srbi;
    VP56Macroblock *macroblocks;
    VP56Block *above_blocks;
    VP56Block left_block[4];
    int prev_dc[3][4];
    int coeff_ctx[4];
    int coeff_ctx_last[4];
    int *above_block_idx;
    int *block_offset;
    int *qscale_table;
    void *models[2];
    void *modelp;
    int mb_type;
    int (*parse_header)(struct VP56Context *, const uint8_t *, int, int *);
    int (*parse_coeff_models)(struct VP56Context *);
    int (*default_models_init)(struct VP56Context *);
    void (*parse_vector_models)(struct VP56Context *);
    void (*parse_mb_type_models)(struct VP56Context *);
} VP56Context;

enum {
    VP56_FRAME_CURRENT,
    VP56_FRAME_GOLDEN,
    VP56_FRAME_GOLDEN2,
    VP56_FRAME_PREVIOUS,
    VP56_FRAME_UNUSED,
    VP56_FRAME_UNUSED2,
    VP56_FRAME_NONE
};

enum {
    VP56_MB_INTRA,
    VP56_MB_INTER_NOVEC_PF
};

enum {
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P
};

enum {
    AV_LOG_ERROR
};

enum {
    FF_QSCALE_TYPE_VP56
};

#define av_uninit(x) x
#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

static inline uint32_t bytestream_get_be24(const uint8_t **b) {
    uint32_t val = ((*b)[0] << 16) | ((*b)[1] << 8) | (*b)[2];
    *b += 3;
    return val;
}

static int vp56_size_changed(AVCodecContext *avctx) {
    return 0;
}

static void vp56_parse_mb_type_models(VP56Context *s) {
}

static void vp56_decode_mb(VP56Context *s, int mb_row, int mb_col, int is_alpha) {
}

static void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {
}
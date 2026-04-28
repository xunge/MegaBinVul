#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext AVCodecContext;
typedef struct RV34DecContext RV34DecContext;

struct AVCodecInternal {
    int is_copy;
};

struct AVCodecContext {
    void *priv_data;
    struct AVCodecInternal *internal;
};

struct MpegEncContext {
    AVCodecContext *avctx;
};

struct RV34DecContext {
    struct MpegEncContext s;
    void *tmp_b_block_base;
    void *cbp_chroma;
    void *cbp_luma;
    void *deblock_coefs;
    void *intra_types_hist;
    void *mb_type;
};

void ff_mpv_idct_init(struct MpegEncContext *s);
int ff_mpv_common_init(struct MpegEncContext *s);
void ff_mpv_common_end(struct MpegEncContext *s);
int rv34_decoder_alloc(RV34DecContext *r);
#include <stdint.h>

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)

typedef int16_t DCTELEM;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct MJpegDecodeContext {
    int comp_index[3];
    AVFrame picture;
    int linesize[3];
    int mb_height;
    int mb_width;
    int block_stride[3];
    DCTELEM (*blocks[3])[64];
    uint8_t *last_nnz[3];
    int quant_index[3];
    int16_t *quant_matrixes[4];
    int64_t coefs_finished[3];
    int interlaced;
    int bottom_field;
    struct AVCodecContext *avctx;
    int ac_index[3];
    struct {
        void (*idct_put)(uint8_t *dest, int line_size, int16_t *block);
    } dsp;
} MJpegDecodeContext;

struct AVCodecContext {
    int lowres;
};

void av_log(struct AVCodecContext *avctx, int level, const char *fmt, ...);

int decode_block_refinement(MJpegDecodeContext *s, int16_t *block, uint8_t *last_nnz,
                           int ac_index, int16_t *quant_matrix, int ss, int se, int Al, int *EOBRUN);

int decode_block_progressive(MJpegDecodeContext *s, int16_t *block, uint8_t *last_nnz,
                            int ac_index, int16_t *quant_matrix, int ss, int se, int Al, int *EOBRUN);
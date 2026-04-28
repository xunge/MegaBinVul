#include <stdint.h>

#define AV_LOG_ERROR 16

typedef int16_t DCTELEM;

typedef struct AVCodecContext {
    // dummy structure for av_log
} AVCodecContext;

typedef struct Vp3DecodeContext {
    int16_t (*qmat)[2][3][64];
    struct {
        uint8_t permutated[64];
    } scantable;
    int *dct_tokens[3][64];
    AVCodecContext *avctx;
} Vp3DecodeContext;

typedef struct Vp3Fragment {
    int qpi;
    int dc;
} Vp3Fragment;

static void av_log(void *avctx, int level, const char *fmt, ...) {}
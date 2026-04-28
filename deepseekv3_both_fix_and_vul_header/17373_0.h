#include <stdint.h>

#define GOP_STARTCODE 0x1b3
#define AV_CODEC_FLAG_CLOSED_GOP (1 << 0)

typedef struct PutBitContext {
    // dummy structure for compilation
} PutBitContext;

typedef struct AVFrame {
    int64_t pts;
    // dummy structure for compilation
} AVFrame;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    AVRational time_base;
    int flags;
    // dummy structure for compilation
} AVCodecContext;

typedef struct Picture {
    AVFrame *f;
    // dummy structure for compilation
} Picture;

typedef struct MpegEncContext {
    PutBitContext pb;
    Picture *current_picture_ptr;
    Picture *reordered_input_picture[2];
    AVCodecContext *avctx;
    int last_time_base;
    // dummy structure for compilation
} MpegEncContext;

static inline int FFUDIV(int a, int b) { return a / b; }
static inline int FFUMOD(int a, int b) { return a % b; }
static inline int64_t FFMIN(int64_t a, int64_t b) { return a < b ? a : b; }

void put_bits(PutBitContext *pb, int n, int value);
void ff_mpeg4_stuffing(PutBitContext *pb);
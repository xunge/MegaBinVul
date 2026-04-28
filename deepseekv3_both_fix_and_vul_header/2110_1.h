#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int skip_frame;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[4];
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct svq1_pmv {
    int x;
    int y;
} svq1_pmv;

typedef struct MpegEncContext {
    GetBitContext gb;
    int f_code;
    int width;
    int height;
    int linesize;
    int uvlinesize;
    int flags;
    int pict_type;
    void *avctx;
    struct {
        AVFrame f;
    } current_picture;
    struct {
        AVFrame f;
    } next_picture;
    struct {
        AVFrame f;
    } last_picture;
    void *last_picture_ptr;
} MpegEncContext;

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0,
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI,
    AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI
};

enum AVDiscard {
    AVDISCARD_NONE = -16,
    AVDISCARD_DEFAULT = 0,
    AVDISCARD_NONREF = 8,
    AVDISCARD_NONKEY = 16,
    AVDISCARD_ALL = 48
};

enum AVLogLevel {
    AV_LOG_INFO
};

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define CODEC_FLAG_GRAY 0x0020

void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
unsigned int get_bits(GetBitContext *s, int n);
int svq1_decode_frame_header(GetBitContext *gb, MpegEncContext *s);
int svq1_decode_block_intra(GetBitContext *gb, uint8_t *block, int stride);
int svq1_decode_delta_block(MpegEncContext *s, GetBitContext *gb, uint8_t *block, uint8_t *previous, int stride, svq1_pmv *pmv, int x, int y);
int MPV_frame_start(MpegEncContext *s, AVCodecContext *avctx);
void MPV_frame_end(MpegEncContext *s);
void *av_malloc(size_t size);
void av_free(void *ptr);
void av_dlog(void *avcl, const char *fmt, ...);
void av_log(void *avcl, int level, const char *fmt, ...);
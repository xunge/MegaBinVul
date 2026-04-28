#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_ERROR 1

typedef struct GetBitContext {
    unsigned int index;
    const uint8_t *buffer;
    int size_in_bits;
} GetBitContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int nb_samples;
} AVFrame;

typedef struct AVCodecContext {
    int (*get_buffer)(struct AVCodecContext *, struct AVFrame *);
} AVCodecContext;

typedef struct Channel {
    int decoded_samples;
    int cur_subframe;
} Channel;

typedef struct WmallDecodeCtx {
    GetBitContext gb;
    int samples_per_frame;
    AVCodecContext *avctx;
    AVFrame frame;
    int16_t *samples_16;
    int32_t *samples_32;
    int len_prefix;
    int log2_frame_size;
    int packet_loss;
    int dynamic_range_compression;
    int drc_gain;
    int parsed_all_subframes;
    int num_channels;
    Channel *channel;
    int skip_frame;
    int frame_num;
    int frame_offset;
} WmallDecodeCtx;

static int get_bits(GetBitContext *gb, int n);
static int get_bits1(GetBitContext *gb);
static void skip_bits_long(GetBitContext *gb, int n);
static int get_bits_count(GetBitContext *gb);
static int av_log2(int v);
static void av_dlog(void *avctx, const char *fmt, ...);
static void av_log(void *avctx, int level, const char *fmt, ...);
static int decode_tilehdr(WmallDecodeCtx *s);
static int decode_subframe(WmallDecodeCtx *s);
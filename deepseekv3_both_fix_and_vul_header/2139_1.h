#include <stdint.h>
#include <stdlib.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct CDLMS {
    int order;
} CDLMS;

typedef struct WmallChannelCtx {
    int decoded_samples;
    int cur_subframe;
    int num_subframes;
    int *subframe_len;
} WmallChannelCtx;

typedef struct WmallDecodeCtx {
    GetBitContext gb;
    int samples_per_frame;
    int num_channels;
    int subframe_offset;
    int channels_for_cur_subframe;
    int *channel_indexes_for_cur_subframe;
    int parsed_all_subframes;
    int seekable_tile;
    int do_arith_coding;
    int do_ac_filter;
    int do_inter_ch_decorr;
    int do_mclms;
    CDLMS cdlms[2][32];
    int movave_scaling;
    int quant_stepsize;
    int bits_per_sample;
    int bV3RTM;
    int do_lpc;
    int *is_channel_coded;
    int **channel_coeffs;
    int **channel_residues;
    int16_t *samples_16;
    int32_t *samples_32;
    WmallChannelCtx *channel;
    void *avctx;
} WmallDecodeCtx;

static inline int get_bits_count(const GetBitContext *s) {
    return s->index;
}

static inline unsigned int get_bits1(GetBitContext *s) {
    return 0;
}

static inline unsigned int get_bits(GetBitContext *s, int n) {
    return 0;
}

static inline int get_sbits(GetBitContext *s, int n) {
    return 0;
}

#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA (-2)

static void clear_codec_buffers(WmallDecodeCtx *s) {}
static void decode_ac_filter(WmallDecodeCtx *s) {}
static void decode_mclms(WmallDecodeCtx *s) {}
static int decode_cdlms(WmallDecodeCtx *s) { return 0; }
static void reset_codec(WmallDecodeCtx *s) {}
static void decode_lpc(WmallDecodeCtx *s) {}
static void decode_channel_residues(WmallDecodeCtx *s, int ch, int len) {}
static void use_high_update_speed(WmallDecodeCtx *s, int ch) {}
static void use_normal_update_speed(WmallDecodeCtx *s, int ch) {}
static void revert_cdlms(WmallDecodeCtx *s, int ch, int a, int b) {}
static void revert_mclms(WmallDecodeCtx *s, int len) {}
static void revert_inter_ch_decorr(WmallDecodeCtx *s, int len) {}
static void revert_acfilter(WmallDecodeCtx *s, int len) {}

#define av_log_missing_feature(ctx, feature, sample) {}
#define av_log_ask_for_sample(ctx, msg) {}
#define av_log(ctx, level, msg, ...) {}
#define av_dlog(ctx, fmt, ...) {}
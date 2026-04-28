#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_DEBUG   0
#define AV_LOG_ERROR   1
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA  (-2)

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    void *opaque;
} AVCodecContext;

typedef struct WmallChannelCtx {
    int decoded_samples;
    int *subframe_len;
    int cur_subframe;
    int num_subframes;
} WmallChannelCtx;

typedef struct CDLMS {
    int order;
} CDLMS;

typedef struct WmallDecodeCtx {
    int samples_per_frame;
    int num_channels;
    int bits_per_sample;
    int bV3RTM;
    int parsed_all_subframes;
    int seekable_tile;
    int do_arith_coding;
    int do_ac_filter;
    int do_inter_ch_decorr;
    int do_mclms;
    int do_lpc;
    int movave_scaling;
    int quant_stepsize;
    int channels_for_cur_subframe;
    int *channel_indexes_for_cur_subframe;
    int *is_channel_coded;
    int **channel_coeffs;
    int **channel_residues;
    int16_t **samples_16;
    int32_t **samples_32;
    WmallChannelCtx *channel;
    CDLMS cdlms[2][32];
    GetBitContext gb;
    AVCodecContext *avctx;
    int subframe_offset;
} WmallDecodeCtx;

static void av_log_missing_feature(void *avctx, const char *feature, int sample) {}
static void av_log_ask_for_sample(void *avctx, const char *msg) {}
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void av_dlog(void *avctx, const char *fmt, ...) {}
static int get_bits_count(GetBitContext *s) { return 0; }
static int get_bits1(GetBitContext *s) { return 0; }
static int get_bits(GetBitContext *s, int n) { return 0; }
static int get_sbits(GetBitContext *s, int n) { return 0; }
static void clear_codec_buffers(WmallDecodeCtx *s) {}
static void decode_ac_filter(WmallDecodeCtx *s) {}
static void decode_mclms(WmallDecodeCtx *s) {}
static int decode_cdlms(WmallDecodeCtx *s) { return 0; }
static void reset_codec(WmallDecodeCtx *s) {}
static void decode_lpc(WmallDecodeCtx *s) {}
static void decode_channel_residues(WmallDecodeCtx *s, int ch, int subframe_len) {}
static void use_high_update_speed(WmallDecodeCtx *s, int ch) {}
static void use_normal_update_speed(WmallDecodeCtx *s, int ch) {}
static void revert_cdlms(WmallDecodeCtx *s, int ch, int coef_begin, int coef_end) {}
static void revert_mclms(WmallDecodeCtx *s, int subframe_len) {}
static void revert_inter_ch_decorr(WmallDecodeCtx *s, int subframe_len) {}
static void revert_acfilter(WmallDecodeCtx *s, int subframe_len) {}
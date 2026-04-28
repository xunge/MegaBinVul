#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define TAK_MIN_FRAME_HEADER_BYTES 0

#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(e) (-(e))

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1

#define AV_EF_CRCCHECK (1 << 0)
#define AV_EF_COMPLIANT (1 << 1)
#define AV_EF_EXPLODE (1 << 2)

enum {
    TAK_CODEC_MONO_STEREO,
    TAK_CODEC_MULTICHANNEL,
};

enum {
    AV_SAMPLE_FMT_U8P,
    AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P,
};

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int bits_per_raw_sample;
    int sample_rate;
    uint64_t channel_layout;
    int channels;
    int err_recognition;
    int sample_fmt;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t **extended_data;
    int nb_samples;
} AVFrame;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct TAKStreamInfo {
    int codec;
    int data_type;
    int channels;
    int bps;
    int sample_rate;
    uint64_t ch_layout;
    int frame_samples;
    int last_frame_samples;
} TAKStreamInfo;

typedef struct TAKDecContext {
    GetBitContext gb;
    TAKStreamInfo ti;
    int nb_samples;
    uint8_t *decode_buffer;
    int decode_buffer_size;
    int32_t *decoded[6];
    int nb_subframes;
    int subframe_len[2];
    int dmode;
    int lpc_mode[6];
    int sample_shift[6];
    struct {
        int present;
        int index;
        int chan1;
        int chan2;
    } mcdparams[6];
} TAKDecContext;

static const int mc_dmodes[] = {0, 1, 2, 3, 4, 5, 6, 7};

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static int init_get_bits8(GetBitContext *gb, const uint8_t *buf, int byte_size) { return 0; }
static int ff_tak_decode_frame_header(AVCodecContext *avctx, GetBitContext *gb, TAKStreamInfo *ti, int flags) { return 0; }
static int ff_tak_check_crc(const uint8_t *buf, int size) { return 0; }
static int set_bps_params(AVCodecContext *avctx) { return 0; }
static void set_sample_rate_params(AVCodecContext *avctx) {}
static int ff_thread_get_buffer(AVCodecContext *avctx, ThreadFrame *f, int flags) { return 0; }
static void ff_thread_finish_setup(AVCodecContext *avctx) {}
static int get_bits_count(GetBitContext *gb) { return 0; }
static int get_bits_left(GetBitContext *gb) { return 0; }
static void align_get_bits(GetBitContext *gb) {}
static void skip_bits(GetBitContext *gb, int n) {}
static int get_bits1(GetBitContext *gb) { return 0; }
static int get_bits(GetBitContext *gb, int n) { return 0; }
static int get_sbits(GetBitContext *gb, int n) { return 0; }
static int decode_channel(TAKDecContext *s, int chan) { return 0; }
static int decorrelate(TAKDecContext *s, int chan1, int chan2, int len) { return 0; }
static void decode_lpc(int32_t *decoded, int lpc_mode, int nb_samples) {}
static void *av_fast_malloc(void *ptr, unsigned int *size, size_t min_size) { return NULL; }
static int av_samples_get_buffer_size(int *linesize, int nb_channels, int nb_samples, int sample_fmt, int align) { return 0; }
static int av_samples_fill_arrays(uint8_t **audio_data, int *linesize,
                                 const uint8_t *buf, int nb_channels,
                                 int nb_samples, int sample_fmt, int align) { return 0; }
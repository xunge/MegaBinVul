#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1
#define AV_SAMPLE_FMT_FLTP 0
#define CODEC_FLAG_BITEXACT 0
#define AVERROR(e) (-(e))
#define EINVAL 1
#define ENOMEM 2
#define AVERROR_INVALIDDATA 3
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define FF_INPUT_BUFFER_PADDING_SIZE 16
#define SAMPLES_PER_FRAME 1024
#define STEREO 0
#define JOINT_STEREO 1

typedef struct AVCodecContext {
    int channels;
    int extradata_size;
    const uint8_t *extradata;
    int block_align;
    void *priv_data;
    int flags;
    int sample_fmt;
    void *coded_frame;
} AVCodecContext;

typedef struct ATRAC3Context {
    int coding_mode;
    int scrambled_stream;
    void *decoded_bytes_buffer;
    void *mdct_ctx;
    int weighting_delay[6];
    int matrix_coeff_index_prev[4];
    int matrix_coeff_index_now[4];
    int matrix_coeff_index_next[4];
    void *fdsp;
    void *fmt_conv;
    void *units;
    void *frame;
} ATRAC3Context;

typedef struct {
} AVFrame;

#define av_cold

static void av_log(void *avctx, int level, const char *fmt, ...) {}
static uint16_t bytestream_get_le16(const uint8_t **p) { return 0; }
static uint32_t bytestream_get_be32(const uint8_t **p) { return 0; }
static uint16_t bytestream_get_be16(const uint8_t **p) { return 0; }
static void *av_mallocz(size_t size) { return NULL; }
static void av_freep(void *ptr) {}
static int ff_mdct_init(void *mdct, int nbits, int inverse, double scale) { return 0; }
static void avpriv_float_dsp_init(void *fdsp, int flags) {}
static void ff_fmt_convert_init(void *fmt_conv, void *avctx) {}
static int atrac3_decode_close(void *avctx) { return 0; }
static void avcodec_get_frame_defaults(void *frame) {}
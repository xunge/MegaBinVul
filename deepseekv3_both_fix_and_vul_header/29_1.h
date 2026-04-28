#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define AV_LOG_ERROR 16
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA (-2)
#define FF_INPUT_BUFFER_PADDING_SIZE 16
#define MAX_BLOCKSIZE 65535
#define FNSIZE 3
#define VERBATIM_CKSIZE_SIZE 5
#define VERBATIM_BYTE_SIZE 8
#define BITSHIFTSIZE 3
#define ENERGYSIZE 5

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int nb_samples;
    void *extended_data;
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct ShortenContext {
    int max_framesize;
    uint8_t *bitstream;
    int allocated_bitstream_size;
    int bitstream_size;
    int bitstream_index;
    GetBitContext gb;
    int bitindex;
    int got_header;
    int got_quit_command;
    int cur_chan;
    int channels;
    int blocksize;
    int nmean;
    int nwrap;
    int version;
    int bitshift;
    int32_t **offset;
    int32_t **decoded;
    AVCodecContext *avctx;
} ShortenContext;

enum {
    FN_VERBATIM = 0,
    FN_BITSHIFT = 1,
    FN_BLOCKSIZE = 2,
    FN_QUIT = 3,
    FN_ZERO = 4
};

static const int is_audio_command[] = {0, 0, 0, 0, 1};

static void init_get_bits(GetBitContext *gb, const uint8_t *buf, int size);
static void skip_bits(GetBitContext *gb, int n);
static int get_bits_left(GetBitContext *gb);
static int get_bits_count(GetBitContext *gb);
static unsigned int get_ur_golomb_shorten(GetBitContext *gb, int k);
static unsigned int get_uint(ShortenContext *s, int k);
static int read_header(ShortenContext *s);
static int decode_subframe_lpc(ShortenContext *s, int cmd, int channel, int residual_size, int32_t coffset);
static void fix_bitshift(ShortenContext *s, int32_t *decoded);
static void output_buffer(int16_t **out, int channels, int blocksize, int32_t **decoded);
static int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags);
static void av_log(void *avctx, int level, const char *fmt, ...);
static void *av_fast_realloc(void *ptr, unsigned int *size, size_t min_size);
static int AVERROR(int err);
static int av_log2(unsigned v);
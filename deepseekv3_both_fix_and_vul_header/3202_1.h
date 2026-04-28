#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEFAULT_BLOCK_SIZE 1024
#define MAX_CHANNELS 8
#define MAX_BLOCKSIZE 65536
#define NWRAP 3
#define OUT_BUFFER_SIZE 1024
#define CANONICAL_HEADER_SIZE 44
#define V2LPCQOFFSET 8

#define TYPESIZE 4
#define CHANSIZE 3
#define LPCQSIZE 3
#define NSKIPSIZE 3
#define FNSIZE 3
#define VERBATIM_CKSIZE_SIZE 5
#define VERBATIM_BYTE_SIZE 8

#define AV_LOG_ERROR 1
#define AVERROR_INVALIDDATA -1
#define AVERROR(EINVAL) -2

#define FN_VERBATIM 0
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int channels;
    void *priv_data;
} AVCodecContext;

typedef struct ShortenContext {
    GetBitContext gb;
    AVCodecContext *avctx;
    int lpcqoffset;
    int blocksize;
    int nmean;
    int version;
    int internal_ftype;
    int channels;
    int nwrap;
    int header_size;
    char header[OUT_BUFFER_SIZE];
    int cur_chan;
    int bitshift;
    int got_header;
} ShortenContext;

static int get_bits(GetBitContext *gb, int n);
static unsigned int get_bits_long(GetBitContext *gb, int n);
static unsigned int get_uint(ShortenContext *s, int n);
static void skip_bits(GetBitContext *gb, int n);
static int get_ur_golomb_shorten(GetBitContext *gb, int k);
static int allocate_buffers(ShortenContext *s);
static int init_offset(ShortenContext *s);
static int decode_wave_header(AVCodecContext *avctx, char *header, int header_size);
static void av_log(void *avctx, int level, const char *fmt, ...);

static inline uint32_t AV_RB32(const uint8_t *x) {
    return (uint32_t)x[0] << 24 | (uint32_t)x[1] << 16 | (uint32_t)x[2] << 8 | (uint32_t)x[3];
}
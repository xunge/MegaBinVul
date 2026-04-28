#include <stdint.h>
#include <string.h>

#define AV_LOG_WARNING 24
#define AV_LOG_DEBUG 48
#define AV_EF_EXPLODE (1 << 9)
#define FF_DEBUG_QP 0x0001
#define FF_QP2LAMBDA 118
#define AVERROR_INVALIDDATA (-1)

#define DQT 0xdb
#define DHT 0xc4
#define SOF0 0xc0
#define SOS 0xda

typedef struct AVCodecContext {
    void *priv_data;
    int err_recognition;
    int debug;
    int width;
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int quality;
    int qstride;
    uint8_t *qscale_table;
    int width;
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct MJpegDecodeContext {
    int restart_interval;
    int restart_count;
    int mjpb_skiptosod;
    GetBitContext gb;
    int start_code;
    AVFrame *picture_ptr;
    int interlaced;
    int bottom_field;
    int interlace_polarity;
    int lossless;
    int qscale[3];
    uint8_t *qscale_table;
    int width;
} MJpegDecodeContext;

static inline uint32_t MKBETAG(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    return (d << 24) | (c << 16) | (b << 8) | a;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
static void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
static void skip_bits(GetBitContext *s, int n);
static unsigned int get_bits_long(GetBitContext *s, int n);
static unsigned int show_bits(GetBitContext *s, int n);
static uint32_t read_offs(AVCodecContext *avctx, GetBitContext *gb, int buf_size, const char *fmt);
static int ff_mjpeg_decode_dqt(MJpegDecodeContext *s);
static int ff_mjpeg_decode_dht(MJpegDecodeContext *s);
static int ff_mjpeg_decode_sof(MJpegDecodeContext *s);
static int ff_mjpeg_decode_sos(MJpegDecodeContext *s, int *got_picture, const uint8_t *buf_end);

#define FFMAX3(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
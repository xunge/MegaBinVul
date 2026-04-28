#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AV_LOG_ERROR 0
#define MADm_TAG 0
#define MADe_TAG 0
#define FF_INPUT_BUFFER_PADDING_SIZE 0
#define AVERROR(e) (-(e))
#define ENOMEM 12

typedef struct AVFrame AVFrame;

typedef struct AVCodecContext {
    int width;
    int height;
    void *priv_data;
    struct {
        int num;
        int den;
    } time_base;
    void (*release_buffer)(struct AVCodecContext *, struct AVFrame *);
    int (*get_buffer)(struct AVCodecContext *, struct AVFrame *);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

struct AVFrame {
    uint8_t *data[8];
    int reference;
};

typedef struct MadContext {
    struct AVFrame frame;
    struct AVFrame last_frame;
    void *bitstream_buf;
    unsigned int bitstream_buf_size;
    struct {
        void (*bswap16_buf)(void *, const uint16_t *, int);
    } dsp;
    struct {
        void *buffer;
    } gb;
    int mb_x;
    int mb_y;
} MadContext;

#define AV_RL32(x) (*(const uint32_t*)(x))
#define AV_RL16(x) (*(const uint16_t*)(x))
#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static void av_reduce(int *num, int *den, int a, int b, int c) {}
static int av_image_check_size(int width, int height, int flags, AVCodecContext *avctx) { return 0; }
static void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {}
static void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size) {}
static void init_get_bits(void *gb, void *buf, int bit_size) {}
static int decode_mb(MadContext *s, int inter) { return 0; }
static void calc_quant_matrix(MadContext *s, uint8_t val) {}
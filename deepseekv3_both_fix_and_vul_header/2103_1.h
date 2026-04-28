#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    void *priv_data;
    struct {
        int id;
    } *codec;
    int codec_tag;
    int (*get_buffer)(struct AVCodecContext *, void *);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int nb_samples;
    uint8_t *data[8];
} AVFrame;

typedef struct DPCMContext {
    int channels;
    int16_t *roq_square_array;
    int sample[2];
    int16_t *sol_table;
    int16_t *sol_table_16;
    AVFrame frame;
} DPCMContext;

enum CodecID {
    CODEC_ID_ROQ_DPCM,
    CODEC_ID_INTERPLAY_DPCM,
    CODEC_ID_XAN_DPCM,
    CODEC_ID_SOL_DPCM
};

#define AV_LOG_ERROR 0
#define AVERROR(EINVAL) (-1)

static int16_t interplay_delta_table[256];
static int16_t sol_table_16[128];

static inline int16_t bytestream_get_le16(const uint8_t **buf) {
    int16_t val = *(*buf)++;
    val |= *(*buf)++ << 8;
    return val;
}

static inline uint8_t bytestream_get_byte(const uint8_t **buf) {
    return *(*buf)++;
}

static inline int av_clip_int16(int a) {
    if ((a+0x8000) & ~0xFFFF) return a<0 ? -0x8000 : 0x7FFF;
    else return a;
}

static inline uint8_t av_clip_uint8(int a) {
    if (a&(~0xFF)) return (~a)>>31;
    else return a;
}
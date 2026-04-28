#include <stdint.h>

#define AV_SAMPLE_FMT_FLT 0
#define AV_SAMPLE_FMT_S16 1
#define AV_SAMPLE_FMT_S32 2
#define AV_LOG_ERROR 0
#define WV_MAX_SAMPLES 131072
#define AVERROR(e) (-(e))
#define EINVAL 22
#define AVERROR_INVALIDDATA (-0x6368616e)

typedef struct AVFrame {
    uint8_t *data[8];
    int nb_samples;
} AVFrame;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int sample_fmt;
    int bits_per_raw_sample;
    int (*get_buffer)(struct AVCodecContext *, struct AVFrame *);
} AVCodecContext;

typedef struct WavpackContext {
    int block;
    int ch_offset;
    int samples;
    int mkv_mode;
    int multichannel;
    AVFrame frame;
} WavpackContext;

static inline uint32_t AV_RL32(const uint8_t *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
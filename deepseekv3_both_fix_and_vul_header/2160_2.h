#include <stdint.h>
#include <string.h>

#define AC3_MAX_CHANNELS 6
#define AC3_FRAME_BUFFER_SIZE 4096
#define LEVEL_MINUS_3DB 0.7071067811865476f
#define AV_CRC_16_ANSI 0
#define AV_EF_CRCCHECK (1 << 0)
#define AV_EF_CAREFUL (1 << 1)
#define AV_LOG_ERROR 16
#define AV_SAMPLE_FMT_FLT 1
#define AAC_AC3_PARSE_ERROR_SYNC 1
#define AAC_AC3_PARSE_ERROR_BSID 2
#define AAC_AC3_PARSE_ERROR_SAMPLE_RATE 3
#define AAC_AC3_PARSE_ERROR_FRAME_SIZE 4
#define AAC_AC3_PARSE_ERROR_FRAME_TYPE 5
#define AAC_AC3_PARSE_ERROR_CRC 6
#define EAC3_FRAME_TYPE_DEPENDENT 1
#define AC3_OUTPUT_LFEON 0x40
#define AC3_CHMODE_MONO 0
#define AC3_CHMODE_STEREO 1
#define AV_AUDIO_SERVICE_TYPE_KARAOKE 1
#define AVERROR_INVALIDDATA -1

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
    int nb_samples;
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct DSPContext {
    void (*bswap16_buf)(uint16_t *dst, const uint16_t *src, int len);
} DSPContext;

typedef struct FmtConvertContext {
    void (*float_interleave)(float *dst, const float **src, int len, int channels);
    void (*float_to_int16_interleave)(int16_t *dst, const float **src, int len, int channels);
} FmtConvertContext;

typedef struct AC3DecodeContext {
    uint8_t input_buffer[AC3_FRAME_BUFFER_SIZE];
    GetBitContext gbc;
    DSPContext dsp;
    FmtConvertContext fmt_conv;
    int frame_type;
    int substreamid;
    int frame_size;
    int sample_rate;
    int bit_rate;
    int channels;
    int out_channels;
    int output_mode;
    int lfe_on;
    int channel_mode;
    int request_channels;
    uint64_t channel_layout;
    int center_mix_level;
    int surround_mix_level;
    float loro_center_mix_level;
    float loro_surround_mix_level;
    float ltrt_center_mix_level;
    float ltrt_surround_mix_level;
    int fbw_channels;
    int bitstream_mode;
    int num_blocks;
    float output[AC3_MAX_CHANNELS][256];
    AVFrame frame;
} AC3DecodeContext;

typedef struct AVCodecContext {
    void *priv_data;
    int sample_rate;
    int bit_rate;
    int channels;
    int request_channels;
    uint64_t channel_layout;
    int err_recognition;
    int audio_service_type;
    int sample_fmt;
    int (*get_buffer)(struct AVCodecContext *c, AVFrame *frame);
    void (*av_log)(void *avcl, int level, const char *fmt, ...);
} AVCodecContext;

static inline uint16_t AV_RB16(const uint8_t *p) {
    return ((p[0] << 8) | p[1]);
}

static inline int FFMIN(int a, int b) {
    return a < b ? a : b;
}

static inline void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size) {
    s->buffer = buffer;
    s->index = 0;
}

static inline unsigned int av_crc(const void *ctx, unsigned int crc, const uint8_t *buffer, size_t len) { return 0; }
static inline const void *av_crc_get_table(int crc_id) { return NULL; }

extern const uint8_t ff_ac3_dec_channel_map[8][2][6];
extern const uint64_t avpriv_ac3_channel_layout_tab[8];
extern const float gain_levels[4];
extern int parse_frame_header(AC3DecodeContext *s);
extern int decode_audio_block(AC3DecodeContext *s, int blk);
extern void set_downmix_coeffs(AC3DecodeContext *s);
extern void av_log(void *avcl, int level, const char *fmt, ...);
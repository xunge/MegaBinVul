#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    void *priv_data;
    int channels;
    struct {
        int id;
    } *codec;
    uint8_t *extradata;
    int extradata_size;
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int nb_samples;
    uint8_t *data[8];
    void *extended_data;
} AVFrame;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct ADPCMChannelStatus {
    int predictor;
    int16_t step_index;
    int step;
    int prev_sample;
    int sample1;
    int sample2;
    int coeff1;
    int coeff2;
    int idelta;
} ADPCMChannelStatus;

typedef struct ADPCMDecodeContext {
    ADPCMChannelStatus status[6];
    AVFrame frame;
    int vqa_version;
} ADPCMDecodeContext;

#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AVERROR_INVALIDDATA -1
#define SEEK_SET 0
#define SEEK_END 2

enum AVCodecID {
    AV_CODEC_ID_ADPCM_IMA_QT,
    AV_CODEC_ID_ADPCM_IMA_WAV,
    AV_CODEC_ID_ADPCM_4XM,
    AV_CODEC_ID_ADPCM_MS,
    AV_CODEC_ID_ADPCM_IMA_DK4,
    AV_CODEC_ID_ADPCM_IMA_DK3,
    AV_CODEC_ID_ADPCM_IMA_ISS,
    AV_CODEC_ID_ADPCM_IMA_APC,
    AV_CODEC_ID_ADPCM_IMA_OKI,
    AV_CODEC_ID_ADPCM_IMA_WS,
    AV_CODEC_ID_ADPCM_XA,
    AV_CODEC_ID_ADPCM_IMA_EA_EACS,
    AV_CODEC_ID_ADPCM_IMA_EA_SEAD,
    AV_CODEC_ID_ADPCM_EA,
    AV_CODEC_ID_ADPCM_EA_MAXIS_XA,
    AV_CODEC_ID_ADPCM_EA_R1,
    AV_CODEC_ID_ADPCM_EA_R2,
    AV_CODEC_ID_ADPCM_EA_R3,
    AV_CODEC_ID_ADPCM_EA_XAS,
    AV_CODEC_ID_ADPCM_IMA_AMV,
    AV_CODEC_ID_ADPCM_IMA_SMJPEG,
    AV_CODEC_ID_ADPCM_CT,
    AV_CODEC_ID_ADPCM_SBPRO_4,
    AV_CODEC_ID_ADPCM_SBPRO_3,
    AV_CODEC_ID_ADPCM_SBPRO_2,
    AV_CODEC_ID_ADPCM_SWF,
    AV_CODEC_ID_ADPCM_YAMAHA,
    AV_CODEC_ID_ADPCM_AFC,
    AV_CODEC_ID_ADPCM_THP
};

static const int ff_adpcm_afc_coeffs[2][16] = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
};

static const int ea_adpcm_table[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
    1, 3, 5, 7, 9, 11, 13, 15, -1, -3, -5, -7, -9, -11, -13, -15,
    2, 6, 10, 14, 18, 22, 26, 30, -2, -6, -10, -14, -18, -22, -26, -30,
    4, 12, 20, 28, 36, 44, 52, 60, -4, -12, -20, -28, -36, -44, -52, -60
};

static const int ff_adpcm_AdaptCoeff1[7] = { 256, 512, 0, 192, 240, 460, 392 };
static const int ff_adpcm_AdaptCoeff2[7] = { 0, -256, 0, 64, 0, -208, -232 };

static inline int sign_extend(int val, unsigned bits) {
    return (val << (32 - bits)) >> (32 - bits);
}

static inline int av_clip_int16(int a) {
    if ((a+32768) & ~65535) return (a>>31) ^ 32767;
    else return a;
}

static inline void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size) {
    gb->buffer = buf;
    gb->buffer_end = buf + buf_size;
    gb->buffer_start = buf;
}

static inline int bytestream2_get_byte(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline int bytestream2_get_be16(GetByteContext *gb) {
    int val = (gb->buffer[0] << 8) | gb->buffer[1];
    gb->buffer += 2;
    return val;
}

static inline int bytestream2_get_le16(GetByteContext *gb) {
    int val = gb->buffer[0] | (gb->buffer[1] << 8);
    gb->buffer += 2;
    return val;
}

static inline int bytestream2_get_be32(GetByteContext *gb) {
    int val = (gb->buffer[0] << 24) | (gb->buffer[1] << 16) | (gb->buffer[2] << 8) | gb->buffer[3];
    gb->buffer += 4;
    return val;
}

static inline int bytestream2_get_le32(GetByteContext *gb) {
    int val = gb->buffer[0] | (gb->buffer[1] << 8) | (gb->buffer[2] << 16) | (gb->buffer[3] << 24);
    gb->buffer += 4;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, int size) {
    gb->buffer += size;
}

static inline int bytestream2_tell(const GetByteContext *gb) {
    return (int)(gb->buffer - gb->buffer_start);
}

static inline void bytestream2_seek(GetByteContext *gb, int offset, int whence) {
    if (whence == SEEK_SET)
        gb->buffer = gb->buffer_start + offset;
    else if (whence == SEEK_END)
        gb->buffer = gb->buffer_end + offset;
}

static inline int bytestream2_get_bytes_left(const GetByteContext *gb) {
    return gb->buffer_end - gb->buffer;
}

static inline int bytestream2_get_byteu(GetByteContext *gb) { return bytestream2_get_byte(gb); }
static inline int bytestream2_get_be16u(GetByteContext *gb) { return bytestream2_get_be16(gb); }
static inline int bytestream2_get_le16u(GetByteContext *gb) { return bytestream2_get_le16(gb); }
static inline int bytestream2_get_le32u(GetByteContext *gb) { return bytestream2_get_le32(gb); }
static inline void bytestream2_skipu(GetByteContext *gb, int size) { bytestream2_skip(gb, size); }

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

static void av_log(void *avcl, int level, const char *fmt, ...) {}

static int get_nb_samples(AVCodecContext *avctx, GetByteContext *gb, int buf_size, int *coded_samples) {
    return 0;
}

static int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame) {
    return 0;
}

static int adpcm_ima_qt_expand_nibble(ADPCMChannelStatus *c, int nibble, int shift) {
    return 0;
}

static int adpcm_ima_expand_nibble(ADPCMChannelStatus *c, int nibble, int shift) {
    return 0;
}

static int adpcm_ms_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}

static int adpcm_ima_oki_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}

static int xa_decode(AVCodecContext *avctx, int16_t *out0, int16_t *out1, const uint8_t *in,
                     ADPCMChannelStatus *left, ADPCMChannelStatus *right, int channels, int sample_offset) {
    return 0;
}

static int adpcm_ct_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}

static int adpcm_sbpro_expand_nibble(ADPCMChannelStatus *c, int nibble, int size, int shift) {
    return 0;
}

static void adpcm_swf_decode(AVCodecContext *avctx, const uint8_t *buf, int buf_size, int16_t *samples) {}

static int adpcm_yamaha_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}
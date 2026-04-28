#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    void *priv_data;
    int channels;
    int block_align;
    struct {
        int id;
    } *codec;
    int (*get_buffer)(struct AVCodecContext *, void *);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
    int nb_samples;
} AVFrame;

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
} ADPCMDecodeContext;

#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define AVERROR_INVALIDDATA (-1)

#define CODEC_ID_ADPCM_IMA_QT 0
#define CODEC_ID_ADPCM_IMA_WAV 1
#define CODEC_ID_ADPCM_4XM 2
#define CODEC_ID_ADPCM_MS 3
#define CODEC_ID_ADPCM_IMA_DK4 4
#define CODEC_ID_ADPCM_IMA_DK3 5
#define CODEC_ID_ADPCM_IMA_ISS 6
#define CODEC_ID_ADPCM_IMA_WS 7
#define CODEC_ID_ADPCM_XA 8
#define CODEC_ID_ADPCM_IMA_EA_EACS 9
#define CODEC_ID_ADPCM_IMA_EA_SEAD 10
#define CODEC_ID_ADPCM_EA 11
#define CODEC_ID_ADPCM_EA_MAXIS_XA 12
#define CODEC_ID_ADPCM_EA_R1 13
#define CODEC_ID_ADPCM_EA_R2 14
#define CODEC_ID_ADPCM_EA_R3 15
#define CODEC_ID_ADPCM_IMA_AMV 16
#define CODEC_ID_ADPCM_IMA_SMJPEG 17
#define CODEC_ID_ADPCM_CT 18
#define CODEC_ID_ADPCM_SBPRO_4 19
#define CODEC_ID_ADPCM_SBPRO_3 20
#define CODEC_ID_ADPCM_SBPRO_2 21
#define CODEC_ID_ADPCM_SWF 22
#define CODEC_ID_ADPCM_YAMAHA 23
#define CODEC_ID_ADPCM_THP 24
#define CODEC_ID_ADPCM_EA_XAS 25

static inline int av_clip(int a, int amin, int amax) {
    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

static inline int16_t av_clip_int16(int a) {
    if ((a+0x8000) & ~0xFFFF) return (a>>31) ^ 0x7FFF;
    else return a;
}

static inline int32_t av_clip_int32(int64_t a) {
    if ((a+0x80000000u) & ~0xFFFFFFFFu) return (a>>63) ^ 0x7FFFFFFF;
    else return (int32_t)a;
}

static inline int sign_extend(int val, unsigned bits) {
    unsigned shift = 8 * sizeof(int) - bits;
    union { unsigned u; int s; } v = { (unsigned) val << shift };
    return v.s >> shift;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}

static int get_nb_samples(AVCodecContext *avctx, const uint8_t *buf, int buf_size, int *coded_samples) {
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

static int adpcm_ct_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}

static int adpcm_sbpro_expand_nibble(ADPCMChannelStatus *c, int nibble, int size, int shift) {
    return 0;
}

static int adpcm_yamaha_expand_nibble(ADPCMChannelStatus *c, int nibble) {
    return 0;
}

static void xa_decode(short *out, const uint8_t *in, ADPCMChannelStatus *left, ADPCMChannelStatus *right, int channels) {}

static const int ff_adpcm_step_table[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

static const int ff_adpcm_index_table[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8
};

static const int ff_adpcm_AdaptCoeff1[7] = { 256, 512, 0, 192, 240, 460, 392 };
static const int ff_adpcm_AdaptCoeff2[7] = { 0, -256, 0, 64, 0, -208, -232 };

static const int ea_adpcm_table[16] = {
    0, 240, 460, 392, 0, 0, -208, -220, 0, 1, 3, 4, 7, 8, 10, 11
};

static const int swf_index_tables[4][16] = {
    /*2*/ { -1, 2 },
    /*3*/ { -1, -1, 2, 4 },
    /*4*/ { -1, -1, -1, -1, 2, 4, 6, 8 },
    /*5*/ { -1, -1, -1, -1, -1, -1, -1, -1, 1, 2, 4, 6, 8, 10, 13, 16 }
};

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

static void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size) {
    s->buffer = buffer;
    s->index = 0;
    s->size_in_bits = bit_size;
}

static unsigned int get_bits(GetBitContext *s, int n) {
    return 0;
}

static int get_bits_count(GetBitContext *s) {
    return 0;
}

static int get_sbits(GetBitContext *s, int n) {
    return 0;
}

#define DK3_GET_NEXT_NIBBLE() \
    if (!decode_top_nibble_next) { \
        nibble = last_byte >> 4; \
        decode_top_nibble_next = 1; \
    } else { \
        nibble = last_byte & 0x0F; \
        decode_top_nibble_next = 0; \
        if (src >= buf + buf_size) { \
            end_of_packet = 1; \
            break; \
        } \
        last_byte = *src++; \
    }

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

static inline uint16_t AV_RB16(const uint8_t *p) {
    return (p[0] << 8) | p[1];
}

static inline uint16_t AV_RL16(const uint8_t *p) {
    return (p[1] << 8) | p[0];
}

static inline uint16_t bytestream_get_le16(const uint8_t **p) {
    uint16_t val = AV_RL16(*p);
    *p += 2;
    return val;
}

static inline uint16_t bytestream_get_be16(const uint8_t **p) {
    uint16_t val = AV_RB16(*p);
    *p += 2;
    return val;
}

static inline uint32_t bytestream_get_le32(const uint8_t **p) {
    uint32_t val = (*p)[0] | ((*p)[1] << 8) | ((*p)[2] << 16) | ((*p)[3] << 24);
    *p += 4;
    return val;
}

static inline uint32_t bytestream_get_be32(const uint8_t **p) {
    uint32_t val = ((*p)[0] << 24) | ((*p)[1] << 16) | ((*p)[2] << 8) | (*p)[3];
    *p += 4;
    return val;
}
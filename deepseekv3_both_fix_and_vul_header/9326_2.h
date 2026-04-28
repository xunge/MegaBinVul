#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AV_CODEC_ID_APNG 0
#define AV_LOG_ERROR 0
#define AV_INPUT_BUFFER_MIN_SIZE 0
#define INT_MAX 2147483647
#define FF_MIN_BUFFER_SIZE 0
#define IOBUF_SIZE 4096
#define PNG_COLOR_TYPE_PALETTE 0
#define APNG_DISPOSE_OP_NONE 0
#define APNG_DISPOSE_OP_PREVIOUS 1
#define APNG_DISPOSE_OP_BACKGROUND 2
#define AV_CRC_32_IEEE_LE 0
#define MKTAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((a) << 24))

typedef struct AVCodecContext {
    int codec_id;
    int width;
    int height;
    int frame_number;
    void *priv_data;
    uint8_t *extradata;
    int extradata_size;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int pts;
    int dts;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width;
    int height;
    int format;
    int pts;
} AVFrame;

typedef struct APNGFctlChunk {
    uint32_t sequence_number;
    uint32_t width;
    uint32_t height;
    uint32_t x_offset;
    uint32_t y_offset;
    uint16_t delay_num;
    uint16_t delay_den;
    uint8_t dispose_op;
    uint8_t blend_op;
} APNGFctlChunk;

typedef struct PNGEncContext {
    int color_type;
    int bits_per_pixel;
    uint32_t palette_checksum;
    uint8_t *bytestream;
    uint8_t *bytestream_start;
    uint8_t *bytestream_end;
    uint8_t *last_frame_packet;
    size_t last_frame_packet_size;
    AVFrame *last_frame;
    AVFrame *prev_frame;
    uint32_t sequence_number;
    struct {
        void *next_in;
        unsigned int avail_in;
        void *next_out;
        unsigned int avail_out;
    } zstream;
    APNGFctlChunk last_frame_fctl;
} PNGEncContext;

static inline void AV_WB32(void *p, uint32_t v) {
    uint8_t *d = p;
    d[0] = v >> 24;
    d[1] = v >> 16;
    d[2] = v >> 8;
    d[3] = v;
}

static inline void AV_WB16(void *p, uint16_t v) {
    uint8_t *d = p;
    d[0] = v >> 8;
    d[1] = v;
}

int av_crc(const void *ctx, unsigned int crc, const uint8_t *buffer, size_t length);
const void *av_crc_get_table(int le);
void av_log(void *avcl, int level, const char *fmt, ...);
unsigned long deflateBound(void *strm, unsigned long sourceLen);
int ff_alloc_packet2(AVCodecContext *avctx, AVPacket *avpkt, int size, int size_min);
void *av_malloc(size_t size);
AVFrame *av_frame_alloc(void);
int av_frame_get_buffer(AVFrame *frame, int align);
void av_frame_unref(AVFrame *frame);
int av_frame_ref(AVFrame *dst, const AVFrame *src);
void av_frame_free(AVFrame **frame);
void png_write_chunk(uint8_t **bytestream, uint32_t tag, const uint8_t *buf, int length);
int encode_headers(AVCodecContext *avctx, const AVFrame *pict);
int apng_encode_frame(AVCodecContext *avctx, const AVFrame *pict, APNGFctlChunk *fctl_chunk, APNGFctlChunk *last_frame_fctl);
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
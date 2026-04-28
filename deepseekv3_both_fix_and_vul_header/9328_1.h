#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define AV_CODEC_ID_APNG 0
#define AV_LOG_ERROR 16
#define AV_INPUT_BUFFER_MIN_SIZE 16384
#define FF_MIN_BUFFER_SIZE 1024
#define IOBUF_SIZE 4096
#define INT_MAX 0x7FFFFFFF
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AV_CRC_32_IEEE_LE 0

enum {
    PNG_COLOR_TYPE_PALETTE = 3,
    APNG_DISPOSE_OP_NONE = 0,
    APNG_DISPOSE_OP_BACKGROUND = 1,
    APNG_DISPOSE_OP_PREVIOUS = 2
};

typedef struct z_stream_s {
    void *next_in;
    unsigned avail_in;
    unsigned long total_in;
    void *next_out;
    unsigned avail_out;
    unsigned long total_out;
    char *msg;
    void *state;
    void *(*zalloc)(void *, unsigned, unsigned);
    void (*zfree)(void *, void *);
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

typedef struct AVCodecContext {
    int codec_id;
    int width;
    int height;
    int frame_number;
    uint8_t *extradata;
    int extradata_size;
    void *priv_data;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int pts;
    int dts;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int format;
    int width;
    int height;
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
    int sequence_number;
    APNGFctlChunk last_frame_fctl;
    z_stream zstream;
} PNGEncContext;

static inline void AV_WB32(void *p, uint32_t v) {
    uint8_t *q = p;
    q[0] = v >> 24;
    q[1] = v >> 16;
    q[2] = v >> 8;
    q[3] = v;
}

static inline void AV_WB16(void *p, uint16_t v) {
    uint8_t *q = p;
    q[0] = v >> 8;
    q[1] = v;
}

static int AVERROR(int e) { return -e; }
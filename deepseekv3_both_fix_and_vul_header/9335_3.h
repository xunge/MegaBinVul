#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define GF_TRANSDIFF 1
#define GF_OFFSETTING 2
#define GIF_IMAGE_SEPARATOR 0x2C
#define AVPALETTE_COUNT 256
#define AVPALETTE_SIZE (AVPALETTE_COUNT * 4)
#define AV_PKT_DATA_PALETTE 0
#define HAVE_BIGENDIAN 0
#define FF_LZW_GIF 1
#define AV_LOG_DEBUG 0
#define AVERROR(e) (-(e))
#define ENOMEM 12

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVCodecContext {
    int height;
    int width;
    void *priv_data;
} AVCodecContext;

typedef struct GIFContext {
    int flags;
    int transparent_index;
    AVFrame *last_frame;
    uint8_t *palette;
    uint8_t *pal_exdata;
    void *lzw;
    uint8_t *buf;
    int buf_size;
    uint8_t *tmpl;
} GIFContext;

typedef struct PutBitContext {
    uint8_t *buf_ptr;
    int bit_left;
    int size_in_bits;
} PutBitContext;

static inline void bytestream_put_byte(uint8_t **bytestream, uint8_t val) {
    *(*bytestream)++ = val;
}

static inline void bytestream_put_le16(uint8_t **bytestream, uint16_t val) {
    *(*bytestream)++ = val;
    *(*bytestream)++ = val >> 8;
}

static inline void bytestream_put_be24(uint8_t **bytestream, uint32_t val) {
    *(*bytestream)++ = val >> 16;
    *(*bytestream)++ = val >> 8;
    *(*bytestream)++ = val;
}

static inline void bytestream_put_buffer(uint8_t **bytestream, const uint8_t *src, int size) {
    memcpy(*bytestream, src, size);
    *bytestream += size;
}

static inline void av_log(void *avctx, int level, const char *fmt, ...) {}

static inline int pick_palette_entry(const uint8_t *buf, int linesize, int width, int height) {
    return -1;
}

static inline uint8_t *av_packet_new_side_data(AVPacket *pkt, int type, int size) {
    return NULL;
}

static inline void put_bits(PutBitContext *s, int n, unsigned int value) {}
static inline void flush_put_bits(PutBitContext *s) {}

static inline void ff_lzw_encode_init(void *s, uint8_t *buf, int buf_size, int maxbits, int fmt, void (*put_bits)(PutBitContext *, int, unsigned)) {}
static inline int ff_lzw_encode(void *s, const uint8_t *inbuf, int insize) { return 0; }
static inline int ff_lzw_encode_flush(void *s, void (*flush_put_bits)(PutBitContext *)) { return 0; }
#include <stdint.h>
#include <string.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct AVCodecContext {
    int dummy;
} AVCodecContext;

typedef struct SANMVideoContext {
    int pitch;
    GetByteContext gb;
    AVCodecContext *avctx;
    int rotate_code;
    void *frm0;
    void *frm1;
    void *frm2;
    int height;
    size_t frm1_size;
    size_t frm2_size;
} SANMVideoContext;

#define AV_LOG_WARNING 0
#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)

static int c37_mv[1536];

static inline unsigned int bytestream2_get_byte(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline unsigned int bytestream2_get_le16(GetByteContext *gb) {
    unsigned int val = gb->buffer[0] | (gb->buffer[1] << 8);
    gb->buffer += 2;
    return val;
}

static inline unsigned int bytestream2_get_le32(GetByteContext *gb) {
    unsigned int val = gb->buffer[0] | (gb->buffer[1] << 8) | (gb->buffer[2] << 16) | (gb->buffer[3] << 24);
    gb->buffer += 4;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, unsigned int size) {
    gb->buffer += size;
}

static inline int bytestream2_get_bytes_left(GetByteContext *gb) {
    return gb->buffer_end - gb->buffer;
}

static inline unsigned int bytestream2_get_byteu(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline void bytestream2_get_bufferu(GetByteContext *gb, uint8_t *dst, unsigned int size) {
    memcpy(dst, gb->buffer, size);
    gb->buffer += size;
}

static inline void bytestream2_get_buffer(GetByteContext *gb, uint8_t *dst, unsigned int size) {
    memcpy(dst, gb->buffer, size);
    gb->buffer += size;
}

static void rotate_bufs(SANMVideoContext *ctx, int rotate) {}
static int rle_decode(SANMVideoContext *ctx, uint8_t *dst, uint32_t decoded_size) { return 0; }
static void copy_block4(uint8_t *dst, uint8_t *src, int dst_stride, int src_stride, int size) {}
static void codec37_mv(uint8_t *dst, uint8_t *src, int height, int stride, int mx, int my) {}
static void av_dlog(void *avctx, const char *fmt, ...) {}
static void av_log(void *avctx, int level, const char *fmt, ...) {}
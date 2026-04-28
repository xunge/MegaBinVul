#include <stdint.h>
#include <string.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct AVCodecContext {
    void *opaque;
} AVCodecContext;

typedef struct SANMVideoContext {
    int pitch;
    void *frm0;
    void *frm1;
    void *frm2;
    int height;
    AVCodecContext *avctx;
    int prev_seq;
    int rotate_code;
    GetByteContext gb;
} SANMVideoContext;

#define AV_LOG_WARNING 24
#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA -1094995529
#define AVERROR_PATCHWELCOME -126

static inline unsigned int bytestream2_tell(const GetByteContext *gb) { return gb->buffer - gb->buffer_start; }
static inline unsigned int bytestream2_get_le16(GetByteContext *gb) { return gb->buffer += 2, (gb->buffer[-2] | (gb->buffer[-1] << 8)); }
static inline unsigned int bytestream2_get_byte(GetByteContext *gb) { return *gb->buffer++; }
static inline void bytestream2_skip(GetByteContext *gb, unsigned int size) { gb->buffer += size; }
static inline unsigned int bytestream2_get_le32(GetByteContext *gb) { return gb->buffer += 4, (gb->buffer[-4] | (gb->buffer[-3] << 8) | (gb->buffer[-2] << 16) | (gb->buffer[-1] << 24)); }
static inline int bytestream2_get_bytes_left(const GetByteContext *gb) { return gb->buffer_end - gb->buffer; }
static inline void bytestream2_get_bufferu(GetByteContext *gb, uint8_t *dst, unsigned int size) { memcpy(dst, gb->buffer, size); gb->buffer += size; }
static inline unsigned int bytestream2_get_byteu(GetByteContext *gb) { return *gb->buffer++; }

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static void av_dlog(AVCodecContext *avctx, const char *fmt, ...) {}

static int process_block(SANMVideoContext *ctx, uint8_t *dst, uint8_t *prev1, uint8_t *prev2, int stride, int tbl_pos, int size) { return 0; }
static int rle_decode(SANMVideoContext *ctx, uint8_t *dst, uint32_t decoded_size) { return 0; }
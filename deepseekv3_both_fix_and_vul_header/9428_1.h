#include <stdint.h>
#include <string.h>

typedef struct ByteIOContext {
    unsigned char *buffer;
    int buffer_size;
    unsigned char *buf_ptr, *buf_end;
} ByteIOContext;

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct MmContext {
    AVCodecContext *avctx;
    AVFrame *frame;
    ByteIOContext gb;
} MmContext;

#define AVERROR_INVALIDDATA (-1)

static inline unsigned int bytestream2_get_byte(ByteIOContext *gb)
{
    if (gb->buf_ptr >= gb->buf_end)
        return 0;
    return *gb->buf_ptr++;
}

static inline int bytestream2_get_bytes_left(ByteIOContext *gb)
{
    return gb->buf_end - gb->buf_ptr;
}
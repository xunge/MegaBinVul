#include <stdint.h>
#include <string.h>

typedef struct SANMVideoContext SANMVideoContext;
typedef struct AVCodecContext AVCodecContext;

struct SANMVideoContext {
    uint8_t *frm0;
    uint8_t *frm1;
    uint8_t *frm2;
    int pitch;
    int height;
    int prev_seq;
    int rotate_code;
    AVCodecContext *avctx;
    struct {
        unsigned char *buffer;
        unsigned char *buffer_end;
        unsigned char *buffer_start;
        int index;
    } gb;
};

#define bytestream2_tell(p) ((p)->index)
#define bytestream2_get_le16(p) (*(uint16_t *)((p)->buffer + (p)->index++ * 2))
#define bytestream2_get_byte(p) (*(p)->buffer + (p)->index++)
#define bytestream2_skip(p, n) ((p)->index += (n))
#define bytestream2_get_le32(p) (*(uint32_t *)((p)->buffer + (p)->index++ * 4))
#define bytestream2_get_bytes_left(p) ((p)->buffer_end - (p)->buffer - (p)->index)
#define bytestream2_get_bufferu(p, dst, n) memcpy(dst, (p)->buffer + (p)->index, n); (p)->index += n
#define bytestream2_get_byteu(p) (*(p)->buffer + (p)->index++)

#define AV_LOG_WARNING 1
#define AV_LOG_ERROR 2
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
static void av_dlog(AVCodecContext *avctx, const char *fmt, ...);
static int process_block(SANMVideoContext *ctx, uint8_t *dst, uint8_t *prev1, uint8_t *prev2, int stride, int tbl_pos, int block_size);
static int rle_decode(SANMVideoContext *ctx, uint8_t *dst, uint32_t decoded_size);
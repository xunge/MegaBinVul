#include <stdint.h>
#include <string.h>
#include <errno.h>

#define AV_PIX_FMT_FLAG_BE 1
#define AV_PIX_FMT_FLAG_PSEUDOPAL 2
#define AV_PICTURE_TYPE_I 1
#define AV_FIELD_PROGRESSIVE 0
#define AV_FIELD_TT 1
#define AV_FIELD_TB 2
#define AVPALETTE_SIZE (256 * 4)
#define AV_PKT_DATA_PALETTE 0
#define AV_LOG_ERROR 16
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-22)

#define FFALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AV_RL32(x) (*(const uint32_t*)(x))
#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

enum AVPixelFormat {
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_RGB555LE,
    AV_PIX_FMT_RGB555BE,
    AV_PIX_FMT_RGB565LE,
    AV_PIX_FMT_MONOWHITE,
    AV_PIX_FMT_NV12,
    AV_PIX_FMT_YUYV422
};

typedef struct AVBufferRef {
    uint8_t *data;
} AVBufferRef;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    AVBufferRef *buf;
    int64_t pos;
    int64_t duration;
} AVPacket;

typedef struct AVFrame {
    int pict_type;
    int key_frame;
    int interlaced_frame;
    int top_field_first;
    int palette_has_changed;
    AVBufferRef *buf[2];
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVPicture {
    uint8_t *data[4];
    int linesize[4];
} AVPicture;

typedef struct AVCodecContext {
    int pix_fmt;
    int width;
    int height;
    int bits_per_coded_sample;
    unsigned int codec_tag;
    int field_order;
    void *priv_data;
    struct {
        AVPacket *pkt;
    } *internal;
} AVCodecContext;

typedef struct AVPixFmtDescriptor {
    int flags;
} AVPixFmtDescriptor;

typedef struct RawVideoContext {
    int is_2_4_bpp;
    int is_lt_16bpp;
    int is_yuv2;
    int tff;
    int frame_size;
    int flip;
    AVBufferRef *palette;
    uint8_t *bitstream_buf;
    int bitstream_buf_size;
    struct {
        void (*bswap16_buf)(uint16_t *dst, const uint16_t *src, int len);
        void (*bswap_buf)(uint32_t *dst, const uint32_t *src, int len);
    } bbdsp;
} RawVideoContext;

const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt);
int avpicture_get_size(int pix_fmt, int width, int height);
int avpicture_fill(AVPicture *picture, const uint8_t *ptr, int pix_fmt, int width, int height);
int av_image_check_size(int width, int height, int log_offset, void *log_ctx);
int ff_decode_frame_props(AVCodecContext *avctx, AVFrame *frame);
void av_frame_set_pkt_pos(AVFrame *frame, int64_t pos);
void av_frame_set_pkt_duration(AVFrame *frame, int64_t duration);
AVBufferRef *av_buffer_alloc(int size);
AVBufferRef *av_buffer_ref(AVBufferRef *buf);
void av_buffer_unref(AVBufferRef **buf);
void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size);
void av_log(void *avcl, int level, const char *fmt, ...);
int av_get_bits_per_pixel(const AVPixFmtDescriptor *pixdesc);
uint8_t *av_packet_get_side_data(const AVPacket *pkt, int type, int *size);
void scale16be(AVCodecContext *avctx, uint8_t *dst, const uint8_t *buf, int buf_size, int packed);
void scale16le(AVCodecContext *avctx, uint8_t *dst, const uint8_t *buf, int buf_size, int packed);
void flip(AVCodecContext *avctx, AVPicture *picture);
void av_assert0(int cond);
int AVERROR(int errnum);
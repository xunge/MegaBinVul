#include <stdint.h>
#include <string.h>

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define AVPALETTE_SIZE (256 * 4)
#define AV_PKT_DATA_PALETTE 0

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int palette_has_changed;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    int width;
    int height;
    int bits_per_coded_sample;
    int pix_fmt;
    void *priv_data;
} AVCodecContext;

typedef struct AVPicture {
    uint8_t *data[4];
    int linesize[4];
} AVPicture;

typedef struct MsrleContext {
    AVFrame *frame;
    uint8_t *buf;
    int size;
    uint8_t pal[AVPALETTE_SIZE];
    GetByteContext gb;
} MsrleContext;

int ff_reget_buffer(AVCodecContext *avctx, AVFrame *frame);
int av_frame_ref(void *dst, const AVFrame *src);
int av_image_get_linesize(int pix_fmt, int width, int plane);
void ff_msrle_decode(AVCodecContext *avctx, AVPicture *pic, int bpp, GetByteContext *gb);
void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size);
uint8_t *av_packet_get_side_data(const AVPacket *pkt, int type, int *size);
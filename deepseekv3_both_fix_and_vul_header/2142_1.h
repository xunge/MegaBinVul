#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int reference;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int (*release_buffer)(struct AVCodecContext *avctx, AVFrame *frame);
    int (*get_buffer)(struct AVCodecContext *avctx, AVFrame *frame);
} AVCodecContext;

typedef struct IVIBandDesc {
    int dummy_band;
} IVIBandDesc;

typedef struct IVIPlaneDesc {
    int num_bands;
    int width;
    int height;
    IVIBandDesc bands[16];
} IVIPlaneDesc;

typedef struct IVI4DecContext {
    GetBitContext gb;
    int frame_type;
    int is_scalable;
    IVIPlaneDesc planes[3];
    AVFrame frame;
} IVI4DecContext;

enum {
    FRAMETYPE_NULL_FIRST,
    FRAMETYPE_INTRA,
    AV_LOG_ERROR = 16
};

void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
int get_bits(GetBitContext *s, int n);
int get_bits_left(GetBitContext *s);
int show_bits(GetBitContext *s, int n);
void skip_bits_long(GetBitContext *s, int n);

int decode_pic_hdr(IVI4DecContext *ctx, AVCodecContext *avctx);
void switch_buffers(IVI4DecContext *ctx);
int decode_band(IVI4DecContext *ctx, int p, IVIBandDesc *band, AVCodecContext *avctx);
void ff_ivi_recompose_haar(IVIPlaneDesc *plane, uint8_t *dst, int dst_pitch, int Haar);
void ff_ivi_output_plane(IVIPlaneDesc *plane, uint8_t *dst, int dst_pitch);

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int avcodec_set_dimensions(AVCodecContext *avctx, int width, int height);
#include <stdint.h>
#include <stdlib.h>

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
    int (*get_buffer)(struct AVCodecContext *, AVFrame *);
    void (*release_buffer)(struct AVCodecContext *, AVFrame *);
} AVCodecContext;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct IVIBandDesc {
    // Placeholder for band description
} IVIBandDesc;

typedef struct IVIPlaneDesc {
    int num_bands;
    IVIBandDesc *bands;
} IVIPlaneDesc;

typedef struct IVI5DecContext {
    GetBitContext gb;
    const uint8_t *frame_data;
    int frame_size;
    int gop_invalid;
    int gop_flags;
    int frame_type;
    int is_scalable;
    AVFrame frame;
    IVIPlaneDesc planes[3];
} IVI5DecContext;

enum {
    IVI5_IS_PROTECTED = 1,
    FRAMETYPE_NULL = 0,
    AV_LOG_ERROR = 16
};

void av_log(void *avcl, int level, const char *fmt, ...);
void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
int decode_pic_hdr(IVI5DecContext *ctx, AVCodecContext *avctx);
void switch_buffers(IVI5DecContext *ctx);
int decode_band(IVI5DecContext *ctx, int plane, IVIBandDesc *band, AVCodecContext *avctx);
void ff_ivi_recompose53(IVIPlaneDesc *plane, uint8_t *dst, int dst_pitch, int flags);
void ff_ivi_output_plane(IVIPlaneDesc *plane, uint8_t *dst, int dst_pitch);
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct AVCodecContext {
    void *priv_data;
    int debug;
    int err_recognition;
    int pix_fmt;
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width;
    int height;
} AVFrame;

typedef struct AVDictionary AVDictionary;

typedef struct AVBufferRef {
    uint8_t *data;
} AVBufferRef;

typedef struct AVStereo3D {
    int type;
    int flags;
} AVStereo3D;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct MJpegDecodeContext {
    AVDictionary *exif_metadata;
    AVStereo3D *stereo3d;
    int adobe_transform;
    GetBitContext gb;
    int start_code;
    AVCodecContext *avctx;
    AVFrame *picture_ptr;
    int got_picture;
    int interlaced;
    int bottom_field;
    int interlace_polarity;
    int lossless;
    int ls;
    int progressive;
    int restart_interval;
    int restart_count;
    int cur_scan;
    int qscale[3];
    int width;
    int height;
    uint32_t upscale_h[4];
    uint32_t upscale_v[4];
    int flipped;
    int linesize[4];
} MJpegDecodeContext;

typedef struct AVPixFmtDescriptor {
    struct {
        int step_minus1;
    } comp[4];
} AVPixFmtDescriptor;

#define FF_DEBUG_STARTCODE 1
#define FF_DEBUG_QP 2
#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48
#define AV_LOG_WARNING 24
#define AV_LOG_FATAL 8
#define AV_EF_EXPLODE 2
#define FF_QSCALE_TYPE_MPEG1 0
#define AVERROR_INVALIDDATA (-1)
#define AVERROR(e) (-(e))
#define ENOSYS 38
#define PTRDIFF_SPECIFIER "ld"
#define FF_CEIL_RSHIFT(x, y) (((x) + (1 << (y)) - 1) >> (y))

#define SOI 0xD8
#define DQT 0xDB
#define DHT 0xC4
#define SOF0 0xC0
#define SOF1 0xC1
#define SOF2 0xC2
#define SOF3 0xC3
#define SOF5 0xC5
#define SOF6 0xC6
#define SOF7 0xC7
#define SOF9 0xC9
#define SOF10 0xCA
#define SOF11 0xCB
#define SOF13 0xCD
#define SOF14 0xCE
#define SOF15 0xCF
#define SOF48 0xF0
#define LSE 0xF1
#define EOI 0xD9
#define SOS 0xDA
#define DRI 0xDD
#define JPG 0xC8
#define COM 0xFE
#define APP0 0xE0
#define APP15 0xEF

#define CONFIG_JPEGLS_DECODER 1

#define AV_PIX_FMT_YUVJ444P  0
#define AV_PIX_FMT_YUV444P   1
#define AV_PIX_FMT_YUVJ440P  2
#define AV_PIX_FMT_YUV440P   3
#define AV_PIX_FMT_YUVA444P  4
#define AV_PIX_FMT_YUVJ420P  5
#define AV_PIX_FMT_YUV420P   6
#define AV_PIX_FMT_YUV420P16 7
#define AV_PIX_FMT_YUVA420P  8
#define AV_PIX_FMT_YUVA420P16 9
#define AV_PIX_FMT_GBRP     10
#define AV_PIX_FMT_GBRAP    11
#define AV_PIX_FMT_YUVJ422P 12
#define AV_PIX_FMT_YUV422P  13

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)
#define AV_RB32(x) (*(const uint32_t*)(x))
#define FFMAX3(a, b, c) FFMAX(FFMAX(a,b),c)
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

static inline void av_dict_free(AVDictionary **m) {}
static inline void av_freep(void *ptr) {}
static inline int av_frame_ref(AVFrame *dst, const AVFrame *src) { return 0; }
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}
static inline int init_get_bits8(GetBitContext *s, const uint8_t *buffer, int byte_size) { return 0; }
static inline int get_bits_count(GetBitContext *s) { return s->index; }
static inline void av_assert0(int cond) {}
static inline void avcodec_get_chroma_sub_sample(int pix_fmt, int *hshift, int *vshift) {
    *hshift = (pix_fmt == AV_PIX_FMT_YUV420P || pix_fmt == AV_PIX_FMT_YUVJ420P) ? 1 : 0;
    *vshift = (pix_fmt == AV_PIX_FMT_YUV420P || pix_fmt == AV_PIX_FMT_YUVJ420P) ? 1 : 0;
}
static inline AVStereo3D *av_stereo3d_create_side_data(void *data) { return NULL; }
static inline void av_dict_copy(AVDictionary **dst, AVDictionary *src, int flags) {}
static inline AVDictionary **avpriv_frame_get_metadatap(AVFrame *frame) { return NULL; }
static inline AVBufferRef *av_buffer_alloc(int size) { return NULL; }
static inline void av_frame_set_qp_table(void *data, AVBufferRef *buf, int stride, int type) {}
static inline AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt) { return NULL; }

int ff_mjpeg_find_marker(MJpegDecodeContext *s, const uint8_t **buf_ptr, 
                        const uint8_t *buf_end, const uint8_t **unescaped_buf_ptr,
                        int *unescaped_buf_size);
int ff_mjpeg_decode_dqt(MJpegDecodeContext *s);
int ff_mjpeg_decode_dht(MJpegDecodeContext *s);
int ff_mjpeg_decode_sof(MJpegDecodeContext *s);
int ff_jpegls_decode_lse(MJpegDecodeContext *s);
int ff_mjpeg_decode_sos(MJpegDecodeContext *s, const uint8_t *mb_bitmask,
                       int mb_bitmask_size, const AVFrame *reference);
void mjpeg_decode_app(MJpegDecodeContext *s);
void mjpeg_decode_com(MJpegDecodeContext *s);
void mjpeg_decode_dri(MJpegDecodeContext *s);
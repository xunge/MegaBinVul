#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int flags;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    uint8_t *data_1[2];
    int width;
    int height;
    int format;
    int pict_type;
    int key_frame;
    int interlaced_frame;
} AVFrame;

typedef struct AVDictionary AVDictionary;

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    int strict_std_compliance;
    int debug;
    void *priv_data;
    int codec_tag;
    AVRational sample_aspect_ratio;
} AVCodecContext;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct z_stream_s {
    void *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    void *msg;
    void *state;
    void *(*zalloc)(void *, unsigned int, unsigned int);
    void (*zfree)(void *, void *);
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

typedef struct bytestream2 {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} bytestream2;

typedef struct PNGDecContext {
    ThreadFrame picture;
    ThreadFrame last_picture;
    uint8_t *buffer;
    int buffer_size;
    uint8_t *crow_buf;
    uint8_t *last_row;
    int last_row_size;
    uint8_t *tmp_row;
    int tmp_row_size;
    uint8_t *image_buf;
    int image_linesize;
    int width;
    int height;
    int bit_depth;
    int color_type;
    int compression_type;
    int filter_type;
    int interlace_type;
    int channels;
    int bits_per_pixel;
    int bpp;
    int row_size;
    int crow_size;
    int pass;
    int pass_row_size;
    int state;
    int y;
    uint32_t palette[256];
    z_stream zstream;
    bytestream2 gb;
} PNGDecContext;

#define FF_COMPLIANCE_NORMAL 0
#define FF_DEBUG_STARTCODE 0
#define FF_DEBUG_PICT_INFO 0
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 0
#define AV_LOG_DEBUG 0
#define AVERROR_INVALIDDATA 0
#define AVERROR_EXTERNAL 0
#define AV_PIX_FMT_RGB24 0
#define AV_PIX_FMT_RGBA 0
#define AV_PIX_FMT_GRAY8 0
#define AV_PIX_FMT_GRAY16BE 0
#define AV_PIX_FMT_RGB48BE 0
#define AV_PIX_FMT_RGBA64BE 0
#define AV_PIX_FMT_PAL8 0
#define AV_PIX_FMT_MONOBLACK 0
#define AV_PIX_FMT_YA8 0
#define AV_PIX_FMT_YA16BE 0
#define AV_PICTURE_TYPE_I 0
#define AV_GET_BUFFER_FLAG_REF 0
#define PNG_ALLIMAGE 0
#define PNG_IHDR 0
#define PNG_IDAT 0
#define PNG_PLTE 0
#define PNGSIG 0
#define MNGSIG 0
#define Z_OK 0
#define AV_PKT_FLAG_KEY 0

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define PNG_COLOR_TYPE_RGB 0
#define PNG_COLOR_TYPE_RGB_ALPHA 0
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_PALETTE 0
#define PNG_COLOR_TYPE_GRAY_ALPHA 0

void bytestream2_init(bytestream2 *s, const uint8_t *buf, int buf_size);
uint32_t bytestream2_get_be32(bytestream2 *s);
uint32_t bytestream2_get_le32(bytestream2 *s);
uint64_t bytestream2_get_be64(bytestream2 *s);
int bytestream2_get_byte(bytestream2 *s);
void bytestream2_skip(bytestream2 *s, int n);
int bytestream2_get_bytes_left(bytestream2 *s);
int bytestream2_tell(bytestream2 *s);

void ff_thread_release_buffer(AVCodecContext *avctx, ThreadFrame *f);
void ff_thread_await_progress(ThreadFrame *f, int progress, int field);
void ff_thread_report_progress(ThreadFrame *f, int progress, int field);
int ff_thread_get_buffer(AVCodecContext *avctx, ThreadFrame *f, int flags);
void ff_thread_finish_setup(AVCodecContext *avctx);
void av_frame_set_metadata(AVFrame *f, AVDictionary *metadata);
int av_frame_ref(AVFrame *dst, AVFrame *src);
void av_dict_free(AVDictionary **m);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int av_image_check_size(int w, int h, int log_offset, AVCodecContext *avctx);
void *ff_png_zalloc(void *opaque, unsigned int items, unsigned int size);
void ff_png_zfree(void *opaque, void *ptr);
int ff_png_get_nb_channels(int color_type);
int ff_png_pass_row_size(int pass, int bits_per_pixel, int width);
void av_fast_padded_mallocz(void *ptr, unsigned int *size, size_t min_size);
void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size);
int png_decode_idat(PNGDecContext *s, int length);
int decode_text_chunk(PNGDecContext *s, int length, int compressed, AVDictionary **metadata);

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)
#define INT_MAX 2147483647

int inflateInit(z_stream *strm);
int inflateEnd(z_stream *strm);
unsigned long AV_RL32(const char *str);
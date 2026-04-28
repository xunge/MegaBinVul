#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HAVE_THREADS 1
#define MAX_THREADS 64
#define MAX_PICTURE_COUNT 32
#define FF_THREAD_SLICE 1
#define av_cold
#define FFMIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct AVFrame AVFrame;

typedef struct AVCodecContext {
    int active_thread_type;
    int thread_count;
    int slices;
    int pix_fmt;
} AVCodecContext;

typedef struct Picture {
    AVFrame *f;
} Picture;

typedef struct ParseContext {
    int state;
} ParseContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    int encoding;
    int codec_id;
    int progressive_sequence;
    int width;
    int height;
    int mb_height;
    int chroma_x_shift;
    int chroma_y_shift;
    Picture *picture;
    Picture next_picture;
    Picture last_picture;
    Picture current_picture;
    Picture new_picture;
    ParseContext parse_context;
    int context_initialized;
    struct MpegEncContext *thread_context[MAX_THREADS];
    int start_mb_y;
    int end_mb_y;
    int slice_context_count;
} MpegEncContext;

#define AV_CODEC_ID_MPEG2VIDEO 1
#define AV_PIX_FMT_NONE 0
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 0

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int av_image_check_size(int width, int height, int log_offset, AVCodecContext *avctx);
void dct_init(MpegEncContext *s);
void avcodec_get_chroma_sub_sample(int pix_fmt, int *chroma_x_shift, int *chroma_y_shift);
AVFrame *av_frame_alloc(void);
void *av_memdup(const void *p, size_t size);
int init_context_frame(MpegEncContext *s);
int init_duplicate_context(MpegEncContext *s);
void ff_mpv_common_end(MpegEncContext *s);

#define FF_ALLOCZ_OR_GOTO(ctx, p, size, label) \
    do { \
        p = calloc(1, size); \
        if (!p) goto label; \
    } while (0)
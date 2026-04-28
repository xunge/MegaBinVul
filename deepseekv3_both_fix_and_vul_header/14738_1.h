#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#define FF_DEBUG_VIS_QP 0
#define FF_DEBUG_VIS_MB_TYPE 0
#define MAX_AUTO_THREADS 16
#define HAVE_W32THREADS 0
#define ENOMEM 12

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVPacket {
    int dummy;
} AVPacket;

typedef struct AVFrame {
    int dummy;
} AVFrame;

typedef struct AVCodecInternal {
    void *thread_ctx;
    void *pkt;
    int is_copy;
} AVCodecInternal;

typedef struct AVCodec {
    int priv_data_size;
    int (*init)(void *);
    int (*init_thread_copy)(void *);
} AVCodec;

typedef struct AVCodecContext {
    int thread_count;
    int debug;
    int debug_mv;
    int active_thread_type;
    const AVCodec *codec;
    AVCodecInternal *internal;
    void *priv_data;
} AVCodecContext;

typedef struct PerThreadContext {
    pthread_t thread;
    pthread_mutex_t mutex;
    pthread_mutex_t progress_mutex;
    pthread_cond_t input_cond;
    pthread_cond_t progress_cond;
    pthread_cond_t output_cond;
    AVFrame *frame;
    AVPacket avpkt;
    struct FrameThreadContext *parent;
    AVCodecContext *avctx;
    int thread_init;
} PerThreadContext;

typedef struct FrameThreadContext {
    pthread_mutex_t buffer_mutex;
    PerThreadContext *threads;
    int delaying;
} FrameThreadContext;

int av_cpu_count(void);
void w32thread_init(void);
void *av_mallocz(size_t size);
void *av_malloc(size_t size);
void *av_mallocz_array(size_t nmemb, size_t size);
void av_freep(void *ptr);
AVFrame *av_frame_alloc(void);
int AVERROR(int errnum);
void update_context_from_thread(AVCodecContext *dst, AVCodecContext *src, int for_user);
void ff_frame_thread_free(AVCodecContext *avctx, int thread_count);
void *frame_worker_thread(void *arg);
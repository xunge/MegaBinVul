#include <stdint.h>
#include <float.h>
#include <math.h>
#include <stddef.h>

#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))
#define AV_TIME_BASE 1000000
#define PRId64 "lld"
#define DBL_MAX __DBL_MAX__
#define ENOMEM 12

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVFrame {
    int64_t pts;
} AVFrame;

typedef struct AVFifoBuffer {
    // Minimal definition for compilation
    int dummy;
} AVFifoBuffer;

typedef struct AVFilterLink {
    struct AVFilterContext *dst;
    AVRational time_base;
    struct AVFilterContext *src;
} AVFilterLink;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
    AVFilterLink **inputs;
} AVFilterContext;

typedef struct FPSContext {
    AVFifoBuffer *fifo;
    int64_t pts;
    int64_t first_pts;
    double start_time;
    int frames_in;
    int frames_out;
    int drop;
    int dup;
    int rounding;
} FPSContext;

enum AVLogLevel {
    AV_LOG_QUIET = -8,
    AV_LOG_PANIC = 0,
    AV_LOG_FATAL = 8,
    AV_LOG_ERROR = 16,
    AV_LOG_WARNING = 24,
    AV_LOG_INFO = 32,
    AV_LOG_VERBOSE = 40,
    AV_LOG_DEBUG = 48
};

enum AVRounding {
    AV_ROUND_ZERO,
    AV_ROUND_INF,
    AV_ROUND_DOWN,
    AV_ROUND_UP,
    AV_ROUND_NEAR_INF,
    AV_ROUND_PASS_MINMAX
};

#define AV_TIME_BASE_Q (AVRational){1, AV_TIME_BASE}
#define AVERROR(e) (-(e))

static inline int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq) { return 0; }
static inline int64_t av_rescale_q_rnd(int64_t a, AVRational bq, AVRational cq, int rnd) { return 0; }
static inline void av_log(void *avcl, int level, const char *fmt, ...) {}
static inline void av_frame_free(AVFrame **frame) {}
static inline int av_fifo_size(AVFifoBuffer *f) { return 0; }
static inline void av_fifo_generic_read(AVFifoBuffer *f, void *dst, int buf_size, void *func) {}
static inline AVFrame *av_frame_clone(AVFrame *src) { return NULL; }

static int write_to_fifo(AVFifoBuffer *fifo, AVFrame *frame) { return 0; }
static void flush_fifo(AVFifoBuffer *fifo) {}
static int ff_filter_frame(AVFilterLink *outlink, AVFrame *frame) { return 0; }

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
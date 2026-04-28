#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct AVFilterLink AVFilterLink;
typedef struct AVFilterBufferRef AVFilterBufferRef;
typedef struct AVFilterPad AVFilterPad;
typedef struct AVFilterContext AVFilterContext;
typedef struct AVFilterBuffer AVFilterBuffer;
typedef struct AVFilterBufferAudio AVFilterBufferAudio;

#define AV_LOG_DEBUG 0

struct AVFilterLink {
    AVFilterPad *dstpad;
    AVFilterContext *dst;
    AVFilterBufferRef *cur_buf;
};

struct AVFilterBufferRef {
    int perms;
    int64_t pts;
    AVFilterBufferAudio *audio;
    uint8_t *data[8];
    int linesize[8];
};

struct AVFilterPad {
    void (*filter_samples)(AVFilterLink *, AVFilterBufferRef *);
    int min_perms;
    int rej_perms;
};

struct AVFilterContext {
    void *log_ctx;
};

struct AVFilterBuffer {
    int perms;
    uint8_t *data[8];
    int linesize[8];
};

struct AVFilterBufferAudio {
    int nb_samples;
    int sample_rate;
};

#define FF_DPRINTF_START(ctx, ...) 
#define ff_dlog_link(ctx, link, flag) 

void avfilter_default_filter_samples(AVFilterLink *link, AVFilterBufferRef *samplesref);
AVFilterBufferRef *avfilter_default_get_audio_buffer(AVFilterLink *link, int perms, int nb_samples);
void avfilter_unref_buffer(AVFilterBufferRef *buf);
void av_log(void *avcl, int level, const char *fmt, ...);
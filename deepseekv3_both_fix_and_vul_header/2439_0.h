#include <stdint.h>
#include <stdlib.h>

typedef uint8_t UID[16];

typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;

typedef struct MXFContext {
    AVFormatContext *fc;
    uint8_t *local_tags;
    int local_tags_count;
} MXFContext;

#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA  (-2)
#define AVERROR(ENOMEM)     (-3)
#define AV_LOG_ERROR        1
#define AV_LOG_VERBOSE      2

int avio_rb32(AVIOContext *s);
void avpriv_request_sample(AVIOContext *s, const char *msg, ...);
void av_log(void *avcl, int level, const char *fmt, ...);
void av_free(void *ptr);
void *av_calloc(size_t nmemb, size_t size);
int avio_read(AVIOContext *s, void *buf, int size);
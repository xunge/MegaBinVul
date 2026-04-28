#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVDictionary AVDictionary;

typedef struct URLContext {
    void *priv_data;
    int is_streamed;
} URLContext;

typedef struct HTTPContext {
    int seekable;
    uint64_t filesize;
    char *location;
    AVDictionary *chained_options;
    char *headers;
    int listen;
} HTTPContext;

#define AV_LOG_WARNING 0
#define AVERROR(e) (-(e))
#define ENOMEM 12

void *av_strdup(const char *s);
void av_dict_copy(AVDictionary **dst, const AVDictionary *src, int flags);
void av_log(URLContext *h, int level, const char *fmt, ...);
int av_reallocp(void *ptr, size_t size);
void av_dict_free(AVDictionary **m);

int http_listen(URLContext *h, const char *uri, int flags, AVDictionary **options);
int http_open_cnx(URLContext *h, AVDictionary **options);
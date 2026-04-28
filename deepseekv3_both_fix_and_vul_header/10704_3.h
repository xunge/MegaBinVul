#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct AVDictionary AVDictionary;
typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;

struct AVFormatContext {
    void *priv_data;
    int (*io_open)(AVFormatContext *s, AVIOContext **pb, const char *url, int flags, AVDictionary **options);
    int flags;
};

#define AV_LOG_ERROR 16
#define AVFMT_FLAG_CUSTOM_IO 0x0040
#define AVIO_FLAG_READ 1
#define AVERROR_INVALIDDATA (-1)
#define AV_OPT_SEARCH_CHILDREN (1 << 0)

typedef struct HLSContext {
    char *cookies;
    const char *allowed_extensions;
} HLSContext;

int av_strstart(const char *str, const char *pfx, const char **ptr);
const char *avio_find_protocol_name(const char *url);
void av_dict_copy(AVDictionary **dst, const AVDictionary *src, int flags);
void av_dict_free(AVDictionary **m);
void av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);
void av_log(void *avcl, int level, const char *fmt, ...);
int av_match_ext(const char *filename, const char *extensions);
void av_free(void *ptr);
int av_opt_get(void *obj, const char *name, int search_flags, uint8_t **out_val);
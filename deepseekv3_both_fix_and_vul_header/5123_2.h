#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

typedef bool Bool;
typedef int32_t s32;
typedef uint32_t u32;

#define GF_FALSE false
#define GF_TRUE true

typedef struct GF_InputService {
    void *priv;
} GF_InputService;

typedef struct GF_BaseInterface {
} GF_BaseInterface;

typedef struct FFDemux {
    void *options;
} FFDemux;

typedef struct AVCodecContext {
    int codec_type;
} AVCodecContext;

typedef struct AVStream {
    AVCodecContext *codec;
} AVStream;

typedef struct AVFormatContext {
    unsigned int nb_streams;
    AVStream **streams;
} AVFormatContext;

typedef struct AVOutputFormat {
    const char *mime_type;
    const char *extensions;
    const char *name;
} AVOutputFormat;

typedef struct AVInputFormat {
} AVInputFormat;

typedef struct AVDictionary {
} AVDictionary;

enum {
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_VIDEO
};

static const char *FFD_MIME_TYPES[] = {NULL};

static int open_file(AVFormatContext **ctx, const char *filename, AVInputFormat *fmt, void **options) {
    return -1;
}

static AVInputFormat *av_find_input_format(const char *name) {
    return NULL;
}

static int av_find_stream_info(AVFormatContext *ctx) {
    return -1;
}

static AVOutputFormat *guess_stream_format(const char *short_name, const char *filename, const char *mime_type) {
    return NULL;
}

static AVOutputFormat *av_guess_format(const char *short_name, const char *filename, const char *mime_type) {
    return NULL;
}

static void av_close_input_file(AVFormatContext *ctx) {}
static void avformat_close_input(AVFormatContext **ctx) {}

static void gf_service_register_mime(GF_InputService *plug, const char *mime_type, const char *extensions, const char *name) {}
static bool gf_service_check_mime_register(GF_InputService *plug, const char *a, const char *b, const char *c, const char *ext) { return false; }
static const char *gf_modules_get_option(GF_BaseInterface *plug, const char *section, const char *name) { return NULL; }
static void gf_modules_set_option(GF_BaseInterface *plug, const char *section, const char *name, char *value) {}
static void *gf_malloc(size_t size) { return malloc(size); }
static void gf_free(void *ptr) { free(ptr); }
static void ffd_parse_options(FFDemux *ffd, const char *url) {}

static int strnicmp(const char *s1, const char *s2, size_t n) {
    return strncasecmp(s1, s2, n);
}

static char *strlwr(char *str) {
    for (char *p = str; *p; p++) {
        *p = tolower(*p);
    }
    return str;
}
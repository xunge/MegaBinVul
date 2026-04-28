#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT_XML 0
#define AVERROR(e) (-(e))
#define EINVAL 22

struct SignatureContext {
    int nb_inputs;
    char *filename;
    int format;
};

struct AVFilterContext {
    struct SignatureContext *priv;
};

typedef struct AVFilterContext AVFilterContext;
typedef struct StreamContext StreamContext;
typedef struct SignatureContext SignatureContext;

static int av_get_frame_filename(char *buf, int buf_size, const char *pat, int number) { return 0; }
static size_t av_strlcpy(char *dst, const char *src, size_t size) { return 0; }
static void av_assert0(int cond) {}
static int xml_export(AVFilterContext *ctx, StreamContext *sc, const char *filename) { return 0; }
static int binary_export(AVFilterContext *ctx, StreamContext *sc, const char *filename) { return 0; }
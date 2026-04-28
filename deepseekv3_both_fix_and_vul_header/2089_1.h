#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef struct AVStream AVStream;

typedef struct AVFormatContext {
    void *priv_data;
    char *filename;
    unsigned int nb_streams;
    AVStream **streams;
} AVFormatContext;

typedef struct NSVContext {
    int state;
    struct {
        uint8_t *data;
    } ahead[2];
} NSVContext;

enum {
    NSV_UNSYNC,
    NSV_FOUND_NSVF,
    NSV_FOUND_NSVS
};

#define NSV_MAX_RESYNC_TRIES 1000
#define av_dlog(ctx, ...) fprintf(stderr, __VA_ARGS__)

static int nsv_resync(AVFormatContext *s);
static int nsv_parse_NSVf_header(AVFormatContext *s);
static int nsv_parse_NSVs_header(AVFormatContext *s);
static int nsv_read_chunk(AVFormatContext *s, int flag);
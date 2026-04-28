#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PROBE_BUF_MAX (1024 * 1024)
#define PROBE_BUF_MIN 2048
#define AVPROBE_SCORE_MAX 100
#define AVPROBE_PADDING_SIZE 32
#define AV_LOG_WARNING 24
#define AV_LOG_DEBUG 48

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct AVInputFormat {
    const char *name;
} AVInputFormat;

typedef struct AVIOContext AVIOContext;

typedef struct AVProbeData {
    const char *filename;
    unsigned char *buf;
    int buf_size;
} AVProbeData;

#define AVERROR(e) (-(e))
#define EINVAL 22
#define ENOMEM 12
#define AVERROR_EOF (-541478725)
#define AVERROR_INVALIDDATA (-1094995529)

extern AVInputFormat *av_probe_input_format2(AVProbeData *pd, int is_opened, int *score_max);
extern int avio_read(AVIOContext *s, unsigned char *buf, int size);
extern void *av_realloc(void *ptr, size_t size);
extern void av_free(void *ptr);
extern int ffio_rewind_with_probe_data(AVIOContext *s, unsigned char *buf, int buf_size);
extern void av_log(void *avcl, int level, const char *fmt, ...);
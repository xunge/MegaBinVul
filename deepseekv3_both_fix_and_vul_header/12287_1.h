#include <stdint.h>
#include <string.h>
#include <inttypes.h>

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;

struct HTTPContext {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    int64_t end_off;
    int64_t filesize;
    int willclose;
    int64_t chunksize;
    URLContext *hd;
    int64_t off;
};

struct URLContext {
    void *priv_data;
};

#define AVERROR_EOF (-1)
#define AVERROR(e) (-e)
#define EIO 5
#define AV_LOG_ERROR 0

int ffurl_read(URLContext *h, uint8_t *buf, int size);
void av_log(URLContext *h, int level, const char *fmt, ...);
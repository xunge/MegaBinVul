#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#define SEEK_SET 0

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;

struct URLContext {
    void *priv_data;
    int is_streamed;
};

struct HTTPContext {
    void *hd;
    int end_chunked_post;
    int end_header;
    uint64_t chunksize;
    int compressed;
    int reconnect;
    int reconnect_streamed;
    int reconnect_at_eof;
    uint64_t filesize;
    uint64_t off;
    int reconnect_delay;
    int reconnect_delay_max;
};

#define AVERROR_EOF (-1)
#define AVERROR(e) (-e)
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define CONFIG_ZLIB 0
#define AV_LOG_TRACE 0
#define AV_LOG_ERROR 0
#define AV_LOG_INFO 0

static int http_read_header(URLContext *h, int *new_location);
static int http_get_line(HTTPContext *s, char *line, int size);
static int http_buf_read(URLContext *h, uint8_t *buf, int size);
static int http_buf_read_compressed(URLContext *h, uint8_t *buf, int size);
static int64_t http_seek_internal(URLContext *h, int64_t target, int whence, int force_reconnect);
static void av_log(URLContext *h, int level, const char *fmt, ...);
static const char *av_err2str(int errnum);
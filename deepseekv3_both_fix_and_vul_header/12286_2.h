#include <stdint.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define AVSEEK_SIZE 0x10000
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define AVERROR(e) (-(e))
#define ENOSYS 38
#define EINVAL 22

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;
typedef struct AVDictionary AVDictionary;

struct URLContext {
    void *priv_data;
    int is_streamed;
};

struct HTTPContext {
    URLContext *hd;
    int64_t off;
    int64_t filesize;
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    uint8_t buffer[BUFFER_SIZE];
};

int http_open_cnx(URLContext *h, AVDictionary **options);
void av_dict_free(AVDictionary **options);
void ffurl_close(URLContext *h);
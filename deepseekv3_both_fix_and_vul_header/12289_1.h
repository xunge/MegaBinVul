#include <stdint.h>
#include <string.h>

#define MAX_URL_SIZE 4096
#define AV_LOG_TRACE 56

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;
typedef struct AVDictionary AVDictionary;

struct URLContext {
    void *priv_data;
    int is_streamed;
};

struct HTTPContext {
    uint64_t chunksize;
    char line[MAX_URL_SIZE];
    int line_count;
    int seekable;
    int is_mediagateway;
    int64_t filesize;
    AVDictionary *cookie_dict;
    char *cookies;
};

static int http_get_line(HTTPContext *s, char *line, int size);
static int process_line(URLContext *h, char *line, int line_count, int *new_location);
static void cookie_string(AVDictionary *dict, char **cookies);
void av_dict_free(AVDictionary **pm);
void av_log(void *avcl, int level, const char *fmt, ...);
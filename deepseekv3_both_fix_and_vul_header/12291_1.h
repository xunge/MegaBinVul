#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#define HTTP_HEADERS_SIZE 4096
#define DEFAULT_USER_AGENT "Lavf/57.83.100"
#define HTTP_AUTH_NONE 0
#define AVIO_FLAG_WRITE 2
#define FF_API_HTTP_USER_AGENT 1
#define AV_LOG_WARNING 24
#define AV_LOG_DEBUG 48

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;

struct URLContext {
    int flags;
    void *priv_data;
};

struct HTTPContext {
    int64_t off;
    int end_off;
    int seekable;
    int multiple_requests;
    int send_expect_100;
    int http_code;
    int post_datalen;
    int chunked_post;
    int icy;
    int willclose;
    int end_chunked_post;
    int end_header;
    int64_t filesize;
    int icy_data_read;
    char *buffer;
    char *buf_ptr;
    char *buf_end;
    char *headers;
    char *post_data;
    char *method;
    char *user_agent;
    char *user_agent_deprecated;
    char *content_type;
    char *cookies;
    void *hd;
    int line_count;
    struct {
        int auth_type;
    } auth_state, proxy_auth_state;
};

char *av_strdup(const char *s);
int av_strlcpy(char *dst, const char *src, size_t size);
int av_strlcatf(char *dst, size_t size, const char *fmt, ...);
void av_freep(void *ptr);
void av_free(void *ptr);
void av_log(void *avcl, int level, const char *fmt, ...);
int ffurl_write(void *h, const unsigned char *buf, int size);
int http_read_header(URLContext *h, int *new_location);
char *ff_http_auth_create_response(void *auth_state, const char *auth, const char *path, const char *method);
int has_header(char *headers, const char *header);
int get_cookies(HTTPContext *s, char **cookies, const char *path, const char *host);
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define AVIO_FLAG_READ 1
#define AV_LOG_TRACE 56
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;
typedef struct AVDictionary AVDictionary;

struct HTTPContext {
    int end_header;
    int is_connected_server;
    char *method;
    char *resource;
    int http_code;
    uint64_t filesize;
    int seekable;
    int chunksize;
    int willclose;
    int is_akamai;
    int is_mediagateway;
    char *mime_type;
    AVDictionary *cookie_dict;
    uint64_t icy_metaint;
    void *auth_state;
    void *proxy_auth_state;
    void *priv_data;
};

struct URLContext {
    HTTPContext *priv_data;
    int flags;
    int is_streamed;
    void (*av_log)(void*, int, const char*, ...);
};

int av_isspace(int c);
int av_strcasecmp(const char *a, const char *b);
int av_strncasecmp(const char *a, const char *b, size_t n);
char *av_strdup(const char *s);
void av_free(void *ptr);
void av_log(void*, int, const char*, ...);

#define AVERROR(e) (-(e))

int ff_http_averror(int status_code, int default_code);
int check_http_code(URLContext *h, int http_code, char *end);
int parse_location(HTTPContext *s, char *p);
void parse_content_range(URLContext *h, char *p);
int parse_icy(HTTPContext *s, char *tag, char *p);
int parse_content_encoding(URLContext *h, char *p);
int parse_cookie(HTTPContext *s, char *p, AVDictionary **dict);
void ff_http_auth_handle_header(void *auth_state, const char *tag, const char *p);
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define AVIO_FLAG_READ_WRITE 2
#define AVERROR(e) (-(e))

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;

enum HTTPAuthType {
    HTTP_AUTH_NONE
};

typedef enum HTTPAuthType HTTPAuthType;

struct HTTPContext {
    int seekable;
    void *hd;
    char buffer[4096];
    char *buf_ptr;
    char *buf_end;
    int line_count;
    uint64_t filesize;
    int http_code;
    struct {
        HTTPAuthType auth_type;
        int stale;
    } proxy_auth_state;
};

struct URLContext {
    void *priv_data;
    int is_streamed;
    const char *protocol_whitelist;
    const char *protocol_blacklist;
    void *interrupt_callback;
};

int av_url_split(char *proto, int proto_len, char *authorization, int authorization_len, char *hostname, int hostname_len, int *port, char *path, int path_len, const char *url);
void ff_url_join(char *str, int size, const char *proto, const char *authorization, const char *hostname, int port, const char *path);
int ffurl_open_whitelist(void **puc, const char *filename, int flags, void *interrupt_callback, void *options, const char *whitelist, const char *blacklist, void *parent);
char *ff_http_auth_create_response(void *state, const char *auth, const char *path, const char *method);
void av_freep(void *ptr);
int ffurl_write(void *h, const unsigned char *buf, int size);
void ffurl_closep(void *h);
int http_read_header(URLContext *h, int *new_loc);
void http_proxy_close(URLContext *h);
int ff_http_averror(int status_code, int default_averror);
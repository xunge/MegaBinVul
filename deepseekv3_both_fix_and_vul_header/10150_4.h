#include <stddef.h>

typedef struct git_stream git_stream;
typedef struct git_cert git_cert;

#define GIT_STREAM_VERSION 0
#define GIT_OK 0
#define GIT_ECERTIFICATE -1
#define GITERR_NET 0

struct http_parser {
    int dummy;
};

typedef struct http_subtransport {
    int connected;
    struct http_parser parser;
    int parse_finished;
    git_stream *io;
    struct {
        int use_ssl;
        const char *host;
        const char *port;
    } connection_data;
    struct {
        struct {
            int (*certificate_check_cb)(git_cert *, int, const char *, void *);
            void *message_cb_payload;
            struct {
                int (*get_http_proxy)(void *, int, char **);
                void *owner;
            } owner;
        } *owner;
    } *owner;
} http_subtransport;

struct git_error {
    int code;
    const char *message;
};

extern struct git_error *giterr_last(void);
extern void giterr_clear(void);
extern void giterr_set(int, const char *);
extern void git__free(void *);

extern int git_stream_close(git_stream *);
extern void git_stream_free(git_stream *);
extern int git_tls_stream_new(git_stream **, const char *, const char *);
extern int git_curl_stream_new(git_stream **, const char *, const char *);
extern int git_socket_stream_new(git_stream **, const char *, const char *);
extern int git_stream_supports_proxy(git_stream *);
extern int git_stream_set_proxy(git_stream *, const char *);
extern int git_stream_connect(git_stream *);
extern int git_stream_is_encrypted(git_stream *);
extern int git_stream_certificate(git_cert **, git_stream *);
extern int http_should_keep_alive(struct http_parser *);
extern int git_remote__get_http_proxy(void *, int, char **);

#define GITERR_CHECK_VERSION(stream, version, name) (0)
#include <stddef.h>

#define APR_EINVAL 1
#define APR_ECONNRESET 2
#define APLOG_MARK 0,0,0,0
#define APLOG_TRACE1 0

typedef int apr_status_t;

enum {
    HTTP_REQUEST_URI_TOO_LARGE,
    HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE
};

enum h2_stream_state {
    H2_STREAM_ST_OPEN
};

struct h2_session {
    long id;
    void *c;
    struct {
        int limit_req_line;
        int limit_req_fieldsize;
        int limit_req_fields;
    } *s;
};

struct h2_stream {
    int id;
    int has_response;
    int request_headers_added;
    struct h2_session *session;
    void *rtmp;
    void *pool;
    enum h2_stream_state state;
};

apr_status_t h2_stream_set_error(struct h2_stream *stream, int error);
apr_status_t h2_req_create(int id, void *pool, void *a, void *b, void *c, void *d, void *e, int f);
apr_status_t h2_request_add_header(void *req, void *pool, const char *name, size_t nlen, const char *value, size_t vlen);
int h2_stream_is_scheduled(struct h2_stream *stream);
apr_status_t add_trailer(struct h2_stream *stream, const char *name, size_t nlen, const char *value, size_t vlen);
void ap_log_cerror(int a, int b, int c, void *d, const char *e, ...);
void ap_assert(void *p);

typedef struct h2_stream h2_stream;
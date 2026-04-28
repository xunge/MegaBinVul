#include <stdint.h>
#include <stddef.h>

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_frame nghttp2_frame;
typedef struct h2_session h2_session;
typedef struct h2_stream h2_stream;
typedef int apr_status_t;

struct nghttp2_frame {
    struct {
        int stream_id;
    } hd;
};

struct h2_session {
    long id;
    void *c;
};

struct h2_stream {
    int id;
};

#define NGHTTP2_ERR_TEMPORAL_CALLBACK_FAILURE -902
#define NGHTTP2_FLAG_NONE 0
#define NGHTTP2_INTERNAL_ERROR 0x02
#define APR_SUCCESS 0
#define APR_ECONNRESET 0

extern h2_stream *get_stream(h2_session *session, int stream_id);
extern apr_status_t h2_stream_add_header(h2_stream *stream, const char *name, size_t namelen, const char *value, size_t valuelen);
extern int h2_stream_is_ready(h2_stream *stream);
extern void ap_log_cerror(const char *file, int line, int level, apr_status_t status, void *c, const char *fmt, ...);
extern int nghttp2_submit_rst_stream(nghttp2_session *session, uint8_t flags, int stream_id, uint32_t error_code);

#define APLOG_MARK __FILE__, __LINE__
#define APLOG_DEBUG 0
#define APLOG_ERR 0
#define APLOG_TRACE1 0
#define APLOGNO(n) ""
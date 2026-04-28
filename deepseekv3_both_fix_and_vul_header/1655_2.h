#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_frame {
    struct {
        int type;
        int stream_id;
        int flags;
    } hd;
    struct {
        int cat;
    } headers;
} nghttp2_frame;

typedef struct nghttp2_nv {
    const char *name;
    const char *value;
} nghttp2_nv;

typedef struct ogs_sbi_session_s {
    struct ogs_sbi_server_s *server;
    struct {
        int max_concurrent_streams;
        int enable_push;
    } settings;
    int last_stream_id;
} ogs_sbi_session_t;

typedef struct ogs_sbi_server_s {
    int (*cb)(void *, void *);
} ogs_sbi_server_t;

typedef struct ogs_sbi_stream_s {
    int stream_id;
    struct ogs_sbi_request_s *request;
    bool memory_overflow;
} ogs_sbi_stream_t;

typedef struct ogs_sbi_request_s {
    struct {
        const char *method;
        const char *uri;
    } h;
    struct {
        void *headers;
        size_t content_length;
        char *content;
    } http;
} ogs_sbi_request_t;

typedef enum {
    OGS_LOG_DEBUG,
    OGS_LOG_ERROR
} ogs_log_level_e;

#define NGHTTP2_SETTINGS 0x4
#define NGHTTP2_GOAWAY 0x7
#define NGHTTP2_HEADERS 0x1
#define NGHTTP2_DATA 0x0
#define NGHTTP2_HCAT_REQUEST 0
#define NGHTTP2_FLAG_NONE 0
#define NGHTTP2_FLAG_END_STREAM 0x1
#define NGHTTP2_SETTINGS_MAX_CONCURRENT_STREAMS 0x3
#define NGHTTP2_SETTINGS_ENABLE_PUSH 0x2
#define NGHTTP2_NO_ERROR 0
#define OGS_SBI_EXPECT "Expect"
#define OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR 500

#define OGS_ERROR -1
#define OGS_OK 0
#define OGS_GNUC_FALLTHROUGH
#define ogs_assert(expr)
#define ogs_debug(...)
#define ogs_error(...)
#define ogs_warn(...)
#define ogs_strcasecmp strcasecmp

extern int session_send(ogs_sbi_session_t *sbi_sess);
extern const char *ogs_sbi_header_get(void *headers, const char *key);
extern bool ogs_sbi_server_send_error(ogs_sbi_stream_t *stream, int status, void *param1, const char *param2, void *param3);
extern void *nghttp2_session_get_stream_user_data(nghttp2_session *session, int stream_id);
extern int nghttp2_session_get_remote_settings(nghttp2_session *session, int id);
extern int nghttp2_submit_goaway(nghttp2_session *session, int flags, int last_stream_id, int error_code, void *opaque_data, size_t opaque_len);
extern int nghttp2_submit_headers(nghttp2_session *session, int flags, int stream_id, void *pri_spec, nghttp2_nv *nva, size_t nvlen, void *stream_user_data);
extern int nghttp2_submit_rst_stream(nghttp2_session *session, int flags, int stream_id, int error_code);
extern const char *nghttp2_strerror(int error_code);
extern void ogs_log_message(ogs_log_level_e level, int dummy, const char *fmt, ...);

static const char *status_string[] = {
    [100] = "100"
};

static void add_header(nghttp2_nv *nva, const char *name, const char *value) {
    nva->name = name;
    nva->value = value;
}
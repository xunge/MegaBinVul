#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nghttp2_session nghttp2_session;

typedef struct {
    char *content;
    size_t content_length;
} http_t;

typedef struct {
    http_t http;
} ogs_sbi_request_t;

typedef struct {
    ogs_sbi_request_t *request;
    bool memory_overflow;
} ogs_sbi_stream_t;

void *nghttp2_session_get_stream_user_data(nghttp2_session *session, int32_t stream_id);

#define ogs_assert(expr) ((void)0)
#define ogs_error(fmt, ...) ((void)0)
#define ogs_log_hexdump(level, data, len) ((void)0)
#define OGS_LOG_ERROR 0
#define OGS_HUGE_LEN (1024 * 1024)
#define ogs_malloc(size) malloc(size)
#define ogs_realloc(ptr, size) realloc(ptr, size)
#define ogs_assert_if_reached() ((void)0)
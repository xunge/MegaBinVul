#include <sys/types.h>
#include <stddef.h>

typedef struct ngx_event_s {
    void *data;
    unsigned timedout:1;
    unsigned ready:1;
} ngx_event_t;

typedef struct ngx_connection_s {
    void *data;
    void *log;
    unsigned close:1;
    unsigned error:1;
    ssize_t (*recv)(struct ngx_connection_s *c, u_char *buf, size_t size);
} ngx_connection_t;

typedef struct ngx_http_connection_s {
    void *conf_ctx;
} ngx_http_connection_t;

typedef struct ngx_http_v2_state_s {
    u_char *buffer;
    size_t buffer_used;
    unsigned incomplete:1;
    u_char *(*handler)(void *h2c, u_char *pos, u_char *end);
} ngx_http_v2_state_t;

typedef struct ngx_http_v2_connection_s {
    void *data;
    ngx_http_connection_t *http_connection;
    unsigned blocked:1;
    unsigned new_streams:1;
    unsigned processing:1;
    unsigned pushing:1;
    unsigned goaway:1;
    ngx_http_v2_state_t state;
    size_t total_bytes;
    size_t payload_bytes;
    unsigned last_out:1;
} ngx_http_v2_connection_t;

typedef struct ngx_http_v2_main_conf_s {
    size_t recv_buffer_size;
    u_char *recv_buffer;
} ngx_http_v2_main_conf_t;

#define NGX_LOG_INFO 0
#define NGX_LOG_DEBUG_HTTP 0
#define NGX_ETIMEDOUT 0
#define NGX_HTTP_V2_PROTOCOL_ERROR 0
#define NGX_HTTP_V2_NO_ERROR 0
#define NGX_HTTP_V2_INTERNAL_ERROR 0
#define NGX_AGAIN 0
#define NGX_ERROR -1
#define NGX_OK 0
#define NGX_HTTP_V2_STATE_BUFFER_SIZE 0

typedef unsigned char u_char;

extern void *ngx_http_v2_module;

void ngx_log_error(int level, void *log, int err, const char *fmt, ...);
void ngx_log_debug0(int level, void *log, int err, const char *fmt);
void ngx_http_v2_finalize_connection(ngx_http_v2_connection_t *h2c, int error);
int ngx_http_v2_send_goaway(ngx_http_v2_connection_t *h2c, int error);
int ngx_http_v2_send_output_queue(ngx_http_v2_connection_t *h2c);
ngx_http_v2_main_conf_t *ngx_http_get_module_main_conf(void *conf_ctx, void *module);
void ngx_memcpy(void *dst, const void *src, size_t n);
int ngx_handle_read_event(ngx_event_t *rev, int flags);
void ngx_http_v2_handle_connection(ngx_http_v2_connection_t *h2c);
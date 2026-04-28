#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef unsigned char u_char;
typedef unsigned int ngx_uint_t;
typedef size_t ngx_str_t;

typedef struct {
    ngx_uint_t flags;
    size_t length;
    ngx_uint_t sid;
    size_t padding;
    void *pool;
    int keep_pool;
    void *stream;
    size_t header_limit;
} ngx_http_v2_state_t;

typedef struct {
    void *log;
    ngx_uint_t requests;
    ngx_uint_t start_time;
} ngx_connection_t;

typedef struct {
    void *conf_ctx;
} ngx_http_connection_t;

typedef struct {
    ngx_http_v2_state_t state;
    ngx_connection_t *connection;
    ngx_http_connection_t *http_connection;
    ngx_uint_t last_sid;
    ngx_uint_t processing;
    ngx_uint_t new_streams;
    ngx_uint_t refused_streams;
    ngx_uint_t goaway;
    ngx_uint_t settings_ack;
    ngx_uint_t closed_nodes;
} ngx_http_v2_connection_t;

typedef struct {
    size_t request_length;
} ngx_http_request_t;

typedef struct {
    ngx_http_request_t *request;
    void *node;
    void *pool;
    ngx_uint_t in_closed;
} ngx_http_v2_stream_t;

typedef struct {
    void *stream;
    void *parent;
    ngx_uint_t weight;
    void *reuse;
} ngx_http_v2_node_t;

typedef struct {
    size_t size;
    ngx_uint_t num;
} ngx_http_v2_buffers_t;

typedef struct {
    ngx_http_v2_buffers_t large_client_header_buffers;
} ngx_http_core_srv_conf_t;

typedef struct {
    ngx_uint_t concurrent_streams;
    ngx_uint_t preread_size;
} ngx_http_v2_srv_conf_t;

typedef struct {
    ngx_uint_t keepalive_timeout;
    ngx_uint_t keepalive_requests;
    ngx_uint_t keepalive_time;
} ngx_http_core_loc_conf_t;

extern void *ngx_http_core_module;
extern void *ngx_http_v2_module;

#define NGX_HTTP_V2_PADDED_FLAG      0x08
#define NGX_HTTP_V2_PRIORITY_FLAG    0x20
#define NGX_HTTP_V2_END_STREAM_FLAG  0x01
#define NGX_HTTP_V2_DEFAULT_WEIGHT   16
#define NGX_HTTP_V2_DEFAULT_WINDOW   65535
#define NGX_HTTP_V2_SIZE_ERROR       0x01
#define NGX_HTTP_V2_PROTOCOL_ERROR   0x02
#define NGX_HTTP_V2_INTERNAL_ERROR   0x03
#define NGX_HTTP_V2_REFUSED_STREAM   0x07
#define NGX_HTTP_V2_NO_ERROR         0x00

#define NGX_LOG_DEBUG_HTTP  0
#define NGX_LOG_INFO        0
#define NGX_LOG_DEBUG       0
#define NGX_OK              0
#define NGX_ERROR          -1

extern void ngx_log_error(ngx_uint_t level, void *log, ngx_uint_t err, const char *fmt, ...);
extern void ngx_log_debug0(ngx_uint_t level, void *log, ngx_uint_t err, const char *fmt);
extern void ngx_log_debug4(ngx_uint_t level, void *log, ngx_uint_t err, const char *fmt, ...);
extern ngx_http_v2_node_t *ngx_http_v2_get_node_by_id(ngx_http_v2_connection_t *h2c, ngx_uint_t sid, int create);
extern ngx_http_v2_stream_t *ngx_http_v2_create_stream(ngx_http_v2_connection_t *h2c, int flag);
extern void ngx_http_v2_set_dependency(ngx_http_v2_connection_t *h2c, ngx_http_v2_node_t *node, ngx_uint_t depend, ngx_uint_t excl);
extern u_char *ngx_http_v2_connection_error(ngx_http_v2_connection_t *h2c, ngx_uint_t err);
extern u_char *ngx_http_v2_state_skip(ngx_http_v2_connection_t *h2c, u_char *pos, u_char *end);
extern u_char *ngx_http_v2_state_save(ngx_http_v2_connection_t *h2c, u_char *pos, u_char *end, void *handler);
extern u_char *ngx_http_v2_state_header_block(ngx_http_v2_connection_t *h2c, u_char *pos, u_char *end);
extern ngx_uint_t ngx_http_v2_parse_uint32(u_char *pos);
extern void *ngx_create_pool(size_t size, void *log);
extern void *ngx_http_get_module_srv_conf(void *conf_ctx, void *module);
extern void *ngx_http_get_module_loc_conf(void *conf_ctx, void *module);
extern ngx_uint_t ngx_http_v2_send_goaway(ngx_http_v2_connection_t *h2c, ngx_uint_t status);
extern ngx_uint_t ngx_http_v2_send_rst_stream(ngx_http_v2_connection_t *h2c, ngx_uint_t sid, ngx_uint_t status);
extern ngx_uint_t ngx_max(ngx_uint_t a, ngx_uint_t b);
extern ngx_uint_t ngx_current_msec;
extern void ngx_queue_remove(void *queue);
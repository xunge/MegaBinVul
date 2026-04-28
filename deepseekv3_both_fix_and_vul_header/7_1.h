#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef struct h2o_iovec_t {
    char *base;
    size_t len;
} h2o_iovec_t;

typedef struct h2o_buffer_t {
    size_t size;
    uint8_t *bytes;
} h2o_buffer_t;

typedef struct h2o_socket_t {
    h2o_buffer_t *input;
} h2o_socket_t;

typedef struct h2o_http2_streams_t {
    size_t half_closed;
} h2o_http2_streams_t;

typedef struct h2o_http2_num_streams_t {
    h2o_http2_streams_t pull;
    h2o_http2_streams_t push;
} h2o_http2_num_streams_t;

typedef struct h2o_http2_settings_t {
    size_t max_concurrent_requests_per_connection;
} h2o_http2_settings_t;

typedef struct h2o_globalconf_t {
    h2o_http2_settings_t http2;
} h2o_globalconf_t;

typedef struct h2o_context_t {
    h2o_globalconf_t *globalconf;
} h2o_context_t;

typedef struct h2o_conn_t {
    h2o_context_t *ctx;
} h2o_conn_t;

enum {
    H2O_HTTP2_CONN_STATE_IS_CLOSING,
    H2O_HTTP2_ERROR_INCOMPLETE,
    H2O_HTTP2_ERROR_PROTOCOL_CLOSE_IMMEDIATELY
};

typedef struct h2o_http2_conn_t {
    h2o_conn_t super;
    h2o_http2_num_streams_t num_streams;
    h2o_socket_t *sock;
    int state;
    ssize_t (*_read_expect)(struct h2o_http2_conn_t *, uint8_t *, size_t, const char **);
} h2o_http2_conn_t;

void enqueue_goaway(h2o_http2_conn_t *conn, int err, h2o_iovec_t desc);
int close_connection(h2o_http2_conn_t *conn);
void h2o_buffer_consume(h2o_buffer_t **buf, size_t bytes);
int h2o_socket_is_reading(h2o_socket_t *sock);
void h2o_socket_read_start(h2o_socket_t *sock, void (*cb)(void));
void h2o_socket_read_stop(h2o_socket_t *sock);
void on_read(void);
#include <stddef.h>

typedef struct h2o_timeout_entry_t {
    // minimal definition to make it complete type
    void *data;
} h2o_timeout_entry_t;

typedef struct h2o_http2_conn_t {
    int state;
    struct {
        void *buf_in_flight;
        h2o_timeout_entry_t timeout_entry;
    } _write;
} h2o_http2_conn_t;

#define H2O_HTTP2_CONN_STATE_IS_CLOSING 0

int h2o_timeout_is_linked(h2o_timeout_entry_t *entry);
void close_connection_now(h2o_http2_conn_t *conn);
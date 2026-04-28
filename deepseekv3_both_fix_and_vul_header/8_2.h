#include <stddef.h>

typedef struct h2o_socket_t h2o_socket_t;
typedef struct h2o_http2_conn_t h2o_http2_conn_t;

struct h2o_timeout_entry {
    struct h2o_timeout_entry *prev;
    struct h2o_timeout_entry *next;
};
typedef struct h2o_timeout_entry h2o_timeout_entry_t;

struct h2o_http2_conn_t {
    h2o_socket_t *sock;
    struct {
        h2o_timeout_entry_t timeout_entry;
    } _write;
    void *data;
};

struct h2o_socket_t {
    h2o_http2_conn_t *data;
};

void h2o_socket_read_stop(h2o_socket_t *sock);
void close_connection(h2o_http2_conn_t *conn);
void update_idle_timeout(h2o_http2_conn_t *conn);
int parse_input(h2o_http2_conn_t *conn);
int h2o_timeout_is_linked(h2o_timeout_entry_t *entry);
void h2o_timeout_unlink(h2o_timeout_entry_t *entry);
void do_emit_writereq(h2o_http2_conn_t *conn);
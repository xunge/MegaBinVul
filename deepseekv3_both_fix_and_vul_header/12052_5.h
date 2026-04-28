#include <assert.h>
#include <stddef.h>
#include <stdint.h>

typedef struct h2o_http2_conn_t h2o_http2_conn_t;
typedef struct h2o_http2_stream_t h2o_http2_stream_t;
typedef struct kh_h2o_http2_stream_t kh_h2o_http2_stream_t;
typedef struct h2o_linklist_t h2o_linklist_t;
typedef unsigned int khiter_t;

struct h2o_linklist_t {
    struct h2o_linklist_t *next;
    struct h2o_linklist_t *prev;
};

struct h2o_http2_req_t {
    int state;
    void *proceed_req;
};

struct h2o_http2_req_body_t {
    int state;
};

struct h2o_http2_dos_mitigation_t {
    int reset_budget;
};

struct h2o_http2_config_t {
    int max_concurrent_requests_per_connection;
};

struct h2o_globalconf_t {
    struct h2o_http2_config_t http2;
};

struct h2o_context_t {
    struct h2o_globalconf_t *globalconf;
};

struct h2o_http2_conn_t {
    struct {
        struct h2o_context_t *ctx;
    } super;
    struct h2o_http2_dos_mitigation_t dos_mitigation;
    struct kh_h2o_http2_stream_t *streams;
    int state;
};

struct h2o_http2_stream_t {
    uint32_t stream_id;
    struct h2o_http2_req_t req;
    struct h2o_http2_req_body_t req_body;
    int blocked_by_server;
    int reset_by_peer;
    int state;
    struct h2o_linklist_t _link;
};

enum {
    H2O_HTTP2_REQ_BODY_NONE,
    H2O_HTTP2_REQ_BODY_CLOSE_DELIVERED
};

enum {
    H2O_HTTP2_STREAM_STATE_RECV_BODY,
    H2O_HTTP2_STREAM_STATE_IDLE,
    H2O_HTTP2_STREAM_STATE_RECV_HEADERS,
    H2O_HTTP2_STREAM_STATE_REQ_PENDING,
    H2O_HTTP2_STREAM_STATE_SEND_HEADERS,
    H2O_HTTP2_STREAM_STATE_SEND_BODY,
    H2O_HTTP2_STREAM_STATE_SEND_BODY_IS_FINAL,
    H2O_HTTP2_STREAM_STATE_END_STREAM
};

enum {
    H2O_HTTP2_CONN_STATE_IS_CLOSING
};

void h2o_http2_conn_preserve_stream_scheduler(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream);
void set_req_body_state(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream, int state);
void h2o_http2_stream_set_blocked_by_server(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream, int blocked);
void h2o_http2_stream_set_state(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream, int state);
void run_pending_requests(h2o_http2_conn_t *conn);
void update_idle_timeout(h2o_http2_conn_t *conn);
khiter_t kh_get_stream(struct kh_h2o_http2_stream_t *map, uint32_t id);
int kh_end(struct kh_h2o_http2_stream_t *map);
void kh_del_stream(struct kh_h2o_http2_stream_t *map, khiter_t iter);
int h2o_linklist_is_linked(struct h2o_linklist_t *list);
void h2o_linklist_unlink(struct h2o_linklist_t *list);

#define kh_get(h2o_http2_stream_t, map, key) kh_get_stream(map, key)
#define kh_del(h2o_http2_stream_t, map, iter) kh_del_stream(map, iter)
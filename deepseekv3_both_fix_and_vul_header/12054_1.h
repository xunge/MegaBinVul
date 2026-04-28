#include <stddef.h>

typedef struct h2o_http2_conn_t h2o_http2_conn_t;
typedef struct h2o_http2_stream_t h2o_http2_stream_t;
typedef struct h2o_linklist_t h2o_linklist_t;
typedef struct h2o_timer_t h2o_timer_t;

struct h2o_linklist_t {
    h2o_linklist_t *next;
};

struct h2o_timer_t {
    h2o_linklist_t process_delay;
};

struct h2o_http2_conn_t {
    struct {
        h2o_timer_t process_delay;
    } dos_mitigation;
    h2o_linklist_t _pending_reqs;
    struct {
        int _req_streaming_in_progress;
        int tunnel;
    } num_streams;
    struct {
        struct {
            struct {
                struct {
                    int max_concurrent_streaming_requests_per_connection;
                } http2;
            } *globalconf;
        } *ctx;
    } super;
};

struct h2o_http2_stream_t {
    h2o_linklist_t _link;
    struct {
        void *proceed_req;
    } req;
};

int h2o_timer_is_linked(h2o_timer_t *timer);
int can_run_requests(h2o_http2_conn_t *conn);
void process_request(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream);
int h2o_linklist_is_empty(h2o_linklist_t *list);
void h2o_linklist_unlink(h2o_linklist_t *link);

#define H2O_STRUCT_FROM_MEMBER(type, member, ptr) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
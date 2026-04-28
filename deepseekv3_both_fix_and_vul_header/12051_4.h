#include <stdint.h>
#include <stddef.h>

typedef struct st_h2o_timer_t st_h2o_timer_t;
struct st_h2o_timer_t {
    st_h2o_timer_t *prev;
    st_h2o_timer_t *next;
    void (*cb)(st_h2o_timer_t *timer);
};

typedef struct st_h2o_http2_conn_t {
    struct {
        struct {
            void* loop;
            struct {
                struct {
                    unsigned dos_delay;
                } http2;
            }* globalconf;
        }* ctx;
    } super;
    struct {
        unsigned reset_budget;
        st_h2o_timer_t process_delay;
    } dos_mitigation;
} h2o_http2_conn_t;

typedef struct st_h2o_http2_frame_t {
    uint32_t stream_id;
    uint8_t *payload;
    size_t length;
} h2o_http2_frame_t;

typedef struct st_h2o_http2_rst_stream_payload_t {
    uint32_t error_code;
} h2o_http2_rst_stream_payload_t;

typedef struct st_h2o_http2_stream_t {
    int reset_by_peer;
    uint32_t stream_id;
    h2o_http2_conn_t *conn;
} h2o_http2_stream_t;

#define H2O_HTTP2_ERROR_PROTOCOL 1

static int is_idle_stream_id(h2o_http2_conn_t *conn, uint32_t stream_id);
static int h2o_http2_decode_rst_stream_payload(h2o_http2_rst_stream_payload_t *payload, h2o_http2_frame_t *frame, const char **err_desc);
static h2o_http2_stream_t *h2o_http2_conn_get_stream(h2o_http2_conn_t *conn, uint32_t stream_id);
static void h2o_http2_stream_reset(h2o_http2_conn_t *conn, h2o_http2_stream_t *stream);
static int h2o_timer_is_linked(st_h2o_timer_t *timer);
static void h2o_timer_link(void *loop, unsigned delay, st_h2o_timer_t *timer);
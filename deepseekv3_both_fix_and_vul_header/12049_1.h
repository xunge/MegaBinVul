#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef struct st_h2o_globalconf_t h2o_globalconf_t;
typedef struct st_h2o_hostconf_t h2o_hostconf_t;

struct st_h2o_linklist_t {
    struct st_h2o_linklist_t *next;
    struct st_h2o_linklist_t *prev;
};

struct st_h2o_iovec_t {
    char *base;
    size_t len;
};

struct st_h2o_mimemap_t {
    void *dummy;
};

struct st_h2o_socketpool_t {
    void *dummy;
};

struct st_quicly_spec_context_t {
    struct {
        unsigned max_idle_timeout;
    } transport_params;
} quicly_spec_context;

struct st_h2o_hostconf_t {
    struct {
        unsigned port;
        char *host;
        char *hostport;
    } authority;
};

struct st_h2o_globalconf_t {
    h2o_hostconf_t **hosts;
    struct st_h2o_linklist_t configurators;
    struct st_h2o_iovec_t server_name;
    size_t max_request_entity_size;
    size_t max_delegations;
    size_t max_reprocesses;
    unsigned handshake_timeout;
    struct {
        unsigned req_timeout;
        unsigned req_io_timeout;
        int upgrade_to_http2;
    } http1;
    struct {
        unsigned idle_timeout;
        unsigned graceful_shutdown_timeout;
        size_t max_concurrent_requests_per_connection;
        size_t max_concurrent_streaming_requests_per_connection;
        size_t max_streams_for_priority;
        size_t active_stream_window_size;
        struct {
            unsigned min_rtt;
            unsigned max_additional_delay;
            unsigned max_cwnd;
        } latency_optimization;
        unsigned dos_delay;
    } http2;
    struct {
        unsigned io_timeout;
        unsigned connect_timeout;
        unsigned first_byte_timeout;
        int emit_x_forwarded_headers;
        int emit_via_header;
        int emit_missing_date_header;
        int zerocopy;
        struct st_h2o_socketpool_t global_socketpool;
    } proxy;
    struct {
        unsigned idle_timeout;
        size_t active_stream_window_size;
        int allow_delayed_ack;
        int use_gso;
    } http3;
    int send_informational_mode;
    struct st_h2o_mimemap_t *mimemap;
    struct st_h2o_hostconf_t *fallback_host;
};

#define H2O_STRLIT(s) (s), sizeof(s) - 1
#define H2O_VERSION "1.0.0"
#define H2O_DEFAULT_MAX_REQUEST_ENTITY_SIZE (1024 * 1024 * 1024)
#define H2O_DEFAULT_MAX_DELEGATIONS 10
#define H2O_DEFAULT_MAX_REPROCESSES 10
#define H2O_DEFAULT_HANDSHAKE_TIMEOUT 10000
#define H2O_DEFAULT_HTTP1_REQ_TIMEOUT 10000
#define H2O_DEFAULT_HTTP1_REQ_IO_TIMEOUT 30000
#define H2O_DEFAULT_HTTP1_UPGRADE_TO_HTTP2 1
#define H2O_DEFAULT_HTTP2_IDLE_TIMEOUT 10000
#define H2O_DEFAULT_HTTP2_GRACEFUL_SHUTDOWN_TIMEOUT 0
#define H2O_DEFAULT_PROXY_IO_TIMEOUT 30000
#define H2O_PROXY_ZEROCOPY_ENABLED 1
#define H2O_HTTP2_SETTINGS_HOST_MAX_CONCURRENT_STREAMS 100
#define H2O_HTTP2_SETTINGS_HOST_MAX_CONCURRENT_STREAMING_REQUESTS 10
#define H2O_DEFAULT_HTTP2_ACTIVE_STREAM_WINDOW_SIZE (65535 * 1024)
#define H2O_DEFAULT_HTTP3_ACTIVE_STREAM_WINDOW_SIZE (65535 * 1024)
#define H2O_SEND_INFORMATIONAL_MODE_EXCEPT_H1 1

void *h2o_mem_alloc(size_t size);
void h2o_linklist_init_anchor(struct st_h2o_linklist_t *anchor);
struct st_h2o_iovec_t h2o_iovec_init(const char *base, size_t len);
struct st_h2o_mimemap_t *h2o_mimemap_create(void);
void h2o_socketpool_init_global(struct st_h2o_socketpool_t *pool, size_t capacity);
void h2o_configurator__init_core(struct st_h2o_globalconf_t *config);
struct st_h2o_hostconf_t *create_hostconf(struct st_h2o_globalconf_t *config);
char *h2o_strdup(void *pool, const char *s, size_t len);
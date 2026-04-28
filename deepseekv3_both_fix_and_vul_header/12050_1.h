#include <stddef.h>

typedef struct h2o_globalconf_t h2o_globalconf_t;
typedef struct h2o_configurator_t h2o_configurator_t;
typedef struct h2o_configurator_context_t h2o_configurator_context_t;
typedef struct h2o_configurator_command_t h2o_configurator_command_t;
typedef struct yoml_t yoml_t;

struct h2o_configurator_t {
    void (*enter)(h2o_configurator_t *configurator, h2o_configurator_context_t *ctx);
    void (*exit)(h2o_configurator_t *configurator, h2o_configurator_context_t *ctx);
};

struct st_core_configurator_t {
    h2o_configurator_t super;
    struct {
        struct {
            int reprioritize_blocking_assets;
            int push_preload;
        } http2;
        struct {
            int emit_request_errors;
        } error_log;
    } *vars;
    struct {
        struct {
            int reprioritize_blocking_assets;
            int push_preload;
        } http2;
        struct {
            int emit_request_errors;
        } error_log;
    } _vars_stack[1];
};

#define H2O_CONFIGURATOR_FLAG_GLOBAL 0x1
#define H2O_CONFIGURATOR_FLAG_HOST 0x2
#define H2O_CONFIGURATOR_FLAG_PATH 0x4
#define H2O_CONFIGURATOR_FLAG_EXTENSION 0x8
#define H2O_CONFIGURATOR_FLAG_EXPECT_MAPPING 0x10
#define H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR 0x20
#define H2O_CONFIGURATOR_FLAG_EXPECT_SEQUENCE 0x40
#define H2O_CONFIGURATOR_FLAG_DEFERRED 0x80
#define H2O_CONFIGURATOR_FLAG_SEMI_DEFERRED 0x100
#define H2O_CONFIGURATOR_FLAG_ALL_LEVELS (H2O_CONFIGURATOR_FLAG_GLOBAL | H2O_CONFIGURATOR_FLAG_HOST | H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_EXTENSION)

h2o_configurator_t *h2o_configurator_create(h2o_globalconf_t *conf, size_t sz);
h2o_configurator_command_t *h2o_configurator_get_command(h2o_globalconf_t *conf, const char *name);
void h2o_configurator_define_command(h2o_configurator_t *configurator, const char *name, int flags, int (*cb)(h2o_configurator_command_t *, h2o_configurator_context_t *, yoml_t *));

int on_config_hosts(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_paths(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_strict_match(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_core_enter(h2o_configurator_t *configurator, h2o_configurator_context_t *ctx);
int on_core_exit(h2o_configurator_t *configurator, h2o_configurator_context_t *ctx);
int on_config_limit_request_body(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_max_delegations(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_max_reprocesses(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_handshake_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http1_request_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http1_request_io_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http1_upgrade_to_http2(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_idle_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_graceful_shutdown_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_max_concurrent_requests_per_connection(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_max_concurrent_streaming_requests_per_connection(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_input_window_size(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_latency_optimization_min_rtt(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_latency_optimization_max_additional_delay(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_latency_optimization_max_cwnd(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_reprioritize_blocking_assets(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_push_preload(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_allow_cross_origin_push(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_casper(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http2_dos_delay(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_idle_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_graceful_shutdown_timeout(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_input_window_size(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_ack_frequency(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_allow_delayed_ack(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_http3_gso(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_mime_settypes(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_mime_addtypes(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_mime_removetypes(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_mime_setdefaulttype(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_custom_handler(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_setenv(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_unsetenv(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_server_name(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_send_server_name(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_error_log_emit_request_errors(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_send_informational(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_stash(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
int on_config_usdt_selective_tracing(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node);
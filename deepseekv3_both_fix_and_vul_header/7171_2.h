#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>

#define TTYD_VERSION "1.0.0"
#define LWS_LIBRARY_VERSION "4.0.0"

#define LWS_SERVER_OPTION_LIBUV 0
#define LWS_SERVER_OPTION_VALIDATE_UTF8 0
#define LWS_SERVER_OPTION_DISABLE_IPV6 0
#define LWS_SERVER_OPTION_UNIX_SOCK 0
#define LWS_SERVER_OPTION_REQUIRE_VALID_OPENSSL_CLIENT_CERT 0
#define LWS_SERVER_OPTION_ALLOW_NON_SSL_ON_SSL_PORT 0
#define LWS_SERVER_OPTION_REDIRECT_HTTP_TO_HTTPS 0
#define LWS_SERVER_OPTION_EXPLICIT_VHOSTS 0

#define LLL_ERR 0
#define LLL_WARN 0
#define LLL_NOTICE 0

struct json_object {
    // Minimal stub for json_object
};

struct uv_signal_s {
    // Minimal stub for uv_signal_t
    void* data;
    int signum;
    void* loop;
    void* close_cb;
    void* signal_cb;
};
typedef struct uv_signal_s uv_signal_t;

struct server {
    char *command;
    bool url_arg;
    bool readonly;
    bool check_origin;
    int max_clients;
    bool once;
    char *cwd;
    char *index;
    char *credential;
    char *auth_header;
    char *prefs_json;
    char terminal_type[32];
    char socket_path[128];
    int sig_code;
    char sig_name[32];
    void *loop;
};

struct lws_retry {
    int secs_since_valid_ping;
    int secs_since_valid_hangup;
};

struct lws_protocols {
    const char *name;
    void *callback;
    int per_session_data_size;
    int rx_buffer_size;
    unsigned int id;
    void *user;
};

struct lws_extension {
    const char *name;
    void *callback;
    int client_offer;
    void *user;
};

struct lws_context_creation_info {
    int port;
    const char *iface;
    struct lws_protocols *protocols;
    int gid;
    int uid;
    int max_http_header_pool;
    unsigned int options;
    struct lws_extension *extensions;
    int max_http_header_data;
    const char *server_string;
    void *foreign_loops;
    const char *unix_socket_perms;
    const char *ssl_cert_filepath;
    const char *ssl_private_key_filepath;
    const char *ssl_ca_filepath;
    unsigned int ssl_options_set;
    struct lws_retry *retry_and_idle_policy;
    int ws_ping_pong_interval;
};

struct lws_context;
struct lws_vhost;

struct lws_retry retry;
struct lws_protocols protocols[] = {0};
struct lws_extension extensions[] = {0};
struct lws_context *context;
struct server *server;

struct option options[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {"debug", required_argument, 0, 'd'},
    {"url-arg", no_argument, 0, 'a'},
    {"readonly", no_argument, 0, 'R'},
    {"check-origin", no_argument, 0, 'O'},
    {"max-clients", required_argument, 0, 'm'},
    {"once", no_argument, 0, 'o'},
    {"browser", no_argument, 0, 'B'},
    {"port", required_argument, 0, 'p'},
    {"interface", required_argument, 0, 'i'},
    {"socket-owner", required_argument, 0, 'U'},
    {"credential", required_argument, 0, 'c'},
    {"auth-header", required_argument, 0, 'H'},
    {"uid", required_argument, 0, 'u'},
    {"gid", required_argument, 0, 'g'},
    {"signal", required_argument, 0, 's'},
    {"working-dir", required_argument, 0, 'w'},
    {"index", required_argument, 0, 'I'},
    {"base-path", required_argument, 0, 'b'},
    {"ping-interval", required_argument, 0, 'P'},
    {"ipv6", no_argument, 0, '6'},
    {"ssl", no_argument, 0, 'S'},
    {"ssl-cert", required_argument, 0, 'C'},
    {"ssl-key", required_argument, 0, 'K'},
    {"ssl-ca", required_argument, 0, 'A'},
    {"terminal-type", required_argument, 0, 'T'},
    {"client-option", required_argument, 0, 't'},
    {0, 0, 0, 0}
};

const char *opt_string = "hvd:aROm:oBp:i:U:c:H:u:g:s:w:I:b:P:6SC:K:A:T:t:";

struct {
    char *ws;
    char *index;
    char *token;
    char *parent;
} endpoints;

struct json_object *json_object_new_object(void);
struct json_object *json_object_new_string(const char *s);
struct json_object *json_object_new_boolean(int b);
void json_object_object_add(struct json_object *obj, const char *key, struct json_object *val);
struct json_object *json_tokener_parse(const char *str);
const char *json_object_to_json_string(struct json_object *obj);
void json_object_put(struct json_object *obj);

struct lws_context *lws_create_context(struct lws_context_creation_info *info);
struct lws_vhost *lws_create_vhost(struct lws_context *context, struct lws_context_creation_info *info);
int lws_get_vhost_listen_port(struct lws_vhost *vhost);
void lws_context_destroy(struct lws_context *context);
void lws_set_log_level(int level, void *log_func);
void lws_service(struct lws_context *context, int timeout_ms);
void lwsl_notice(const char *format, ...);
void lwsl_err(const char *format, ...);
int lws_b64_encode_string(const char *in, int in_len, char *out, int out_size);

void uv_signal_init(void *loop, uv_signal_t *handle);
void uv_signal_start(uv_signal_t *handle, void (*signal_cb)(uv_signal_t *handle, int signum), int signum);
void uv_signal_stop(uv_signal_t *handle);

void print_help();
int calc_command_start(int argc, char **argv);
struct server *server_new(int argc, char **argv, int start);
int parse_int(const char *name, const char *value);
int get_sig(const char *name);
void get_sig_name(int sig, char *name, size_t len);
bool endswith(const char *str, const char *suffix);
void lowercase(char *str);
void *xrealloc(void *ptr, size_t size);
void print_config();
void open_uri(const char *uri);
void signal_cb(uv_signal_t *handle, int signum);
void server_free(struct server *server);
#ifdef _WIN32
bool conpty_init();
#endif
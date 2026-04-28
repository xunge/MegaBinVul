#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <dlfcn.h>

#define NI_MAXHOST 1025
#define NI_MAXSERV 32
#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 8192
#define PERDITION_LOG_STR_CLIENT "client"
#define PERDITION_LOG_STR_REAL "real server"
#define PROTOCOL_IMAP4 1
#define PROTOCOL_IMAP4S 2
#define PROTOCOL_NO 0
#define PROTOCOL_ERR -1
#define PROTOCOL_OK 1
#define PROTOCOL_S_SASL_MASK 0xFF
#define PROTOCOL_S_STARTTLS 0x100
#define GREETING_ADD_NODENAME 1
#define WRITE_STR_NO_CLLF 1
#define NULL_FLAG 0
#define STATE_GET_SERVER 0
#define STATE_LOCAL_AUTH 1
#define STATE_REMOTE_LOGIN 2
#define SSL_LISTEN_MASK 1
#define SSL_MODE_SSL_LISTEN 1
#define SSL_MODE_TLS_LISTEN 2
#define SSL_MODE_SSL_OUTGOING 4
#define SSL_MODE_TLS_OUTGOING 8
#define SSL_MODE_TLS_LISTEN_FORCE 16
#define SSL_MODE_TLS_OUTGOING_FORCE 32
#define PERDITION_SSL_SERVER 1
#define PERDITION_AUTH_FAIL_SLEEP 1
#define VANESSA_LOGGER_ERR_SLEEP 1
#define OPT_FIRST_CALL 1
#define io_err_timeout 1
#define LOG_ERR 3
#define LOG_INFO 6
#define VANESSA_SOCKET_NO_LOOKUP 1
#define VANESSA_SOCKET_TCP_KEEPALIVE 2

typedef struct auth {
    char *authorisation_id;
} STRUCT_AUTH;

typedef struct io {
    int fd_in;
    int fd_out;
    const char *log_str;
    int timeout;
    int err;
} io_t;

typedef struct token {
    char *value;
} token_t;

typedef unsigned int flag_t;

typedef struct timed_log {
    time_t start;
    time_t end;
} timed_log_t;

typedef struct user_server_port {
    char *server;
    char *port;
    char *user;
} user_server_port_t;

typedef struct protocol {
    char *(*port)(char *port);
    int (*greeting)(io_t *io, int flags);
    int (*in_get_auth)(io_t *io, int ssl_mode, flag_t tls_state, struct auth *auth, token_t **tag);
    int (*in_authenticate)(struct auth *auth, io_t *io, token_t *tag);
    int (*out_setup)(io_t *server_io, io_t *client_io, struct auth *auth, token_t *tag);
    int (*out_authenticate)(io_t *server_io, io_t *client_io, flag_t tls_state, struct auth *auth, int sasl_mech, token_t *tag, struct protocol *protocol, char *resp_buf, size_t *resp_size);
    int (*write_str)(io_t *io, int flags, token_t *tag, const char *prefix, const char *str);
    int (*bye)(io_t *io, const char *msg);
    const char *type[];
} protocol_t;

struct opt {
    char *config_file;
    int debug;
    int quiet;
    char *map_library;
    char *map_library_opt;
    char *listen_port;
    char *outgoing_port;
    char *log_facility;
    int no_lookup;
    int tcp_keepalive;
    char *pid_file;
    char *username;
    char *group;
    int inetd_mode;
    int no_daemon;
    char *outgoing_server;
    int server_resp_line;
    char *ok_line;
    int authenticate_timeout;
    int timeout;
    int connection_limit;
    int protocol;
    int ssl_mode;
    char *ssl_ca_file;
    char *ssl_ca_path;
    char *ssl_cert_file;
    char *ssl_key_file;
    char *ssl_ca_chain_file;
    char *ssl_listen_ciphers;
    char *ssl_outgoing_ciphers;
    int authenticate_in;
    int username_from_database;
    int login_disabled;
    int client_server_specification;
    void *bind_address;
};

extern struct opt opt;
extern void *handle;
extern int (*dbserver_get)(const char *, const char *, const char *, const char *, user_server_port_t **);
extern int (*dbserver_get2)(const char *, const char *, const char *, const char *, user_server_port_t **, void *);
extern struct sockaddr *sockname;
extern struct sockaddr *peername;
extern char *progname;
extern char *pid_file;
extern struct utsname *system_uname;

// Function declarations
void logger_init(void);
void logger_reopen(FILE *fh);
void options(int argc, char **argv, int flag);
void config_file_to_opt(char *config_file);
void init_set_proc_title(int argc, char **argv, char **envp);
char *get_progname(char *arg);
void set_proc_title(const char *fmt, ...);
void vanessa_logger_change_max_priority(void *logger, int priority);
void *vanessa_logger_get(void);
int vanessa_logger_reopen(void *logger);
int getserver_openlib(const char *lib, const char *opt, void **handle, int (**dbserver_get)(), int (**dbserver_get2)());
void perdition_reread_handler(int sig);
void perdition_exit_cleanly(int status);
void vanessa_socket_handler_noop(int sig);
void vanessa_socket_handler_reaper(int sig);
int log_options(void);
void perdition_log_close_early(char *str, struct auth *auth);
void perdition_log_close(char *str, struct auth *auth, size_t bytes_read, size_t bytes_written);
#define PERDITION_CLEAN_UP_MAIN do { \
    if (client_io) io_close(client_io); \
    if (server_io) io_close(server_io); \
    if (our_tag) token_free(our_tag); \
    if (client_tag) token_free(client_tag); \
    if (usp) user_server_port_free(usp); \
    if (buffer) free(buffer); \
    if (server_resp_buf) free(server_resp_buf); \
    auth_cleanup(&auth); \
} while (0)

#define PERDITION_SET_UID_AND_GID do { \
    if (opt.username && setuid(opt.username) < 0) { \
        VANESSA_LOGGER_DEBUG_ERRNO("setuid"); \
        VANESSA_LOGGER_ERR("Failed to set uid"); \
        perdition_exit_cleanly(-1); \
    } \
    if (opt.group && setgid(opt.group) < 0) { \
        VANESSA_LOGGER_DEBUG_ERRNO("setgid"); \
        VANESSA_LOGGER_ERR("Failed to set gid"); \
        perdition_exit_cleanly(-1); \
    } \
} while (0)

void PERDITION_LOG_AUTH(const char *msg);
void LOGIN_FAILED_PROTOCOL(int code, const char *msg);
void quit(io_t *io, protocol_t *protocol, token_t *tag);
char *username_mangle(char *id, int state);
user_server_port_t *getserver(char *id, char *from_host, char *to_host, char *from_serv, char *to_serv, int (*dbserver_get)(), int (*dbserver_get2)());
void getserver_closelib(void *handle);
char *str_null_safe(char *str);
void token_flush(void);
io_t *io_create_fd(int fd_in, int fd_out, const char *log_str);
void io_set_timeout(io_t *io, int timeout);
int io_get_err(io_t *io);
int io_pipe(io_t *in, io_t *out, char *buffer, size_t size, size_t *bytes_written, size_t *bytes_read, timed_log_t *log);
int vanessa_socket_daemon_inetd_process(void);
int vanessa_socket_daemon_process(void);
int *vanessa_socket_server_bindv(const char **addrs, int flags);
int vanessa_socket_server_acceptv(int *g, int limit, struct sockaddr *peername, struct sockaddr *sockname, int flags);
int vanessa_socket_client_src_open(const char *src_host, const char *src_port, const char *host, const char *port, int flags);
size_t vanessa_dynamic_array_get_count(void *array);
void *vanessa_dynamic_array_get_element(void *array, size_t index);
char *user_server_port_get_server(user_server_port_t *usp);
char *user_server_port_get_port(user_server_port_t *usp);
char *auth_get_authorisation_id(struct auth *auth);
void auth_set_authorisation_id(struct auth *auth, char *id);
void auth_cleanup(struct auth *auth);
protocol_t *protocol_initialise(int protocol, protocol_t *proto);
token_t *imap4_tag_create(void);
void token_free(token_t *token);
void user_server_port_free(user_server_port_t *usp);
void io_close(io_t *io);
size_t perdition_get_salen(struct sockaddr *sa);
int write_pid_file(char *pid_file, char *username, char *group);
void VANESSA_LOGGER_DEBUG(const char *msg);
void VANESSA_LOGGER_DEBUG_ERRNO(const char *msg);
void VANESSA_LOGGER_ERR(const char *msg);
void VANESSA_LOGGER_ERR_UNSAFE(const char *fmt, ...);
void VANESSA_LOGGER_DEBUG_UNSAFE(const char *fmt, ...);
void VANESSA_LOGGER_INFO(const char *msg);
void VANESSA_LOGGER_INFO_UNSAFE(const char *fmt, ...);
void usage(int status);

#ifdef WITH_SSL_SUPPORT
#include <openssl/ssl.h>
SSL_CTX *perdition_ssl_ctx(char *ca_file, char *ca_path, char *cert_file, char *key_file, char *ca_chain_file, char *ciphers, int mode);
io_t *perdition_ssl_server_connection(io_t *io, SSL_CTX *ctx);
io_t *perdition_ssl_client_connection(io_t *io, char *ca_file, char *ca_path, char *ciphers, char *hostname);
#endif
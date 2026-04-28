#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct mg_context {
    struct {
        void (*init_thread)(struct mg_context *, int);
    } callbacks;
    void *user_data;
    unsigned cfg_worker_threads;
    size_t max_request_size;
    struct mg_connection *worker_connections;
    volatile int stop_flag;
    void *ssl_ctx;
};

struct mg_connection {
    char *buf;
    int buf_size;
    struct mg_context *ctx;
    int thread_index;
    struct {
        void *user_data;
        int remote_port;
        char remote_addr[46];
        int is_ssl;
        struct {
            char *subject;
            char *issuer;
            char *serial;
            char *finger;
        } *client_cert;
    } request_info;
    pthread_mutex_t mutex;
    struct {
        int is_ssl;
        union {
            struct sockaddr sa;
            struct sockaddr_in sin;
            struct sockaddr_in6 sin6;
        } rsa;
    } client;
    time_t conn_birth_time;
#if defined(USE_SERVER_STATS)
    int conn_state;
#endif
};

struct mg_workerTLS {
    int is_master;
    unsigned thread_idx;
#if defined(_WIN32) && !defined(__SYMBIAN32__)
    void *pthread_cond_helper_mutex;
#endif
};

struct worker_thread_args {
    struct mg_context *ctx;
    int index;
};

extern pthread_key_t sTlsKey;
extern pthread_mutexattr_t pthread_mutex_attr;
extern volatile int thread_idx_max;

#define DEBUG_TRACE(fmt, ...) 
#define SSL_accept accept

int mg_atomic_inc(volatile int *val);
void mg_set_thread_name(const char *name);
void *fc(struct mg_context *ctx);
void mg_cry(void *fc, const char *fmt, ...);
void *mg_malloc_ctx(size_t size, void *ctx);
void mg_free(void *ptr);
int consume_socket(struct mg_context *ctx, void *client, int thread_index);
void sockaddr_to_string(char *buf, size_t len, void *sa);
void process_new_connection(struct mg_connection *conn);
int sslize(struct mg_connection *conn, void *ssl_ctx, int (*func)(), volatile int *stop_flag);
void ssl_get_client_cert_info(struct mg_connection *conn);
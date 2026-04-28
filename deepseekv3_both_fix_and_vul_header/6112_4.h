#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

typedef int pj_bool_t;
typedef int pj_status_t;
typedef struct {
    unsigned sec;
    unsigned msec;
} pj_time_val;

#define PJ_SUCCESS 0
#define PJ_FALSE 0
#define PJ_TRUE 1
#define PJ_INET6_ADDRSTRLEN 46
#define PJ_SSL_SOCK_DELAYED_CLOSE_TIMEOUT 100
#define TIMER_HANDSHAKE_TIMEOUT 1
#define TIMER_NONE 0
#define TIMER_CLOSE 2

typedef enum {
    SSL_STATE_NULL
} ssl_state_t;

typedef struct pj_timer_entry {
    int id;
} pj_timer_entry;

typedef struct pj_grp_lock pj_grp_lock;
typedef struct pj_sockaddr_t pj_sockaddr_t;

typedef struct {
    const char* obj_name;
    void* unused;
} pj_pool_t;

typedef struct {
    pj_bool_t (*on_accept_complete)(void*, void*, pj_sockaddr_t*, int);
    pj_bool_t (*on_accept_complete2)(void*, void*, pj_sockaddr_t*, int, pj_status_t);
    pj_bool_t (*on_connect_complete)(void*, pj_status_t);
} pj_ssl_sock_cb;

typedef struct {
    pj_ssl_sock_cb cb;
    void* timer_heap;
    pj_grp_lock* grp_lock;
} pj_ssl_sock_param;

typedef struct pj_ssl_sock_t {
    pj_ssl_sock_param param;
    pj_timer_entry timer;
    pj_bool_t is_server;
    struct pj_ssl_sock_t* parent;
    pj_pool_t* pool;
    struct sockaddr_in6 rem_addr;
    ssl_state_t ssl_state;
} pj_ssl_sock_t;

static void pj_timer_heap_cancel(void* heap, pj_timer_entry* timer) {}
static void ssl_update_certs_info(pj_ssl_sock_t* ssock) {}
static int pj_sockaddr_print(const struct sockaddr_in6* addr, char* buf, int size, int flags) { return 0; }
static int pj_sockaddr_get_len(const pj_sockaddr_t* addr) { return sizeof(struct sockaddr_in6); }
static void pj_grp_lock_dec_ref(pj_grp_lock* lock) {}
static void ssl_close_sockets(pj_ssl_sock_t* ssock) {}
static void pj_time_val_normalize(pj_time_val* tv) {}
static pj_status_t pj_timer_heap_schedule_w_grp_lock(void* heap, pj_timer_entry* timer, 
                                                   pj_time_val* delay, int id, pj_grp_lock* lock) { return 0; }
static void pj_ssl_sock_close(pj_ssl_sock_t* ssock) {}
static void ssl_reset_sock_state(pj_ssl_sock_t* ssock) {}

#define PJ_PERROR(level, ...) fprintf(stderr, __VA_ARGS__)
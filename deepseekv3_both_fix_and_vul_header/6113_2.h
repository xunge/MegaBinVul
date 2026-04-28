#include <stddef.h>
#include <stdint.h>
#include <assert.h>

typedef int pj_bool_t;
typedef int pj_sock_t;
typedef int pj_status_t;
typedef size_t pj_size_t;

#define PJ_SUCCESS 0
#define PJ_ENOMEM (-1)
#define PJ_EPENDING (-2)
#define PJ_TRUE 1
#define PJ_FALSE 0
#define PJ_UNUSED_ARG(arg) (void)(arg)

#define SSL_SOCK_IMP_USE_OWN_NETWORK 0
#define TIMER_NONE 0
#define TIMER_HANDSHAKE_TIMEOUT 1

typedef enum {
    SSL_STATE_HANDSHAKING
} ssl_state_t;

typedef struct pj_sockaddr_t {
    char dummy[128];  // Placeholder for sockaddr structure
} pj_sockaddr_t;

typedef struct pj_grp_lock_t pj_grp_lock_t;
typedef struct pj_timer_entry_t {
    int id;
} pj_timer_entry_t;
typedef struct pj_ioqueue_t pj_ioqueue_t;
typedef struct pj_timer_heap_t pj_timer_heap_t;
typedef struct pj_pool_t pj_pool_t;

typedef struct {
    void (*on_accept_complete2)(void*, void*, const pj_sockaddr_t*, int, pj_status_t);
} cb_t;

typedef struct {
    unsigned async_cnt;
    unsigned concurrency;
    unsigned read_buffer_size;
    unsigned send_buffer_size;
    pj_grp_lock_t *grp_lock;
    pj_ioqueue_t *ioqueue;
    pj_timer_heap_t *timer_heap;
    int sock_type;
    pj_bool_t qos_ignore_error;
    pj_bool_t sockopt_ignore_error;
    struct {
        int cnt;
    } sockopt_params;
    struct {
        int sec;
        int msec;
    } timeout;
    cb_t cb;
} param_t;

typedef struct {
    char *buf;
    char *start;
    unsigned len;
    unsigned max_len;
} send_buf_t;

typedef struct pj_ssl_sock_t {
    pj_sock_t sock;
    pj_pool_t *pool;
    pj_bool_t is_server;
    void *cert;
    param_t param;
    pj_sockaddr_t local_addr;
    pj_sockaddr_t rem_addr;
    int addr_len;
    void **asock_rbuf;
    void *asock;
    send_buf_t send_buf;
    pj_timer_entry_t timer;
    ssl_state_t ssl_state;
    struct pj_ssl_sock_t *parent;
    param_t newsock_param;
} pj_ssl_sock_t;

typedef struct {
    pj_grp_lock_t *grp_lock;
    unsigned async_cnt;
    unsigned concurrency;
    pj_bool_t whole_data;
} pj_activesock_cfg;

typedef struct {
    void (*on_data_read)(void*, void*, pj_size_t);
    void (*on_data_sent)(void*, void*, pj_size_t);
} pj_activesock_cb;

typedef struct read_data_t read_data_t;

void ssl_on_destroy(void*);
pj_status_t network_setup_connection(pj_ssl_sock_t*, void*);
#define pj_assert(expr) assert(expr)

pj_status_t pj_ssl_sock_create(pj_pool_t*, param_t*, pj_ssl_sock_t**);
pj_status_t pj_ssl_sock_set_certificate(pj_ssl_sock_t*, pj_pool_t*, void*);
void pj_sockaddr_cp(pj_sockaddr_t*, const pj_sockaddr_t*);
pj_status_t ssl_create(pj_ssl_sock_t*);
void* pj_pool_calloc(pj_pool_t*, unsigned, size_t);
void* pj_pool_alloc(pj_pool_t*, size_t);
pj_status_t pj_grp_lock_create(pj_pool_t*, void*, pj_grp_lock_t**);
void pj_grp_lock_add_ref(pj_grp_lock_t*);
void pj_grp_lock_add_handler(pj_grp_lock_t*, pj_pool_t*, void*, void(*)(void*));
void pj_activesock_cfg_default(pj_activesock_cfg*);
void pj_bzero(void*, size_t);
pj_status_t pj_activesock_create(pj_pool_t*, pj_sock_t, int, pj_activesock_cfg*, pj_ioqueue_t*, pj_activesock_cb*, void*, void**);
pj_status_t pj_activesock_start_read2(void*, pj_pool_t*, unsigned, void**, int);
pj_status_t get_localaddr(pj_ssl_sock_t*, pj_sockaddr_t*, int*);
void ssl_set_state(pj_ssl_sock_t*, pj_bool_t);
pj_status_t ssl_do_handshake(pj_ssl_sock_t*);
void on_handshake_complete(pj_ssl_sock_t*, pj_status_t);
pj_status_t pj_timer_heap_schedule_w_grp_lock(pj_timer_heap_t*, pj_timer_entry_t*, void*, int, pj_grp_lock_t*);
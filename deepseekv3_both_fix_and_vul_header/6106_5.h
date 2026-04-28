#include <sys/time.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef struct pj_ssl_sock_t pj_ssl_sock_t;
typedef struct pj_sockaddr_t pj_sockaddr_t;
typedef pj_sockaddr_t pj_sockaddr;
typedef struct pj_ssl_sock_info pj_ssl_sock_info;
typedef struct pjsip_tls_setting pjsip_tls_setting;
typedef struct pjsip_tpfactory pjsip_tpfactory;
typedef struct tls_listener tls_listener;
typedef struct pjsip_transport pjsip_transport;
typedef struct tls_transport tls_transport;
typedef struct pjsip_tls_on_accept_fail_param pjsip_tls_on_accept_fail_param;
typedef struct pjsip_transport_state_info pjsip_transport_state_info;
typedef struct pjsip_tls_state_info pjsip_tls_state_info;
typedef enum pjsip_transport_state pjsip_transport_state;
typedef struct pj_time_val pj_time_val;
typedef struct pjsip_cfg_t pjsip_cfg_t;

#define PJ_INET6_ADDRSTRLEN 46
#define PJ_FALSE 0
#define PJ_TRUE 1
#define PJ_SUCCESS 0
#define PJSIP_TLS_EACCEPT (-1)
#define PJSIP_TLS_ECERTVERIF (-2)

typedef int pj_status_t;
typedef uint8_t pj_bool_t;

struct pj_sockaddr_t {
    uint8_t sa_len;
    uint8_t sa_family;
    char sa_data[14];
};

struct pj_ssl_sock_t {
    void *user_data;
};

struct pj_ssl_sock_info {
    struct pj_sockaddr_t local_addr;
    pj_status_t verify_status;
    pj_status_t last_native_err;
    void *grp_lock;
};

struct pjsip_tls_setting {
    pj_bool_t verify_client;
    void (*on_accept_fail_cb)(void *param);
};

struct pjsip_tpfactory {
    struct pj_sockaddr_t local_addr;
    char *obj_name;
    struct {
        const char *host;
        int port;
    } addr_name;
};

struct tls_listener {
    struct pjsip_tls_setting tls_setting;
    struct pjsip_tpfactory factory;
    pj_bool_t is_registered;
    void *endpt;
};

struct pjsip_transport {
    void *tpmgr;
    pj_bool_t is_shutdown;
    char *obj_name;
};

struct tls_transport {
    struct pjsip_transport base;
    pj_status_t close_reason;
    struct {
        int id;
    } ka_timer;
    struct timeval last_activity;
};

struct pjsip_transport_state_info {
    pj_status_t status;
    void *ext_info;
};

struct pjsip_tls_state_info {
    struct pj_ssl_sock_info *ssl_sock_info;
};

enum pjsip_transport_state {
    PJSIP_TP_STATE_DISCONNECTED,
    PJSIP_TP_STATE_CONNECTED
};

struct pj_time_val {
    long sec;
    long msec;
};

struct pjsip_cfg_t {
    struct {
        int keep_alive_interval;
    } tls;
};

typedef void (*pjsip_tp_state_callback)(struct pjsip_transport *transport, 
                                      enum pjsip_transport_state state,
                                      struct pjsip_transport_state_info *info);

struct pjsip_tls_on_accept_fail_param {
    pj_status_t status;
    const struct pj_sockaddr_t *local_addr;
    const struct pj_sockaddr_t *remote_addr;
    pj_status_t last_native_err;
};

#define PJ_UNUSED_ARG(arg) (void)(arg)
#define PJ_ASSERT_RETURN(expr, retval) do { if (!(expr)) return (retval); } while(0)
#define PJ_LOG(level, args) printf args
#define THIS_FILE __FILE__

static void pj_bzero(void *dst, size_t size) { memset(dst, 0, size); }
static void pj_sockaddr_cp(struct pj_sockaddr_t *dst, const struct pj_sockaddr_t *src) { *dst = *src; }
static const char *pj_sockaddr_print(const struct pj_sockaddr_t *addr, char *buf, int size, int flags) { return ""; }
static const char *pj_addr_str_print(const char *host, int port, char *buf, int size, int flags) { return ""; }
static void pj_ssl_sock_close(pj_ssl_sock_t *sock) {}
static pj_status_t pj_ssl_sock_get_info(pj_ssl_sock_t *sock, struct pj_ssl_sock_info *info) { return PJ_SUCCESS; }
static void *pj_ssl_sock_get_user_data(pj_ssl_sock_t *sock) { return sock->user_data; }
static void pj_ssl_sock_set_user_data(pj_ssl_sock_t *sock, void *user_data) { sock->user_data = user_data; }
static void pjsip_transport_add_ref(pjsip_transport *t) {}
static void pjsip_transport_dec_ref(pjsip_transport *t) {}
static void pjsip_transport_shutdown(pjsip_transport *t) {}
static pjsip_tp_state_callback pjsip_tpmgr_get_state_cb(void *tpmgr) { return NULL; }
static int pj_gettimeofday(struct timeval *tv) { gettimeofday(tv, NULL); return 0; }
static void pjsip_endpt_schedule_timer(void *endpt, void *timer, struct timeval *delay) {}
static pj_status_t tls_create(tls_listener *listener, void *pool, pj_ssl_sock_t *sock, pj_bool_t is_server,
                             struct pj_sockaddr_t *local, struct pj_sockaddr_t *remote, void *tls_cfg,
                             void *grp_lock, tls_transport **p_tls) { return PJ_SUCCESS; }
static pj_status_t tls_start_read(tls_transport *tls) { return PJ_SUCCESS; }
static void tls_init_shutdown(tls_transport *tls, pj_status_t status) {}
static void tls_destroy(pjsip_transport *transport, pj_status_t status) {}
static pjsip_cfg_t* pjsip_cfg() { static pjsip_cfg_t cfg; return &cfg; }
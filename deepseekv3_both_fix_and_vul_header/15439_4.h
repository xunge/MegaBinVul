#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ast_rtp_instance;
struct ast_sockaddr {
    int dummy;
};

struct ast_rtp_engine_test {
    int packets_to_drop;
};

struct ast_rtp_engine_ice_candidate {
    struct ast_sockaddr address;
};

struct ast_rtp_rtcp {
    int s;
    struct ast_sockaddr them;
};

struct dtls_details {
    void *ssl;
    void *read_bio;
    int dtls_setup;
    int connection;
};

struct ast_rtp {
    int s;
    struct ast_rtp_rtcp *rtcp;
    struct ast_sockaddr rtp_loop;
    struct ast_sockaddr rtcp_loop;
    struct dtls_details dtls;
    void *ice;
    void *ice_active_remote_candidates;
    void *ice_proposed_remote_candidates;
    int ice_media_started;
    int passthrough;
};

struct ice_wrap {
    void *real_ice;
};

typedef struct {
    char *ptr;
    size_t slen;
} pj_str_t;

typedef int pj_status_t;
typedef struct {
    int af;
} pj_sockaddr;

#define HAVE_OPENSSL 0
#define HAVE_PJPROJECT 0
#define TEST_FRAMEWORK 0
#define PJ_ICE_MAX_CAND 32
#define AST_RTP_ICE_COMPONENT_RTP 1
#define AST_RTP_ICE_COMPONENT_RTCP 2
#define TRANSPORT_SOCKET_RTP 1
#define TRANSPORT_SOCKET_RTCP 2
#define AST_RTP_DTLS_SETUP_ACTPASS 1
#define AST_RTP_DTLS_SETUP_PASSIVE 2
#define AST_RTP_DTLS_CONNECTION_EXISTING 1
#define RTP_DTLS_ESTABLISHED 1
#define LOG_WARNING 4
#define LOG_ERROR 3
#define PJ_SUCCESS 0
#define PJ_AF_UNSPEC 0

static inline pj_str_t pj_str(const char *s) {
    pj_str_t str = { (char*)s, s ? strlen(s) : 0 };
    return str;
}

static inline void pj_thread_register_check(void) {}
static inline int pj_sockaddr_parse(int af, int flags, pj_str_t *input, pj_sockaddr *addr) { return 0; }
static inline pj_status_t pj_ice_sess_on_rx_pkt(void *ice, int comp, int transport, void *buf, int len, pj_sockaddr *addr, int addr_len) { return 0; }
static inline int pj_sockaddr_get_len(pj_sockaddr *addr) { return 0; }
static inline void pj_strerror(pj_status_t status, char *buf, size_t size) { snprintf(buf, size, "Unknown error"); }

int ast_recvfrom(int s, void *buf, size_t size, int flags, struct ast_sockaddr *sa);
struct ast_rtp *ast_rtp_instance_get_data(struct ast_rtp_instance *instance);
void ast_log(int level, const char *format, ...);
void ast_debug_dtls(int level, const char *format, ...);
const char *ast_rtp_instance_get_channel_id(struct ast_rtp_instance *instance);
char *ast_sockaddr_stringify(struct ast_sockaddr *sa);
int ast_sockaddr_cmp_addr(const struct ast_sockaddr *addr1, const struct ast_sockaddr *addr2);
int ast_sockaddr_isnull(const struct ast_sockaddr *addr);
int ast_sockaddr_cmp(const struct ast_sockaddr *addr1, const struct ast_sockaddr *addr2);
void ast_sockaddr_copy(struct ast_sockaddr *dst, const struct ast_sockaddr *src);
void ast_rtp_instance_get_remote_address(struct ast_rtp_instance *instance, struct ast_sockaddr *sa);
void ast_rtp_instance_set_remote_address(struct ast_rtp_instance *instance, struct ast_sockaddr *sa);
struct ast_rtp_engine_test *ast_rtp_instance_get_test(struct ast_rtp_instance *instance);
void ao2_unlock(void *obj);
void ao2_lock(void *obj);
void ao2_ref(void *obj, int change);
void *ao2_iterator_init(void *obj, int flags);
void *ao2_iterator_next(void *iter);
void ao2_iterator_destroy(void *iter);
int dtls_srtp_setup(struct ast_rtp *rtp, struct ast_rtp_instance *instance, int rtcp);
void dtls_srtp_stop_timeout_timer(struct ast_rtp_instance *instance, struct ast_rtp *rtp, int rtcp);
void dtls_srtp_start_timeout_timer(struct ast_rtp_instance *instance, struct ast_rtp *rtp, int rtcp);
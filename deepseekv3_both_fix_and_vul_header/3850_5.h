#include <stddef.h>
#include <time.h>

typedef struct gnutls_session_int *gnutls_session_t;

typedef struct version_entry_st {
    int tls13_sem;
} version_entry_st;

typedef struct priorities_st {
    struct {
        size_t size;
    } cs;
} priorities_st;

typedef struct gnutls_session_int {
    struct {
        int initial_negotiation_completed;
        priorities_st *priorities;
        unsigned int used_exts;
        unsigned int hsk_flags;
        int handshake_in_progress;
        int vc_status;
        struct timespec handshake_start_time;
        unsigned int handshake_timeout_ms;
        struct timespec handshake_abs_timeout;
        int recv_state;
        unsigned int ertt;
        int record_presend_buffer;
    } internals;
    struct {
        int entity;
    } security_parameters;
} gnutls_session_int;

enum {
    GNUTLS_CLIENT = 0,
    GNUTLS_E_NO_PRIORITIES_WERE_SET = -1,
    GNUTLS_E_HANDSHAKE_DURING_FALSE_START = -2,
    GNUTLS_KU_PEER = 0,
    STATE0 = 0,
    RECV_STATE_FALSE_START = 0,
    RECV_STATE_EARLY_START = 1,
    HSK_HRR_RECEIVED = 1
};

#define unlikely(x) (x)
#define IS_DTLS(x) 0
#define IS_SERVER(x) 0
#define STATE (session->internals.handshake_in_progress)

static const version_entry_st *get_version(gnutls_session_t session);
static int gnutls_session_key_update(gnutls_session_t session, int flag);
static int gnutls_assert_val(int val);
static int _gnutls_epoch_setup_next(gnutls_session_t session, int a, void *b);
static void gnutls_gettime(struct timespec *ts);
static void session_invalidate(gnutls_session_t session);
static int handshake_client(gnutls_session_t session);
static int handshake_server(gnutls_session_t session);
static int _gnutls_abort_handshake(gnutls_session_t session, int ret);
static void _gnutls_handshake_hash_buffers_clear(gnutls_session_t session);
static void _gnutls_handshake_io_buffer_clear(gnutls_session_t session);
static void _dtls_async_timer_init(gnutls_session_t session);
static void _gnutls_handshake_internal_state_clear(gnutls_session_t session);
static void _gnutls_buffer_clear(int *buffer);
static void _gnutls_epoch_bump(gnutls_session_t session);
static long long timespec_sub_ms(struct timespec *a, struct timespec *b);
#include <stdint.h>
#include <time.h>

#define GNUTLS_MAX_SESSION_ID_SIZE 32
#define GNUTLS_RANDOM_SIZE 32
#define GNUTLS_SSL3 1
#define GNUTLS_CLIENT 1
#define GNUTLS_HANDSHAKE_CLIENT_HELLO 1
#define GNUTLS_EXT_ANY 0
#define GNUTLS_EXT_MANDATORY 1
#define GNUTLS_EXT_FLAG_CLIENT_HELLO (1 << 0)
#define GNUTLS_E_INSUFFICIENT_CREDENTIALS -100
#define GNUTLS_E_NO_PRIORITIES_WERE_SET -101
#define GNUTLS_E_UNSUPPORTED_VERSION_PACKET -102
#define INT_FLAG_NO_TLS13 (1 << 0)
#define HSK_HRR_RECEIVED (1 << 0)

typedef struct version_entry_st version_entry_st;
typedef struct gnutls_datum_t gnutls_datum_t;
typedef struct resumed_security_parameters_st resumed_security_parameters_st;
typedef struct security_parameters_st security_parameters_st;
typedef struct priorities_st priorities_st;
typedef struct session_internals_st session_internals_st;
typedef struct gnutls_session_int gnutls_session_int;
typedef struct gnutls_buffer_st gnutls_buffer_st;
typedef struct mbuffer_st mbuffer_st;

struct version_entry_st {
    uint8_t major;
    uint8_t minor;
    int id;
    unsigned tls13_sem;
};

struct gnutls_datum_t {
    unsigned char *data;
    size_t size;
};

struct resumed_security_parameters_st {
    uint8_t session_id[GNUTLS_MAX_SESSION_ID_SIZE];
    uint8_t session_id_size;
    version_entry_st *pversion;
    gnutls_datum_t dcookie;
};

struct security_parameters_st {
    uint8_t client_random[GNUTLS_RANDOM_SIZE];
    uint8_t session_id[GNUTLS_MAX_SESSION_ID_SIZE];
    uint8_t session_id_size;
    time_t timestamp;
    int entity;
};

struct priorities_st {
    int no_extensions;
    int min_record_version;
};

struct dtls_internals_st {
    gnutls_datum_t dcookie;
    int hsk_hello_verify_requests;
};

struct session_internals_st {
    unsigned hsk_flags;
    unsigned flags;
    unsigned initial_negotiation_completed;
    unsigned resumption_requested;
    unsigned premaster_set;
    uint8_t default_hello_version[2];
    struct dtls_internals_st dtls;
    resumed_security_parameters_st resumed_security_parameters;
    security_parameters_st security_parameters;
    priorities_st *priorities;
};

struct gnutls_session_int {
    session_internals_st internals;
    security_parameters_st security_parameters;
};

typedef gnutls_session_int* gnutls_session_t;

struct gnutls_buffer_st {
    unsigned char *data;
    size_t length;
};

struct mbuffer_st {
    struct mbuffer_st *next;
    unsigned char *data;
    size_t length;
};

static inline int unlikely(int x) { return x; }
static time_t gnutls_time(time_t *t) { return time(t); }
static int gnutls_assert_val(int x) { return x; }
static void gnutls_assert(void) {}